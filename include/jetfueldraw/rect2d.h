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

#ifndef JETFUELDRAW_RECT2D_H_
#define JETFUELDRAW_RECT2D_H_
#include <jetfueldraw/vector2d.h>

namespace jetfuel {
    namespace draw {
        template <class T>
        class Rect2d {
        public:
            /// \brief Default constructor
            ///
            /// Constructs an empty Rect2d with all values set to 0.
            Rect2d() : Rect2d(0,0,0,0) {}

            /// \brief Constructs a Rect2d with a x coordinate, a y
            /// coordinate, width, and height.
            ///
            /// Constructs a Rect2d with a x coordinate, a y
            /// coordinate, width, and height.
            ///
            /// \param T X
            /// \param T Y
            /// \param T Width
            /// \param T Height
            Rect2d(const T X, const T Y, const T Width, const T Height){
                x = X;
                y = Y;
                width = Width;
                height = Height;
            }

            /// \brief Constructs a Rect2d with a position vector, and
            /// a size vector.
            ///
            /// Constructs a Rect2d with a position vector, and
            /// a size vector.
            ///
            /// \brief jetfuel::draw::Vector2d<T> position
            /// \brief jetfuel::draw::Vector2d<T> size
            Rect2d(const Vector2d<T> position, const Vector2d<T> size){
                x = position.x;
                y = position.y;
                width = size.x;
                height = size.y;
            }

            /// \brief Gets the position Vector2d of the Rect2d.
            ///
            /// Gets the position Vector2d of the Rect2d.
            jetfuel::draw::Vector2d<T> Get_position(){
                return jetfuel::draw::Vector2d<T>(x,y);
            }

            /// \brief Gets the size Vector2d of the Rect2d.
            ///
            /// Gets the size Vector2d of the Rect2d.
            jetfuel::draw::Vector2d<T> Get_size(){
                return jetfuel::draw::Vector2d<T>(width,height);
            }
            
            /// \brief Detects whether this Rect2d has collided with
            /// another Rect2d with the same type.
            ///
            /// Detects whether this Rect2d has collided with
            /// another Rect2d with the same type.
            ///
            /// \param Rect2d<T>
            bool Has_collided_with_rect(jetfuel::draw::Rect2d<T> rect){
                T leftinternalrect, leftrect;
                T rightinternalrect, rightrect;
                T topinternalrect, toprect;
                T bottominternalrect, bottomrect;

                leftinternalrect = x;
                rightinternalrect = x + width;
                topinternalrect = y;
                bottominternalrect = y + height;

                leftrect = rect.x;
                rightrect = rect.x + rect.width;
                toprect = rect.y;
                bottomrect = rect.y + rect.height;


                if(bottominternalrect <= toprect){
                    return false;
                }else if(topinternalrect >= bottomrect){
                    return false;
                }else if(rightinternalrect <= leftrect){
                    return false;
                }else if(leftinternalrect >= rightrect){
                    return false;
                }else{
                    return true;
                }
            }

            /// \brief Returns whether this Rect2d
            /// has collided with the mouse.
            ///
            /// Returns whether this Rect2d
            /// has collided with the mouse.
            bool Has_mouse_collided(){
                // TODO(Bobby): Make this work without 
                // -fpermissive on g++
                int mousex, mousey;
                SDL_GetMouseState(&mousex,&mousey);

                return Has_collided_with_rect(jetfuel::draw::Rect2d<T>(
                                             static_cast<T>(mousex),
                                              static_cast<T>(mousey),
                                              static_cast<T>(1),
                                              static_cast<T>(1)));

            }

            ///////////////////
            /// member data ///
            ///////////////////

            T x; ///< x coordinate
            T y; ///< y coordinate
            T width; ///< width of rectangle
            T height; ///< height of rectangle
        };

        template <typename T>
        Rect2d<T> operator +(Rect2d<T> left,Rect2d<T> right){
            return Rect2d<T>(left.Get_position() + right.Get_position(),
                             left.Get_size() + right.Get_size());
        }

        template <typename T>
        Rect2d<T> operator +=(Rect2d<T> &left,const Rect2d<T> right){
            left.x += right.x;
            left.y += right.y;
            left.width += right.width;
            left.height += right.height;

            return left;
        }

        template <typename T>
        Rect2d<T> operator -(const Rect2d<T> left,const Rect2d<T> right){
            return Rect2d<T>(left.Get_position() - right.Get_position(),
                             left.Get_size() - right.Get_size());
        }

        template <typename T>
        Rect2d<T> operator -=(Rect2d<T> &left,const Rect2d<T> right){
            left.x -= right.x;
            left.y -= right.y;
            left.width -= right.width;
            left.height -= right.height;

            return left;
        }

        template <typename T>
        Rect2d<T> operator *=(Rect2d<T> &left, Rect2d<T> &right){
            left.x *= right.x;
            left.y *= right.y;
            left.width *= right.width;
            left.height *= right.height;

            return left;
        }

        template <typename T>
        Rect2d<T> operator /=(Rect2d<T> &left, Rect2d<T> &right){
            left.x /= right.x;
            left.y /= right.y;
            left.width /= right.width;
            left.height /= right.height;

            return left;
        }

        template <typename T>
        Rect2d<T> operator *=(Rect2d<T> &left, const T right){
            left.x *= right.x;
            left.y *= right.y;
            left.width *= right.width;
            left.height *= right.height;

            return left;
        }

        template <typename T>
        Rect2d<T> operator *(T left, const Rect2d<T> right){
            return Rect2d<T>(right.Get_position() * left,
                               right.Get_size() * left);
        }

        template <typename T>
        Rect2d<T> operator /(const Rect2d<T> left, const T right){
            return Vector2d<T>(left.Get_position()/right, left.Get_size()/right);
        }

        template <typename T>
        Rect2d<T> operator /=(Rect2d<T> &left, const T right){
            left.x /= right;
            left.y /= right;
            left.width /= right;
            left.height /= right;

            return left;
        }

        template <typename T>
        Rect2d<T> operator +(const Rect2d<T> left, const T right){
            return Rect2d<T>(left.Get_position() + right,
                             left.Get_size() + right);
        }

        template <typename T>
        Rect2d<T> operator +=(Rect2d<T> &left, const T right){
            left.x += right;
            left.y += right;
            left.width += right;
            left.height += right;

            return left;
        }

        template <typename T>
        Rect2d<T> operator -(const Rect2d<T> left,const T right){
            return Rect2d<T>(left.Get_position() - right,
                             left.Get_size() - right);
        }

        template <typename T>
        Rect2d<T> operator -=(Rect2d<T> &left,const T right){
            left.x -= right;
            left.y -= right;
            left.width -= right;
            left.height -= right;

            return left;
        }

        template <typename T>
        bool operator ==(const Rect2d<T> left, const Rect2d<T> right){
            return (left.Get_position() == right.Get_position())
                    && (left.Get_size() == right.Get_size());
        }

        template <typename T>
        bool operator !=(const Rect2d<T> left, const Rect2d<T> right){
            return (left.Get_position() != right.Get_position())
                    && (left.Get_size() != right.Get_size());
        }

        //////////////////////////////
        /// Common Rect2d typedefs ///
        //////////////////////////////

        typedef Rect2d<int> Rect2d_int;
        typedef Rect2d<unsigned int> Rect2d_uint;
        typedef Rect2d<float> Rect2d_float;

        /// \class jetfuel::draw::Rect2d
        ///
        /// A simple 2d rectangle manipulation class.
        ///
        /// Code Example:
        ///   jetfuel::draw::Rect2d_int myrect(0,0,5,5);
        ///   jetfuel::draw::Rectangle_2d_shape mydrawablerect(myrect);
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
        ///   mydrawablerect.Set_fill_color(jetfuel::draw::Color::Cyan);
        ///   scene1.Attach_drawable(&mydrawablerect,1S);
        ///
        ///   scenemanager.Draw_current_scene();

    } /* namespace draw */
} /* namespace jetfuel */

#endif /* JETFUELDRAW_RECT2D_H_ */
