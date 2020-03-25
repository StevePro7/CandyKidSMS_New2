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

static void display_cursor();
static unsigned char distance;
static unsigned char cursorY[ 2 ] = { TEXT4_Y + 0, TEXT4_Y + 1 };
static unsigned char cursor;

void screen_start_screen_init()
{
	cursor = 0;
}

void screen_start_screen_load()
{
	struct_state_object *st = &global_state_object;
	engine_option_manager_clear();

	distance = menu_type_double;

	engine_option_manager_text_start( st->state_object_availables );

	engine_font_manager_draw_text( "AA", SCREEN_TILE_LEFT, 6 );
}

void screen_start_screen_update( unsigned char *screen_type )
{
	struct_state_object *st = &global_state_object;

	engine_option_manager_draw_actor( distance );
	if( !st->state_object_delay_test )
	{
		engine_option_manager_update( st->state_object_curr_screen );
	}

	*screen_type = screen_type_start;
}