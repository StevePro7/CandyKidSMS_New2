#include "boss_manager.h"
#include "enum_manager.h"
#include "state_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\banks\bank3.h"

// Global variable.
//struct_boss_object global_boss_object;

// Global variables.
struct_boss_object global_boss_objects[ MAX_BOSSES ];



void engine_boss_manager_init()
{
	struct_boss_object *bo;
	unsigned char bossX;

	for( bossX = 0; bossX < MAX_BOSSES; bossX++ )
	{
		bo = &global_boss_objects[ bossX ];

		bo->actor = 0;
		bo->posnX = 0;
		bo->posnY = 0;
		bo->homeX = 0;
		bo->homeY = 0;
		bo->tileX = 0;
		bo->tileY = 0;
		bo->tileZ = 0;
		bo->waiter = 0;
		bo->waiter = enemymove_type_wait;

		bo->sizer = boss_type_large;
		bo->mover = 1;
		bo->drawr = 1;

		bo->lifecycle = lifecycle_type_idle;
		bo->prev_move = direction_type_none;
		bo->direction = direction_type_none;

		bo->image = 0;
	}
}

void engine_boss_manager_load( unsigned char round )
{
	struct_boss_object *bo;
	// TODO calculate
	// boss1	every  5th round
	// boss2	every 10th round
	round++;
	engine_state_manager_fight( fight_type_boss1 );
	//engine_state_manager_fight( fight_type_boss2 );

	bo = &global_boss_objects[ 0 ];
	bo->posnX = 128;
	bo->posnY = 96;
	bo->sizer = boss_type_large;
	bo->mover = 1;
	bo->drawr = 1;
}

void engine_boss_manager_update()
{
}

void engine_boss_manager_draw()
{
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