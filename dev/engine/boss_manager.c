#include "boss_manager.h"
#include "enum_manager.h"
#include "function_manager.h"
#include "sprite_manager.h"
#include "state_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\object\board_object.h"
#include "..\banks\bank3.h"
#include <stdlib.h>

// Global variable.
//struct_boss_object global_boss_object;

// Global variables.
struct_boss_object global_boss_objects[ MAX_BOSSES ];

static void calcd_spots( unsigned char index );

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

		bo->lifecycle = lifecycle_type_idle;
		bo->prev_move = direction_type_none;
		bo->direction = direction_type_none;

		bo->image = 0;
	}
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
	engine_function_manager_convertXYtoZ( MAZE_ROWS, bo->tileX, bo->tileY, &bo->tileZ );
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
	enemy = actor_type_adi;
	enemy = actor_type_suz;
	index = 0;
	bo = &global_boss_objects[ index ];
	bo->sizer = boss_type_large;

	bo->homeX = board_object_homeX[ enemy ];
	bo->homeY = board_object_homeY[ enemy ];

	if( boss_type_large == bo->sizer )
	{
		if( actor_type_suz != enemy )
		{
			bo->homeY -= 1;
		}
	}

	bo->tileX = bo->homeX;
	bo->tileY = bo->homeY;
	
	//bo->sizer = boss_type_small;
	bo->mover = 1;
	bo->drawr = 1;

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
		engine_sprite_manager_draw_boss2( 0, 0, bo->posnX, bo->posnY );
	}
}


void engine_boss_manager_content( unsigned char index )
{
	const unsigned char *tiles = boss_object_tiles[ index ];
	const unsigned char *color = boss_object_color[ index ];
	const unsigned char bank = boss_object_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( tiles, SPRITE_TILES );
	devkit_SMS_loadSpritePalette( ( void * ) color );
}