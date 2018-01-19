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
#ifndef JETFUELDRAW_CIRCLEINTERFACE_H_
#define JETFUELDRAW_CIRCLEINTERFACE_H_

#include <jetfueldraw/circle2d.h>

namespace jetfuel {
    namespace draw {

        class Circle_interface {
        public:
            /// \brief Gets the circle that will be drawn.
            ///
            /// This is a pure virtual function (that should get the
            /// circle that will be drawn) that must be implemented
            /// by any class that inherits this class.
            virtual Circle2d_int Get_circle_to_draw() = 0;
        };
        /// jetfuel::draw::Circle_interface
        ///
        /// A simple interface that specifies unique functions
        /// Drawable circles should implement.
        ///
        /// \see jetfuel::draw::Circle_2d_shape

    } /* namespace draw */
} /* namespace jetfuel */

#endif /* JETFUELDRAW_CIRCLEINTERFACE_H_ */
