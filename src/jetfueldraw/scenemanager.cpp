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

#include "scenemanager.h"

#include "scene.h"
#include "image.h"

namespace jetfuel {
    namespace draw {
        Scene_manager::Scene_manager(bool initwindow) {
            if(initwindow){
                if(SDL_Init(SDL_INIT_VIDEO) != 0){
                    throw exceptions::SDL_Init_exception(SDL_GetError());
                }
            }
        }

        Scene_manager::~Scene_manager(){
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);

            SDL_Quit();
        }

        bool Scene_manager::Create_window(const std::string windowtitle,
                                     const Vector2d<int> positiontocreatewindow,
                                          const Vector2d<int> windowsize,
                                          Window_mode windowmode){
            // Creates the window with arguments, 
            // then checks to see if it was actually created.

            switch(windowmode){
                case Window_mode::Windowed:
                    window = SDL_CreateWindow(windowtitle.c_str(),
                                              positiontocreatewindow.x,
                                              positiontocreatewindow.y,
                                              windowsize.x, windowsize.y,
                                              SDL_WINDOW_SHOWN);
                    break;
                case Window_mode::Windowed_fullscreen:
                    window = SDL_CreateWindow(windowtitle.c_str(),
                                              positiontocreatewindow.x,
                                              positiontocreatewindow.y,
                                              windowsize.x, windowsize.y,
                                              SDL_WINDOW_SHOWN |
                                              SDL_WINDOW_FULLSCREEN_DESKTOP);
                    break;
                case Window_mode::Fullscreen:
                    window = SDL_CreateWindow(windowtitle.c_str(),
                                              positiontocreatewindow.x,
                                              positiontocreatewindow.y,
                                              windowsize.x, windowsize.y,
                                              SDL_WINDOW_SHOWN |
                                              SDL_WINDOW_FULLSCREEN);
                    break;
            }

            Set_window_window_mode(windowmode);

            if(window == nullptr){
                Set_window_id(SDL_GetWindowID(window));

                return false;
            }

            return true;
        }

        void Scene_manager::Set_window_icon(jetfuel::draw::Image icon){
            SDL_SetWindowIcon(window,
                    IMG_Load(icon.Get_image_location().c_str()));
        }

        bool Scene_manager::Set_window(SDL_Window *windowtouse){
            // Checks to see that windowtouse is a valid pointer.

            if(windowtouse != nullptr){
                window = windowtouse;
                Set_window_id(SDL_GetWindowID(window));

                return true;
            }

            return false;
        }

        bool Scene_manager::Create_renderer(const bool vsyncenabled,
                                            const bool usehardwareaccel,
                                            const int gpuindex){
            // Creates the renderer with given arguments, 
            // then checks to see if renderer was created.

            if(vsyncenabled){
                if(usehardwareaccel){
                    renderer = SDL_CreateRenderer(window,gpuindex,
                                                  SDL_RENDERER_ACCELERATED
                                                  | SDL_RENDERER_PRESENTVSYNC);
                }else{
                    renderer = SDL_CreateRenderer(window,gpuindex,
                                                   SDL_RENDERER_PRESENTVSYNC |
                                                   SDL_RENDERER_SOFTWARE);
                }
            }else if(usehardwareaccel){
                renderer = SDL_CreateRenderer(window,gpuindex,
                                              SDL_RENDERER_ACCELERATED);
            }else{
                renderer = SDL_CreateRenderer(window,gpuindex,
                                             SDL_RENDERER_SOFTWARE);
            }

            // Checks to see if renderer was created.

            if(renderer != nullptr){
                if(SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND)
                   != 0){
                    return false;
                }

                return true;
            }

            return false;
        }

        bool Scene_manager::Set_renderer(SDL_Renderer *renderertouse){
            // Checks that renderer pointer is a valid pointer.

            if(renderertouse != nullptr){
                renderer = renderertouse;

                return true;
            }

            return false;
        }

        void Scene_manager::Switch_current_scene(Scene *scene){
            // Destroys current scene (if necessary), then switches
            // scene.

            Scene *currentscene = Get_current_scene();
            if(currentscene != nullptr){
                delete currentscene;
            }
            Set_current_scene(scene);
            Get_current_scene()->Assign_renderer(renderer);
        }

        void Scene_manager::Draw_current_scene(){
            // Sets the universal background color, 
            // then draws the current scene (if it exists).

            SDL_SetRenderDrawColor(renderer, Get_universal_background_color().r,
                                   Get_universal_background_color().g, 
                                   Get_universal_background_color().b,
                                   Get_universal_background_color().a);

            SDL_RenderClear(renderer);

            if(Get_current_scene() != nullptr){
                Get_current_scene()->Draw_scene();
            }
            
            // Resets SDL renderer drawing color.

            SDL_SetRenderDrawColor(renderer,0,0,0,255);


        }
    } /* namespace inspire */
} /* namespace jetfuel */
