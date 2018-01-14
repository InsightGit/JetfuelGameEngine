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

#include "image.h"

namespace jetfuel {
    namespace draw {
        Image::Image(const std::string imagepath, Scene_manager *scenemanager) {
            // Set image path to internal variable, then load a texture
            // with the given scenemanager's renderer
            // to find the size of the image,
            // then destroy that texture.

			SDL_SetError("None");

            m_imagepath = imagepath;

            SDL_Texture *imagetexture = IMG_LoadTexture(scenemanager->
                                                        Get_renderer(),
                                                        m_imagepath.c_str());
            SDL_QueryTexture(imagetexture, NULL, NULL, &m_sizeofimage.x,
                             &m_sizeofimage.y);
			std::string error = SDL_GetError();

			if (error == "None") {
				SDL_DestroyTexture(imagetexture);
				SDL_ClearError();
			}
        }

        Image::Image(const std::string imagepath, const Vector2d_int imagesize){
            m_imagepath = imagepath;
            m_sizeofimage = imagesize;
        }

        void Image::Set_image(const std::string imagepath, 
                              Scene_manager *scenemanager){
            // Set image path to internal variable, then load a texture
            // with the given scenemanager's renderer
            // to find the size of the image,
            // then destroy that texture.                  
                              
			SDL_SetError("None");

            m_imagepath = imagepath;

            scenemanager->Get_window_id();

            SDL_Texture *imagetexture = IMG_LoadTexture(scenemanager->
                                                        Get_renderer(),
                                                        m_imagepath.c_str());

            SDL_QueryTexture(imagetexture, NULL, NULL, &m_sizeofimage.x,
                             &m_sizeofimage.y);

			const char *sdlerror = SDL_GetError();

			if (strcmp(sdlerror,"None") == 0) {
				SDL_DestroyTexture(imagetexture);
				SDL_ClearError();
			}
        }

        void Image::Set_image(const std::string imagepath, 
                              const Vector2d_int imagesize){
            m_imagepath = imagepath;
            m_sizeofimage = imagesize;
        }
    } /* namespace draw */
} /* namespace jetfuel */
