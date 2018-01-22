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

#include <jetfueldraw/font.h>

namespace jetfuel {
    namespace draw {
		bool Font::m_ttfinit = false;

        Font::Font(const std::string filename) {
            m_filename = filename;

            m_isfontloaded = true;
        }

        Font::Font(const std::string filename, const long faceindex) {
            m_filename = filename;
            m_faceindex = faceindex;

            m_isfontloaded = true;
        }

        void Font::Load_font(const std::string filename){
            Set_file_name(filename);

            Set_is_font_loaded(true);
        }

        void Font::Load_font(const std::string filename, const long faceindex){
            Set_file_name(filename);
            Set_face_index(faceindex);

            Set_is_font_loaded(true);
        }

        void Font::Change_size(const unsigned int size){
            // Open Font with font index if index is set.

			if (!Get_ttf_init()) {
				if (TTF_Init() != 0) {
					std::cerr << "SDL TTF ERROR:" << TTF_GetError() << "\n";
					throw exceptions::SDL_ttf_exception();
				}

				Set_ttf_init(true);
			}

            if(Get_file_name()!=""){
				if (Get_ttf_font() != nullptr) {
					TTF_CloseFont(Get_ttf_font());
				}

				std::string filename = Get_file_name();
				char *filenamecstring = new char[filename.length()+1];
				TTF_Font *ttffont;

				strcpy(filenamecstring, filename.c_str());

				SDL_ClearError();

                if(Get_face_index()!=-1){
					ttffont = TTF_OpenFontIndex(filenamecstring, size,
												Get_face_index());
				}else{
					ttffont = TTF_OpenFont(filenamecstring, size);
                }

				Set_ttf_font(ttffont);

                if(Get_ttf_font()==nullptr){
					std::cerr << "SDL TTF ERROR:" << TTF_GetError() << "\n";
                    throw exceptions::SDL_ttf_exception();
                }
            }
        }
    } /* namespace draw */
} /* namespace jetfuel */
