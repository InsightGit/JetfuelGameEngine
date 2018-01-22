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

#include <jetfueldraw/color.h>

namespace jetfuel {
    namespace draw {
        const Color Color::Black(0,0,0); //< Black predefined color
        const Color Color::White(255,255,255); //< White predefined
        //^ color
        const Color Color::Red(255,0,0); //< Red predefined color
        const Color Color::Green(0,255,0); //< Green predefined color
        const Color Color::Blue(0,0,255); //< Blue predefined color
        const Color Color::Yellow(255,255,0); //< Yellow predefined
        //^ color
        const Color Color::Magenta(255,0,255); //< Magenta predefined
        //^ color
        const Color Color::Cyan(0,255,255); //< Cyan predefined color

        Color::Color() : Color(0,0,0,255){}

        Color::Color(unsigned int red, unsigned int green, unsigned int blue,
                     unsigned int alpha){
            r = red;
            g = green;
            b = blue;
            a = alpha;
        }

        bool operator ==(const Color left, const Color right){
            return (left.r == right.r && left.g == right.g &&
                    left.b == right.b && left.a == right.a);
        }

        bool operator !=(const Color left, const Color right){
            return (left.r != right.r && left.g != right.g &&
                    left.b != right.b && left.a != right.a);
        }

        Color operator +(const Color left, const Color right){
            // Clamps result to 255 if above 255

            return Color(std::max<unsigned int>(255,left.r + right.r),
                         std::max<unsigned int>(255,left.g + right.g),
                         std::max<unsigned int>(255,left.b + right.b),
                         std::max<unsigned int>(255, left.a + right.a));
        }

        Color operator -(const Color left, const Color right){
            // Clamps result to 0 if below 0

            return Color(std::min<unsigned int>(0,left.r - right.r),
                         std::min<unsigned int>(0,left.g - right.g),
                         std::min<unsigned int>(0,left.b - right.b),
                         std::min<unsigned int>(0, left.a - right.a));
        }

        Color operator +=(Color left, Color right){
            return left = left + right;
        }

        Color operator -=(Color left, Color right){
            return left = left - right;
        }

    } /* namespace draw */
} /* namespace jetfuel */
