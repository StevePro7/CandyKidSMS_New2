#include "test_screen.h"
#include "..\engine\asm_manager.h"
#include "..\engine\board_manager.h"
#include "..\engine\content_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\global_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\locale_manager.h"
#include "..\engine\main_manager.h"
#include "..\engine\option_manager.h"
#include "..\engine\sprite_manager.h"
#include "..\engine\tile_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\banks\bank3.h"

static void load_boss32();
//static void draw_boss32();

static void load_boss64();
static void draw_boss64( unsigned char x, unsigned char y );

void screen_test_screen_load()
{
	engine_asm_manager_clear_VRAM();
	engine_content_manager_load_tiles_font();
	engine_content_manager_load_tiles_game();

	load_boss64();
	engine_board_manager_border( border_type_game );

	// TODO delete
	//engine_font_manager_draw_text( "TS", 2, 6 );

	engine_gamer_manager_load();
	engine_gamer_manager_reset();

	engine_enemy_manager_load();
	engine_enemy_manager_reset_home();
}

void screen_test_screen_update( unsigned char *screen_type )
{
	engine_gamer_manager_draw();
	engine_enemy_manager_draw();

	// top left		3, 3
	//draw_boss64( 48-16, 32-16 );

	// bot left		3, 9
	//draw_boss64( 48 - 16, 144 - 32 );
	//draw_boss64( 48 - 16, 128 - 16 );

	// top right	10, 3
	draw_boss64( 160 - 16, 32 - 16 );
	*screen_type = screen_type_test;
}

static void load_boss32()
{
	devkit_SMS_mapROMBank( boss32_00__tiles__psgcompr_bank );
	devkit_SMS_loadPSGaidencompressedTiles( boss32_00__tiles__psgcompr, SPRITE_TILES );
	devkit_SMS_loadSpritePalette( ( void * ) boss32_00__palette__bin );
}
static void load_boss64()
{
	devkit_SMS_mapROMBank( boss64_00__tiles__psgcompr_bank );
	devkit_SMS_loadPSGaidencompressedTiles( boss64_00__tiles__psgcompr, SPRITE_TILES );
	devkit_SMS_loadSpritePalette( ( void * ) boss64_00__palette__bin );
}

static void draw_boss64( unsigned char x, unsigned char y )
{
	unsigned int tile;
	unsigned char r, c;
	for( r = 0; r < 8; r++ )
	{
		for( c = 0; c < 6; c++ )
		{
			tile = SPRITE_TILES + r * 6 + c;
			devkit_SMS_addSprite( x + c * 8, y + r * 8, tile );
		}
	}
}