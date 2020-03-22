#include "audio_manager.h"
#include "state_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\devkit\_snd_manager.h"
#include "..\object\audio_object.h"

static unsigned char music_bank;

// Music.
void engine_audio_manager_music_play( unsigned char index )
{
	struct_state_object *st = &global_state_object;
	const unsigned char *music_data;

	if( !st->state_object_music_data )
	{
		return;
	}

	music_data = music_object_data[ index ];
	music_bank = music_object_bank[ index ];

	devkit_SMS_mapROMBank( music_bank );
	devkit_PSGPlay( ( unsigned char* ) music_data );
}
void engine_audio_manager_music_play_norepeat( unsigned char index )
{
	struct_state_object *st = &global_state_object;
	const unsigned char *music;
	unsigned char bank;

	if( !st->state_object_music_data )
	{
		return;
	}

	music = music_object_data[ index ];
	bank = music_object_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_PSGPlayNoRepeat( ( unsigned char* ) music );
}
void engine_audio_manager_music_resume()
{
	devkit_SMS_mapROMBank( music_bank );
	devkit_PSGResume();
}
void engine_audio_manager_music_stop()
{
	devkit_PSGStop();
}

// Sound.
void engine_audio_manager_sfx_play( unsigned char index )
{
	struct_state_object *st = &global_state_object;
	const unsigned char *sfx;
	unsigned char status;

	// If sound effects are  disabled then return.
	if( !st->state_object_sound_data )
	{
		return;
	}

	// If sound effect already playing then return.
	status = devkit_PSGSFXGetStatus();
	if( status )
	{
		return;
	}

	sfx = sfx_object_data[ index ];
	devkit_PSGSFXPlay( ( unsigned char* ) sfx, devkit_SFX_CHANNEL2() );
}