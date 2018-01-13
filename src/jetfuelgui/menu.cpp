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

#include "menu.h"

namespace jetfuel {
    namespace gui {
        bool Menu::Add_button(Button_characteristics buttonchars,
                const std::string UISactiontowatchfor,
                const std::string messagetosenduponclick,
                jetfuel::core::Message_bus* bus,
                bool dynamicallyloadimage) {
            Button buttontopush;

            m_buttons.push_back(Button());

            Button *button = Get_button_in_buttons_vector(
                                  Get_size_of_buttons_vector()-1);

            if(Get_renderer()!=nullptr){
                button->Assign_renderer(Get_renderer());
            }

            if(dynamicallyloadimage){
                button->Dynamic_load_base_button_image(buttonchars.image);
            }else if(!button->Load_base_button_image(buttonchars.image)){
                return false;
            }

            Push_back_into_button_image_vector(buttonchars.image);

            button->Set_button_color(buttonchars.color);
            button->Set_button_text_characteristics(buttonchars.buttontextchars);
            button->Set_UIS_action_to_watch(UISactiontowatchfor);
            button->Set_clicked_message(messagetosenduponclick,bus);
            button->Set_position(Determine_button_position(m_buttons.size()-1));

            return true;
        }

        void Menu::Create_container_box(jetfuel::draw::Vector2d_int position){
            Push_back_container_box(jetfuel::draw::Sprite());
            jetfuel::draw::Sprite *box = Get_box_in_container_boxes_vector(
                                              Get_size_of_container_boxes_vector
                                              ()-1);

            box->Load_from_image(Get_container_box_image());
            box->Set_position(position);

            if(Get_renderer()!=nullptr){
                box->Assign_renderer(Get_renderer());
            }
        }

        jetfuel::draw::Vector2d_int Menu::Determine_button_position(unsigned int
                                                                 whichbutton){
            jetfuel::draw::Vector2d_int returnvalue = Get_position();

            unsigned int height = 0;
            for(int i = 0; Get_size_of_buttons_vector() > i; ++i){
                if(i!=whichbutton && Get_button_in_buttons_vector(i)->
                  Has_been_assigned_renderer()){
                     Get_button_in_buttons_vector(i)->Force_load_dynamic_image();
                     height +=
                     Get_button_in_buttons_vector(i)->Get_rect_to_draw().width;

                     if(height>=Get_max_height()){
                         if(Use_container_boxes()){
                             jetfuel::draw::Vector2d_int boxpos(
                                                  Get_position().y,
                                                  returnvalue.x+
                                                  Get_column_gap());
                             if(!Does_container_box_exist_inside_vector(boxpos)){
                                 Create_container_box(boxpos);
                             }

                             returnvalue.y = boxpos.y+
                             Get_container_box_border().y;
                             returnvalue.x += boxpos.x+
                             Get_container_box_border().x;
                         }else{
                             returnvalue.y = Get_position().y;
                             returnvalue.x += Get_column_gap();
                         }
                     }else{
                         returnvalue.y += Get_button_in_buttons_vector(i)->
                                          Get_rect_to_draw().height+
                                          Get_button_gap();
                     }
                }else{
                    break;
                }
            }

            return returnvalue;
        }

        void Menu::Check_for_clicks(jetfuel::control::Action
                                    UISinterpreterdata){
            for(int i = 0;Get_size_of_buttons_vector() > i; ++i){
                Get_button_in_buttons_vector(i)->
                Check_for_clicks(UISinterpreterdata);
            }
        }

        void Menu::Create_container_boxes(){
            Create_container_box(Get_position());

            unsigned int height = 0;
            for(int i = 0; Get_size_of_buttons_vector() > i; ++i){
                height +=
                Get_button_in_buttons_vector(i)->Get_rect_to_draw().width;

                if(height>=Get_max_height()){
                    Create_container_box(jetfuel::draw::Vector2d_int(
                                                                  Get_position().y,
                                                                  Get_position().x+
                                                                  Get_column_gap()));
                }
            }
        }

        bool Menu::Draw(){
            for(int i = 0;Get_size_of_buttons_vector() > i; ++i){
                if(!Get_button_in_buttons_vector(i)->Draw()){
                    return false;
                }

                jetfuel::draw::Vector2d_int buttonsize(
                  Get_button_in_buttons_vector(i)->Get_rect_to_draw().width,
                  Get_button_in_buttons_vector(i)->Get_rect_to_draw().height);

                 if(buttonsize
                    != Get_button_image_in_vector(i).Get_size_of_image()){
                    Get_button_in_buttons_vector(i)->Load_base_button_image(
                                                  Get_button_image_in_vector(i));
                }
            }
            for(int i = 0;Get_size_of_container_boxes_vector() > i; ++i){
                if(!Get_box_in_container_boxes_vector(i)->Draw()){
                    return false;
                }
            }

            return true;
        }
    } /* namespace gui */
} /* namespace jetfuel */


