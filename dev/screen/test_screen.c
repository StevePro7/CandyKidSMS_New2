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

void screen_test_screen_load()
{
	engine_asm_manager_clear_VRAM();
	engine_content_manager_load_tiles_font();
	engine_content_manager_load_tiles_main();
	engine_content_manager_load_sprites_game();

	engine_board_manager_border( border_type_main );
	engine_tile_manager_main_title( 2, 2 );


	engine_option_manager_text_right();


	// TODO delete
	engine_font_manager_draw_text( "TEST SCREEN!!", 2, 6 );
}

void screen_test_screen_update( unsigned char *screen_type )
{
	//engine_option_manager_draw_actor( menu_type_single );
	engine_option_manager_draw_actor( menu_type_double );

	/*unsigned char input = engine_input_manager_hold( input_type_fire1 );
	if( input )
	{
	}*/

	*screen_type = screen_type_test;
}