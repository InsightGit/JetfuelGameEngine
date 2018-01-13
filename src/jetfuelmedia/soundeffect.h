/*
* Jetfuel Game Engine- A SDL-based 2D game-engine
* Copyright (C) 2017 InfernoStudios
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

#ifndef NEONCONTROL_SOUNDEFFECT_H_
#define NEONCONTROL_SOUNDEFFECT_H_
#include <jetfuelmedia/sound.h>

#include <jetfueldraw/scenemanager.h>


namespace jetfuel{
   
   namespace media{
   
       class Sound_effect : public Sound{
       public:
           Sound_effect();
           
           virtual ~Sound_effect();

           static bool Is_sound_effect_or_music_playing(){
               return Mix_Playing(-1) > 0;
           }

           std::string Get_loaded_audio_file_path() const{
               return m_musicfilepath;
           }

           bool Load_audio_file(const std::string musicfilepath)override{
               m_soundfx = Mix_LoadWAV(musicfilepath.c_str());
               if(m_soundfx == NULL){
                   return false;
               }else{
                   m_musicfilepath = musicfilepath;
                   return true;
               }
           }

           unsigned int Get_times_to_repeat() const{
               return m_repeattimes;
           }

           void Set_times_to_repeat(const unsigned int repeattimes){
               m_repeattimes = repeattimes;
           }

           bool Play()override;
           
           void Pause()override;
           
           void Resume()override;
       protected:
           bool Is_sound_effect_loaded()const{
               return m_soundfx != NULL;
           }

           bool Play_sound_effect(){
               if(m_soundfx != NULL){
                   Mix_PlayChannel(Get_active_channel_num(), m_soundfx,
                                   Get_times_to_repeat());
                   return true;
               }else{
                   return false;
               }
           }

           void Pause_sound_effect(){
               Mix_Pause(Get_active_channel_num());
           }

           void Resume_sound_effect(){
               Mix_Resume(Get_active_channel_num());
           }
       private:
           Mix_Chunk *m_soundfx;

           unsigned int m_repeattimes = 0;

           std::string m_musicfilepath;
       };

   }
   
}

#endif
