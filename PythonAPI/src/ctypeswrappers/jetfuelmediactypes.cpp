/*
* Jetfuel Game Engine- A SDL-based 2D game-engine
* Copyright (C) 2018 InfernoStudios
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <jetfuelmedia.h>

#define MAX_FILE_NAME_SIZE 4096

#if defined(_MSC_VER) // If on Visual Studio, export function
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT 
#endif

extern "C"{
    // Wrapper for jetfuel::media::Music

    EXPORT jetfuel::media::Music *Music_new(){
        return new jetfuel::media::Music();
    }

	EXPORT void Music_delete(jetfuel::media::Music *music){
        delete music;
    }

	EXPORT bool Music_is_music_playing(){
        return Mix_PlayingMusic();
    }

	EXPORT bool Music_is_music_paused(){
        return Mix_PausedMusic();
    }

	EXPORT bool Music_load_audio_file(jetfuel::media::Music *music,
                               const wchar_t *musicfilepath){
        char musicfilepathchar[MAX_FILE_NAME_SIZE];

        wcstombs(musicfilepathchar,musicfilepath,
                MAX_FILE_NAME_SIZE);

        if(!music->Load_audio_file(musicfilepathchar)){
            return false;
        }

        return true;
    }

	EXPORT bool Music_play(jetfuel::media::Music *music){
        return music->Play();
    }

	EXPORT void Music_pause(jetfuel::media::Music *music){
        music->Pause();
    }

	EXPORT void Music_resume(jetfuel::media::Music *music){
        music->Resume();
    }

	EXPORT wchar_t *Get_sdl_error(){
        const char *sdlerror = Mix_GetError();

        wchar_t returnvalue[4096];

        mbstowcs(returnvalue, sdlerror, 4096);

        return returnvalue;
    }

    // Wrapper for jetfuel::media::Sound_effect

	EXPORT jetfuel::media::Sound_effect *Sound_effect_new(){
        return new jetfuel::media::Sound_effect();
    }

	EXPORT void Sound_effect_delete(jetfuel::media::Sound_effect *sfx){
        delete sfx;
    }

	EXPORT bool Sound_effect_is_sound_effect_or_music_playing(){
        return jetfuel::media::Sound_effect::Is_sound_effect_or_music_playing();
    }

	EXPORT wchar_t *Sound_effect_get_loaded_sound_effect_file(jetfuel::media::
                                                       Sound_effect *sfx){
        const char *soundeffectfile = sfx->Get_loaded_audio_file_path().c_str();
        wchar_t returnvalue[MAX_FILE_NAME_SIZE];

        mbstowcs(returnvalue, soundeffectfile, MAX_FILE_NAME_SIZE);

        return returnvalue;
    }

	EXPORT bool Sound_effect_load_audio_file(jetfuel::media::Sound_effect *sfx,
                                      const wchar_t *musicfilepath){
        char musicfilepathchar[MAX_FILE_NAME_SIZE];

        wcstombs(musicfilepathchar,musicfilepath,
                MAX_FILE_NAME_SIZE);

        if(!sfx->Load_audio_file(musicfilepathchar)){
            return false;
        }

        return true;
    }

	EXPORT unsigned int Sound_effect_get_times_to_repeat(jetfuel::media::
													Sound_effect *sfx){
        return sfx->Get_times_to_repeat();
    }

	EXPORT void Sound_effect_set_times_to_repeat(jetfuel::media::Sound_effect 
											*sfx,unsigned int timestorepeat){
        return sfx->Set_times_to_repeat(timestorepeat);
    }

	EXPORT bool Sound_effect_play(jetfuel::media::Sound_effect *sfx){
        return sfx->Play();
    }

	EXPORT void Sound_effect_pause(jetfuel::media::Sound_effect *sfx){
        sfx->Pause();
    }

	EXPORT void Sound_effect_resume(jetfuel::media::Sound_effect *sfx){
        sfx->Resume();
    }
}
