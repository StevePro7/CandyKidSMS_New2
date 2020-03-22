#include "test_screen.h"
#include "..\engine\audio_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\input_manager.h"
#include "..\devkit\_snd_manager.h"

void screen_test_screen_load()
{
	//engine_audio_manager_music_play_norepeat( mus_type_cont );
	engine_font_manager_draw_text( "TEST SCREEN!!", 10, 14 );
}

void screen_test_screen_update( unsigned char *screen_type )
{
	unsigned char input = engine_input_manager_hold( input_type_fire1 );
	if( input )
	{
		engine_font_manager_draw_text( "END", 15, 15 );
		//devkit_PSGSFXStop();
		devkit_PSGStop();
		engine_font_manager_draw_text( "BOB", 15, 16 );
	}
	*screen_type = screen_type_test;
}