# CandyKidSMS_New2

02/04/2020
Boss delay + speed parameterized
Boss collision detection
Boss hide on dead + cont
Boss to drop cross
Algorthm to determine how many oneup

01/04/2020
Pass + Cont screen	hide boss(es) if they are in the middle section

31/03/2020
Boss music
bank11		2x bosses		Space Harrier - 05 - Ida.vgm		mus_boss01.psg
bank12		1x boss			Space Harrier - 04 - Squilla.vgm	mus_boss02.psg
bank13		1x boss			Space Harrier - 12 - Haya Oh.vgm	mus_boss03.psg

30/03/2020
Once I have music with boss screen don't forget to resume music on Dead screen like Play
Integrate every 5th and 10th level boss screen - test Beat screen on 100 level boss

Large boss
minX	3	maxX	10
minY	3	maxY	 9

Small boss
minX	2	maxX	11
minY	2	maxY	10

Home spots
Large + Small
Pro		10, 9
Adi		 3, 9
Suz		10, 3

29/03/2020
TODO
Boss battles
Dead	go back to fight_screen	just like ready_screen
Cont	go back to fight screen just like ready_screen
i.e.	cannot advance until beaten boss10
Pass	this is the only screen in which you can advance level
Pass	every 5th and 10th round goto Prep screen for boss

Decide which boss1 or boss2
if boss1 then load content is easy but boss2 need to work out algorithm

Will have 2x bosses always but only 1x for boss1 move + draw
Will have 2x bosses for Easy but 1x will move and both draw AND Hard both will move and draw


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