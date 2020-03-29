#include "credit_screen.h"
#include "..\engine\asm_manager.h"
#include "..\engine\board_manager.h"
#include "..\engine\boss_manager.h"
#include "..\engine\content_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\global_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\locale_manager.h"
#include "..\engine\main_manager.h"
#include "..\engine\option_manager.h"
#include "..\engine\sprite_manager.h"
#include "..\engine\state_manager.h"
#include "..\engine\tile_manager.h"
#include "..\engine\timer_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\object\level_object.h"

static unsigned char first_time;
static unsigned char nextr_direction;

void screen_credit_screen_load()
{
	engine_asm_manager_clear_VRAM();
	engine_content_manager_load_tiles_font();
	engine_content_manager_load_tiles_game();

	engine_boss_manager_content( 3 );
	engine_board_manager_border( border_type_game );

	engine_level_manager_clear();
	engine_level_manager_load_oneup( 5 );

	engine_level_manager_draw_level();
	engine_level_manager_draw_middle();

	engine_gamer_manager_load();
	engine_gamer_manager_reset();

	nextr_direction = direction_type_none;
	engine_reset_manager_load( QUIT_SCREEN_DELAY );


	engine_font_manager_draw_text( "CREDIT SCREEN...!!", 4, 10 );
}

void screen_credit_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	struct_gamer_object *go = &global_gamer_object;
	struct_state_object *st = &global_state_object;
	struct_level_object *lo = &global_level_object;
	//struct_boss_object *bo;

	//unsigned char proceed;
	//unsigned char input;
	//unsigned char boss;

	engine_gamer_manager_draw();
	*screen_type = screen_type_credit;
}
