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
			   /// \brief Default constructor.
			   ///
			   /// Default constructor.
               SDL_mixer_init_exception() : 
               std::runtime_error(std::string("SDL_mixer init error! Error was:")
                                  +Mix_GetError()){}
           };
		   /// \class jetfuel::media::exceptions::SDL_mixer_init_exception
		   ///
		   /// An exception thrown when initializing SDL_mixer fails.
		   ///
		   /// \see jetfuel::media::Sound
		   /// \see jetfuel::media::Music
		   /// \see jetfuel::media::Sound_effect
       
       }
   
       class Sound{
       public:
		   /// \brief Virtual destructor.
		   ///
		   /// Virtual destructor.
		   virtual ~Sound() {};

		   /// \brief Loads an audio file.
		   ///
		   /// Loads an audio file. This is a pure virtual function 
		   /// that any children MUST implement.
		   ///
		   /// \param std::string musicfilepath
           virtual bool Load_audio_file(const std::string musicfilepath) = 0;

		   /// \brief Sets the GLOBAL(affects ALL sound objects) 
		   /// volume.
		   ///
		   /// Sets the GLOBAL(affects ALL sound objects) 
		   /// volume.
		   ///
		   /// \param unsigned int channel
		   /// \param int volume
           virtual void Set_global_volume(const unsigned int channel, 
                                          const int volume){
               Mix_Volume(channel, volume);
           }
           
		   /// \brief Gets the current audio frequency(44100 by 
		   /// default).
		   ///
		   /// Gets the current audio frequency(44100 by 
		   /// default).
           int Get_frequency()const{
               return m_frequency;
           }
           
		   /// \brief Sets the current audio frequency.
		   ///
		   /// Sets the current audio frequency. 
		   /// At the risk of sounding obvious:
		   /// Don't mess with this unless you know what
		   /// you are doing.
		   ///
		   /// \param int frequency
           void Set_frequency(const int frequency){
               m_frequency = frequency;
               
               Mix_CloseAudio();
               if(Mix_OpenAudio(m_frequency,m_format,m_numofchannels,m_chunksize)
                  != 0){
                   throw exceptions::SDL_mixer_init_exception();
               } 
           }


		   /// \brief Gets the current audio frequency(
		   /// MIX_DEFAULT_FORMAT by default).
		   ///
		   /// Gets the current audio frequency(MIX_DEFAULT_FORMAT by 
		   /// default).
           Uint16 Get_format()const{
               return m_format;
           }
           
		   /// \brief Sets the current audio format.
		   ///
		   /// Sets the current audio format. 
		   /// At the risk of sounding obvious:
		   /// Don't mess with this unless you know what
		   /// you are doing.
		   ///
		   /// \param Uint16 format
           void Set_format(Uint16 format){
               m_format = format;
               
               Mix_CloseAudio();
               if(Mix_OpenAudio(m_frequency,m_format,m_numofchannels,m_chunksize)
                  != 0){
                   throw exceptions::SDL_mixer_init_exception();
               } 
           }
           
		   /// \brief Gets the current audio chunk size(
		   /// 2048 by default).
		   ///
		   /// Gets the current audio frequency(2048 by 
		   /// default).
           int Get_chunk_size()const{
               return m_chunksize;
           }
           
		   /// \brief Sets the current audio chunk size.
		   ///
		   /// Sets the current audio chunk size. 
		   /// At the risk of sounding obvious:
		   /// Don't mess with this unless you know what
		   /// you are doing.
		   ///
		   /// \param int chunksize
           void Set_chunk_size(const int chunksize){
               m_chunksize = chunksize;
               
               Mix_CloseAudio();
               if(Mix_OpenAudio(m_frequency,m_format,m_numofchannels,m_chunksize)
                  != 0){
                   throw exceptions::SDL_mixer_init_exception();
               } 
           }
            
		   /// \brief Gets the number of audio channels(2 by default).
		   ///
		   /// Gets the number of audio channels(2 by default).
           unsigned int Get_number_of_channels()const{
               return m_numofchannels;
           }
           
		   /// \brief Sets the number of audio channels.
		   ///
		   /// Sets the number of audio channels.
		   ///
		   /// \param unsigned int numofchannels
           void Set_number_of_channels(const unsigned int numofchannels){
               m_numofchannels = numofchannels;
               
               Mix_CloseAudio();
               if(Mix_OpenAudio(m_frequency,m_format,m_numofchannels,m_chunksize)
                  != 0){
                   throw exceptions::SDL_mixer_init_exception();
               }               
           }

		   /// \brief Gets the current active channel number(-1(or 
		   /// automatically choose active channel) by default).
		   ///
		   /// Gets the current active channel number(-1(or 
		   /// automatically choose active channel) by default).
           int Get_active_channel_num() const{
               return m_activechannelnum;
           }

		   /// \brief Sets the current active channel number.
		   ///
		   /// Sets the current active channel number. 
		   /// At the risk of sounding obvious:
		   /// Don't mess with this unless you know what
		   /// you are doing.
		   ///
		   /// \param int activechannelnum
           void Set_active_channel_num(const int activechannelnum){
               m_activechannelnum = activechannelnum;
           }
             
		   /// \brief Starts audio playback.
		   ///
		   /// Starts audio playback. This is a pure virtual function 
		   /// that any children MUST implement.
           virtual bool Play() = 0;
           
		   /// \brief Pauses audio playback.
		   ///
		   /// Pauses audio playback. This is a pure virtual function 
		   /// that any children MUST implement.
           virtual void Pause() = 0;
           
		   /// \brief Resumes audio playback.
		   ///
		   /// Resumes audio playback. This is a pure virtual function 
		   /// that any children MUST implement.
           virtual void Resume() = 0;
       private:
           int m_frequency = 44100; ///< Audio frequency.
           Uint16 m_format = MIX_DEFAULT_FORMAT; ///< Audio format.
           unsigned int m_numofchannels = 2; ///< Number of audio 
											 ///< channels.
           int m_activechannelnum = -1; ///< Number of the active 
										///< audio channel.

           int m_chunksize = 2048; ///< The audio chunk size.

           std::string m_filepath; ///< The audio file path.
       };
	   /// \class jetfuel::media::Sound
	   ///
	   /// A simple base Sound class that, when inherited, simplifies
	   /// the process of building an audio playback class 
	   /// significantly.
	   ///
	   /// \see jetfuel::media::Sound_effect
	   /// \see jetfuel::media::Music
   }
   
}

#endif
