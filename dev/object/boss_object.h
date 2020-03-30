#ifndef _BOSS_OBJECT_H_
#define _BOSS_OBJECT_H_

typedef struct tag_struct_boss_object
{
	unsigned char posnX;		// PositionX during movement.
	unsigned char posnY;		// PositionY during movement.
	unsigned char tileX;		// Posn tileX on bossX stops.
	unsigned char tileY;		// Posn tileY on bossX stops.
	unsigned char tileZ;		// Posn tile stored as R x C.
	unsigned char sizer;		// Size this bossX can shows.
	unsigned char mover;		// Flag when bossX can moves.
	unsigned char drawr;		// Flag when bossX can draws.
	
	unsigned char image;

} struct_boss_object;


// FIXED bank.
// Boss Manager.
extern const unsigned char *boss_object_tiles[];
extern const unsigned char *boss_object_color[];
extern const unsigned char boss_object_bank[];

extern const unsigned char boss_object_tileX[];
extern const unsigned char boss_object_tileY[];

#endif//_GAMER_OBJECT_H_