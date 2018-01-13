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

#include "checkbox.h"

namespace jetfuel {
    namespace gui {
        Check_box::Check_box(bool checked) {
            m_checkboxstatus = checked;
        }

        void Check_box::Check_for_clicks(jetfuel::control::Action
                                         UISinterpreterdata){
        	// If the mouse has clicked on this Check_box and the UIS
        	// action has been triggered, invert the Is_Checked status.

            if(UISinterpreterdata.action == Get_action_to_listen_for()
               && UISinterpreterdata.inputstate ==
               UISinterpreterdata.Down &&
               Get_checkbox_rect_to_draw().Has_mouse_collided()){
                Set_checked(!Is_checked());
            }
        }

        bool Check_box::Draw(){
            if(Is_checked()){
                Set_checkbox_sprite_image(Get_active_checkbox_image());
            }else{
                Set_checkbox_sprite_image(Get_disabled_checkbox_image());
            }

            return Draw_drawables();
        }
    } /* namespace gui */
} /* namespace jetfuel */
