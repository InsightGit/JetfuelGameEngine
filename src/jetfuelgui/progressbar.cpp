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
#include "progressbar.h"

namespace jetfuel {
    namespace gui {
    
        Progress_bar::Progress_bar(const jetfuel::draw::Image 
                         progressbarholderimage, 
                         const jetfuel::draw::Color progressbarcolor,
                        const jetfuel::draw::Rect2d_int progressbarholderborders,
                         const unsigned int progressbarmax){
            m_progressbarholder.Dynamic_load_from_image(
                                             progressbarholderimage);

            m_progressbar.Set_fill_color(progressbarcolor);
            m_progressbarholderborders = progressbarholderborders;
            m_progressbarmax = progressbarmax;
            
            m_progressbarholderdynamicloading = true;

            Set_position(Get_position());               
        }
        
        void Progress_bar::Set_progress_bar(const jetfuel::draw::Image 
                         progressbarholderimage, 
                         const jetfuel::draw::Color progressbarcolor,
                        const jetfuel::draw::Rect2d_int progressbarholderborders,
                         const unsigned int progressbarmax){
            m_progressbarholder.Dynamic_load_from_image(
                                         progressbarholderimage);
            m_progressbar.Set_fill_color(progressbarcolor);
            m_progressbarholderborders = progressbarholderborders;
            m_progressbarmax = progressbarmax;
            
            m_progressbarholderdynamicloading = true;

            Set_position(Get_position());                
        }
        
        bool Progress_bar::Draw(){
            if(!Draw_progress_bar_holder()){
                return false;
            }else{
                Mark_progress_bar_size();
            }

            Set_width_of_progress_bar((Get_max_progress_bar_width()
                                      /Get_max_progress_bar())
                                      *Get_progress_bar_progress());
            if(!Draw_progress_bar()){
                return false;
            }
            
            return true;
        }
 
    }
}
