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

#include <jetfueldraw/sprite.h>

#include <iostream>

namespace jetfuel {
    namespace draw {
        Sprite::Sprite(){}

        Sprite::~Sprite(){
            // If a texture exists, destroy it.

            Destroy_image_texture();
        }

        bool Sprite::Load_from_image(const Image image){
            // Get the renderer, and load the image into a
            // SDL_Texture. If there is no texture after that,
            // return false.
            Destroy_image_texture();

            Set_texture(IMG_LoadTexture(Get_renderer(),
                        image.Get_image_location().c_str()));

            if(Get_texture() == nullptr){
                return false;
            }

            Set_dest_width_height(image.Get_size_of_image());
            Set_size_of_sprite(image.Get_size_of_image());

            Set_dynamic_image_loaded(true);

            return true;
        }

        void Sprite::Dynamic_load_from_image(const Image image){
            Set_dynamic_image(image);

            Set_dynamic_image_loaded(false);
        }

        bool Sprite::Draw(){
           // Load image if dynamic and not loaded yet.

           if(!Is_dynamic_image_loaded() &&
               Get_dynamic_image().Get_image_location() != ""){
               Load_from_image(Get_dynamic_image());

               Set_dynamic_image_loaded(true);
           }
           
           // If there is no renderer or texture, return false.
           // Otherwise, draw the Sprite.

           SDL_Renderer *renderer = Get_renderer();
           SDL_Texture *texture = m_texture;

           if(renderer == nullptr || texture == nullptr){
               return false;
           }else{
               Set_dest_position(Get_position());
               SDL_Rect dest = Get_dest_rect();

               if(Is_src_view_rect_set()){
                   SDL_RenderCopy(Get_renderer(), Get_texture(), &Get_src_rect(),
                                  &dest);
               }else{
                   SDL_RenderCopy(Get_renderer(), Get_texture(), NULL, &dest);
               }

               return true;
           }
        }
    } /* namespace draw */
} /* namespace jetfuel */
