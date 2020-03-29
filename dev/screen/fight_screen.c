#include "fight_screen.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"

void screen_fight_screen_load()
{
	engine_font_manager_draw_text( "FIGHT SCREEN!!", 4, 10 );
}

void screen_fight_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_fight;
}
