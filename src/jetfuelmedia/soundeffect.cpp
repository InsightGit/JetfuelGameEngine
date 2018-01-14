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

#include "soundeffect.h"

namespace jetfuel{

    namespace media{
        Sound_effect::Sound_effect(){
            if(SDL_Init(SDL_INIT_AUDIO) != 0){
                throw jetfuel::draw::exceptions::SDL_Init_exception(Mix_GetError());
            }

            Set_frequency(Get_frequency());
        }

        Sound_effect::~Sound_effect(){
            if(m_soundfx != nullptr && 
				reinterpret_cast<long int>(m_soundfx) != 0xcccccccc){
                Mix_FreeChunk(m_soundfx);
            }
        }

        bool Sound_effect::Play(){
            if(Is_sound_effect_loaded()){
                return Play_sound_effect();
            }else{
                return false;
            }
        }

        void Sound_effect::Resume(){
            Resume_sound_effect();
        }

        void Sound_effect::Pause(){
            Pause_sound_effect();
        }
    }

}
