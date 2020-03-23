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

	//engine_font_manager_draw_text( "OPTION SCREEN!!", 4, 10 );
}

void screen_option_screen_update( unsigned char *screen_type )
{
	unsigned char x = 48;
	unsigned char y = 64;
	unsigned char e = 120;
	engine_sprite_manager_draw_entity( x, y + 0, 352 );

	engine_sprite_manager_draw_entity( x + e - 16, y + 0, 304 );
	engine_sprite_manager_draw_entity( x + e - 16, y + 24, 318 );
	engine_sprite_manager_draw_entity( x + e - 16, y + 48, 332 );

	*screen_type = screen_type_option;
}

static void draw_tiles()
{
	unsigned char t = 11;
	unsigned char x = 48;
	unsigned char y = 64;
	unsigned char e = 112;
	unsigned char d = 0;

	// KID
	engine_font_manager_draw_text( LOCALE_SELECT_ARROWS, SCREEN_TILE_LEFT + 6, y / 8 + 1 );

	//unsigned char type = 0;
	engine_tile_manager_draw_trees( tree_type_avoid, x / 8, y / 8 + 3 );
	//engine_tile_manager_draw_trees( tree_type_death, x / 8, y / 8 + 6 );

	//engine_tile_manager_draw_bonus( tile_type_bonusB, x / 8 + d, y / 8 + 3, 1 );
	//engine_tile_manager_main_candy( 4, x / 8 + d, y / 8 + 6 );

	engine_font_manager_draw_text( "CANDY", x / 8 + d + 5, y / 8 + 0 );
	engine_font_manager_draw_text( "KID1", x / 8 + d + 6, y / 8 + 1 );

	//engine_font_manager_draw_text( "200 PTS", x / 8 + d + 3, y / 8 + 4 );
	//engine_font_manager_draw_text( "200", x / 8 + d + 4, y / 8 + 3 );
	//engine_font_manager_draw_text( "PTS", x / 8 + d + 4, y / 8 + 4 );
	//engine_font_manager_draw_text( " 10 PTS", x / 8 + d + 3, y / 8 + 7 );
	//engine_font_manager_draw_text( "10", x / 8 + d + 4, y / 8 + 6 );
	//engine_font_manager_draw_text( "PTS", x / 8 + d + 4, y / 8 + 7 );

	engine_font_manager_draw_text( "ENEMY", ( x + e ) / 8 + d + 4, y / 8 + 0 );
	engine_font_manager_draw_text( ">>  PRO", ( x + e ) / 8 + d + 1, y / 8 + 1 );
	engine_font_manager_draw_text( "ENEMY", ( x + e ) / 8 + d + 4, y / 8 + 3 );
	engine_font_manager_draw_text( "ADI", ( x + e ) / 8 + d + 5, y / 8 + 4 );
	engine_font_manager_draw_text( "ENEMY", ( x + e ) / 8 + d + 4, y / 8 + 6 );
	engine_font_manager_draw_text( "SUZ", ( x + e ) / 8 + d + 5, y / 8 + 7 );

	// CHEAT!
	engine_font_manager_draw_text( "CHEAT", SCREEN_TILE_LEFT + 2, BOTT_TEXT_Y );

	//engine_font_manager_draw_text( "NEW GAME", SCREEN_TILE_LEFT + t, TEXT4_Y + 0 );
	//engine_font_manager_draw_text( "CONTINUE", SCREEN_TILE_LEFT + t, TEXT4_Y + 0 );
	//engine_font_manager_draw_text( "OPTIONS ", SCREEN_TILE_LEFT + t, TEXT4_Y + 1 );
	//engine_font_manager_draw_text( LOCALE_SELECT_ARROWS, SCREEN_TILE_LEFT + t - 3, TEXT4_Y + 1 );


	engine_font_manager_draw_text( "AVOID", x / 8 + d + 5, y / 8 + 3 );
	//engine_font_manager_draw_text( "DEATH", x / 8 + d + 3, y / 8 + 3 );
	engine_font_manager_draw_text( "TREES", x / 8 + d + 5, y / 8 + 4 );
	//engine_font_manager_draw_text( LOCALE_SELECT_ARROWS, x / 8 + d + 2, y / 8 + 4 );


	engine_font_manager_draw_text( "EX", x / 8 + d + 0, y / 8 + 6 );
	engine_font_manager_draw_text( "IT", x / 8 + d + 0, y / 8 + 7 );

	engine_font_manager_draw_text( "EXITS", x / 8 + d + 5, y / 8 + 6 );
	engine_font_manager_draw_text( " OPEN", x / 8 + d + 5, y / 8 + 7 );
	//engine_font_manager_draw_text( " SHUT", x / 8 + d + 3, y / 8 + 7 );
	//engine_font_manager_draw_text( LOCALE_SELECT_ARROWS, x / 8 + d + 2, y / 8 + 7 );

	engine_font_manager_draw_text( "WORLD 01", x / 8 + d + 2, y / 8 + 10 );
	engine_font_manager_draw_text( "ROUND 05", x / 8 + d + 2, y / 8 + 11 );
	engine_font_manager_draw_text( LOCALE_SELECT_ARROWS, SCREEN_TILE_LEFT + 4, TEXT4_Y + 1 );

	engine_font_manager_draw_text( "DIFFICULTY", x / 8 + d + 13, y / 8 + 10 );
	//engine_font_manager_draw_text( "CHALLENGE", x / 8 + d + 14, y / 8 + 10 );
	engine_font_manager_draw_text( ">> EASY", x / 8 + d + 15, y / 8 + 11 );
}