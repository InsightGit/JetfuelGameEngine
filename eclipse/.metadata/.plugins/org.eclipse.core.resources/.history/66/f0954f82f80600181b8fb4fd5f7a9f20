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

#ifndef JETFUELDRAW_COLOR_H_
#define JETFUELDRAW_COLOR_H_
#include <algorithm>

namespace jetfuel {
    namespace draw {
        class Color {
        public:
            /// \brief Default Constructor
            ///
            /// Constructs a default color of black with it's transparency(alpha)
            /// variable set to 255.
            Color();

            /// \brief Construct a color from RGBA values.
            ///
            /// Construct a Color from the red, green, blue,
            /// and alpha(255 if none is specified) values.
            ///
            /// \param unsigned int red
            /// \param unsigned int green
            /// \param unsigned int blue
            /// \param unsigned int alpha
            Color(unsigned int red, unsigned int green, unsigned int blue,
                  unsigned int alpha = 255);

            ////////////////////////////////
            /// Predefined color presets ///
            ////////////////////////////////

            static const Color Black;    ///< Black predefined color
            static const Color White;    ///< White predefined color
            static const Color Red;      ///< Red predefined color
            static const Color Green;    ///< Green predefined color
            static const Color Blue;     ///< Blue predefined color
            static const Color Yellow;   ///< Yellow predefined color
            static const Color Magenta;  ///< Magenta predefined color
            static const Color Cyan;     ///< Cyan predefined color

            ///////////////////
            /// Member data ///
            ///////////////////

            unsigned int r;   ///< Red value
            unsigned int g;   ///< Green value
            unsigned int b;   ///< Blue value
            unsigned int a;   ///< Alpha (transparency) value
        };

        bool operator ==(const Color left, const Color right);

        bool operator !=(const Color left, const Color right);

        /// \relates Color
        /// \brief Overload of the + operator
        ///
        /// This operator adds all the components of 2 colors
        /// and returns the result.
        /// Components that exceed 255, a limit, will be kept
        /// at 255.
        ///
        /// \param Color left
        /// \param Color right
        Color operator +(const Color left, const Color right);

        /// \relates Color
        /// \brief Overload of the - operator
        ///
        /// This operator subtracts all the components of 2 colors
        /// and returns the result.
        /// Components that are below 0, a limit, will be kept
        /// at 0.
        ///
        /// \param Color left
        /// \param Color right
        Color operator -(const Color left, const Color right);

        /// \relates Color
        /// \brief Overload of the += operator
        ///
        /// This operator adds all the components of 2 colors
        /// and assigns the result to the left operand.
        /// Components that exceed 255, a limit, will be kept
        /// at 255.
        ///
        /// \param Color left
        /// \param Color right
        Color operator +=(Color left,Color right);

        /// \relates Color
        /// \brief Overload of the -= operator
        ///
        /// This operator subtracts all the components of 2 colors
        /// and assigns the result to the left operand.
        /// Components that are below 0, a limit, will be kept
        /// at 0.
        ///
        /// \param Color left
        /// \param Color right
        Color operator -=(Color left,Color right);

        /// \class jetfuel::draw::Color
        ///
        /// A simple useful class for working with rgba colors.
        /// This can be used with the Rectangle2dshape object or
        /// with the Text object.
        ///
        /// Code Example:
        ///     jetfuel::draw::Scene_manager scenemanager;
        ///     jetfuel::draw::Scene scene1(1);
        ///     jetfuel::draw::Color color(jetfuel::draw::Color::Blue);
        ///     jetfuel::draw::Rectangle_2d_shape rectangle(
        ///      jetfuel::draw::Rect2d_int(50,50,50,100);
        ///
        ///     if(!scenemanager.Create_window("example",
        ///                              jetfuel::draw::Vector2d_int(0,0),
        ///                              jetfuel::draw::Vector2d_int(500,500))){
        ///        std::cerr << "[!]ERROR with creating sdl renderer!" <<
        ///        "Error is:" << SDL_GetError() << "\n";
        ///     }
        ///
        ///     if(!scenemanager.Create_renderer()){
        ///          std::cerr << "[!]ERROR with creating sdl renderer!" <<
        ///         "Error is:" << SDL_GetError() << "\n";
        ///     }
        ///
        ///     scenemanager.Switch_current_scene(&scene1);
        ///     scene1.Attach_drawable(&background);
        ///     rectangle.Set_fill_color(color);
        ///
        ///     scenemanager.Draw_current_scene();

    } /* namespace draw */
} /* namespace jetfuel */

#endif /* JETFUELDRAW_COLOR_H_ */
