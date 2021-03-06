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

#include <jetfuelgui/button.h>

namespace jetfuel {
    namespace gui {
        void Button::Set_button_color(jetfuel::draw::Color color){
            m_buttonoverlay.Set_fill_color(color);
        }

        void Button::Assign_renderer(SDL_Renderer *renderer) {
            if(renderer != nullptr){
                m_buttonsprite.Assign_renderer(renderer);
                m_buttonoverlay.Assign_renderer(renderer);
                m_buttontext.Assign_renderer(renderer);
                m_renderready = true;

                Set_assigned_renderer(true);
            }
        }

        void Button::Check_for_clicks(jetfuel::control::Action
                                      UISinterpreterdata){
            // TODO(Bobby): Implement Keyboard and joystick input
            // methods if possible
            if(UISinterpreterdata.action == m_actiontolistenfor
               && UISinterpreterdata.inputstate ==
               UISinterpreterdata.Down &&
               UISinterpreterdata.inputtype == UISinterpreterdata.Mouse
               && Get_rect_to_draw().Has_mouse_collided()){
                if(m_messagebus != nullptr){
                    m_messagebus->Post_message(m_messagetopostonclick);
                }
            }
        }

        bool Button::Draw(){
            // If button is rendered and ready to draw, draw the
            // button
            if(Is_ready_to_draw() && Is_render_ready() &&
			   reinterpret_cast<long int>(this) != 0x00000003){
                if(Draw_button_sprite()){
                    if(Draw_button_overlay()){
                        if(Draw_button_text()){
                            return true;
                        }
                    }
                    return false;
                }

            }

            return false;
        }
    } /* namespace gui */
} /* namespace jetfuel */
