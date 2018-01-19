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

#ifndef JETFUELDRAW_IMAGE_H_
#define JETFUELDRAW_IMAGE_H_

#ifdef __linux__
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
#else
	#include <SDL.h>
	#include <SDL_image.h>
#endif

#include <jetfueldraw/scenemanager.h>
#include <jetfueldraw/vector2d.h>

#include <string>


namespace jetfuel {
    namespace draw {
        class Image {
        public:
            /// \brief Default constructor
            ///
            /// Initializes an Image with an image path 
            /// and an image size to be set later.
            Image(){}

            /// \brief Constructs an image with an image path 
            /// and a scene manager.
            ///
            /// Initializes an Image with an image path and 
            /// an scene manager,
            /// so that the image is ready to be used by a Sprite.
            ///
            /// \param std::string imagepath
            /// \param jetfuel::draw::Scene_manager *scenemanager
            Image(const std::string imagepath, Scene_manager *scenemanager);

            /// \brief Constructs an image with
            /// an image path and an image size,
            /// without the need of a Scene_manager.
            ///
            /// Constructs an image with an image
            /// path and an image size,
            /// without the need of a Scene_manager so that an image
            /// is ready to be used by a Sprite.
            ///
            /// \param std::string imagepath
            /// \param jetfuel::draw::Vector2d_int imagesize
            Image(const std::string imagepath, const Vector2d_int imagesize);

            /// \brief Sets an image path and a scene manager.
            ///
            /// Sets an image path and an scene manager after an Image
            /// has been constructed.
            /// This function is especially useful when using the
            /// default constructor, as you need to set the image path
            /// and a scene manager or image size later.
            ///
            /// \param std::string imagepath
            /// \param jetfuel::draw::Scene_manager *scenemanager
            void Set_image(const std::string imagepath,
                           Scene_manager *scenemanager);

            /// \brief Sets an image with
            /// an image path and an image size,
            /// without the need of a Scene_manager.
            ///
            /// Sets an image with an image
            /// path and an image size,
            /// without the need of a Scene_manager so that an image
            /// is ready to be used by a Sprite.
            ///
            /// This function is especially useful when using the
            /// default constructor, as you need to set the image path
            /// and a scene manager or image size later.
            ///
            /// \param std::string imagepath
            /// \param jetfuel::draw::Vector2d_int imagesize
            void Set_image(const std::string imagepath, 
                           const Vector2d_int imagesize);

            /// \brief Returns the image's location
            ///
            /// Returns the image's location (or path) to load in 
            /// a Sprite.
            std::string Get_image_location() const {
                return m_imagepath;
            }

            /// \brief Returns the image's size (in pixels)
            ///
            /// Returns the image's size as given as calculated
            /// with a Scene_manager or given to this class via an
            /// argument.
            jetfuel::draw::Vector2d_int Get_size_of_image() const {
                return m_sizeofimage;
            }

            /// \brief Gets SDL_image error, if any.
            ///
            /// Gets SDL_image error, if any. This function is useful
            /// to call when something goes wrong with this 
            /// Image class.
            std::string Get_error(){
                return IMG_GetError();
            }

        protected:
            /// \brief Sets the image location.
            ///
            /// Sets the image file location to be used when loading
            /// this image.
            ///
            /// \param std::string imagelocation
            void Set_image_location(const std::string imagelocation) {
                m_imagepath = imagelocation;
            }

            /// \brief Sets the size of the image.
            ///
            /// Sets the size of the image to be used when drawing and
            /// positioning this image.
            ///
            /// \param Vector2d_int imagesize
            void Set_size_of_image(const Vector2d_int imagesize) {
                m_sizeofimage = imagesize;
            }
        private:
            ///////////////////
            /// Member data ///
            ///////////////////

            std::string m_imagepath; ///< Image path (or location)
            jetfuel::draw::Vector2d_int m_sizeofimage; ///< Size of
                                                       ///< image (in
                                                       ///< pixels)
        };

        /// \class jetfuel::draw::Image
        ///
        /// A image to be used with a Sprite to display images.
        /// This image is a simple wrapper to be used with a Sprite that
        /// stores the filepath of an image and the size of an image.
        ///
        /// Code Example:
        ///     jetfuel::draw::Scene_manager scenemanager;
        ///     jetfuel::draw::Scene scene1(1);
        ///     jetfuel::draw::Image image = jetfuel::draw::Image("test.png",
        ///                                                 &scenemanager);
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
        ///     scene1.Attach_drawable(&background,1);
        ///
        ///     if(!background.Load_from_image(backgroundimage)){
        ///         std::cerr << "[!]ERROR with loading from image! Error is:"
        ///         << backgroundimage.Get_error << "\n";
        ///
        ///         return 1;
        ///     }
        ///
        ///     background.Set_position(jetfuel::draw::Vector2d_int(0,0));
        ///
        ///     scenemanager.Draw_current_scene();

    } /* namespace draw */
} /* namespace jetfuel */

#endif /* JETFUELDRAW_IMAGE_H_ */
