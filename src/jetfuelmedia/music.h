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

#ifndef JETFUELMEDIA_MUSIC_H_
#define JETFUELMEDIA_MUSIC_H_

#include <jetfuelmedia/sound.h>

#include "../jetfueldraw/scenemanager.h"


namespace jetfuel {
    namespace media {
        class Music : public Sound {
        public:
            Music();

            bool Is_music_playing(){
                if(Mix_PlayingMusic() == 1){
                    m_playing = true;
                }else{
                    m_playing = false;
                }

                return m_playing;
            }

            bool Is_music_paused() const{
                return m_paused;
            }

            std::string Get_loaded_music_file_path() const{
                return m_musicfilepath;
            }

            bool Load_audio_file(const std::string musicfilepath)override{
                m_music = Mix_LoadMUS(musicfilepath.c_str());
                if(m_music == NULL){
                    return false;
                }else{
                    m_musicfilepath = musicfilepath;
                    return true;
                }
            }

            bool Play()override;

            void Pause()override;

            void Resume()override;
        protected:
            bool Is_music_loaded() const{
                return m_music != NULL;
            }

            bool Play_music(){
                if(m_music != NULL){
                    Mix_PlayMusic(m_music, Get_active_channel_num());

                    m_playing = true;
                    return true;
                }else{
                    return false;
                }
            }

            void Pause_music(){
                Mix_PauseMusic();

                m_playing = false;
                m_paused = true;
            }

            void Resume_music(){
                Mix_ResumeMusic();

                m_playing = true;
                m_paused = false;
            }

        private:
            Mix_Music *m_music;

            bool m_playing = false;
            bool m_paused = false;

            std::string m_musicfilepath;
        };
    } /* namespace media */
} /* namespace jetfuel */

#endif /* JETFUELMEDIA_MUSIC_H_ */
