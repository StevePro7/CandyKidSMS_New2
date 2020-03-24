#include "option_manager.h"
#include "enemy_manager.h"
#include "enum_manager.h"
#include "gamer_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "..\object\locale_object.h"

#define OPTION_X	SCREEN_TILE_LEFT + 4
#define OPTION_Y	TEXT1_Y + TEXT1_Y

static unsigned char value_x[] = { OPTION_X + 0, OPTION_X + 5, OPTION_X + 12, OPTION_X + 17 };
static unsigned char value_y[] = { OPTION_Y + 0, OPTION_Y + 3, OPTION_Y + 6,  OPTION_Y + 10 };

void engine_option_manager_init()
{
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
	engine_gamer_manager_draws( x, y );

	x = value_x[ 2 ] * 8 + ( index * 8 );
	for( enemy = 0; enemy < MAX_ENEMIES; enemy++ )
	{
		y = value_y[ enemy ] * 8;
		engine_enemy_manager_draws( enemy, x, y );
	}
}

void engine_option_manager_text_left( unsigned index )
{
	unsigned char loc = 29;
	unsigned char x = value_x[ 1 ] - index;
	engine_locale_manager_draw_text( loc + 0, x + 0, value_y[ 0 ] + 0 );
	engine_locale_manager_draw_text( loc + 1, x + 1, value_y[ 0 ] + 1 );
}


void engine_option_manager_text_right()
{
	unsigned char idx;
	unsigned char loc = 25;
	for( idx = 0; idx < 3; idx++ )
	{
		engine_locale_manager_draw_text( loc, value_x[ 3 ] + 0, value_y[ idx ] + 0 );
		engine_locale_manager_draw_text( loc + idx + 1, value_x[ 3 ] + 1, value_y[ idx ] + 1 );
	}
}