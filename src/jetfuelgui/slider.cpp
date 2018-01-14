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
 
#include "slider.h"

namespace jetfuel{

    namespace gui{
    
        void Slider::Check_for_clicks(jetfuel::control::Action
                                          UISinterpreterdata){
			// If the input is a mouse, the action is the
			// message to watch, and the mouse has collided with 
			// this object, get where it collided and set the slider
			// to the closest status to there.

			// TODO(Bobby): Add other input types support.
            if(UISinterpreterdata.inputtype ==
               UISinterpreterdata.Mouse){
                if(UISinterpreterdata.action == Get_control_scheme().
                   mousemessagetowatch &&
                   UISinterpreterdata.inputstate ==
                   UISinterpreterdata.Down &&
                   Get_rect_to_draw().Has_mouse_collided()){
                    // TODO(Bobby): Make this work without
                    // -fpermissive on g++
                    int mousex, mousey;
                    SDL_GetMouseState(&mousex,&mousey);

                    const int currentstatus = (mousex-Get_position().x)/
                                              (Get_width_of_slider_rail()/
                                              Get_number_of_statuses());
                    Set_current_status(currentstatus);
                }
            }                                 
        }
    
        bool Slider::Draw(){
			// Set where the slider button should be based on the past
			// button position, then draw this Slider's member objects.

            jetfuel::draw::Vector2d_int sliderbuttonposition = Get_position();
            
            sliderbuttonposition.x += (Get_width_of_slider_rail()/
                                      Get_number_of_statuses())*
                                      Get_current_status();
            Set_slider_button_position(sliderbuttonposition);
            
            return Draw_slider_member_objects();
        }
    
    }

}
