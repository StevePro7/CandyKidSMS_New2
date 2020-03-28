#ifndef _BOSS_OBJECT_H_
#define _BOSS_OBJECT_H_

typedef struct tag_struct_boss_object
{
	unsigned char posnX;		// PositionX during movement.
	unsigned char posnY;		// PositionY during movement.

} struct_boss_object;


// FIXED bank.
// Boss Manager.
extern const unsigned char *boss_object_tiles[];
extern const unsigned char *boss_object_color[];
extern const unsigned char boss_object_bank[];


#endif//_GAMER_OBJECT_H_