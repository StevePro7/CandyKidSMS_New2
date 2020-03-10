#include "font_manager.h"
#include "global_manager.h"
#include "..\banks\bank2.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"

#define TEXT_ROOT	32		// 32 is " " in ASCII.
#define DATA_ROOT	16		// 16 is "0" (48=16+32)
#define UNIT_ROOT	10		// 10 is decimal
#define DATA_LONG	5		// 4 placeholder

static void draw_data( unsigned int data, unsigned char x, unsigned char y, unsigned char len );

void engine_font_manager_draw_char( const unsigned char ch, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = font_tiles__tilemap__bin;
	unsigned char tile = ch - TEXT_ROOT;
	devkit_SMS_setNextTileatXY( x, y );
	devkit_SMS_setTile( *pnt + tile );
}

void engine_font_manager_draw_text( const unsigned char *text, unsigned char x, unsigned char y )
{
	const unsigned char *pnt = font_tiles__tilemap__bin;
	unsigned char idx = 0;

	while( '\0' != text[idx] )
	{
		signed char tile = text[idx] - TEXT_ROOT;
		devkit_SMS_setNextTileatXY( x++, y );
		devkit_SMS_setTile( *pnt + tile );
		idx++;
	}
}

//void engine_font_manager_draw_data( unsigned int data, unsigned char x, unsigned char y )
//{
//	const unsigned char *pnt = font_tiles__tilemap__bin;
//
//	unsigned char idx;
//	unsigned char tile;
//
//	unsigned int quotient = 0;
//	unsigned char remainder = 0;
//
//	//char hold[DATA_LONG];
//	engine_font_manager_draw_text( "     ", x - 4, y );
//	//engine_font_manager_draw_text( "ABCDE", x - 4, y );
//
//	for( idx = 0; idx < DATA_LONG; ++idx )
//	{
//		quotient = data / UNIT_ROOT;
//		remainder = data % UNIT_ROOT;
//
//		//hold[idx] = remainder;
//		data /= UNIT_ROOT;
//
//		//tile = hold[idx] + DATA_ROOT;
//		tile = remainder + DATA_ROOT;
//		if( 0 == quotient && 0 == remainder && idx > 0 )
//		{
//			// Replace with space!
//			//tile = 0;
//			break;
//		}
//
//		devkit_SMS_setNextTileatXY( x--, y );
//		devkit_SMS_setTile( *pnt + tile );
//	}
//}

void engine_font_manager_draw_data( unsigned int data, unsigned char x, unsigned char y )
{
	draw_data( data, x, y, DATA_LONG );
	//const unsigned char *pnt = font_tiles__tilemap__bin;

	//unsigned char idx;
	//signed char tile;

	//unsigned int quotient = 0;
	//unsigned char remainder = 0;

	////char hold[ DATA_LONG ];
	//for( idx = 0; idx < DATA_LONG; ++idx )
	//{
	//	quotient = data / UNIT_ROOT;
	//	remainder = data % UNIT_ROOT;

	//	//hold[ idx ] = remainder;
	//	data /= UNIT_ROOT;

	//	//tile = hold[ idx ] + DATA_ROOT;
	//	tile = remainder + DATA_ROOT;
	//	if( 0 == quotient && 0 == remainder && idx > 0 )
	//	{
	//		// Replace with space!
	//		tile = 0;
	//	}

	//	devkit_SMS_setNextTileatXY( x--, y );
	//	devkit_SMS_setTile( *pnt + tile );
	//}
}

void engine_font_manager_draw_data4( unsigned int data, unsigned char x, unsigned char y )
{
	draw_data( data, x, y, DATA_LONG - 1 );
	//const unsigned char *pnt = font_tiles__tilemap__bin;

	//unsigned char idx;
	//signed char tile;

	//unsigned int quotient = 0;
	//unsigned char remainder = 0;

	////char hold[ DATA_LONG ];
	////for( idx = 0; idx < DATA_LONG; ++idx )
	//for( idx = 0; idx < len; ++idx )
	//{
	//	quotient = data / UNIT_ROOT;
	//	remainder = data % UNIT_ROOT;

	//	//hold[ idx ] = remainder;
	//	data /= UNIT_ROOT;

	//	//tile = hold[ idx ] + DATA_ROOT;
	//	tile = remainder + DATA_ROOT;
	//	if( 0 == quotient && 0 == remainder && idx > 0 )
	//	{
	//		// Replace with space!
	//		tile = 0;
	//	}

	//	devkit_SMS_setNextTileatXY( x--, y );
	//	devkit_SMS_setTile( *pnt + tile );
	//}
}

static void draw_data( unsigned int data, unsigned char x, unsigned char y, unsigned char len )
{
	const unsigned char *pnt = font_tiles__tilemap__bin;

	unsigned char idx;
	signed char tile;

	unsigned int quotient = 0;
	unsigned char remainder = 0;

	//char hold[ DATA_LONG ];
	//for( idx = 0; idx < DATA_LONG; ++idx )
	for( idx = 0; idx < len; ++idx )
	{
		quotient = data / UNIT_ROOT;
		remainder = data % UNIT_ROOT;

		//hold[ idx ] = remainder;
		data /= UNIT_ROOT;

		//tile = hold[ idx ] + DATA_ROOT;
		tile = remainder + DATA_ROOT;
		if( 0 == quotient && 0 == remainder && idx > 0 )
		{
			// Replace with space!
			tile = 0;
		}

		devkit_SMS_setNextTileatXY( x--, y );
		devkit_SMS_setTile( *pnt + tile );
	}
}

//void engine_font_manager_draw_long( unsigned long data, unsigned char x, unsigned char y )
//{
//	const unsigned char *pnt = font_tiles__tilemap__bin;
//
//	unsigned char idx;
//	unsigned char tile;
//
//	unsigned long quotient = 0;
//	unsigned char remainder = 0;
//
//	//char hold[DATA_LONG];
//	engine_font_manager_draw_text( "     ", x - 4, y );
//	//engine_font_manager_draw_text( "ABCDE", x - 4, y );
//
//	//char hold[ DATA_LONG ];
//	for( idx = 0; idx < DATA_LONG; ++idx )
//	{
//		quotient = data / UNIT_ROOT;
//		remainder = data % UNIT_ROOT;
//
//		//hold[ idx ] = remainder;
//		data /= UNIT_ROOT;
//
//		//tile = hold[ idx ] + DATA_ROOT;
//		tile = remainder + DATA_ROOT;
//		if( 0 == quotient && 0 == remainder && idx > 0 )
//		{
//			// Replace with space!
//			//tile = 0;
//			break;
//		}
//
//		devkit_SMS_setNextTileatXY( x--, y );
//		devkit_SMS_setTile( *pnt + tile );
//	}
//}

//void engine_font_manager_draw_long( unsigned long data, unsigned char x, unsigned char y )
//{
//	const unsigned char *pnt = font_tiles__tilemap__bin;
//
//	unsigned char idx;
//	signed char tile;
//
//	unsigned int quotient = 0;
//	unsigned char remainder = 0;
//
//	char hold[ DATA_LONG ];
//	for( idx = 0; idx < DATA_LONG; ++idx )
//	{
//		quotient = data / UNIT_ROOT;
//		remainder = data % UNIT_ROOT;
//
//		hold[ idx ] = remainder;
//		data /= UNIT_ROOT;
//
//		tile = hold[ idx ] + DATA_ROOT;
//		if( 0 == quotient && 0 == remainder && idx > 0 )
//		{
//			// Replace with space!
//			tile = 0;
//		}
//
//		devkit_SMS_setNextTileatXY( x--, y );
//		devkit_SMS_setTile( *pnt + tile );
//	}
//}