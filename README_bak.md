# CandyKidSMS_New2


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