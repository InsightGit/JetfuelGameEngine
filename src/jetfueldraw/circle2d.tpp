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

#include "circle2d.h"

namespace jetfuel {
    namespace draw {
        template <class T>
        Circle2d<T>::Circle2d(const T X, const T Y, const T Radius){
            x = X;
            y = Y;
            radius = Radius;
        }

        template <typename T>
        Circle2d<T>::Circle2d(const Vector2d<T> position, T Radius){
            x = position.x;
            y = position.y;
            radius = Radius;
        }
    } /* namespace draw */
} /* namespace neon */
