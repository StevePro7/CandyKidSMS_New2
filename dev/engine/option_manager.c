#include "option_manager.h"
#include "enemy_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "gamer_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "score_manager.h"
#include "tile_manager.h"
#include "..\object\locale_object.h"

#define OPTION_X	SCREEN_TILE_LEFT + 4
#define OPTION_Y	TEXT1_Y + TEXT1_Y

static unsigned char value_x[] = { OPTION_X + 0, OPTION_X + 5, OPTION_X + 12, OPTION_X + 17 };
static unsigned char value_y[] = { OPTION_Y + 0, OPTION_Y + 3, OPTION_Y + 6,  OPTION_Y + 10 };

static unsigned char bonus_tile;
static unsigned char location;
static unsigned char leftside;

void engine_option_manager_init()
{
	bonus_tile = tile_type_bonusA;
	location = 29;
	leftside = value_x[ 1 ];
}

//void engine_option_manager_load( unsigned char type )
//{
//}

void engine_option_manager_update()
{
}

void engine_option_manager_draw_actor( unsigned index )
{
	unsigned x, y;
	unsigned enemy;

	x = value_x[ 0 ] * 8;
	y = value_y[ 0 ] * 8;

	// Render all sprites.
	engine_gamer_manager_draws( x, y );

	x = value_x[ 2 ] * 8 + ( index * 8 );
	for( enemy = 0; enemy < MAX_ENEMIES; enemy++ )
	{
		y = value_y[ enemy ] * 8;
		engine_enemy_manager_draws( enemy, x, y );
	}
}

void engine_option_manager_text_kid( unsigned index )
{
	unsigned char x =leftside - index;

	// Candy Kid.
	engine_locale_manager_draw_text( location + 0, x + 0, value_y[ 0 ] + 0 );
	engine_locale_manager_draw_text( location + 1, x + 1, value_y[ 0 ] + 1 );
}

////void engine_option_manager_text_left( unsigned index )
////{
////	//unsigned char x = leftside - index;
////
////	//// Candy Kid.
////	//engine_locale_manager_draw_text( location + 0, x + 0, value_y[ 0 ] + 0 );
////	//engine_locale_manager_draw_text( location + 1, x + 1, value_y[ 0 ] + 1 );
////
////	//// PTS.
////	//engine_font_manager_draw_char( '0', x + 3, value_y[ 1 ] + 0 );
////	//engine_locale_manager_draw_text( location + 2, x + 1, value_y[ 1 ] + 1 );
////
////	
////}

void engine_option_manager_text_enemy()
{
	unsigned char idx;
	unsigned char loc = 25;

	// Enemy: Pro / Adi / Suz.
	for( idx = 0; idx < MAX_ENEMIES; idx++ )
	{
		engine_locale_manager_draw_text( loc, value_x[ 3 ] + 0, value_y[ idx ] + 0 );
		engine_locale_manager_draw_text( loc + idx + 1, value_x[ 3 ] + 1, value_y[ idx ] + 1 );
	}

	// Build version is on each "intro" screen so draw it here!
	engine_locale_manager_draw_text( 0, SCREEN_TILE_LEFT + 24, BOTT_TEXT_Y );
}

void engine_option_manager_draw_bonus( unsigned index )
{
	unsigned char value_data = engine_score_manager_get_bonus( bonus_tile );
	unsigned char x = leftside - index;

	engine_tile_manager_draw_bonus( bonus_tile, value_x[ 0 ] + 0, value_y[ 1 ] + 0, 1 );
	engine_font_manager_draw_data( value_data, value_x[ 1 ] + 1, value_y[ 1 ] + 0 );

	// PTS.
	engine_font_manager_draw_char( '0', x + 3, value_y[ 1 ] + 0 );
	engine_locale_manager_draw_text( location + 2, x + 1, value_y[ 1 ] + 1 );
}

void engine_option_manager_draw_candy( unsigned index )
{
	unsigned char x = leftside - index;
	engine_tile_manager_main_candy( value_x[ 0 ] + 0, value_y[ 2 ] + 0 );

	// PTS.
	engine_font_manager_draw_data( 10, x + 2, value_y[ 2 ] + 0 );
	engine_locale_manager_draw_text( location + 2, x + 1, value_y[ 2 ] + 1 );
}

void engine_option_manager_option_exit()
{
	engine_font_manager_draw_text( "EX", value_x[ 0 ], value_y[ 2 ] + 0 );
	engine_font_manager_draw_text( "IT", value_x[ 0 ], value_y[ 2 ] + 1 );
}

void engine_option_manager_option_tree( unsigned char type )
{
	engine_tile_manager_draw_trees( type, value_x[ 0 ], value_y[ 1 ] );
}