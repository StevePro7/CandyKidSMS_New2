#ifndef _LEVEL_MANAGER_H_
#define _LEVEL_MANAGER_H_

void engine_level_manager_load_level( const unsigned char world, const unsigned char round );
void engine_level_manager_update_level( const unsigned char round, unsigned char *actor_mover, unsigned char *actor_tileZ );
void engine_level_manager_beat_level( const unsigned char *data, const unsigned char size, const unsigned char bank );
void engine_level_manager_blank_tile( unsigned char index );
void engine_level_manager_draw_level();
void engine_level_manager_draw_middle();

unsigned char engine_level_manager_get_collision( unsigned char x, unsigned char y, unsigned char direction, unsigned char offset );
unsigned char engine_level_manager_get_direction( unsigned char x, unsigned char y, unsigned char direction, unsigned char offset );
unsigned char engine_level_manager_get_tile_type( unsigned char x, unsigned char y, unsigned char direction, unsigned char offset );
unsigned char engine_level_manager_get_next_tile( unsigned char x, unsigned char y, unsigned char direction, unsigned char offset );
void engine_level_manager_get_next_index( unsigned char *x, unsigned char *y, unsigned char direction, signed char offset );

unsigned char engine_level_manager_test_direction( unsigned char row, unsigned char col );

#endif//_LEVEL_MANAGER_H_