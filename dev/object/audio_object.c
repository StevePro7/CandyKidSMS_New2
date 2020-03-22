#include "audio_object.h"
#include "..\banks\bank6.h"
#include "..\banks\bank7.h"
#include "..\banks\bank8.h"
#include "..\banks\bank9.h"
#include "..\banks\bank10.h"
#include "..\psg.h"

// DATA bank.
// Audio Manager.
const unsigned char *sfx_object_data[] =
{
	sfx_accept_psg,
	sfx_reset_psg,
	sfx_power_psg,
};


// FIXED bank.
// Audio Manager.
const unsigned char *music_object_data[] =
{
	mus_level_psg,
	mus_cont_psg,
	mus_over_psg,
	mus_game01_psg,
	mus_game02_psg,
	mus_game03_psg,
	mus_beat_psg,
	mus_candykid_psg,
};
const unsigned char music_object_bank[] =
{
	mus_level_psg_bank,
	mus_cont_psg_bank,
	mus_over_psg_bank,
	mus_game01_psg_bank,
	mus_game02_psg_bank,
	mus_game03_psg_bank,
	mus_beat_psg_bank,
	mus_candykid_psg_bank,
};