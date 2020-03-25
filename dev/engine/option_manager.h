#ifndef _OPTION_MANAGER_H_
#define _OPTION_MANAGER_H_

void engine_option_manager_init();
//void engine_option_manager_load( unsigned char type );
void engine_option_manager_update();

void engine_option_manager_draw_actor( unsigned index );
void engine_option_manager_text_kid( unsigned index );
void engine_option_manager_text_left( unsigned index );
void engine_option_manager_text_left( unsigned index );
void engine_option_manager_text_enemy();

void engine_option_manager_draw_bonus();
void engine_option_manager_draw_candy();

void engine_option_manager_option_exit();
void engine_option_manager_option_tree( unsigned char type );

#endif//_OPTION_MANAGER_H_
