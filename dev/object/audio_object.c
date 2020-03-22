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
	sfx_reset_psg,
	sfx_power_psg,
};


// FIXED bank.
// Audio Manager.
const unsigned char *music_object_data[] =
{
	music_beat_psg,
	music_over_psg,
	music_game03_psg,
	music_candykid_psg,
};
const unsigned char music_object_bank[] =
{
	music_beat_psg_bank,
	music_over_psg_bank,
	music_game03_psg_bank,
	music_candykid_psg_bank,
};