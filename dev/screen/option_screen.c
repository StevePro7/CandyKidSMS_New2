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
#include "..\engine\option_manager.h"
#include "..\engine\state_manager.h"
#include "..\engine\tile_manager.h"
#include "..\devkit\_sms_manager.h"

static void display_cursor();

// TODO - correct cursor locations
static unsigned char distance;
static unsigned char cursorX[ 2 ] = { 7, 8 };
static unsigned char cursorY[ 5 ] = { 1, 2,3, 4, 5 };
static unsigned char cursor;

void screen_option_screen_init()
{
	cursor = 0;
}

void screen_option_screen_load()
{
	struct_state_object *st = &global_state_object;
	struct_gamer_object *go = &global_gamer_object;
	struct_enemy_object *eo;
	unsigned char enemy;

	// Clear menu area first.
	engine_option_manager_clear();
	distance = menu_type_double;


	engine_option_manager_option_tree( st->state_object_trees_type );
	engine_option_manager_option_exit();

	// Draw Kid#, Pro#, Adi#, Suz#
	engine_option_manager_text_kid_no( distance, go->image );
	for( enemy = 0; enemy < MAX_ENEMIES; enemy++ )
	{
		eo = &global_enemy_objects[ enemy ];
		engine_option_manager_text_enemy_no( enemy, eo->image );
	}

	// Draw tree options.
	engine_option_manager_text_tree( distance, st->state_object_trees_type );

	// Draw exit options.
	engine_option_manager_text_exit( distance, st->state_object_exits_type );

	// Draw level text + difficulty.
	engine_option_manager_text_other();

	st->state_object_curr_screen = screen_type_option;
	st->state_object_next_screen = screen_type_start;

	// TODO delete
	engine_font_manager_draw_text( "OS", SCREEN_TILE_LEFT, 6 );
}

void screen_option_screen_update( unsigned char *screen_type )
{
	struct_state_object *st = &global_state_object;
	unsigned char input[ 2 ] = { 0, 0 };

	engine_option_manager_draw_actor( distance );
	if( !st->state_object_delay_test )
	{
		// TODO do I want to update actors on options screen - could be annoying!!
		//engine_option_manager_update( st->state_object_curr_screen );
	}

	input[ 1 ] = engine_input_manager_hold( input_type_fire2 );
	if( input[ 1 ] )
	{
		// TODO sound FX
		//engine_audio_manager_sfx_play( sfx_type_reset );
		*screen_type = screen_type_start;
		return;
	}

	*screen_type = st->state_object_curr_screen;
}