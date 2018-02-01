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


#ifndef JETFUELDRAW_SCENE_H_
#define JETFUELDRAW_SCENE_H_

#include <algorithm>
#include <iterator>

//#include <boost/ptr_container/ptr_vector.hpp>

#include <jetfueldraw/color.h>
#include <jetfueldraw/drawable.h>

#include "../jetfuelcore/messagebus.h"


namespace jetfuel {
    namespace draw {
        class Scene {
        public:
            /// \brief Constructs a Scene with a Scene id.
            ///
            /// Constructs a Scene with an optional Scene id and label
            /// for categorization.
            ///
            /// \param int id
            Scene(const int id = 0, const std::string label = "");

            /// \brief Cleans up Scene objects.
            ///
            /// Cleans up Scene objects.
            virtual ~Scene();

            /// \brief Attaches a Drawable to the Scene.
            ///
            /// Attaches a Drawable's reference and a drawingweight
            /// to the Scene to be drawn upon
            /// the function Draw_scene() being called.
            /// Lower drawingweights are drawn lower,
            /// and might overlap with another
            /// higher weighted Drawable. Sprites on the
            /// same drawingweight
            /// will be overlapped by Rectangle_2d_shapes and Texts.
            ///
            /// \param Drawable *drawable
            /// \param unsigned int drawingweight
            bool Attach_drawable(Drawable *drawable,
                                 const unsigned int drawingweight);

            /// \brief Disables a Drawable already attached to the
            /// Scene.
            ///
            /// Disables a Drawable already attached to the Scene.
            /// This associates that Drawable with a bool of false
            /// in a Drawable status vector, which dictates whenever
            /// a certain Drawable should be drawed. This allows you
            /// to re-enable this Drawable any time by calling the
            /// Enable_drawable function. If the drawable passed in
            /// is not found in this Scene object, this function will
            /// not do anything
            ///
            /// \param Drawable *drawable
            void Disable_drawable(Drawable *drawable);

            void Enable_drawable(Drawable *drawable);

            /// \brief Returns the Scene's id.
            ///
            /// Returns the Scene's id.
            int Get_scene_id() const {
                return m_id;
            }

            /// \brief Gets the scene's background color.
            ///
            /// Gets the scene's background color. This color will
            /// be black by default if it has not been set.
            Color Get_background_color() const {
                return m_backgroundcolor;
            }

            /// \brief Sets the background color of the Scene.
            ///
            /// Sets the background color of the Scene.
            /// If set, this background color will override the
            /// universal background color set by the 
            /// jetfuel::draw::Scene_manager and will trigger a change
            /// of the background color during when the Scene is 
            /// displayed.
            ///
            /// \param Color backgroundcolor
            void Set_background_color(const Color backgroundcolor) {
                m_backgroundcolor = backgroundcolor;
                m_backgroundcolorset = true;
            }

            /// \brief Clears the Scene of any previously 
            /// attached objects.
            ///
            /// Clears the scene of any previously attached 
            /// drawable objects.
            void Reset_scene(){
                m_drawables.clear();
            }

            /// \brief Assigns a renderer to use when rendering 
            /// a Sprite.
            ///
            /// Assigns a renderer to use when rendering a Drawable.
            /// This function should be called by a 
            /// Scene_manager upon switching scenes.
            ///
            /// \param SDL_Renderer *scenemanagerrenderer
            void Assign_renderer(SDL_Renderer *scenemanagerrenderer){
                m_scenemanagerrenderer = scenemanagerrenderer;
            }

            /// \brief Draws the Scene.
            ///
            /// Draws the Scene by drawing all of the attached
            /// drawable objects.
            /// This function should be called by a 
            /// jetfuel::draw::Scene_manager upon the function
            /// jetfuel::draw::Scene_manager::Draw_current_scene()
            /// being called.
            void Draw_scene();
        protected:
            /// \brief Returns the scene manager's renderer.
            ///
            /// Returns the scene manager's renderer.
            /// This function should be used after a scene is attached
            /// to a Scene_manager.
            SDL_Renderer* Get_scene_manager_renderer() const {
                return m_scenemanagerrenderer;
            }

            /// \brief Returns the size of the internal
            /// m_drawables vector.
            ///
            /// Returns the size of the internal private
            /// m_drawabless vector.
            size_t Get_size_of_drawables_vector() const{
                return m_drawables.size();
            }

            /// \brief Returns a Drawable's reference in the
            /// internal m_drawables vector.
            ///
            /// Returns a Drawable's reference in the
            /// internal private m_drawables vector.
            /// If place is not in the Drawable's vector range,
            /// this function will throw a jetfuel::core::exceptions
            /// ::Out_of_vector_range_exception().
            /// Otherwise, it will return that Drawable's reference.
            ///
            /// \param size_t place
            Drawable *Get_drawable_in_vector(size_t place){
                if(m_drawables.size() <= place){
                    // Not in vector range... throw 
                    // Out_of_vector_range_exception
                    throw jetfuel::core::exceptions::
                    Out_of_vector_range_exception();
                }else{
                    Drawable *returnvalue = m_drawables[place];

                    return returnvalue;
                }
            }

            /// \brief Gets Drawable's placement
            /// (or drawingweight) in vector.
            ///
            /// Gets Drawable's placement
            /// (or drawingweight) in vector.
            /// If this function is given
            /// a place that is bigger or equal to the vector's size,
            /// this function will throw a jetfuel::core::exceptions
            /// ::Out_of_vector_range_exception() exception.
            /// Otherwise, this function will return that Drawable's
            /// placement.
            ///
            /// \param size_t place
            unsigned int Get_drawable_placement_in_vector(size_t place){
                if(m_drawablesplacement.size() <= place){
                    // Not in vector range... throw 
                    // Out_of_vector_range_exception
                    throw jetfuel::core::exceptions::
                    Out_of_vector_range_exception();
                }else{
                    return m_drawablesplacement[place];
                }
            }

            /// \brief Adds a Drawable placement (or drawingweight) to
            /// the Drawable placement vector.
            ///
            /// Adds a Drawable placement (or drawingweight) to
            /// the Drawable placement vector.
            ///
            /// \param unsigned int placement
            void Add_drawable_placement_to_drawable_placement_vector(
            const unsigned int placement){
                if(placement>m_highestplacement){
                    m_highestplacement = placement;
                }

                m_drawablesplacement.push_back(placement);
            }

            /// \brief Gets the highest Drawable placement
            /// (or drawingweight) of the Drawable placement vector.
            ///
            /// Gets the highest Drawable placement
            /// (or drawingweight) of the Drawable placement vector.
            /// This value is pre-calculated whenever a new placement
            /// is added.
            unsigned int Get_highest_placement() const {
                return m_highestplacement;
            }


            /// \brief Adds a drawable to the scene.
            ///
            /// Adds a drawable to the scene to be drawn upon the
            /// the function Draw_scene() being called.
            ///
            /// \param Drawable *drawable
            void Add_drawable_to_drawable_vector(Drawable *drawable){
                m_drawables.push_back(drawable);
                m_drawablesenabled.push_back(true);
            }

            /// \brief Gets a Drawable's status in the
            /// drawablesenabled vector.
            ///
            /// Gets a Drawable's status in the drawablesenabled
            /// vector to determine whether the Drawable should be
            /// drawn or not.
            ///
            /// \param size_t place
            bool Get_drawable_status(size_t place) const{
                if(place >= m_drawablesenabled.size()){
                    throw jetfuel::core::exceptions::
                    Out_of_vector_range_exception();
                }else{
                    return m_drawablesenabled[place];
                }
            }

            /// \brief Enables a Drawable to be drawn when 
            /// Draw_scene is called.
            ///
            /// Enables a Drawable to be drawn when 
            /// Draw_scene is called.
            ///
            /// \param size_t place
            void Enable_drawable_in_vector(size_t place){
                if(place >= m_drawablesenabled.size()){
                    throw jetfuel::core::exceptions::
                     Out_of_vector_range_exception();
                }else{
                    m_drawablesenabled[place] = true;
                }
            }
            
            /// \brief Disables a Drawable to not be drawn when
            /// Draw_scene is called.
            ///
            /// Disables a Drawable to not be drawn when 
            /// Draw_scene is called.
            ///
            /// \param size_t place
            void Disable_drawable_in_vector(size_t place){
                if(place >= m_drawablesenabled.size()){
                    throw jetfuel::core::exceptions::
                    Out_of_vector_range_exception();
                }else{
                    m_drawablesenabled[place] = false;
                }
            }

            /// \brief Checks whether the Scene's background color is
            /// set.
            ///
            /// Checks whether the Scene's background color is
            /// set.
            bool Is_background_color_set() const {
                return m_backgroundcolorset;
            }
        private:
            ///////////////////
            /// Member data ///
            ///////////////////

            int m_id; ///< The Scene's id

            std::string m_label; ///< The Scene's label

            unsigned int m_highestplacement = 0; ///< highest Drawable
                                                 ///<  placement (or
                                                 ///< drawingweight)
                                                 ///< number.

            bool m_backgroundcolorset = false; ///< Whether the
                                               ///< background color
                                               ///< has been set or
                                               ///< not.

            std::vector<bool> m_drawablesenabled; ///< Whether this
                                                  ///< Drawable should
                                                  ///< be drawn.

            std::vector<unsigned int> m_drawablesplacement; ///< Drawable
                                                            ///< placement
                                                            ///< vector.

            std::vector<Drawable*> m_drawables; ///< A
                                               ///< pointer
                                               ///< vector of
                                               ///< Drawables to
                                               ///< draw.

            SDL_Renderer *m_scenemanagerrenderer; ///< A reference
                                                  ///< to the
                                                  ///< scene manager's
                                                  ///< renderer.

            Color m_backgroundcolor; ///< The background's color.
        };

        /// \class jetfuel::draw::Scene
        ///
        /// A scene to be used with Scene_manager to produce a series
        /// of drawable scenes to be presented to the player.
        ///
        /// Code Example:
        ///     jetfuel::draw::Scene_manager scenemanager;
        ///     jetfuel::draw::Scene scene1(1);
        ///     jetfuel::draw::Image image = jetfuel::draw::Image("test.png");
        ///     jetfuel::draw::Sprite background;
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
        ///     scenemanager.Switch_current_scene(&scene1);
        ///     scene1.Attach_drawable(&background);
        ///
        ///     if(!background.Load_from_image(backgroundimage)){
        ///         std::cerr << "[!]ERROR with loading from image! Error is:" << IMG_GetError() << "\n";
        ///         return 1;
        ///     }
        ///
        ///     background.Set_position(jetfuel::draw::Vector2d_int(0,0));
        ///
        ///     scenemanager.Draw_current_scene();

    } /* namespace draw */
} /* namespace jetfuel */

#endif /* JETFUELDRAW_SCENE_H_ */
