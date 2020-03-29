#include "boss_manager.h"
#include "enum_manager.h"
#include "state_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\banks\bank3.h"

// Global variable.
struct_boss_object global_boss_object;

// Global variables.
struct_boss_object global_boss_objects[ MAX_BOSSES ];

void engine_boss_manager_content( unsigned char index )
{
	const unsigned char *tiles = boss_object_tiles[ index ];
	const unsigned char *color = boss_object_color[ index ];
	const unsigned char bank = boss_object_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( tiles, SPRITE_TILES );
	devkit_SMS_loadSpritePalette( ( void * ) color );

	//devkit_SMS_mapROMBank( boss64_00__tiles__psgcompr_bank );
	//devkit_SMS_loadPSGaidencompressedTiles( boss64_00__tiles__psgcompr, SPRITE_TILES );
	//devkit_SMS_loadSpritePalette( ( void * ) boss64_00__palette__bin );
}

void engine_boss_manager_init()
{
}

void engine_boss_manager_load()
{
	engine_state_manager_fight( fight_type_boss );
}

void engine_boss_manager_update()
{
}

void engine_boss_manager_draw()
{
}
