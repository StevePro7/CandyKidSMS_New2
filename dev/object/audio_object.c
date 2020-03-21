#include "audio_object.h"
#include "..\banks\bank2.h"
#include "..\banks\bank4.h"
#include "..\banks\bank5.h"
#include "..\banks\bank6.h"
#include "..\banks\bank7.h"
#include "..\banks\bank8.h"
#include "..\banks\bank9.h"
#include "..\psg.h"

// DATA bank.
// Audio Manager.
const unsigned char *sfx_object_data[] =
{
	sfx_accept_psg,
	sfx_death_psg,
	sfx_power_psg,
	sfx_reset_psg,
};


// FIXED bank.
// Audio Manager.
const unsigned char *music_object_data[] =
{
	music_beat_psg,
	music_over_psg,
	music_title_psg,
	music_game03_psg,
	music_flicky_psg,
	music_beatgame_psg,
	music_candykid_psg,
};
const unsigned char music_object_bank[] =
{
	music_beat_psg_bank,
	music_over_psg_bank,
	music_title_psg_bank,
	music_game03_psg_bank,
	music_flicky_psg_bank,
	music_beatgame_psg_bank,
	music_candykid_psg_bank,
};

const unsigned char *sound_object_data[] =
{
	sound_accept_psg,
	sound_death_psg,
	sound_gem_psg,
	sound_level_psg,
	sound_power_psg,
	sound_reset_psg,
};
const unsigned char sound_object_bank[] =
{
	sound_accept_psg_bank,
	sound_death_psg_bank,
	sound_gem_psg_bank,
	sound_level_psg_bank,
	sound_power_psg_bank,
	sound_reset_psg_bank,
};