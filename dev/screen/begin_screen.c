#include "begin_screen.h"
#include "..\engine\asm_manager.h"
#include "..\engine\board_manager.h"
#include "..\engine\content_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\locale_manager.h"
#include "..\engine\main_manager.h"
#include "..\engine\option_manager.h"
#include "..\engine\tile_manager.h"
#include "..\devkit\_sms_manager.h"

static unsigned char distance;

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


	//engine_locale_manager_draw_text( 0, SCREEN_TILE_LEFT + 24, BOTT_TEXT_Y );
	devkit_SMS_displayOn();
}

void screen_begin_screen_update( unsigned char *screen_type )
{
    *screen_type = screen_type_begin;
	//*screen_type = screen_type_title;
}