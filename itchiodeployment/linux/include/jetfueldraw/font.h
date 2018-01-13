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

#ifndef JETFUELDRAW_FONT_H_
#define JETFUELDRAW_FONT_H_
#include <string>
#include <iostream>
#include <stdexcept>

#ifdef __linux__
	#include <SDL2/SDL_ttf.h>
#else
	#include <SDL_ttf.h>
#endif

namespace jetfuel {
    namespace draw {
        namespace exceptions {
            class SDL_ttf_exception : public std::exception {
            public:
				virtual const char* what() const throw()override{
					const char *ttferror = TTF_GetError();

					if (ttferror != nullptr) {
						return std::string(whaterror + ttferror).c_str();
					}
					else {
						return std::string(
							whaterror+ "Nullptr Error from SDL").c_str();
					}
				}
            private:
                ///////////////////
                /// member data ///
                ///////////////////

                std::string whaterror = "SDL_ttf error. Error is:";
            };

            /// \class jetfuel::draw::exceptions::SDL_ttf_exception
            ///
            /// An exception to be thrown whenever a SDL_TTF action
            /// done within a Font or Text object fails.
            ///
            /// Code Example:
            /// if(TTF_Init() < 0){
            ///     throw exceptions::SDL_ttf_exception("TTF_Init()");
            /// }
        }

        class Font{
        public:
            /// \brief Default constructor
            ///
            /// Constructs an empty Font object with the filename
            /// and (optionally) the face index to be set later.
            Font(){}

            /// \brief Constructs a Font object with a filename.
            ///
            /// Constructs a Font object with a filename of where
            /// the TrueType font file is located.
            ///
            /// \param std::string filename
            Font(const std::string filename);

            /// \brief Constructs a Font object with a filename and
            /// a face index.
            ///
            /// Constructs a Font object with a filename of where
            /// the TrueType font file is located, and a face index
            /// for which face to open.
            ///
            /// \param std::string filename
            /// \param long faceindex
            Font(const std::string filename, const long faceindex);

            /// \brief Checks if the font is loaded.
            ///
            /// Checks if the font is loaded. In other words,
            /// Check if at least a filename, and, optionally, a face
            /// index have been set.
            bool Is_font_loaded() const {
                return m_isfontloaded;
            }

            /// \brief Gets a reference to the TTF_Font used by the
            /// library.
            ///
            /// Get a reference to the TTF_Font used by the engine.
            /// If you fully utilize this engine and do not modify
            /// it's internals, you should not have to call
            /// this function.
            TTF_Font *Get_ttf_font() const {
                return m_ttffont;
            }

            /// \brief Returns this Font's filename.
            ///
            /// Returns this Font's filename that it was loaded with
            /// or constructed with.
            std::string Get_file_name() const {
                return m_filename;
            }

            /// \brief Returns this Font's face index.
            ///
            /// Returns this Font's face index that it was loaded with
            /// or constructed with.
            long Get_face_index() const {
                return m_faceindex;
            }

            /// \brief Loads the font with a filename.
            ///
            /// Loads the font with a filename locating
            /// the TrueType font file.
            ///
            /// \param std::string filename
            void Load_font(const std::string filename);

            /// \brief Loads the font with a filename and a face
            /// index.
            ///
            /// Loads the font with a filename locating
            /// the TrueType font file and a face index to indicate
            /// which face to use.
            ///
            /// \param std::string filename
            /// \param long faceindex
            void Load_font(const std::string filename, const long faceindex);

            /// \brief Changes the point size of the Font.
            ///
            /// Changes the point size of the Font. You should not
            /// use this function with just a Font. Instead,
            /// use jetfuel::draw::Text's Set_font_size function
            /// change the size which calls this
            /// function to function anyways.
            ///
            /// \param int size
            void Change_size(const unsigned int size);
        protected:
            /// \brief Set whether the font is loaded.
            ///
            /// Set whether the font is loaded when constructing or
            /// loading a font.
            ///
            /// \param bool isfontloaded
            void Set_is_font_loaded(bool isfontloaded = false) {
                m_isfontloaded = isfontloaded;
            }

            /// \brief Set the filename of the Font object.
            ///
            /// Set the filename of the Font object during
            /// construction or loading of the Font object.
            ///
            /// \param std::string filename
            void Set_file_name(const std::string filename) {
                m_filename = filename;
            }

            /// \brief Set the face index of the Font object.
            ///
            /// Set the face index of the Font object during 
            /// construction or
            /// loading of the Font object.
            void Set_face_index(long faceindex = -1) {
                m_faceindex = faceindex;
            }

            /// \brief Set the TTF_Font reference.
            ///
            /// Set the TTF_Font reference used when creating text.
            void Set_ttf_font(TTF_Font *ttffont) {
				if (ttffont != nullptr) {
					m_ttffont = ttffont;
				}
            }

			static bool Get_ttf_init() {
				return m_ttfinit;
			}

			void Set_ttf_init(bool ttfinit) {
				m_ttfinit = ttfinit;
			}
        private:
			static bool m_ttfinit;

            ///////////////////
            /// member data ///
            ///////////////////

            bool m_isfontloaded = false; ///< is font loaded boolean

            std::string m_filename; ///< filename string
            long m_faceindex = -1; ///< face index long

            TTF_Font *m_ttffont = NULL; ///< TTF_Font reference
        };

        /// \class jetfuel::draw::Font
        ///
        /// A TrueType font object to be used in conjunction with a
        /// jetfuel::draw::Text object to display some text.
        ///
        /// Code Example:
        ///  jetfuel::draw::Scene_manager scenemanager;
        ///  jetfuel::draw::Scene scene1;
        ///  jetfuel::draw::Font font("default.ttf");
        ///  jetfuel::draw::Text hello(font);
        ///
        ///  if(!scenemanager.Create_window("example",
        ///                           jetfuel::draw::Vector2d_int(0,0),
        ///                           jetfuel::draw::Vector2d_int(500,500))){
        ///     std::cerr << "[!]ERROR with creating sdl renderer!" <<
        ///     "Error is:" << SDL_GetError() << "\n";
        ///  }
        ///
        ///  if(!scenemanager.Create_renderer()){
        ///     std::cerr << "[!]ERROR with creating sdl renderer!" <<
        ///     "Error is:" << SDL_GetError() << "\n";
        ///  }
        ///
        ///  scenemanager.Switch_current_scene(&scene1);
        ///
        ///  hello.Set_string("Why Hello There");
        ///  hello.Set_position(jetfuel::draw::Vector2d_int(100,100));
        ///  hello.Set_text_color(jetfuel::draw::Color::Cyan);
        ///  hello.Set_font_size(50);
        ///  hello.Set_render_mode(jetfuel::draw::Text::Render_mode::Blended);
        ///
        ///  scene1.Attach_drawable(&hello,1);
        ///
        ///  scenemanager.Draw_current_scene();

    } /* namespace draw */
} /* namespace jetfuel */

#endif /* JETFUELDRAW_FONT_H_ */
