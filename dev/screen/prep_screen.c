#include "prep_screen.h"
#include "..\engine\asm_manager.h"
#include "..\engine\audio_manager.h"
#include "..\engine\board_manager.h"
#include "..\engine\boss_manager.h"
#include "..\engine\content_manager.h"
//#include "..\engine\collision_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"
#include "..\engine\global_manager.h"
#include "..\engine\hack_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\level_manager.h"
#include "..\engine\locale_manager.h"
//#include "..\engine\main_manager.h"
#include "..\engine\memo_manager.h"
//#include "..\engine\option_manager.h"
#include "..\engine\score_manager.h"
//#include "..\engine\sprite_manager.h"
#include "..\engine\state_manager.h"
//#include "..\engine\tile_manager.h"
#include "..\engine\timer_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\object\locale_object.h"
#include <stdlib.h>

#define PREP_SCREEN_DELAY	150
//#define PREP_SCREEN_DELAY	0

static void print_level();

void screen_prep_screen_load()
{
	struct_state_object *st = &global_state_object;
	struct_level_object *lo = &global_level_object;
	struct_hack_object *ho = &global_hack_object;

	// TODO calc how many oneup
	unsigned char oneup_count = 2;


	st->state_object_curr_screen = screen_type_prep;
	st->state_object_next_screen = screen_type_prep;
	//st->state_object_next_screen = screen_type_fight;

	engine_delay_manager_load( PREP_SCREEN_DELAY );


	// TODO calculate which content to load depending on boos1 or boss2
	// If boss2 then also calculate what index of 4 to render per boss.
	engine_boss_manager_content( 3 );


	// load screen
	// Reset all score data.
	engine_score_manager_load();

	// TODO
	//engine_boss_manager_reset_home()
	engine_gamer_manager_reset();

	// Force override enemy move!
	//engine_enemy_manager_debug();
	//engine_boss_manager_debug();

	engine_gamer_manager_load();
	engine_boss_manager_load( st->state_object_round_data );

	// load oneup
	engine_level_manager_clear();
	engine_level_manager_load_oneup( oneup_count );

	engine_level_manager_draw_level();
	//engine_level_manager_draw_middle();
	
	if( !ho->hack_object_delay_test )
	{
		print_level();
	}

	engine_font_manager_draw_text( "PREP", 4, 10 );
}

void screen_prep_screen_update( unsigned char *screen_type )
{
	struct_state_object *st = &global_state_object;
	unsigned char delay;
	unsigned char input;
	unsigned char index;

	// Draw sprites first.
	//engine_enemy_manager_draw();
	engine_boss_manager_draw();
	engine_gamer_manager_draw();

	delay = engine_delay_manager_update();
	input = devkit_SMS_getKeysStatus();
	if( delay || input )
	{
		index = rand() % MAX_MUSIC;
		engine_level_manager_draw_middle();
		//engine_audio_manager_music_play( index + 3 );
		*screen_type = st->state_object_next_screen;
		return;
	}

	*screen_type = st->state_object_curr_screen;
}



static void print_level()
{
	struct_state_object *st = &global_state_object;
	unsigned char index = 49 + st->state_object_fight_type;

	engine_board_manager_midd_text();
	engine_memo_manager_levels( 14, 11, 12 );

	engine_font_manager_draw_text( locale_object_texts[ 12 ], SCREEN_TILE_LEFT + 8, 11 );
	engine_font_manager_draw_text( locale_object_texts[ index ], SCREEN_TILE_LEFT + 8, 12 );
}