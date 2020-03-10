#include "replay_screen.h"
#include "..\engine\screen_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\tile_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\gfx.h"

void screen_replay_screen_load()
{
	engine_tile_manager_draw_trees( 0, 2, 2 );
	engine_tile_manager_draw_trees( 1, 6, 2 );

	engine_tile_manager_draw_bonus( 3, 3, 5, 1 );
	engine_tile_manager_draw_bonus( 4, 7, 5, 1 );
	engine_tile_manager_draw_bonus( 5, 11, 5, 1 );
	engine_tile_manager_draw_bonus( 6, 15, 5, 1 );

	//engine_tile_manager_draw_bonus( 3, 3, 8, 2 );
	//engine_tile_manager_draw_bonus( 4, 7, 8, 2 );
	//engine_tile_manager_draw_bonus( 5, 11, 8, 2 );
	//engine_tile_manager_draw_bonus( 6, 15, 8, 2 );

	engine_tile_manager_draw_oneup( 10, 10 );

	engine_tile_manager_draw_cross( 0, 14, 12 );
	engine_tile_manager_draw_cross( 1, 16, 12 );

	engine_tile_manager_draw_sides( 20, 20 );

	engine_tile_manager_draw_candy( 0, 4, 16 );
	engine_tile_manager_draw_candy( 1, 6, 16 );
	engine_tile_manager_draw_candy( 2, 8, 16 );
	engine_tile_manager_draw_candy( 3, 10, 16 );
	engine_tile_manager_draw_candy( 4, 12, 16 );
	engine_tile_manager_draw_candy( 5, 14, 16 );
}

void screen_replay_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_replay;
}

