#include "state_manager.h"
#include "enum_manager.h"

// Global variable.
struct_state_object global_state_object;

void engine_state_manager_init()
{
	struct_state_object *st = &global_state_object;

	st->state_object_availables = 0;
	st->state_object_localcheat = 0;
	st->state_object_high_score = 0;

	st->state_object_trees_type = 0;
	st->state_object_exits_type = 0;
	st->state_object_difficulty = 0;
	st->state_object_pace_speed = 0;

	st->state_object_world_data = 0;
	st->state_object_round_data = 0;

	st->state_object_curr_screen = screen_type_none;
	st->state_object_next_screen = screen_type_none;
}