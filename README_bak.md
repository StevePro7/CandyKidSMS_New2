# CandyKidSMS_New2

29/03/2020
Boss battles	TODO
Invincibility	check still works	w/ death tree + boss
Exits open + shut still work	
Death tree = death => dead and then play [next level] if lives > 0 or cont screen then play screen [next level]

Boss level => dead / cont logic like pass i.e. increment level count
Oneup implement logic to NOT place near boss home tiles


28/03/2020
Kid dies by Trees death + recalc directions on death tile
Revert code in dead + cont screen and just calc for  tile
Refactor code in level Mgr to bulk calc directions and call refactored method per tile

27/03/2020
Levels esp. that may need tweaking
03	02
03	03


SoundFX
E:\Steven\roms\SegaStuff\SMSpower\MusicTOOLS\Mod2PSG2_V2_04
E:\Steven\XNA\BlogNEW\Mod2Psg2
E:\GitHub\StevePro7\CandyKidSMSgraphics\MyAudio


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