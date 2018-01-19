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

#ifndef JETFUELGUI_PROGRESSBAR_H_
#define JETFUELGUI_PROGRESSBAR_H_

#include <jetfuelgui/iclickable.h>

#include "../jetfueldraw/drawable.h"
#include "../jetfueldraw/sprite.h"
#include "../jetfueldraw/rectangle2dshape.h"


namespace jetfuel{
    namespace gui{
        class Progress_bar : public jetfuel::draw::Drawable,
        public jetfuel::draw::Rectangle_interface{
        public:
			/// \brief Default Constructor.
			///
			/// Default Constructor.
            Progress_bar(){}

            /// \brief Constructs a Progress_bar with a holder image,
			/// a color (for the bar), the borders of the holder image,
			/// and the max number of this Progress_bar's progress.
			///
			/// Sets a Progress_bar with a holder image,
			/// a color (for the bar), the borders of the holder image, 
			/// and the max number of this Progress_bar's progress
			/// (optional set to 100 by default).
			///
			/// \param jetfuel::draw::Image progressbarholderimage
			/// \param jetfuel::draw::Color progressbarcolor
			/// \param jetfuel::draw::Rect2d_int progressbarholderborders
			/// \param unsigned int progressbarmax
            Progress_bar(const jetfuel::draw::Image progressbarholderimage, 
                         const jetfuel::draw::Color progressbarcolor,
                         const jetfuel::draw::Rect2d_int progressbarholderborders,
                         const unsigned int progressbarmax = 100);

			/// \brief Sets a Progress_bar with a holder image,
			/// a color (for the bar), the borders of the holder image,
			/// and the max number of this Progress_bar's progress.
			///
			/// Sets a Progress_bar with a holder image,
			/// a color (for the bar), the borders of the holder image, 
			/// and the max number of this Progress_bar's progress
			/// (optional set to 100 by default).
			///
			/// This function is useful when you used the default
			/// constructor.
			///
			/// \param jetfuel::draw::Image progressbarholderimage
			/// \param jetfuel::draw::Color progressbarcolor
			/// \param jetfuel::draw::Rect2d_int progressbarholderborders
			/// \param unsigned int progressbarmax
            void Set_progress_bar(const jetfuel::draw::Image progressbarholderimage, 
                                  const jetfuel::draw::Color progressbarcolor,
                     const jetfuel::draw::Rect2d_int progressbarholderborders,
                                  const unsigned int progressbarmax = 100);
            
			/// \brief Gets this Progress_bar's progress.
			///
			/// Gets this Progress_bar's progress.
			/// This progress is shown to the user via a colored 
			/// rectangle inside the progress bar holder sprite.
            unsigned int Get_progress_bar_progress() const{
                return m_progressbarprogress;
            }

			/// \brief Sets this Progress_bar's progress.
			///
			/// Sets this Progress_bar's progress.
			/// This progress is shown to the user via a colored 
			/// rectangle inside the progress bar holder sprite.
			///
			/// If a number is given beyond the max number,
			/// it will take cap the value at the max value.
			///
			/// \param unsigned int progressbarprogress
            void Set_progress_bar_progress(const unsigned int 
                                           progressbarprogress){
                m_progressbarprogress = std::min<unsigned int>
                                        (m_progressbarmax,
                                        progressbarprogress);
            }
            
			/// \brief Gets the max progress bar progress.
			///
			/// Gets the max progress bar progress.
			///
			/// Any value given past this number will be
			/// capped at this value.
            unsigned int Get_max_progress_bar() const{
                return m_progressbarmax;
            }
            
			/// \brief Returns whether this Progress_bar
			/// has been completed.
			///
			/// Returns whether this Progress_bar
			/// has been completed
			/// (the progress is greater than or equal to the max
			/// progress).
            bool Has_progress_bar_completed(){
                return m_progressbarprogress >= m_progressbarmax;
            }
                  
			/// \brief Assigns a SDL Renderer to this Progress_bar's 
			/// objects.
			///
			/// Assigns a SDL Renderer to this Progress_bar's 
			/// objects.
			///
			/// It is recommmended to let jetfuel::draw::Scene and
			/// jetfuel::draw::Scene_manager call this rather than
			/// yourself unless you are not using either of them.
			///
			/// \param SDL_Renderer *renderer
            void Assign_renderer(SDL_Renderer *renderer)override{
                m_progressbarholder.Assign_renderer(renderer);
                m_progressbar.Assign_renderer(renderer);

                Set_assigned_renderer(true);
            }

            /// \brief Gets this Progress_bar's position.   
			///
			/// Gets this Progress_bar's position.
            jetfuel::draw::Vector2d_int Get_position()override{
                return m_progressbarholder.Get_position();
            }
            
			/// \brief Sets this Progress_bar's position.   
			///
			/// Sets this Progress_bar's position.
			///
			/// \param jetfuel::draw::Vector2d_int position
            void Set_position(jetfuel::draw::Vector2d_int position)override{
                m_progressbarholder.Set_position(position);
                
                m_progressbar.Set_position(Get_position()+
                  m_progressbarholderborders.Get_position());
                
                if(!m_progressbarholderdynamicloading){
                    m_progressbarmaxsize = (jetfuel::draw::Vector2d_int(
                     m_progressbarholder.Get_size_of_sprite().x-
                      m_progressbarholderborders.width,
                       m_progressbarholder.Get_size_of_sprite().y-
                         m_progressbarholderborders.height*2));
                }

            }
            
			/// \brief Gets the rect to be drawn when the function Draw
			/// is called.
			///
			/// Gets the rect to be drawn when the function Draw
			/// is called.
            jetfuel::draw::Rect2d_int Get_rect_to_draw()override{
                return m_progressbarholder.Get_rect_to_draw();
            }
                         
			/// \brief Draws this Progress_bar.
			///
			/// Draws this Progress_bar.
            bool Draw()override;
        protected:
			/// \brief Draws this Progress_bar's holder sprite.
			///
			/// Draws this Progress_bar's holder sprite.
            bool Draw_progress_bar_holder(){
                return m_progressbarholder.Draw();
            }
            
			/// \brief Draws this Progress_bar's colored rectangle 
			/// (the actual progress bar).
			///
			/// Draws this Progress_bar's colored rectangle 
			/// (the actual progress bar).
            bool Draw_progress_bar(){
                return m_progressbar.Draw();
            }

			/// \brief Gets the max size of the progress bar (in width).
			///
			/// Gets the max size of a progress bar (in width).
            int Get_max_progress_bar_width() const{
                return m_progressbarmaxsize.x;
            }

            /// \brief Sets the width of the progress bar.
			///
			/// Sets the width of the progress bar.
			///
			/// \param int width
            void Set_width_of_progress_bar(const int width){
                m_progressbar.Set_size(jetfuel::draw::Vector2d_int(width,
                m_progressbarmaxsize.y));
            }

			/// \brief Forces a refresh of the max size of
			/// the progress bar.
			///
			/// Forces a refresh of the max size of
			/// the progress bar.
            void Mark_progress_bar_size(){
                m_progressbarholderdynamicloading = false;

                Set_position(Get_position());
            }
        private:
            jetfuel::draw::Sprite m_progressbarholder; ///< The 
													   ///< progress 
													   ///< bar
													   ///< holder.
            bool m_progressbarholderdynamicloading = false; ///< Whether 
			                                                ///< to 
															///< dynamically
															///< load 
															///< the 
															///< progress
															///< bar 
															///< holder 
															///< image.
            jetfuel::draw::Rect2d_int m_progressbarholderborders; ///< The 
																  ///< progress 
																  ///< bar 
																  ///< holder 
																  ///< borders.
            
            jetfuel::draw::Rectangle_2d_shape m_progressbar; ///< The 
															 ///< progress 
															 ///< bar.
            jetfuel::draw::Vector2d_int m_progressbarmaxsize; ///< The
															  ///< max
															  ///< size
														   	  ///< of a
															  ///< progress
															  ///< bar
            unsigned int m_progressbarprogress = 0; ///< The amount of
													///< progress in 
													///< the progress 
													///< bar.
            unsigned int m_progressbarmax; ///< The max amount of 
										   ///< progress in the 
										   ///< progress bar.
        };
		/// \class jetfuel::gui::Progress_bar
		///
		/// A simple progress bar with a holder sprite and a colored 
		/// rectangle representing the progress bar.
		///
		/// Code Example:
		///		jetfuel::draw::Scene_manager scenemanager;
        ///     jetfuel::draw::Scene scene1(1);
        ///     jetfuel::core::Message_bus messagebus;
		///     jetfuel::draw::Image progressbarholderimage(
		///												"progressbarholder.png",
		///                                      		  &scenemanager);
        ///     jetfuel::gui::Progress_bar progressbar(progressbarholderimage,
		///                                       jetfuel::draw::Color::Green,
		///										  jetfuel::draw::Rect2d_int(20,
		///														20,20,20),400);
        ///
        ///     if(!scenemanager.Create_window("Hello Progressbars!",
        ///                                    jetfuel::draw::Vector2d_int(0,0),
        ///                               jetfuel::draw::Vector2d_int(640,480))){
        ///         std::cout << "[!]ERROR with creating sdl window! Error is:"
        ///         << SDL_GetError() << "\n";
        ///     }
        ///
        ///     if(!scenemanager.Create_renderer()){
        ///         std::cout << "[!]ERROR with creating sdl renderer! Error is:"
        ///         << SDL_GetError() << "\n";
        ///     }
        ///     scenemanager.Switch_current_scene(&scene1);
        ///     scene1.Attach_drawable(&progressbar,1);
        ///
        ///     progressbar.Set_position(jetfuel::draw::Vector2d_int(0,0));
        ///
		///		progressbar.Set_progress_bar_progress(200);
        ///
        ///     scenemanager.Draw_current_scene();
    }
}

#endif /* JETFUELGUI_PROGRESSBAR_H_ */
