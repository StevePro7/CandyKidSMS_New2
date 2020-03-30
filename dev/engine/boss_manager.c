#include "boss_manager.h"
#include "enemy_manager.h"
#include "enum_manager.h"
#include "function_manager.h"
#include "sprite_manager.h"
#include "state_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\object\board_object.h"
#include "..\banks\bank3.h"
#include <stdlib.h>

// IMPORTANT disable compiler warning 110
#ifdef _CONSOLE
#else
	#pragma disable_warning 110
	#pragma disable_warning 126
#endif

// Global variable.
//struct_boss_object global_boss_object;

// Global variables.
struct_boss_object global_boss_objects[ MAX_BOSSES ];

static void calcd_spots( unsigned char index );
static unsigned char boss_one;
static unsigned char boss_two;
static unsigned char content_index;

void engine_boss_manager_init()
{
	struct_boss_object *bo;
	unsigned char bossX;

	for( bossX = 0; bossX < MAX_BOSSES; bossX++ )
	{
		bo = &global_boss_objects[ bossX ];

		bo->actor = 0;
		bo->posnX = 0;	bo->posnY = 0;
		bo->homeX = 0;	bo->homeY = 0;
		bo->tileX = 0;	bo->tileY = 0;	bo->tileZ = 0;
		bo->waiter = 0;	bo->action = enemymove_type_wait;

		bo->sizer = boss_type_large;
		bo->mover = 1;	bo->drawr = 1;
		bo->high = 0;	bo->wide = 0;

		bo->lifecycle = lifecycle_type_idle;
		bo->prev_move = direction_type_none;
		bo->direction = direction_type_none;

		bo->image = 0;
	}

	boss_one = 0; boss_two = 0;
	content_index = 0;
}

void engine_boss_manager_setup( unsigned char round )
{
	struct_enemy_object *eo;
	unsigned char enemy;
	unsigned char image;

	// Randomize the first boss.
	enemy = rand() % MAX_ENEMIES;
	boss_one = enemy;
	if( 0 == ( round + 1 ) % MAX_ROUNDS )
	{
		engine_state_manager_fight( fight_type_boss1 );
		boss_two = enemy;

		eo = &global_enemy_objects[ enemy ];
		image = eo->image;

		content_index = enemy * 2 + image;
	}
	else
	{
		engine_state_manager_fight( fight_type_boss2 );

		// Randomize the second boss.
		while( 1 )
		{
			enemy = rand() % MAX_ENEMIES;
			if( boss_one != enemy )
			{
				boss_two = enemy;
				break;
			}
		}

		if( ( actor_type_pro == boss_one && actor_type_adi == boss_two ) || ( actor_type_adi == boss_one && actor_type_pro == boss_two ) )
		{
			content_index = 0;
		}
		else if( ( actor_type_adi == boss_one && actor_type_suz == boss_two ) || ( actor_type_suz == boss_one && actor_type_adi == boss_two ) )
		{
			content_index = 1;
		}
		else if( ( actor_type_pro == boss_one && actor_type_suz == boss_two ) || ( actor_type_suz == boss_one && actor_type_pro == boss_two ) )
		{
			content_index = 2;
		}
	}
}

void engine_boss_manager_load( unsigned char round )
{
	struct_boss_object *bo;
	unsigned char enemy;
	unsigned char index;


	// TODO calculate
	// boss1	every  5th round
	// boss2	every 10th round
	round++;
	engine_state_manager_fight( fight_type_boss1 );
	//engine_state_manager_fight( fight_type_boss2 );

	enemy = actor_type_pro;
	//enemy = actor_type_adi;
	//enemy = actor_type_suz;
	index = 0;
	bo = &global_boss_objects[ index ];
	//bo->sizer = boss_type_large;
	bo->sizer = boss_type_small;

	bo->homeX = board_object_homeX[ enemy ];
	bo->homeY = board_object_homeY[ enemy ];

	// Offset homeY by 1x row for bottom enemies.
	if( actor_type_suz != enemy )
	{
		bo->homeY -= 1;
	}

	bo->tileX = bo->homeX;
	bo->tileY = bo->homeY;
	
	bo->mover = 1;
	bo->drawr = 1;

	bo->wide = 1;
	bo->high = 1;

	calcd_spots( index );
}

void engine_boss_manager_update()
{
}

void engine_boss_manager_draw()
{
	struct_boss_object *bo;
	bo = &global_boss_objects[ 0 ];
	if( boss_type_large == bo->sizer )
	{
		engine_sprite_manager_draw_boss1( bo->posnX, bo->posnY );
	}
	else if( boss_type_small == bo->sizer )
	{
		engine_sprite_manager_draw_boss2( bo->wide, bo->high, bo->posnX, bo->posnY );
	}
}


//void engine_boss_manager_content( unsigned char index )
void engine_boss_manager_content()
{
	const unsigned char *tiles = boss_object_tiles[ content_index ];
	const unsigned char *color = boss_object_color[ content_index ];
	const unsigned char bank = boss_object_bank[ content_index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( tiles, SPRITE_TILES );
	devkit_SMS_loadSpritePalette( ( void * ) color );
}

static void calcd_spots( unsigned char index )
{
	struct_boss_object *bo = &global_boss_objects[ index ];
	bo->posnX = board_object_posnX[ bo->tileX ];
	bo->posnY = board_object_posnY[ bo->tileY ];

	if( boss_type_large == bo->sizer )
	{
		bo->posnX -= TILE_WIDE;
		bo->posnY -= TILE_HIGH;
	}
	if( boss_type_small == bo->sizer )
	{
		bo->posnX -= TILE_HALF / 2;
	}

	engine_function_manager_convertXYtoZ( MAZE_ROWS, bo->tileX, bo->tileY, &bo->tileZ );
}