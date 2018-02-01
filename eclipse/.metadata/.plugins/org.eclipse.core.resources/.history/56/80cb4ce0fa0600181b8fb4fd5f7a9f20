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

#ifndef JETFUELDRAW_VECTOR2D_H_
#define JETFUELDRAW_VECTOR2D_H_

namespace jetfuel {
    namespace draw {
        template <class T>
        class Vector2d {
        public:
            /// \brief Constructs an empty Vector2d.
            ///
            /// Constructs an empty Vector2d with empty x and y
            /// coordinates.
            Vector2d(){}

            /// \brief Constructs a Vector2d with an x and y
            /// coordinates.
            ///
            /// Constructs a Vector2d with an x and y
            /// coordinates.
            ///
            /// \param T X
            /// \param T Y
            Vector2d(T X, T Y){
                x=X;
                y=Y;
            }
            ///////////////////
            /// member data ///
            ///////////////////

            T x; ///< x coordinate
            T y; ///< y coordinate
        };


        template <typename T>
        Vector2d<T> operator +(const Vector2d<T> left,const Vector2d<T> right){
            return Vector2d<T>(left.x + right.x, left.y + right.y);
        }

        template <typename T>
        Vector2d<T> operator +=(Vector2d<T> &left,const Vector2d<T> right){
            left.x += right.x;
            left.y += right.y;

            return left;
        }

        template <typename T>
        Vector2d<T> operator -(const Vector2d<T> left,const Vector2d<T> right){
            return Vector2d<T>(left.x - right.x, left.y - right.y);
        }

        template <typename T>
        Vector2d<T> operator -=(Vector2d<T> &left,const Vector2d<T> right){
            left.x -= right.x;
            left.y -= right.y;

            return left;
        }

        template <typename T>
        Vector2d<T> operator *(const Vector2d<T> left, const Vector2d<T> right){
            return Vector2d<T>(right.x * left.x, right.y * left.y);
        }

        template <typename T>
        Vector2d<T> operator *=(Vector2d<T> &left, const Vector2d<T> right){
            left.x * right.x;
            left.y * right.y;

            return left;
        }

        template <typename T>
        Vector2d<T> operator /(const Vector2d<T> left, const Vector2d<T> right){
            return Vector2d<T>(left.x/right.x, left.y/right.y);
        }

        template <typename T>
        Vector2d<T> operator /=(Vector2d<T> &left, const Vector2d<T> right){
            left.x /= right.x;
            left.y /= right.y;

            return left;
        }

        template <typename T>
        Vector2d<T> operator *(T left, const Vector2d<T> right){
            return Vector2d<T>(right.x * left, right.y * left);
        }

        template <typename T>
        Vector2d<T> operator *=(Vector2d<T> &left, const T right){
            left.x * right;
            left.y * right;

            return left;
        }

        template <typename T>
        Vector2d<T> operator /(const Vector2d<T> left, const T right){
            return Vector2d<T>(left.x/right, left.y/right);
        }

        template <typename T>
        Vector2d<T> operator /=(Vector2d<T> &left, const T right){
            left.x /= right;
            left.y /= right;

            return left;
        }

        template <typename T>
        Vector2d<T> operator +(const Vector2d<T> left, const T right){
            return Vector2d<T>(left.x + right, left.y + right);
        }

        template <typename T>
        Vector2d<T> operator +=(Vector2d<T> &left, const T right){
            left.x += right;
            left.y += right;

            return left;
        }

        template <typename T>
        Vector2d<T> operator -(const Vector2d<T> left,const T right){
            return Vector2d<T>(left.x - right, left.y - right);
        }

        template <typename T>
        Vector2d<T> operator -=(Vector2d<T> &left,const T right){
            left.x -= right;
            left.y -= right;

            return left;
        }

        template <typename T>
        bool operator ==(const Vector2d<T> left, const Vector2d<T> right){
            return (left.x == right.x) && (left.y == right.y);
        }

        template <typename T>
        bool operator !=(const Vector2d<T> left, const Vector2d<T> right){
            return (left.x != right.x) && (left.y != right.y);
        }

        ////////////////////////////////
        /// Common Vector2d typedefs ///
        ////////////////////////////////

        typedef Vector2d<unsigned int> Vector2d_uint;
        typedef Vector2d<int> Vector2d_int;
        typedef Vector2d<float> Vector2d_float;


        /// \class jetfuel::draw::Vector2d
        ///
        /// A simple 2d vector class that stores an x coordinate and a
        /// y coordinate. This class is used for the position of
        /// drawable objects on the screen in Jetfuel.
        ///
        /// Code Example:
        ///     Vector2d_int myvector(5,8);
        ///
        ///     std::cout << "My x coordinate is" << myvector.x <<
        ///                  "My y coordinate is" << myvector.y <<
        ///     std::endl;
    } /* namespace draw */

} /* namespace jetfuel */

#endif /* JETFUELDRAW_VECTOR2D_H_ */
