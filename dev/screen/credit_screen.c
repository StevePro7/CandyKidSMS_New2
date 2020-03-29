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
	struct_state_object *st = &global_state_object;

	engine_asm_manager_clear_VRAM();
	engine_content_manager_load_tiles_font();
	engine_content_manager_load_tiles_game();

	engine_boss_manager_content( 3 );
	engine_board_manager_border( border_type_game );

	engine_level_manager_clear();
	engine_level_manager_load_oneup( 5 );

	engine_level_manager_draw_level();
	engine_level_manager_draw_middle();

	// load screen
	engine_gamer_manager_load();
	engine_boss_manager_load();

	// ready screen
	//engine_boss_manager_reset_home()
	engine_gamer_manager_reset();
	

	engine_delay_manager_load( 0 );

	//	engine_command_manager_load();
	engine_frame_manager_load();

	engine_frame_manager_draw();
	engine_delay_manager_draw();


	nextr_direction = direction_type_none;
	engine_reset_manager_load( QUIT_SCREEN_DELAY );


	//st->state_object_next_screen = screen_type_init;
	st->state_object_curr_screen = screen_type_credit;


	engine_font_manager_draw_text( "CREDIT SCREEN...!!", 4, 10 );
}

void screen_credit_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	struct_gamer_object *go = &global_gamer_object;
	struct_state_object *st = &global_state_object;
	struct_level_object *lo = &global_level_object;
	//struct_boss_object *bo;

	unsigned char proceed;
	unsigned char input;
	//unsigned char boss;
	unsigned char check;
	unsigned int frame = fo->frame_count;
	st->state_object_actor_kill = actor_type_kid;

	// Draw sprites first.
	//engine_boss_manager_draw();
	engine_gamer_manager_draw();

	// Set the current screen first.
	*screen_type = st->state_object_curr_screen;


	engine_frame_manager_draw();
	engine_delay_manager_draw();
	if( !first_time )
	{
		proceed = engine_delay_manager_update();
		if( !proceed )
		{
			return;
		}

		engine_frame_manager_update();
		first_time = 1;
	}

	// Continue...
	frame = fo->frame_count;


	// Does player want to quit out?
	input = engine_input_manager_move( input_type_fire2 );
	if( input )
	{
		engine_font_manager_draw_text( "CREDIT SCREEN...!!", 4, 14 );
		check = engine_reset_manager_update();
		if( check )
		{
			engine_board_manager_midd_text();
			*screen_type = screen_type_over;
			return;
		}
	}
	else
	{
		engine_reset_manager_reset();
	}


	// Execute all commands for this frame.
	//engine_command_manager_execute( frame );
	first_time = 0;
}
