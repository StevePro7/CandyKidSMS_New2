#include "cont_screen.h"
#include "..\engine\audio_manager.h"
#include "..\engine\collision_manager.h"
#include "..\engine\enemy_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\locale_manager.h"
#include "..\engine\memo_manager.h"
#include "..\engine\score_manager.h"
#include "..\engine\state_manager.h"
#include "..\engine\tile_manager.h"
#include "..\engine\timer_manager.h"

//#define CONT_SCREEN_DELAY	10		// org.
#define CONT_SCREEN_DELAY	100
#define CONT_X				10
#define TEXT_Y				11
#define OPT1_X				CONT_X + 0
#define OPT2_X				CONT_X + 5

static unsigned char event_stage;

static void display_cursor();
static unsigned char cursorX[ 2 ] = { OPT1_X, OPT2_X };
static unsigned char cursor;

void screen_cont_screen_load()
{
	engine_audio_manager_music_stop();
	engine_delay_manager_load( CONT_SCREEN_DELAY );
	engine_memo_manager_draw( 17, 18 );
	cursor = 0;

	display_cursor();
	event_stage = event_stage_start;

	engine_audio_manager_music_play_norepeat( mus_type_cont );
}

void screen_cont_screen_update( unsigned char *screen_type )
{
	struct_state_object *st = &global_state_object;
	unsigned char input[ 3 ] = { 0, 0, 0 };
	unsigned char delay;

	if( event_stage_pause == event_stage )
	{
		// Draw sprites first.
		engine_enemy_manager_hide();
		engine_gamer_manager_hide_death();

		delay = engine_delay_manager_update();
		if( delay )
		{
			if( 0 == cursor )
			{
				
				engine_collision_manager_reset_death();

				// Reset enemy that killed Kid to scatter mode only.
				// Nasty bug : do NOT set when death tree kills Kid!
				if( actor_type_pro == st->state_object_actor_kill || actor_type_adi == st->state_object_actor_kill || actor_type_suz == st->state_object_actor_kill )
				{
					engine_enemy_manager_reset_mode( st->state_object_actor_kill, enemymove_type_tour );
				}

				engine_score_manager_reset_boost();
				engine_score_manager_reset_lives();
				engine_level_manager_draw_middle();
				*screen_type = screen_type_ready;
				return;
			}
			else
			{
				*screen_type = screen_type_over;
				return;
			}
		}
		else
		{
			*screen_type = screen_type_cont;
			return;
		}
	}

	// Draw sprites last.
	engine_enemy_manager_hide();
	engine_gamer_manager_hide_death();

	input[ 0 ] = engine_input_manager_hold( input_type_left );
	input[ 1 ] = engine_input_manager_hold( input_type_right );
	if( input[ 0 ] || input[ 1 ] )
	{
		cursor = 1 - cursor;
		display_cursor();
	}

	input[ 2 ] = engine_input_manager_hold( input_type_fire1 );
	if( input[ 2 ] )
	{
		// TODO play sound FX
		//engine_audio_manager_sound_accept();		// adriana
		engine_audio_manager_music_stop();
		engine_delay_manager_load( CONT_SCREEN_DELAY );
		event_stage = event_stage_pause;
		return;
	}

	*screen_type = screen_type_cont;
}

static void display_cursor()
{
	engine_font_manager_draw_text( LOCALE_SELECT_SPACE, OPT1_X, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_SELECT_SPACE, OPT2_X, TEXT_Y + 1 );
	engine_font_manager_draw_text( LOCALE_SELECT_ARROW, cursorX[ cursor ], TEXT_Y + 1 );
}