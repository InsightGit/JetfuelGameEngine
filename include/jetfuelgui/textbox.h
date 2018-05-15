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
#ifndef JETFUELGUI_TEXTBOX_H_
#define JETFUELGUI_TEXTBOX_H_
#include <jetfuelgui/iclickable.h>

#include <jetfueldraw/drawable.h>
#include <jetfueldraw/rectangle2dshape.h>
#include <jetfueldraw/text.h>

namespace jetfuel{
	namespace gui{
		class Text_box : public jetfuel::draw::Drawable, public IClickable,
							   public jetfuel::draw::Rectangle_interface{
		public:
			/// \brief Constructs a Text_box with a max character
			/// limit.
			///
			/// Constructs a Text_box with a max character limit.
			/// By default, the limit is 20 characters.
			///
			/// \param maxchars
			Text_box(int maxchars = 20);

			/// \brief Returns whether this Text_box is focused on or not.
			///
			/// Returns whether this Text_box is focused on or not.
			bool Is_focused_on() const{
				return m_focusedon;
			}

			/// \brief Assigns a renderer to this Text_box.
			///
			/// Assigns a renderer to this Text_box. Unless you are
			/// not using jetfuel::draw::Scene_manager and/or
			/// jetfuel::draw::Scene, you should not need to call this
			/// function directly.
			///
			/// \param SDL_Renderer *renderer
			void Assign_renderer(SDL_Renderer *renderer)override{
				m_textentered.Assign_renderer(renderer);
				m_textrectanglebox.Assign_renderer(renderer);
			}

			/// \brief Gets this Text_box's text characteristics.
			///
			/// Gets this Text_box's text characteristics, which
			/// defines the entered text's appearance.
			jetfuel::draw::Text::Text_characteristics
			Get_text_box_text_characteristics() const{
				return m_textboxtextchars;
			}

			/// \brief Gets this Text_box's text characteristics.
			///
			/// Gets this Text_box's text characteristics, which
			/// defines the entered text's appearance. This method
			/// does not use jetfuel::draw::Text::Text_characteristics'
			/// textstring variable.
			///
			/// \param jetfuel::draw::Text::Text_characteristics \
			/// textchars
			void Set_text_box_text_characteristics(jetfuel::draw::Text::
										Text_characteristics textchars){
				m_textboxtextchars = textchars;

				m_textentered.Set_font(textchars.font);
				m_textentered.Set_render_mode(textchars.rendermode);
				m_textentered.Set_text_color(textchars.textcolor);
				m_textentered.Set_background_color(textchars.backgroundcolor);
				m_textentered.Set_font_outline_width(textchars.fontoutlinewidth);
				m_textentered.Set_kerning_status(textchars.kerningstatus);
				m_textentered.Set_font_style(textchars.fontstyle);
				m_textentered.Set_font_size(textchars.fontsize);
				m_textentered.Set_font_hinting(textchars.fonthinting);

				// Refresh position to update x
				Set_position(Get_position());
			}

			/// \brief Gets this Text_box rectangular box's fill color.
			///
			/// Gets this Text_box background rectangular box's fill
			/// color.
			jetfuel::draw::Color Get_text_box_box_fill_color(){
				return m_textrectanglebox.Get_fill_color();
			}

			/// \brief Sets this Text_box rectangular box's fill color.
			///
			/// Sets this Text_box background rectangular box's fill
			/// color.
			///
			/// \param jetfuel::draw::Color fillcolor
			void Set_text_box_box_fill_color(jetfuel::draw::Color fillcolor){
				m_textrectanglebox.Set_fill_color(fillcolor);
			}

			/// \brief Gets this Text_box's position.
			///
			/// Gets this Text_box's position.
			jetfuel::draw::Vector2d_int Get_position()override{
				return m_textrectanglebox.Get_position();
			}

			/// \brief Sets this Text_box's position.
			///
			/// Sets this Text_box's position.
			///
			/// \param jetfuel::draw::Vector2d_int position
			void Set_position(const jetfuel::draw::Vector2d_int
							  position)override{
				m_textrectanglebox.Set_position(position);

				// Put m_textentered at the box plus it's size for x,
				// and center of the box's height.

				m_textentered.Set_position(jetfuel::draw::Vector2d_int(position.x
									+ m_textentered.Get_font_size(),
									m_textrectanglebox.Get_rect_to_draw().
									height/2 - m_textentered.Get_font_size()));
			}

			/// \brief Gets this Text_box's rectangle to be drawn upon
			/// the Draw function being called.
			///
			/// Gets this Text_box rectangle to be drawn upon
			/// the Draw function being called.
			jetfuel::draw::Rect2d_int Get_rect_to_draw()override{
				return m_textrectanglebox.Get_rect_to_draw();
			}

			/// \brief Gets this Text_box's maximum character limit.
			///
			/// Gets this Text_box's maximum character limit.
			int Get_max_char_limit() const {
				return m_maxchars;
			}

			/// \brief Sets this Text_box's maximum character limit.
			///
			/// Sets this Text_box's maximum character limit. If the
			/// max character limit is set to a negative number,
			/// it will treat it as no character limit.
			///
			/// \param int maxchars
			void Set_max_char_limit(int maxchars) {
				m_maxchars = maxchars;
			}

			/// \brief Gets this Text_box's current entered text.
			///
			/// Gets this Text_box's current entered text.
			std::string Get_current_text(){
				return m_currenttext;
			}

			/// \brief Checks this Text_box for any clicks on it.
			///
			/// Checks this Text_box for any clicks on it modifying
			/// it's focus status.
			///
			/// \param jetfuel::control::Action UISinterpreterdata
			void Check_for_clicks(jetfuel::control::Action
                                  UISinterpreterdata)override;

			/// \brief Processes any SDL_TextInput events passed
			/// in, updating the text displayed if necessary.
			///
			/// Processes any SDL_TextInput events passed
			/// in, updating the text displayed if necessary.
			///
			/// \param SDL_Event *event
			void Process_text_input_event(SDL_Event *event);

			/// \brief Draws this Text_box onto the screen.
			///
			/// Draws this Text_box onto the screen.
			bool Draw()override;
		protected:
			/// \brief Updates this Text_box's rectangle box size.
			///
			/// Updates this Text_box's rectangle box size.
			void Update_box_size(){
				if(m_maxchars > 0){
					// Constrain max amount of characters.
					m_textrectanglebox.Set_size(jetfuel::draw::Vector2d_int(
									(m_maxchars+1)*m_textentered.Get_font_size(),
									m_textboxtextchars.fontsize*3));
									//^ m_maxchars+1 for extra space.
				}else{
					// Don't constrain max amount of characters
					// through scrolling.
					// TODO(Bobby): Support scrolling for no max char \
					// limit.
				}
			}
		private:
			int m_maxchars; ///< Max character limit.
			bool m_focusedon = false; ///< Whether this Text_box is
									  ///< focused on.

			std::string m_currenttext; ///< The current entered text
			 	 	 	 	 	 	   ///< string.

			jetfuel::draw::Text::Text_characteristics
						m_textboxtextchars; ///< This Text_box's
										 ///< Text_characteristics for
										 ///< m_enteredtext.
			jetfuel::draw::Text m_textentered; ///< Text representative
			 	 	 	 	 	 	 	 	   ///< of m_enteredtext.
			jetfuel::draw::Rectangle_2d_shape
								m_textrectanglebox; ///< Encapsulates
												 ///< m_enteredtext.
		};
		/// \class jetfuel::gui::Text_box
		///
		/// A simple Text box that, when focused on, records and
		/// displays text entered into it. That displayed text can be
		/// easily retrieved by calling Get_current_text().
		///
		/// Code Example:
		///
		/// \code
		/// jetfuel::draw::Scene_manager scenemanager;
		/// jetfuel::draw::Scene scene1(1);
		/// jetfuel::core::Message_bus messagebus;
		/// jetfuel::gui::Text_box textbox;
		/// jetfuel::control::UIS_manager UISmanager(&messagebus,
		///                                       scenemanager.Get_window_id());
		/// jetfuel::control::UIS_interpreter UISinterpreter(&messagebus);
		/// jetfuel::draw::Text::Text_characteristics textchars;
		/// jetfuel::draw::Font font("default.ttf");
		///
		/// if(!scenemanager.Create_window("Hello Text_boxes!",
		///                                jetfuel::draw::Vector2d_int(0,0),
		///                               jetfuel::draw::Vector2d_int(640,480))){
		///     std::cout << "[!]ERROR with creating sdl window! Error is:"
		///       << SDL_GetError() << "\n";
		/// }
		///
		/// if(!scenemanager.Create_renderer()){
		///    std::cout << "[!]ERROR with creating sdl renderer! Error is:"
		///         << SDL_GetError() << "\n";
		/// }
		/// scenemanager.Switch_current_scene(&scene1);
		/// scene1.Attach_drawable(&textbox,1);
		///
		/// textbox.Set_position(jetfuel::draw::Vector2d_int(0,0));
		///
		/// textchars.font = font;
		/// textbox.Set_text_box_box_fill_color(jetfuel::draw::Color::Black);
		///
		/// textbox.Set_text_characteristics(textchars);
		///
		/// while(true){
		/// 	jetfuel::control::Action UISaction =
        ///     UISinterpreter.Interpret();
        ///
        /// 	textbox.Check_for_clicks(UISaction);
        /// 	for(int i = 0; messagebus.Get_SDL_events_size() > i; ++i){
		///			textbox.Process_text_input_event(messagebus.
		/// 										Get_SDL_event(i));
		/// 	}
        ///
		/// 	scenemanager.Draw_current_scene();
		/// }
		///
		/// \endcode
	}
}

#endif
