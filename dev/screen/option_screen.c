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

static void toggle_kid();
static void toggle_enemy( unsigned char enemy );
static void toggle_trees();
static void toggle_exits();
static void toggle_world();
static void toggle_round();
static void toggle_diff();

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

	// Draw level + difficulty text.
	engine_option_manager_text_other();

	// Draw world + round data.
	engine_option_manager_option_world( st->state_object_world_data );
	engine_option_manager_option_round( st->state_object_round_data );

	// Draw difficulty.
	engine_option_manager_option_diff( st->state_object_difficulty );


	st->state_object_curr_screen = screen_type_option;
	st->state_object_next_screen = screen_type_start;
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


	input[ 0 ] = engine_input_manager_hold( input_type_fire1 );
	if( input[ 0 ] )
	{
		//toggle_world();
		//toggle_round();
		//toggle_diff();

		//toggle_kid();
		//toggle_enemy( 0 );
		toggle_trees();
		//toggle_exits();
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

static void toggle_kid()
{
	struct_gamer_object *go = &global_gamer_object;
	engine_gamer_manager_swap();
	engine_option_manager_text_kid_no( distance, go->image );
}
static void toggle_enemy( unsigned char enemy )
{
	struct_enemy_object *eo = &global_enemy_objects[ enemy ];
	engine_enemy_manager_swap( enemy );
	engine_option_manager_text_enemy_no( enemy, eo->image );
}
static void toggle_trees()
{
	struct_state_object *st = &global_state_object;
	st->state_object_trees_type = 1 - st->state_object_trees_type;
	engine_board_manager_border( border_type_main );
	engine_option_manager_text_tree( distance, st->state_object_trees_type );
	engine_option_manager_option_tree( st->state_object_trees_type );
}
static void toggle_exits()
{
	struct_state_object *st = &global_state_object;
	st->state_object_exits_type = 1 - st->state_object_exits_type;
	engine_option_manager_text_exit( distance, st->state_object_exits_type );
	engine_board_manager_toggle();
}
static void toggle_world()
{
	struct_state_object *st = &global_state_object;
	st->state_object_world_data++;
	if (st->state_object_world_data >= MAX_WORLDS )
	{
		st->state_object_world_data = 0;
	}

	engine_option_manager_option_world( st->state_object_world_data );
}
static void toggle_round()
{
	struct_state_object *st = &global_state_object;
	st->state_object_round_data++;
	if( st->state_object_round_data >= MAX_ROUNDS )
	{
		st->state_object_round_data = 0;
	}

	engine_option_manager_option_round( st->state_object_round_data );
}
static void toggle_diff()
{
	struct_state_object *st = &global_state_object;
	st->state_object_difficulty = 1 - st->state_object_difficulty;
	engine_option_manager_option_diff( st->state_object_difficulty );
}