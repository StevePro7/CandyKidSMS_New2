#include "init_screen.h"
#include "..\engine\asm_manager.h"
#include "..\engine\board_manager.h"
#include "..\engine\content_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\memo_manager.h"
#include "..\engine\score_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\banks\databank.h"

#include "..\engine\level_manager.h"

void screen_init_screen_load()
{
	devkit_SMS_displayOff();

	//if( state_object_mydebugger )
	//{
	//	engine_asm_manager_clear_VRAM();
	//	engine_content_manager_load_tiles_font();
	//	engine_content_manager_load_tiles_game();
	//	engine_content_manager_load_sprites_game();
	//}

	// Manually clear any text artifacts.
	//engine_memo_manager_clear();

	// Draw tree border with exits.
	//engine_board_manager_debugger();
	engine_board_manager_draw_full();
	engine_board_manager_draw_exit();
	engine_board_manager_side_tile();

	// Reset all score data.
	engine_score_manager_text();
	engine_score_manager_init();
	engine_memo_manager_option();

	devkit_SMS_displayOn();
}

void screen_init_screen_update( unsigned char *screen_type )
{
	//*screen_type = screen_type_init;
	*screen_type = screen_type_load;
}
