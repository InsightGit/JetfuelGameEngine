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

#ifndef JETFUELDRAW_DRAWABLE_H_
#define JETFUELDRAW_DRAWABLE_H_

#ifdef __linux__
	#include <SDL2/SDL.h>
    #include <boost/uuid/uuid.hpp>
    #include <boost/uuid/uuid_generators.hpp>
#else
	#include <SDL.h>
    #include <Guid.hpp>
#endif

#include <jetfueldraw/rect2d.h>

namespace jetfuel {
    namespace draw {
        class Drawable {
        public:
			virtual ~Drawable() {};

            /// \brief Returns internal m_position variable.
            ///
            /// Returns private internal m_position
            /// variable used for positioning.
            virtual Vector2d_int Get_position(){
                return m_position;
            }

            /// \brief Set the internal m_position variable.
            ///
            /// Set the internal private m_position variable
            /// used for positioning.
            ///
            /// \param Vector2d_int position
            virtual void Set_position(const Vector2d_int position){
                m_position = position;

                m_dest.x = m_position.x;
                m_dest.y = m_position.y;
            }

            /// \brief Using the Drawable's UUID, compare this
            /// Drawable with another.
            ///
            /// Using the Drawable's UUID, compare this Drawable with
            /// another. The UUID ensures that different Drawables
            /// with the same exact position and renderer don't get
            /// falsely marked as equals.
            ///
            /// \param Drawable &drawable
            bool operator ==(Drawable &drawable){
                return m_guid == drawable.m_guid;
            }

            /// \brief Returns whether this Drawable was assigned a
            /// renderer.
            ///
            /// Returns whether this Drawable was assigned a renderer
            /// based on a internal private boolean variable set to
            /// true when the function Assign_renderer has been called
            /// and false otherwise.
            bool Assigned_renderer() const{
                return m_rendererset;
            }

            /// \brief Assigns the renderer to be used by
            /// the object.
            ///
            /// Assigns the renderer to be used by the
            /// object while drawing.
            ///
            /// This function should only be used by the
            /// Scene_manager if you are using the Scene_manager and
            /// Scene objects.
            ///
            /// \param SDL_Renderer *renderer
            virtual void Assign_renderer(SDL_Renderer *renderer){
                m_renderer = renderer;

                m_rendererset = true;
            }

            /// \brief Draws the object.
            ///
            /// This function (which should draw the object)
            /// is a pure virtual one that must be implemented
            /// by any class that inherits this class.
            virtual bool Draw() = 0;
        protected:
            /// \brief Gets the internal destination SDL_Rect
            /// variable.
            ///
            /// Gets the internal private destination SDL_Rect
            /// variable to be used when drawing
            /// sand positioning a Drawable.
            SDL_Rect Get_dest() const {
                return m_dest;
            }

            /// \brief Sets the internal destination SDL_Rect
            /// variable.
            ///
            /// Sets the internal private destination SDL_Rect
            /// variable to be used when drawing
            /// and positioning a Drawable.
            ///
            /// \param SDL_Rect dest
            void Set_dest(const SDL_Rect dest) {
                m_dest = dest;
            }

            /// \brief Sets the variable that tells whether the
            /// renderer was assigned or not.
            ///
            /// Sets the variable that tells whether the
            /// renderer was assigned or not.
            ///
            /// \param bool rendererassigned
            void Set_assigned_renderer(bool rendererassigned){
                m_rendererset = rendererassigned;
            }

            /// \brief Gets the renderer to be used for
            /// drawing.
            ///
            /// Gets the renderer to be used for drawing
            /// purposes.
            virtual SDL_Renderer *Get_renderer(){
                return m_renderer;
            }
        private:
            ///////////////////
            /// member data ///
            ///////////////////

            SDL_Renderer *m_renderer;///< Renderer to be used for
                                     ///< drawing.

            bool m_rendererset = false;///< Whether the renderer was
                                       ///< set or not.

            SDL_Rect m_dest;///< SDL dest rect for drawing and
                            ///< positioning.
            #ifdef __linux__
                boost::uuids::uuid m_guid =
                boost::uuids::uuid(boost::uuids::random_generator()());
                                                                       ///< Boost
                                                                       ///< GUID
                                                                       ///< used
                                                                       ///< for
                                                                       ///< uniquely
                                                                       ///< identifying
                                                                       ///< Drawables
            #else
			    xg::Guid m_guid = xg::newGuid(); ///< Random crossguid GUID used
											     ///< for uniquely identifying
											     ///< Drawables
            #endif

            Vector2d_int m_position;  
                                    ///< Position to be used for
                                    ///< positioning.
        };

        /// \class jetfuel::draw::Drawable
        ///
        /// A simple header-only base class that provides a base
        /// if you want to make a sprite that uses the renderer.
        ///
        /// You must inherit from this class if you want to draw it
        /// to the screen via jetfuel::draw::Scene.
        ///
        /// \see jetfuel::draw::Sprite
        /// \see jetfuel::draw::Text
        /// \see jetfuel::draw::Rectangle_2d_shape

    } /* namespace draw */
} /* namespace jetfuel */

#endif /* JETFUELDRAW_DRAWABLE_H_ */
