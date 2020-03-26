#include "start_screen.h"
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
#include "..\devkit\_sms_manager.h"
#include <stdlib.h>

static void display_cursor();
static unsigned char distance;
static unsigned char cursorY[ 2 ] = { TEXT4_Y + 0, TEXT4_Y + 1 };
static unsigned char cursor;

void screen_start_screen_init()
{
	cursor = 0;

	// TODO delete!!
	cursor = 1;
}

void screen_start_screen_load()
{
	struct_state_object *st = &global_state_object;

	// Clear menu area first.
	engine_option_manager_clear();
	distance = menu_type_double;
	engine_option_manager_draw_bonus( distance );
	engine_option_manager_draw_candy( distance );

	// Draw all generic actor text.
	engine_option_manager_text_kid( distance );
	engine_option_manager_text_enemy();

	// Draw NEW GAME or CONTINUE...
	engine_option_manager_text_start( st->state_object_availables );

	display_cursor();


	st->state_object_curr_screen = screen_type_option;
	st->state_object_curr_screen = screen_type_start;
}

void screen_start_screen_update( unsigned char *screen_type )
{
	struct_state_object *st = &global_state_object;
	unsigned char input[ 2 ] = { 0, 0 };

	engine_option_manager_draw_actor( distance );
	if( !st->state_object_delay_test )
	{
		engine_option_manager_update( st->state_object_curr_screen );
	}

	input[ 0 ] = engine_input_manager_hold( input_type_up );
	input[ 1 ] = engine_input_manager_hold( input_type_down );
	if( input[ 0 ] || input[ 1 ] )
	{
		cursor = 1 - cursor;
		display_cursor();
	}

	// TODO go forward and go back.
	input[ 0 ] = engine_input_manager_hold( input_type_fire1 );
	if( input[ 0 ] )
	{
		if( 0 == cursor )
		{
			*screen_type = screen_type_init;
		}
		else if( 1 == cursor )
		{
			*screen_type = screen_type_option;
		}

		// TODO sound FX
		//engine_audio_manager_sfx_play( sfx_type_accept );
		//*screen_type = screen_type_init;
		//*screen_type = screen_type_intro;
		return;
	}

	input[ 1 ] = engine_input_manager_hold( input_type_fire2 );
	if( input[ 1 ] )
	{
		// TODO sound FX
		//engine_audio_manager_sfx_play( sfx_type_reset );
		*screen_type = screen_type_title;
		return;
	}

	// TODO implement:
	//rand();
	*screen_type = st->state_object_curr_screen;
}

static void display_cursor()
{
	engine_font_manager_draw_text( LOCALE_SELECT_SPACES, SCREEN_TILE_LEFT + 8, cursorY[ 0 ] );
	engine_font_manager_draw_text( LOCALE_SELECT_SPACES, SCREEN_TILE_LEFT + 8, cursorY[ 1 ] );
	engine_font_manager_draw_text( LOCALE_SELECT_ARROWS, SCREEN_TILE_LEFT + 8, cursorY[ cursor ] );
}