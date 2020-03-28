#ifndef _BOSS_MANAGER_H_
#define _BOSS_MANAGER_H_

#include "global_manager.h"
#include "..\object\boss_object.h"

// Global variable.
extern struct_boss_object global_boss_object;

// Global variables.
extern struct_boss_object global_boss_objects[ MAX_BOSSES ];

void engine_boss_manager_content( unsigned char index );
void engine_boss_manager_init();
void engine_boss_manager_load();
void engine_boss_manager_update();

#endif//_BOSS_MANAGER_H_
