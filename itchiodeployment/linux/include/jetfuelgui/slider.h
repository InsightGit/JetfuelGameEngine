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

#ifndef NEONDRAW_SLIDER_H_
#define NEONDRAW_SLIDER_H_
#include <jetfuelgui/iclickable.h>

#include "../jetfueldraw/drawable.h"
#include "../jetfueldraw/circle2dshape.h"
#include "../jetfueldraw/rectangle2dshape.h"

namespace jetfuel{
    namespace gui{
    
        class Slider : public jetfuel::draw::Drawable, public IClickable,
                       public jetfuel::draw::Rectangle_interface{
        public:
            Slider(){}

            jetfuel::draw::Rectangle_2d_shape::
            Rectangle_2d_shape_characteristics
            Get_slider_rail_characteristics() const{
                return m_sliderrailchars;
            }

            void Set_slider_rail_characteristics(jetfuel::draw::Rectangle_2d_shape::
                   Rectangle_2d_shape_characteristics sliderrailcharacteristics){
                m_sliderrailchars = sliderrailcharacteristics;

                m_sliderrail.Set_size(m_sliderrailchars.size);
                m_sliderrail.Set_fill_color(m_sliderrailchars.fillcolor);
                m_sliderrail.Set_outline_color(m_sliderrailchars.outlinecolor);
            }


            jetfuel::draw::Circle_2d_shape::
            Circle_2d_shape_characteristics Get_slider_button_characteristics(){
                return m_sliderbuttonchars;
            }

            void Set_slider_button_characteristics(jetfuel::draw::Circle_2d_shape::
                                  Circle_2d_shape_characteristics
                                  sliderbuttoncharacteristics){
                m_sliderbuttonchars = sliderbuttoncharacteristics;

                m_sliderbutton.Set_anti_aliasing_status(
                              m_sliderbuttonchars.antialiasingstatus);
                m_sliderbutton.Set_filled_circle_status(
                              m_sliderbuttonchars.filledcirclestatus);
                m_sliderbutton.Set_color(m_sliderbuttonchars.color);
                m_sliderbutton.Set_radius(m_sliderbuttonchars.radius);
            }

            unsigned int Get_number_of_statuses() const{
                return m_statusnumber;
            }
            
            void Set_number_of_statuses(const unsigned int statusnumber){
                m_statusnumber = statusnumber;
            }
            
            unsigned int Get_current_status() const{
                return m_currentstatus;
            }
            
            void Set_current_status(const unsigned int currentstatus){
                m_currentstatus = std::min<unsigned int>(m_statusnumber,
                                                        currentstatus);
            }

            jetfuel::control::UIS_input_actions Get_control_scheme() const{
                return m_UIScontrols;
            }
            
            void Set_control_scheme(jetfuel::control::UIS_input_actions 
                                    UIScontrols){
                m_UIScontrols = UIScontrols;                       
            }
            
            void Assign_renderer(SDL_Renderer *renderer)override{
                m_sliderrail.Assign_renderer(renderer);
                m_sliderbutton.Assign_renderer(renderer);

                Set_assigned_renderer(true);
            }

            jetfuel::draw::Vector2d_int Get_position()override{
                return m_sliderrail.Get_position();
            }

            void Set_position(jetfuel::draw::Vector2d_int position)override{
                m_sliderrail.Set_position(position);
            }

            jetfuel::draw::Rect2d_int Get_rect_to_draw()override{
                return jetfuel::draw::Rect2d_int(Get_position(),
                                              jetfuel::draw::Vector2d_int(
                                              m_sliderrail.Get_size().x,
                           m_sliderbutton.Get_circle_to_draw().radius*2));
            }

            void Check_for_clicks(jetfuel::control::Action
                                  UISinterpreterdata)override;
            
            bool Draw()override;
        protected:
            void Set_slider_button_position(jetfuel::draw::Vector2d_int position){
                m_sliderbutton.Set_position(position);
            }
            
            bool Draw_slider_member_objects(){
                if(!m_sliderrail.Draw()){
                    return false;
                }else if(!m_sliderbutton.Draw()){
                    return false;
                }else{
                    return true;
                }
            }

            int Get_width_of_slider_rail(){
                return m_sliderrail.Get_size().x;
            }
        private:
            unsigned int m_statusnumber = 1;
            unsigned int m_currentstatus = 0;
            
            jetfuel::control::UIS_input_actions m_UIScontrols;

            jetfuel::draw::Rectangle_2d_shape::
            Rectangle_2d_shape_characteristics m_sliderrailchars;

            jetfuel::draw::Circle_2d_shape::
            Circle_2d_shape_characteristics m_sliderbuttonchars;
        
            jetfuel::draw::Circle_2d_shape m_sliderbutton;
            jetfuel::draw::Rectangle_2d_shape m_sliderrail;
        };
    
    }
}

#endif
