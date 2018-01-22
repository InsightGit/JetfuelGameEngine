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
 
#include <jetfueldraw/circle2dshape.h>

namespace jetfuel{
    namespace draw{
        Circle_2d_shape::Circle_2d_shape(const Circle2d_int circletodraw){
            m_circletodraw = circletodraw;
        }
        
        bool Circle_2d_shape::Draw(){
                if(Get_filled_circle_status()){
                    // Draws a filled circle and returns the results.

                    if(filledCircleRGBA(Get_renderer(), Get_position().x,    
                                        Get_position().y, Get_radius(),
                                        Get_color().r, Get_color().g,
                                        Get_color().b, Get_color().a) != 0){
                        return false;                   
                    }else{
                        return true;
                    }
                                        
                }
        
            if(Get_anti_aliasing_status()){
                // Draws an anti-aliased hollow circle and returns the
                // results.

                if(aacircleRGBA(Get_renderer(), Get_position().x,    
                                        Get_position().y, Get_radius(),
                                        Get_color().r, Get_color().g,
                                        Get_color().b, Get_color().a) != 0){
                    return false;
                }else{
                    return true;
                }
            }else{
                // Draws a hollow circle and returns the results.

                if(circleRGBA(Get_renderer(), Get_position().x,    
                                        Get_position().y, Get_radius(),
                                        Get_color().r, Get_color().g,
                                        Get_color().b, Get_color().a) != 0){  
                    return false;
                }else{
                    return true;
                }     
            }
        }
    }
}

