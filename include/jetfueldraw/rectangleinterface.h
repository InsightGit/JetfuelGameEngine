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

#ifndef JETFUELDRAW_RECTANGLEINTERFACE_H_
#define JETFUELDRAW_RECTANGLEINTERFACE_H_

#include <jetfueldraw/rect2d.h>

namespace jetfuel {
    namespace draw {
        class Rectangle_interface {
        public:
            /// \brief Returns the Rect2d to be drawn.
            ///
            /// Returns the jetfuel::draw::Rect2d to be drawn when
            /// Draw() is called.
            /// This is a pure virtual function that must be
            /// implemented by the children. This Rect2d_int
            /// will be a rectangle of the entire Drawable.
            virtual Rect2d_int Get_rect_to_draw() = 0;
        };
        /// \class jetfuel::draw::Rectangle_interface
        ///
        /// A simple interface that specifies unique functions
        /// Drawable rectangles should implement.
        ///
        /// \see jetfuel::draw::Sprite
        /// \see jetfuel::draw::Rectangle_2d_shape
        /// \see jetfuel::draw::Text

    } /* namespace draw */
} /* namespace jetfuel */
#endif /* JETFUELDRAW_RECTANGLEINTERFACE_H_ */

