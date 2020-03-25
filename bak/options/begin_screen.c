#include "begin_screen.h"
#include "..\engine\asm_manager.h"
#include "..\engine\board_manager.h"
#include "..\engine\content_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\global_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\locale_manager.h"
#include "..\engine\main_manager.h"
#include "..\engine\tile_manager.h"
#include "..\devkit\_sms_manager.h"

static void draw_tiles();

void screen_begin_screen_load()
{
	// Load from SRAM first.
	engine_main_manager_load();

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
}

void screen_begin_screen_update( unsigned char *screen_type )
{
	unsigned char input = engine_input_manager_hold( input_type_fire1 );
	if( input )
	{
		*screen_type = screen_type_init;
		return;
	}

	*screen_type = screen_type_title;
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

	unsigned char m1 = SCREEN_TILE_LEFT + 11;		// 13

	unsigned char b1 = 8;

	// LHS #1
	engine_tile_manager_draw_bonus( tile_type_bonusB, l1, b1 + 3, 1 );
	engine_tile_manager_main_candy( 2, l1, b1 + 6 );
	//engine_tile_manager_draw_trees( tree_type_avoid, l1, b1 + 3 );
	//engine_font_manager_draw_text( "EX", l1, b1 + 6 );
	//engine_font_manager_draw_text( "IT", l1, b1 + 7 );


	// LHS #2.	arrow
	//engine_font_manager_draw_text( "WORLD", l2, b1 + 10 );
	//engine_font_manager_draw_text( "ROUND", l2, b1 + 11 );


	// LHS #3
	engine_font_manager_draw_text( "CANDY", l3, b1 + 0 );
	engine_font_manager_draw_text( "KID1", l3 + 1, b1 + 1 );

	engine_font_manager_draw_text( "200", l3 + 1, b1 + 3 );
	engine_font_manager_draw_text( "PTS", l3 + 1, b1 + 4 );

	engine_font_manager_draw_text( "10", l3 + 1, b1 + 6 );
	engine_font_manager_draw_text( "PTS", l3 + 1, b1 + 7 );


	// LHS #3
	//engine_font_manager_draw_text( "01", l4, b1 + 10 );
	//engine_font_manager_draw_text( "02", l4, b1 + 11 );


	// RHS #1
	//engine_font_manager_draw_text( "DIFFICULTY", r1, b1 + 10 );

	// RHS #2.	arrow
	//engine_font_manager_draw_text( LOCALE_SELECT_ARROWS, r2, b1 + 11 );

	// RHS #3.
	engine_font_manager_draw_text( "ENEMY", r3, b1 + 0 );
	engine_font_manager_draw_text( " PRO1", r3, b1 + 1 );
	engine_font_manager_draw_text( "ENEMY", r3, b1 + 3 );
	engine_font_manager_draw_text( " ADI1", r3, b1 + 4 );
	engine_font_manager_draw_text( "ENEMY", r3, b1 + 6 );
	engine_font_manager_draw_text( " SUZ1", r3, b1 + 7 );


	// BOTTOM
	//engine_font_manager_draw_text( "CONTINUE", m1, b1 + 10 );
	//engine_font_manager_draw_text( "OPTIONS", m1, b1 + 11 );


	//engine_locale_manager_draw_text( 1, SCREEN_TILE_LEFT + 6, TEXT4_Y );

	// cheat
	//engine_locale_manager_draw_text( 2, SCREEN_TILE_LEFT + 2, BOTT_TEXT_Y );
}


// TODO delete this...
static void draw_tiles_OLD()
{
	const unsigned char multiplier = 1;
	engine_tile_manager_draw_trees( tree_type_avoid, SCREEN_TILE_LEFT + 10, 8 );
	engine_tile_manager_draw_trees( tree_type_death, SCREEN_TILE_LEFT + 10, 10 );

	engine_tile_manager_draw_bonus( tile_type_bonusA, SCREEN_TILE_LEFT + 15, 8, multiplier );
	engine_tile_manager_draw_bonus( tile_type_bonusB, SCREEN_TILE_LEFT + 15, 10, multiplier );
	engine_tile_manager_draw_bonus( tile_type_bonusC, SCREEN_TILE_LEFT + 15, 12, multiplier );
	engine_tile_manager_draw_bonus( tile_type_bonusD, SCREEN_TILE_LEFT + 15, 14, multiplier );
}