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
			/// \brief Default constructor.
			///
			/// Default constructor.
            Music();

			/// \brief Returns whether ANY music is playing, 
			/// does not have to be this Music object playing.
			///
			/// Returns whether ANY music is playing, 
			/// does not have to be this Music object playing.
            bool Is_music_playing(){
                if(Mix_PlayingMusic() == 1){
                    m_playing = true;
                }else{
                    m_playing = false;
                }

                return m_playing;
            }

			/// \brief Returns whether this music is paused.
			///
			/// Returns whether this music is paused.
            bool Is_music_paused() const{
                return m_paused;
            }

			/// \brief Gets the loaded music's file path.
			///
			/// Gets the loaded music's file path.
            std::string Get_loaded_music_file_path() const{
                return m_musicfilepath;
            }

			/// \brief Loads an audio music file.
			///
			/// Loads an audio music file.
			///
			/// \param std::string musicfilepath
            bool Load_audio_file(const std::string musicfilepath)override{
                m_music = Mix_LoadMUS(musicfilepath.c_str());
                if(m_music == NULL){
                    return false;
                }else{
                    m_musicfilepath = musicfilepath;
                    return true;
                }
            }

			/// \brief Plays the music from the loaded audio file and
			/// returns if it succeeded starting playback.
			///
			/// Plays the music from the loaded audio file and
			/// returns if it succeeded starting playback.
            bool Play()override;

			/// \brief Pauses the music playback.
			///
			/// Pauses the music playback.
            void Pause()override;

			/// \brief Resumes the music playback after it was paused.
			///
			/// Resumes the music playback after it was paused.
            void Resume()override;
        protected:
			/// \brief Returns whether this Music's audio file is 
			/// loaded.
			///
			/// Returns whether this Music's audio file is loaded.
            bool Is_music_loaded() const{
                return m_music != nullptr;
            }

			/// \brief Plays this Music's audio file.
			///
			/// Plays this Music's audio file.
            bool Play_music(){
                if(m_music != nullptr){
                    Mix_PlayMusic(m_music, Get_active_channel_num());

                    m_playing = true;
                    return true;
                }else{
                    return false;
                }
            }

			/// \brief Pauses the music.
			///
			/// Pauses the music.
            void Pause_music(){
                Mix_PauseMusic();

                m_playing = false;
                m_paused = true;
            }


			/// \brief Resumes the music.
			///
			/// Resumes the music.
            void Resume_music(){
                Mix_ResumeMusic();

                m_playing = true;
                m_paused = false;
            }

        private:
            Mix_Music *m_music; ///< The SDL_mixer music object.

            bool m_playing = false; ///< Whether the music is playing
			                        ///< or not.
            bool m_paused = false; ///< Whether the music is paused
			                       ///< or not.

            std::string m_musicfilepath; ///< The music's file path.
        };
		/// \class jetfuel::media::Music
		///
		/// A sound playback class for long audio files (example: BGM),
		/// which supports WAV(.wav), AIFF(.aiff), VOC(.voc), 
		/// MOD(.mod, .xm, .s3m, and more), MIDI(.mid), 
		/// OggVorbis(.ogg), MP3(.mp3), and FLAC(.flac).
		///
		/// Code Example:
		///
		/// jetfuel::media::Music music;
		///
		/// if(music.load_audio_file("BGM.ogg")){
		///		std::cout << "Unable to load BGM.ogg Error:" << Mix_GetError() 
		///		<< std:endl;
		///		return 1;
		///	}
		///
		/// music.Play();
    } /* namespace media */
} /* namespace jetfuel */

#endif /* JETFUELMEDIA_MUSIC_H_ */
