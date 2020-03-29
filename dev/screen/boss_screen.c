#include "boss_screen.h"
#include "..\engine\audio_manager.h"
#include "..\engine\board_manager.h"
#include "..\engine\boss_manager.h"
#include "..\engine\collision_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
//#include "..\engine\global_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\memo_manager.h"
#include "..\engine\score_manager.h"
#include "..\engine\state_manager.h"
#include "..\engine\timer_manager.h"
#include "..\devkit\_sms_manager.h"

// IMPORTANT disable compiler warning 110
//#ifdef _CONSOLE
//#else
//#pragma disable_warning 110
//#endif

static unsigned char first_time;
//static unsigned char frame_spot;
static unsigned char nextr_direction;

void screen_boss_screen_load()
{
	//struct_hack_object *ho = &global_hack_object;
	struct_state_object *st = &global_state_object;

	//struct_boss_object *bo;
	engine_delay_manager_load( 0 );

	//	engine_command_manager_load();
	engine_frame_manager_load();

	engine_frame_manager_draw();
	engine_delay_manager_draw();


	first_time = 1;
	nextr_direction = direction_type_none;

	engine_reset_manager_load( QUIT_SCREEN_DELAY );

	st->state_object_curr_screen = screen_type_boss;

	engine_font_manager_draw_text( "BOSS SCREEN!!", 4, 12 );
}

void screen_boss_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	struct_gamer_object *go = &global_gamer_object;
	struct_state_object *st = &global_state_object;
	struct_level_object *lo = &global_level_object;
	//struct_boss_object *bo;

	unsigned char gamer_boost = 0;
	unsigned char enemy_boost = 0;
	unsigned char gamer_direction = direction_type_none;
	unsigned char bossX_direction = direction_type_none;
	unsigned char input_direction = direction_type_none;
	unsigned char gamer_collision = coll_type_empty;
	unsigned char gamer_tile_type = tile_type_blank;
	unsigned char oneup_count = 0;

	unsigned char proceed;
	//unsigned char input;
	//unsigned char bossX;
	//unsigned char check;
	unsigned int frame = fo->frame_count;
	st->state_object_actor_kill = actor_type_kid;

	// Draw sprites first.
	engine_boss_manager_draw();
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


	// Execute all commands for this frame.
	//engine_command_manager_execute( frame );
	first_time = 0;

}
