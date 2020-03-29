#include "boss_screen.h"
#include "..\engine\boss_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\gamer_manager.h"

void screen_boss_screen_load()
{
	//engine_font_manager_draw_text( "BOSS SCREEN!!", 4, 12 );
}

void screen_boss_screen_update( unsigned char *screen_type )
{
	// Draw sprites first.
	engine_boss_manager_draw();
	engine_gamer_manager_draw();


	*screen_type = screen_type_boss;
}
