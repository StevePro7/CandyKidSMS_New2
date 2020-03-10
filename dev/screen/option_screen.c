#include "option_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\sprite_manager.h"
#include "..\devkit\_sms_manager.h"

#define SPRITE_TILES_ENEMY	256 + 48
#define SPRITE_TILES_GAMER	256 + 96

static void draw_enemy( unsigned char x, unsigned char y, unsigned int t );
static void draw_gamer( unsigned char x, unsigned char y, unsigned int t );
static void draw_bossB( unsigned char x, unsigned char y );

void screen_option_screen_load()
{
//	engine_font_manager_draw_text( "OPTION SCREEN...!!", 2, 10 );
}

void screen_option_screen_update( unsigned char *screen_type )
{
	draw_gamer( 1, 1, 0 );
	draw_gamer( 3, 1, 2 );
	draw_gamer( 5, 1, 4 );
	draw_gamer( 7, 1, 12 );
	draw_gamer( 9, 2, 14 );
	draw_gamer( 11, 2, 16 );

	draw_enemy( 1, 3, 0 );
	draw_enemy( 3, 3, 2 );
	draw_enemy( 5, 3, 4 );
	draw_enemy( 7, 3, 12 );

	draw_enemy( 1, 5, 14 );
	draw_enemy( 3, 5, 16 );
	draw_enemy( 5, 5, 24 );
	draw_enemy( 7, 5, 26 );

	draw_enemy( 1, 7, 28 );
	draw_enemy( 3, 7, 36 );
	draw_enemy( 5, 7, 38 );
	draw_enemy( 7, 7, 40 );

	//draw_bossB( 128, 64 );
	*screen_type = screen_type_option;
}

static void draw_gamer( unsigned char x, unsigned char y, unsigned int t )
{
	unsigned int calcd = SPRITE_TILES_GAMER + t;
	engine_sprite_manager_draw_entity( x * 16, y * 16, calcd );
}
static void draw_enemy( unsigned char x, unsigned char y, unsigned int t )
{
	unsigned int calcd = SPRITE_TILES_ENEMY + t;
	engine_sprite_manager_draw_entity( x * 16, y * 16, calcd );
}

static void draw_bossB( unsigned char x, unsigned char y )
{
	unsigned int tile;
	unsigned char r, c;
	for( r = 0; r < 8; r++ )
	{
		for( c = 0; c < 6; c++ )
		{
			tile = 256 + r * 6 + c;
			devkit_SMS_addSprite( x + c * 8, y + r * 8, tile );
		}
	}
	
}