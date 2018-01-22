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

#include <jetfuelmedia/music.h>

namespace jetfuel {
    namespace media {
        Music::Music() {
			// Initializes SDL audio subsystem, and then starts up
			// SDL_mixer via Set_frequency.

            if(SDL_Init(SDL_INIT_AUDIO) != 0){
                throw jetfuel::draw::exceptions::SDL_Init_exception(
														Mix_GetError());
            }

            Set_frequency(Get_frequency());
        }

        bool Music::Play(){
            if(Is_music_loaded() && !Is_music_playing() && !Is_music_paused()){
                return Play_music();
            }else{
                return false;
            }
        }

        void Music::Pause(){
            if(Is_music_loaded() && Is_music_playing()){
                Pause_music();
            }
        }

        void Music::Resume(){
            if(Is_music_loaded() && Is_music_paused()){
                Resume_music();
            }
        }
    } /* namespace media */
} /* namespace jetfuel */
