#include "memo_manager.h"
#include "board_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "locale_manager.h"
#include "score_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\banks\databank.h"
#include "..\banks\fixedbank.h"

void engine_memo_manager_clear()
{
	unsigned char row;
	for( row = 0; row < 23; row++ )
	{
		engine_font_manager_draw_text( LOCALE_BLANK_WIDTH, 0, row );
	}
}

void engine_memo_manager_draw( unsigned char topIndex, unsigned char botIndex )
{
	unsigned char x = SCREEN_TILE_LEFT + LFT_SIDE_X + 8;
	unsigned char y = TOP_SIDE_Y + 10;

	engine_board_manager_midd_text();
	engine_locale_manager_draw_text( topIndex, x, y + 1 );
	engine_locale_manager_draw_text( botIndex, x, y + 2 );
}

void engine_memo_manager_pass( unsigned char perfect )
{
	unsigned char topIndex = 15;
	unsigned char botIndex = 16;

	if( perfect )
	{
		botIndex = 17;
	}

	engine_memo_manager_draw( topIndex, botIndex );
}

// TODO maybe take out permanently as I won't use...
//void engine_memo_manager_bonus( unsigned char perfect )
//{
//	unsigned char topIndex = 18;
//	unsigned char botIndex = 19;
//
//	if( perfect )
//	{
//		topIndex = 20;
//		botIndex = 21;
//	}
//
//	engine_memo_manager_draw( topIndex, botIndex );
//}

void engine_memo_manager_option()
{
	const unsigned char *text;
	const unsigned char dataY = 22;
	//unsigned char index[ 2 ] = { 11,13 };
	//unsigned char loop;

	devkit_SMS_mapROMBank( FIXED_BANK );

	//if( diff_type_hard == state_object_difficulty && pace_type_fast == state_object_pace_speed )
	//{
	//	index[ 0 ] = 13;
	//	index[ 1 ] = 11;
	//}

	if( diff_type_hard == state_object_difficulty && pace_type_fast == state_object_pace_speed )
	{
		text = locale_object_texts[ state_object_difficulty + 11 ];
		engine_font_manager_draw_text( text, TEXT_X, dataY + 0 );

		text = locale_object_texts[ state_object_pace_speed + 13 ];
		engine_font_manager_draw_text( text, TEXT_X, dataY + 1 );
	}
	else
	{
		text = locale_object_texts[ state_object_pace_speed + 13 ];
		engine_font_manager_draw_text( text, TEXT_X, dataY + 0 );

		text = locale_object_texts[ state_object_difficulty + 11 ];
		engine_font_manager_draw_text( text, TEXT_X, dataY + 1 );
	}

	// TODO did I want this??
	//engine_font_manager_draw_text( "&", TEXT_X, dataY + 1 );
}