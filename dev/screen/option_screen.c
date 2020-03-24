#include "option_screen.h"
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
#include "..\engine\sprite_manager.h"
#include "..\engine\tile_manager.h"
#include "..\devkit\_sms_manager.h"

#ifdef _CONSOLE
#else
#pragma disable_warning 110
#endif

static void draw_tiles();

void screen_option_screen_load()
{
	// Load from SRAM first.
	//engine_main_manager_load();

	devkit_SMS_displayOff();
	engine_asm_manager_clear_VRAM();
	engine_content_manager_load_tiles_font();
	engine_content_manager_load_tiles_main();
	engine_content_manager_load_sprites_game();

	engine_board_manager_border( border_type_main );
	engine_tile_manager_main_title( 2, 2 );

	draw_tiles();

	engine_locale_manager_draw_text( 0, SCREEN_TILE_LEFT + 24, BOTT_TEXT_Y );
	devkit_SMS_displayOn();

	engine_font_manager_draw_text( "OPTION SCREEN!!", 4, 6 );
}

void screen_option_screen_update( unsigned char *screen_type )
{
	/*unsigned char x = 48;
	unsigned char y = 64;
	unsigned char e = 112;
	engine_sprite_manager_draw_entity( x, y + 0, 352 );

	engine_sprite_manager_draw_entity( x + e - 16, y + 0, 304 );
	engine_sprite_manager_draw_entity( x + e - 16, y + 24, 318 );
	engine_sprite_manager_draw_entity( x + e - 16, y + 48, 332 );*/

	*screen_type = screen_type_option;
}

static void draw_tiles()
{
	unsigned char l1 = SCREEN_TILE_LEFT + 4;		// 6
	unsigned char l2 = SCREEN_TILE_LEFT + 6;		// 8
	unsigned char l3 = SCREEN_TILE_LEFT + 9;		// 11
	unsigned char l4 = SCREEN_TILE_LEFT + 12;		// 14

	unsigned char r1 = SCREEN_TILE_LEFT + 16;		// 18
	unsigned char r2 = SCREEN_TILE_LEFT + 18;		// 20
	unsigned char r3 = SCREEN_TILE_LEFT + 21;		// 23

	unsigned char b1 = 8;

	// LHS #1
	engine_tile_manager_draw_trees( tree_type_avoid, l1, b1 + 3 );
	engine_font_manager_draw_text( "EX", l1, b1 + 6 );
	engine_font_manager_draw_text( "IT", l1, b1 + 7 );


	// LHS #2.	arrow
	engine_font_manager_draw_text( "WORLD", l2, b1 + 10 );
	engine_font_manager_draw_text( "ROUND", l2, b1 + 11 );


	// LHS #3
	engine_font_manager_draw_text( "CANDY", l3, b1 + 0 );
	engine_font_manager_draw_text( " KID1", l3, b1 + 1 );

	engine_font_manager_draw_text( "AVOID", l3, b1 + 3 );
	//engine_font_manager_draw_text( "DEATH", l3, b1 + 4 );
	engine_font_manager_draw_text( "TREES", l3, b1 + 4 );

	engine_font_manager_draw_text( "EXITS", l3, b1 + 6 );
	//engine_font_manager_draw_text( " OPEN", l3, b1 + 7 );
	engine_font_manager_draw_text( " SHUT", l3, b1 + 7 );


	// LHS #3
	engine_font_manager_draw_text( "01", l4, b1 + 10 );
	engine_font_manager_draw_text( "02", l4, b1 + 11 );


	// RHS #1
	engine_font_manager_draw_text( "DIFFICULTY", r1, b1 + 10 );

	// RHS #2.	arrow
	//engine_font_manager_draw_text( LOCALE_SELECT_ARROWS, r2, b1 + 11 );

	// RHS #3.
	engine_font_manager_draw_text( "ENEMY", r3, b1 + 0 );
	engine_font_manager_draw_text( " PRO1", r3, b1 + 1 );
	engine_font_manager_draw_text( "ENEMY", r3, b1 + 3 );
	engine_font_manager_draw_text( " ADI1", r3, b1 + 4 );
	engine_font_manager_draw_text( "ENEMY", r3, b1 + 6 );
	engine_font_manager_draw_text( " SUZ1", r3, b1 + 7 );

	engine_font_manager_draw_text( " HARD", r3, b1 + 11 );
}