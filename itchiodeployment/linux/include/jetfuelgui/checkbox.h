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

#ifndef JETFUELGUI_CHECKBOX_H_
#define JETFUELGUI_CHECKBOX_H_

#include <jetfuelgui/iclickable.h>

#include "../jetfueldraw/text.h"
#include "../jetfueldraw/sprite.h"


namespace jetfuel {
    namespace gui {
        class Check_box: public jetfuel::draw::Drawable,
                         public IClickable,
                         public jetfuel::draw::Rectangle_interface{
        public:
            enum class Label_position{
                Left,
                Right
            };

            Check_box(const bool checked = false);

            void Load_check_box_images(const jetfuel::draw::Image activeimage,
                                      const jetfuel::draw::Image disabledimage){
                m_activecheckboximage = activeimage;
                m_disabledcheckboximage = disabledimage;
            }

            void Dynamic_load_check_box_images(
                                      const jetfuel::draw::Image activeimage,
                                      const jetfuel::draw::Image disabledimage){
                Load_check_box_images(activeimage, disabledimage);

                m_imagedynamicloading = true;
            }

            void Assign_renderer(SDL_Renderer *renderer)override{
                m_checkbox.Assign_renderer(renderer);
                m_label.Assign_renderer(renderer);

                Set_assigned_renderer(true);
            }

            bool Is_checked(){
                return m_checkboxstatus;
            }

            jetfuel::draw::Vector2d_int Get_position()override{
                m_positioningmutex.lock();

                jetfuel::draw::Vector2d_int position = m_checkbox.Get_position();

                m_positioningmutex.unlock();

                return position;
            }

            void Set_position(const jetfuel::draw::Vector2d_int position)override{
                m_positioningmutex.lock();

                m_checkbox.Set_position(position);

                jetfuel::draw::Vector2d_int textposition;

                textposition.y = m_checkbox.Get_position().y+
                (Get_active_checkbox_image().Get_size_of_image().y/2);

                if(m_labelposition == Label_position::Right){
                    textposition.x = m_checkbox.Get_position().x+
                    Get_active_checkbox_image().Get_size_of_image().x+m_labelgap;
                }else{
                    textposition.x = m_checkbox.Get_position().x-m_labelgap;
                }
                m_label.Set_position(textposition);

                m_positioningmutex.unlock();
            }

            jetfuel::draw::Text::Text_characteristics Get_label_characteristics()
            const{
                return m_labelcharacteristics;
            }

            void Set_label_characteristics(jetfuel::draw::Text::Text_characteristics
                                           labelcharacteristics,
                                           Label_position labelposition,
                                           unsigned int labelgap){
                m_label.Set_font(labelcharacteristics.font);
                m_label.Set_font_size(labelcharacteristics.fontsize);
                m_label.Set_font_style(labelcharacteristics.fontstyle);
                m_label.Set_render_mode(labelcharacteristics.rendermode);
                m_label.Set_string(labelcharacteristics.textstring);
                m_label.Set_text_color(labelcharacteristics.textcolor);
                m_label.Set_background_color(labelcharacteristics.
                                             backgroundcolor);
                if(labelcharacteristics.fontoutlinewidth != 0){
                    m_label.Set_font_outline_width(labelcharacteristics.
                                                   fontoutlinewidth);
                }
                m_label.Set_kerning_status(labelcharacteristics.kerningstatus);

                m_label.Set_font_hinting(labelcharacteristics.fonthinting);

                m_labelposition = labelposition;
                m_labelgap = labelgap;
                m_drawlabel = true;
                Set_position(Get_position());
            }

            void Set_UIS_action_to_watch(const std::string action){
                m_actiontolistenfor = action;
            }

            void Check_for_clicks(jetfuel::control::Action
                                  UISinterpreterdata)override;

            jetfuel::draw::Rect2d_int Get_rect_to_draw()override{
                return m_checkbox.Get_rect_to_draw()+
                       m_label.Get_rect_to_draw();
            }

            jetfuel::draw::Rect2d_int Get_checkbox_rect_to_draw(){
                return m_checkbox.Get_rect_to_draw();
            }

            bool Draw()override;
        protected:
            std::string Get_action_to_listen_for(){
                return m_actiontolistenfor;
            }

            void Set_checked(const bool checked){
                m_checkboxstatus = checked;
            }

            bool Set_checkbox_sprite_image(const jetfuel::draw::Image
                                           image){
                bool returnvalue = true;

                if(m_imagedynamicloading){
                    m_checkbox.Dynamic_load_from_image(image);
                }else{
                    returnvalue = m_checkbox.Load_from_image(image);
                }

                if(image.Get_size_of_image() != m_pastimagesize){
                    Set_position(Get_position());

                    m_pastimagesize = image.Get_size_of_image();
                }

                return returnvalue;
            }

            jetfuel::draw::Image Get_active_checkbox_image() const{
                return m_activecheckboximage;
            }

            jetfuel::draw::Image Get_disabled_checkbox_image() const{
                return m_disabledcheckboximage;
            }

            bool Draw_drawables(){
                if(!m_checkbox.Draw()){
                    return false;
                }else if(m_drawlabel){
                    if(!m_label.Draw()){
                        return false;
                    }
                }else{
                    return true;
                }
            }
        private:
            std::mutex m_positioningmutex;

            jetfuel::draw::Vector2d_int m_pastimagesize;

            bool m_checkboxstatus;
            bool m_drawlabel = false;

            bool m_imagedynamicloading = false;

            unsigned int m_labelgap;

            Label_position m_labelposition = Label_position::Right;

            std::string m_actiontolistenfor;

            jetfuel::draw::Image m_activecheckboximage;
            jetfuel::draw::Image m_disabledcheckboximage;
            jetfuel::draw::Sprite m_checkbox;

            jetfuel::draw::Text m_label;
            jetfuel::draw::Text::Text_characteristics m_labelcharacteristics;
        };
    } /* namespace gui */
} /* namespace jetfuel */

#endif /* JETFUELGUI_CHECKBOX_H_ */
