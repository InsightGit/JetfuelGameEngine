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


#include "scene.h"

#include "scenemanager.h"

namespace jetfuel {
    namespace draw {
        Scene::Scene(const int id, const std::string label) {
            m_id = id;
            m_label = label;
        }

        Scene::~Scene(){
            for(int i = 0; m_drawables.size() > i; ++i){
                if(&m_drawables[i] != nullptr){
                    m_drawables.erase(m_drawables.begin()+i);
                }
            }

        }

        bool Scene::Attach_drawable(Drawable *drawable,
                                    const unsigned int drawingweight){
            // Assigns the scene_manager's renderer to
            // the drawable, then adds the drawable
            // to the internal private m_sprites vector.

			if (drawable != nullptr) {
				if (!drawable->Assigned_renderer()) {
					drawable->Assign_renderer(Get_scene_manager_renderer());
				}

				Add_drawable_placement_to_drawable_placement_vector(drawingweight);
				Add_drawable_to_drawable_vector(drawable);
				return true;
			}
			else {
				return false;
			}
        }

        void Scene::Disable_drawable(Drawable *drawable){
            // Locates drawable by UUID and then, if found disables
            // the drawable.

            for(int i = 0; m_drawables.size() > i; ++i){
                if(*drawable == *m_drawables[i]){
                    Disable_drawable_in_vector(i);
                }
            }
        }

        void Scene::Enable_drawable(Drawable *drawable){
            for(int i = 0; m_drawables.size() > i; ++i){
                if(*drawable == *m_drawables[i]){
                    Enable_drawable_in_vector(i);
                }
            }
        }

        void Scene::Draw_scene(){
            // Draws background color (if there is any), and then
            // Draws drawables based on drawing placement
            // (or drawingweight)

            // Draws background color

            if(Is_background_color_set()){
                SDL_SetRenderDrawColor(Get_scene_manager_renderer(),
                                       Get_background_color().r,
                                       Get_background_color().g,
                                       Get_background_color().b,
                                       Get_background_color().a);

                SDL_RenderClear(Get_scene_manager_renderer());
            }

            // Draws drawables based on drawing placement
            // (or drawingweight).

            if(Get_highest_placement()!=0){
                int currentint = 1;

                while(currentint<=Get_highest_placement()){
                    for(int i = 0; Get_size_of_drawables_vector() > i; ++i){
                        Drawable *currentdrawable = Get_drawable_in_vector(i);

                        if(Get_drawable_placement_in_vector(i) == currentint &&
                           Get_drawable_status(i) && currentdrawable != nullptr){
                            SDL_SetRenderDrawBlendMode(
                            Get_scene_manager_renderer(),SDL_BLENDMODE_BLEND);

                            currentdrawable->Draw();
                        }
                    }
                    ++currentint;
                }
            }

            SDL_RenderPresent(Get_scene_manager_renderer());
        }
    } /* namespace draw */
} /* namespace jetfuel */
