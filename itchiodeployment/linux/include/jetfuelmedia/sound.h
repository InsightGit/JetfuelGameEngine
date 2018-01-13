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

#ifndef NEONCONTROL_SOUND_H_
#define NEONCONTROL_SOUND_H_
#include <cstdlib>
#include <string>
#include <stdexcept>

#ifdef __linux__
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_mixer.h>
#else
	#include <SDL.h>
	#include <SDL_mixer.h>
#endif

namespace jetfuel{
   
   namespace media{
   
       namespace exceptions{
       
           class SDL_mixer_init_exception : public std::runtime_error{
           public:
               SDL_mixer_init_exception() : 
               std::runtime_error(std::string("SDL_mixer init error! Error was:")
                                  +Mix_GetError()){}
           };
       
       }
   
       class Sound{
       public:
		   virtual ~Sound() {};

           virtual bool Load_audio_file(const std::string musicfilepath) = 0;

           virtual void Set_global_volume(const unsigned int channel, 
                                          const int volume){
               Mix_Volume(channel, volume);
           }
           
           int Get_frequency()const{
               return m_frequency;
           }
           
           void Set_frequency(const int frequency){
               m_frequency = frequency;
               
               Mix_CloseAudio();
               if(Mix_OpenAudio(m_frequency,m_format,m_numofchannels,m_chunksize)
                  != 0){
                   throw exceptions::SDL_mixer_init_exception();
               } 
           }

           Uint16 Get_format()const{
               return m_format;
           }
           
           void Set_format(Uint16 format){
               m_format = format;
               
               Mix_CloseAudio();
               if(Mix_OpenAudio(m_frequency,m_format,m_numofchannels,m_chunksize)
                  != 0){
                   throw exceptions::SDL_mixer_init_exception();
               } 
           }
           
           int Get_chunk_size()const{
               return m_chunksize;
           }
           
           void Set_chunk_size(const int chunksize){
               m_chunksize = chunksize;
               
               Mix_CloseAudio();
               if(Mix_OpenAudio(m_frequency,m_format,m_numofchannels,m_chunksize)
                  != 0){
                   throw exceptions::SDL_mixer_init_exception();
               } 
           }
            
           unsigned int Get_number_of_channels()const{
               return m_numofchannels;
           }
           
           void Set_number_of_channels(const unsigned int numofchannels){
               m_numofchannels = numofchannels;
               
               Mix_CloseAudio();
               if(Mix_OpenAudio(m_frequency,m_format,m_numofchannels,m_chunksize)
                  != 0){
                   throw exceptions::SDL_mixer_init_exception();
               }               
           }

           int Get_active_channel_num() const{
               return m_activechannelnum;
           }

           void Set_active_channel_num(const int activechannelnum){
               m_activechannelnum = activechannelnum;
           }
             
           virtual bool Play() = 0;
           
           virtual void Pause() = 0;
           
           virtual void Resume() = 0;
       private:
           int m_frequency = 44100;
           Uint16 m_format = MIX_DEFAULT_FORMAT;
           unsigned int m_numofchannels = 2;
           int m_activechannelnum = -1;

           int m_chunksize = 2048;

           std::string m_filepath;
       };
   }
   
}

#endif
