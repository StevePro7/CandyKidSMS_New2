#include "boss_screen.h"
//#include "..\engine\asm_manager.h"
//#include "..\engine\audio_manager.h"
//#include "..\engine\board_manager.h"
#include "..\engine\boss_manager.h"
//#include "..\engine\content_manager.h"
//#include "..\engine\collision_manager.h"
#include "..\engine\enum_manager.h"
//#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
//#include "..\engine\global_manager.h"
//#include "..\engine\input_manager.h"
//#include "..\engine\level_manager.h"
//#include "..\engine\locale_manager.h"
//#include "..\engine\main_manager.h"
//#include "..\engine\memo_manager.h"
//#include "..\engine\option_manager.h"
//#include "..\engine\score_manager.h"
////#include "..\engine\sprite_manager.h"
#include "..\engine\state_manager.h"
//#include "..\engine\tile_manager.h"
#include "..\engine\timer_manager.h"
//#include "..\devkit\_sms_manager.h"
//#include "..\object\level_object.h"

void screen_boss_screen_load()
{
	//struct_hack_object *ho = &global_hack_object;
	struct_state_object *st = &global_state_object;

	//struct_boss_object *bo;
	engine_delay_manager_load( 0 );

	//	engine_command_manager_load();
	engine_frame_manager_load();

	//engine_frame_manager_draw();
	//engine_delay_manager_draw();

	//engine_font_manager_draw_text( "BOSS SCREEN!!", 4, 12 );
}

void screen_boss_screen_update( unsigned char *screen_type )
{
	// Draw sprites first.
	engine_boss_manager_draw();
	engine_gamer_manager_draw();


	*screen_type = screen_type_boss;
}
