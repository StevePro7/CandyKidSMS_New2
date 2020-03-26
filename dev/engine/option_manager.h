#ifndef _OPTION_MANAGER_H_
#define _OPTION_MANAGER_H_

void engine_option_manager_init( unsigned char sides );
//void engine_option_manager_load( unsigned char type );
void engine_option_manager_update( unsigned char screen );

void engine_option_manager_clear();
void engine_option_manager_draw_actor( unsigned index );
void engine_option_manager_text_kid( unsigned index );
void engine_option_manager_text_kid_no( unsigned index, unsigned char image );
void engine_option_manager_text_enemy();
void engine_option_manager_text_enemy_no( unsigned enemy, unsigned char image );
void engine_option_manager_text_start( unsigned char mode );

void engine_option_manager_draw_bonus( unsigned index );
void engine_option_manager_draw_candy( unsigned index );

void engine_option_manager_text_tree( unsigned char index, unsigned char type );
void engine_option_manager_text_exit( unsigned char index, unsigned char type );
void engine_option_manager_option_tree( unsigned char type );
void engine_option_manager_option_exit();

#endif//_OPTION_MANAGER_H_
