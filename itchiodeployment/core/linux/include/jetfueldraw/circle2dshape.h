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

#ifndef JETFUELDRAW_CIRCLE2DSHAPE_H_
#define JETFUELDRAW_CIRCLE2DSHAPE_H_

#ifdef __linux__
	#include <SDL2/SDL2_gfxPrimitives.h>
#else
	#include <SDL2_gfxPrimitives.h>
#endif

#include <jetfueldraw/circleinterface.h>
#include <jetfueldraw/color.h>
#include <jetfueldraw/drawable.h>

namespace jetfuel{
    namespace draw{
        class Circle_2d_shape : public Drawable, public Circle_interface{
        public:
            struct Circle_2d_shape_characteristics{
                Vector2d_int position;
                int radius = 0;
                Color color;
                bool antialiasingstatus = false;
                bool filledcirclestatus = false;
            };

            /// \brief Default constructor
            ///
            /// Constructs an empty Circle_2d_shape.
            Circle_2d_shape(){}
            
            /// \brief Constructs a Circle_2d_shape with a
            /// Circle2d_int.
            ///
            /// Constructs a Circle_2d_shape with a
            /// Circle2d_int.
            ///
            /// \param Circle2d_int circletodraw
            Circle_2d_shape(const Circle2d_int circletodraw);
            
            /// \brief Gets the Circle_2d_shape's position.
            ///
            /// Gets the Circle_2d_shape's position.
            Vector2d_int Get_position()override{
                return m_circletodraw.Get_position();
            }

            /// \brief Sets the Circle_2d_shape's position.
            ///
            /// Sets the Circle_2d_shape's position.
            ///
            /// \param Vector2d_int position
            void Set_position(const Vector2d_int position)override{
                m_circletodraw.x = position.x;
                m_circletodraw.y = position.y;
            }

            /// \brief Gets the Circle_2d_shape's radius.
            ///
            /// Gets the Circle_2d_shape's radius.
            int Get_radius() const{
                return m_circletodraw.radius;
            }
            
            /// \brief Sets the Circle_2d_shape's radius.
            ///
            /// Sets the Circle_2d_shape's radius.
            ///
            /// \param int radius
            void Set_radius(const int radius){
                m_circletodraw.radius = radius;
            }
            
            /// \brief Gets the circle to draw.
            ///
            /// Gets the circle to draw that will be drawn upon
            /// the function Draw() being called.
            Circle2d_int Get_circle_to_draw()override{
                return m_circletodraw;
            }
            
            /// \brief Gets the anti aliasing status.
            ///
            /// Gets the anti aliasing status. If this
            /// is set to true, it means that anti aliasing is enabled
            /// on this circle, and, theoretically,
            /// it will render much slower. For this reason, you
            /// should not enable this unless the player specifies to
            /// enable it, or you are confident that players running
            /// your game will not suffer any major performance loss.
            /// This anti aliasing status will ONLY come into effect
            /// if the circle being drawn is NOT filled.
            bool Get_anti_aliasing_status() const{
                return m_aastatus;
            }
            
            /// \brief Sets the anti aliasing status.
            ///
            /// Sets the anti aliasing status.
            /// If this is set to true, it means that
            /// anti aliasing is enabled on this circle, and,
            /// theoretically, it will render much slower.
            /// For this reason, you should not enable this unless
            /// the player wants to enable it, or you are
            /// confident that players running your game will not
            /// suffer any major performance loss.
            /// This anti aliasing status will ONLY come into effect
            /// if the circle being drawn is NOT filled.
            ///
            /// \param bool aastatus
            void Set_anti_aliasing_status(const bool aastatus){
                m_aastatus = aastatus;
            }
            
            /// \brief Gets whether the circle is being filled in.
            ///
            /// Gets whether the circle is being filled in.
            bool Get_filled_circle_status() const{
                return m_filledincircle;
            }
            
            /// \brief Sets whether the circle will be filled in.
            ///
            /// Sets whether the circle will be filled in.
            ///
            /// \param bool filledincircle
            void Set_filled_circle_status(const bool filledincircle){
                m_filledincircle = filledincircle;
            }
            
            /// \brief Gets the global color of this circle.
            ///
            /// Gets the global color of this circle that will be
            /// displayed to the player upon Draw() being called.
            Color Get_color() const{
                return m_color;
            }
            
            /// \brief Sets the global color of this circle.
            ///
            /// Sets the global color of this circle that will be
            /// displayed to the player upon Draw() being called.
            ///
            /// \param Color color
            void Set_color(const Color color){
                m_color = color;
            }
            
            /// \brief Draws the circle.
            ///
            /// Draws the circle. It is recommended to let
            /// jetfuel::draw::Scene and jetfuel::draw::Scene_manager
            /// call this, and not by yourself.
            bool Draw()override;
        private:
            ///////////////////
            /// member data ///
            ///////////////////

            bool m_aastatus = true; ///< Whether anti aliasing
            ///^ is enabled.
            bool m_filledincircle = false; ///< Whether this circle
            ///^ is filled in.
            
            jetfuel::draw::Circle2d_int m_circletodraw; ///< The circle
            ///^ to draw once Draw() is called.

            jetfuel::draw::Color m_color; //< This circle's global color.
        };
        /// \class jetfuel::draw::Circle_2d_shape
        ///
        /// A drawable 2d circle shape to be shown to the player.
        ///
        /// Code Example:
        ///   \code
        ///   jetfuel::draw::Circle2d_int mycircle(0,0,50);
        ///   jetfuel::draw::Circle_2d_shape mydrawablecircle(mycircle);
        ///   jetfuel::draw::Scene_manager scenemanager;
        ///   jetfuel::draw::Scene scene1(1);
        ///
        ///   if(!scenemanager.Create_window("example",
        ///                            jetfuel::draw::Vector2d_int(0,0),
        ///                            jetfuel::draw::Vector2d_int(500,500))){
        ///      std::cerr << "[!]ERROR with creating sdl renderer!" <<
        ///      "Error is:" << SDL_GetError() << "\n";
        ///   }
        ///
        ///     if(!scenemanager.Create_renderer()){
        ///          std::cerr << "[!]ERROR with creating sdl renderer!" <<
        ///         "Error is:" << SDL_GetError() << "\n";
        ///     }
        ///
        ///   scenemanager.Switch_current_scene(&scene1);
        ///
        ///   mydrawablecircle.Set_color(jetfuel::draw::Color::Cyan);
        ///   scene1.Attach_drawable(&mydrawablecircle,1S);
        ///
        ///   scenemanager.Draw_current_scene();
        ///   \endcode
    }
}
#endif
