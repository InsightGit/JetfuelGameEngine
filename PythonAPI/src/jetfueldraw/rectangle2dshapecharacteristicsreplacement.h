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

#ifndef JETFUELDRAW_RECTANGLE2DSHAPECHARACTERISTICSREPLACEMENT_H_
#define JETFUELDRAW_RECTANGLE2DSHAPECHARACTERISTICSREPLACEMENT_H_

#include <jetfueldraw.h>

namespace jetfuel {
    namespace draw {

        class Rectangle_2d_shape_characteristics_replacement {
        public:
            Rectangle_2d_shape_characteristics_replacement() {}

            Rectangle_2d_shape_characteristics_replacement(
            jetfuel::draw::Rectangle_2d_shape::Rectangle_2d_shape_characteristics
            rectchars){
                rectpositionx = rectchars.position.x;
                rectpositiony = rectchars.position.y;
                rectsizewidth = rectchars.size.x;
                rectsizeheight = rectchars.size.y;

                fillcolor = rectchars.fillcolor;
                outlinecolor = rectchars.outlinecolor;
            }

            jetfuel::draw::Rectangle_2d_shape::Rectangle_2d_shape_characteristics
             Convert_to_rectangle_2d_shape_chars(){
                jetfuel::draw::Rectangle_2d_shape::
                 Rectangle_2d_shape_characteristics returnvalue;

                returnvalue.position = jetfuel::draw::Vector2d_int(rectpositionx,
                                                                   rectpositiony);
                returnvalue.size = jetfuel::draw::Vector2d_int(rectsizewidth,
                                                               rectsizeheight);
                returnvalue.fillcolor = fillcolor;

                returnvalue.outlinecolor = outlinecolor;

                return returnvalue;
            }

            int rectpositionx = 0;
            int rectpositiony = 0;
            int rectsizewidth = 0;
            int rectsizeheight = 0;

            Color fillcolor;
            Color outlinecolor;
        };

    } /* namespace draw */
} /* namespace jetfuel */

#endif /* JETFUELDRAW_RECTANGLE2DSHAPECHARACTERISTICSREPLACEMENT_H_ */
