# CandyKidSMS_New2


BUGS
01.
tree change from 1 to 0 on death

Problem
reset_death()
engine_enemy_manager_reset_mode( st->state_object_actor_kill, enemymove_type_tour );

unconditionally resets the enemy that killed Kid to scatter mode [tour]
HOWEVER this code ignores that fact that death tree killed Kid!!

Long story short we get an out of bounds exception

Managers order
global
mask
enum		global
input		enum
function	mask
state		mask
content		global		banks




TODO
tidy up audio
factor out timer mgr