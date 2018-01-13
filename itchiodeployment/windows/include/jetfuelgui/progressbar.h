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

#ifndef JETFUELGUI_PROGRESSBAR_H_
#define JETFUELGUI_PROGRESSBAR_H_

#include <jetfuelgui/iclickable.h>

#include "../jetfueldraw/drawable.h"
#include "../jetfueldraw/sprite.h"
#include "../jetfueldraw/rectangle2dshape.h"


namespace jetfuel{
    namespace gui{
        class Progress_bar : public jetfuel::draw::Drawable,
        public jetfuel::draw::Rectangle_interface{
        public:
            Progress_bar(){}
            
            Progress_bar(const jetfuel::draw::Image progressbarholderimage, 
                         const jetfuel::draw::Color progressbarcolor,
                         const jetfuel::draw::Rect2d_int progressbarholderborders,
                         const unsigned int progressbarmax = 100);
           
            void Set_progress_bar(const jetfuel::draw::Image progressbarholderimage, 
                                  const jetfuel::draw::Color progressbarcolor,
                     const jetfuel::draw::Rect2d_int progressbarholderborders,
                                  const unsigned int progressbarmax = 100);
                           
            unsigned int Get_progress_bar_progress() const{
                return m_progressbarprogress;
            }
            
            void Set_progress_bar_progress(const unsigned int 
                                           progressbarprogress){
                m_progressbarprogress = std::min<unsigned int>
                                        (m_progressbarmax,
                                        progressbarprogress);
            }
            
            unsigned int Get_max_progress_bar() const{
                return m_progressbarmax;
            }
            
            bool Has_progress_bar_completed(){
                return m_progressbarprogress >= m_progressbarmax;
            }
                           
            void Assign_renderer(SDL_Renderer *renderer)override{
                m_progressbarholder.Assign_renderer(renderer);
                m_progressbar.Assign_renderer(renderer);

                Set_assigned_renderer(true);
            }
                           
            jetfuel::draw::Vector2d_int Get_position()override{
                return m_progressbarholder.Get_position();
            }
            
            void Set_position(jetfuel::draw::Vector2d_int position)override{
                m_progressbarholder.Set_position(position);
                
                m_progressbar.Set_position(Get_position()+
                  m_progressbarholderborders.Get_position());
                
                if(!m_progressbarholderdynamicloading){
                    m_progressbarmaxsize = (jetfuel::draw::Vector2d_int(
                     m_progressbarholder.Get_size_of_sprite().x-
                      m_progressbarholderborders.width,
                       m_progressbarholder.Get_size_of_sprite().y-
                         m_progressbarholderborders.height*2));
                }

            }
            
            jetfuel::draw::Rect2d_int Get_rect_to_draw()override{
                return m_progressbarholder.Get_rect_to_draw();
            }
                           
            bool Draw()override;
        protected:
            bool Draw_progress_bar_holder(){
                return m_progressbarholder.Draw();
            }
            
            bool Draw_progress_bar(){
                return m_progressbar.Draw();
            }

            int Get_max_progress_bar_width() const{
                return m_progressbarmaxsize.x;
            }
               
            void Set_width_of_progress_bar(const int width){
                m_progressbar.Set_size(jetfuel::draw::Vector2d_int(width,
                m_progressbarmaxsize.y));
            }

            void Mark_progress_bar_size(){
                m_progressbarholderdynamicloading = false;

                Set_position(Get_position());
            }
        private:
            jetfuel::draw::Sprite m_progressbarholder;
            bool m_progressbarholderdynamicloading = false;
            jetfuel::draw::Rect2d_int m_progressbarholderborders;
            
            jetfuel::draw::Rectangle_2d_shape m_progressbar;
            jetfuel::draw::Vector2d_int m_progressbarmaxsize;
            unsigned int m_progressbarprogress = 0;
            unsigned int m_progressbarmax;
        };
    }
}

#endif /* JETFUELGUI_PROGRESSBAR_H_ */
