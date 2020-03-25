#include "title_screen.h"
#include "..\engine\audio_manager.h"
#include "..\engine\board_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\global_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\locale_manager.h"
#include "..\engine\state_manager.h"
#include "..\engine\tile_manager.h"
#include "..\engine\timer_manager.h"
#include "..\engine\sprite_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\object\locale_object.h"

#define TITLE_FLASH_DELAY	50
#define LOCAL_CHEAT_TOTAL	5
#define COIN_TEXT_X			6

static unsigned char flash_count;
static unsigned char cheat_count;
static unsigned char distance;

void screen_title_screen_load()
{
	struct_state_object *st = &global_state_object;
	distance = menu_type_double;

	engine_locale_manager_draw_text( 1, SCREEN_TILE_LEFT + COIN_TEXT_X + 2, TEXT4_Y );
	engine_font_manager_draw_text( locale_object_blank18, SCREEN_TILE_LEFT + COIN_TEXT_X, TEXT4_Y + 1 );
	engine_font_manager_draw_text( locale_object_blank18, SCREEN_TILE_LEFT + 2, BOTT_TEXT_Y );

	st->state_object_localcheat = 0;
	if( st->state_object_invincibie )
	{
		engine_locale_manager_draw_text( 2, SCREEN_TILE_LEFT + 2, BOTT_TEXT_Y );
		st->state_object_localcheat = 1;
	}

	engine_delay_manager_load( TITLE_FLASH_DELAY );
	flash_count = 0;
	cheat_count = 0;

	// TODO delete
	engine_font_manager_draw_text( "TS", SCREEN_TILE_LEFT, 6 );
}

void screen_title_screen_update( unsigned char *screen_type )
{
	struct_state_object *st = &global_state_object;
	unsigned char input;
	unsigned char delay;


	//// NEW
	//unsigned char x = 48;
	//unsigned char y = 64;
	//unsigned char e = 112;
	//engine_sprite_manager_draw_entity( x, y + 0, 352 );

	//engine_sprite_manager_draw_entity( x + e - 16, y + 0, 304 );
	//engine_sprite_manager_draw_entity( x + e - 16, y + 24, 318 );
	//engine_sprite_manager_draw_entity( x + e - 16, y + 48, 332 );
	//// NEW


	delay = engine_delay_manager_update();
	if( delay )
	{
		if( !st->state_object_delay_test )
		{
			flash_count = 1 - flash_count;
		}

		if( flash_count )
		{
			engine_font_manager_draw_text( locale_object_blank18, SCREEN_TILE_LEFT + COIN_TEXT_X, TEXT4_Y );
		}
		else
		{
			engine_locale_manager_draw_text( 1, SCREEN_TILE_LEFT + COIN_TEXT_X + 2, TEXT4_Y );
		}
	}

	input = engine_input_manager_hold( input_type_fire1 );
	if( input )
	{
		//engine_audio_manager_sfx_play( sfx_type_accept );
		*screen_type = screen_type_init;
		//*screen_type = screen_type_intro;
		return;
	}

	if( !st->state_object_invincibie )
	{
		input = engine_input_manager_hold( input_type_fire2 );
		if( input )
		{
			cheat_count++;
			if( cheat_count >= LOCAL_CHEAT_TOTAL )
			{
				engine_audio_manager_sfx_play( sfx_type_power );
				engine_locale_manager_draw_text( 2, SCREEN_TILE_LEFT + 2, BOTT_TEXT_Y );
				st->state_object_localcheat = 1;
			}
		}
	}

	//*screen_type = screen_type_init;
	*screen_type = screen_type_title;
}