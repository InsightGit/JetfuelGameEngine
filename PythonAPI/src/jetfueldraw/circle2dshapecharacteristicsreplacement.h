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

#ifndef JETFUELDRAW_CIRCLE2DSHAPECHARACTERISTICSREPLACEMENT_H_
#define JETFUELDRAW_CIRCLE2DSHAPECHARACTERISTICSREPLACEMENT_H_

#include <jetfueldraw.h>

namespace jetfuel {
    namespace draw {
        class Circle_2d_shape_characteristics_replacement {
        public:
            Circle_2d_shape_characteristics_replacement() {}

            Circle_2d_shape_characteristics_replacement(Circle_2d_shape::
                                Circle_2d_shape_characteristics circlechars){
                positionx = circlechars.position.x;
                positiony = circlechars.position.y;
                radius = circlechars.radius;
                color = circlechars.color;
                antialiasingstatus = circlechars.antialiasingstatus;
                filledcirclestatus = circlechars.filledcirclestatus;
            }

            Circle_2d_shape::Circle_2d_shape_characteristics
             Convert_to_circle_2d_shape_chars(){
                Circle_2d_shape::Circle_2d_shape_characteristics returnvalue;

                returnvalue.position = Vector2d_int(positionx, positiony);
                returnvalue.radius = radius;
                returnvalue.color = color;
                returnvalue.antialiasingstatus = antialiasingstatus;
                returnvalue.filledcirclestatus = filledcirclestatus;

                return returnvalue;
            }

            int positionx = 0;
            int positiony = 0;
            int radius = 0;
            Color color;
            bool antialiasingstatus = false;
            bool filledcirclestatus = false;
        };
    } /* namespace draw */
} /* namespace jetfuel */

#endif /* JETFUELDRAW_CIRCLE2DSHAPECHARACTERISTICSREPLACEMENT_H_ */
