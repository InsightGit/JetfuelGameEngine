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
			Text_box(int maxchars = 20);

			bool Is_focused_on() const{
				return m_focusedon;
			}

			void Assign_renderer(SDL_Renderer *renderer)override{
				m_textentered.Assign_renderer(renderer);
				m_textrectanglebox.Assign_renderer(renderer);
			}

			jetfuel::draw::Text::Text_characteristics
			Get_text_box_text_characteristics() const{
				return m_textboxtextchars;
			}

			void Set_text_box_text_characteristics(jetfuel::draw::Text::
										Text_characteristics textchars){
				m_textboxtextchars = textchars;

				m_textentered.Set_render_mode(textchars.rendermode);
				m_textentered.Set_text_color(textchars.textcolor);
				m_textentered.Set_background_color(textchars.backgroundcolor);
				m_textentered.Set_font_outline_width(textchars.fontoutlinewidth);
				m_textentered.Set_kerning_status(textchars.kerningstatus);
				m_textentered.Set_font_style(textchars.fontstyle);
				m_textentered.Set_font_size(textchars.fontsize);
				m_textentered.Set_font_hinting(textchars.fonthinting);
				m_textentered.Set_font(textchars.font);
			}

			void Set_text_box_box_fill_color(jetfuel::draw::Color fillcolor){
				m_textrectanglebox.Set_fill_color(fillcolor);
			}

			jetfuel::draw::Vector2d_int Get_position()override{
				return m_textrectanglebox.Get_position();
			}

			void Set_position(const jetfuel::draw::Vector2d_int
							  position)override{
				m_textentered.Set_position(position);
				m_textrectanglebox.Set_position(position);
			}

			jetfuel::draw::Rect2d_int Get_rect_to_draw()override{
				return m_textrectanglebox.Get_rect_to_draw();
			}

			int Get_max_char_limit() const {
				return m_maxchars;
			}

			void Set_max_char_limit(int maxchars) {
				m_maxchars = maxchars;

				Update_box_size();
			}

			void Check_for_clicks(jetfuel::control::Action
                                  UISinterpreterdata)override;

			void Process_text_input_event(SDL_Event *event);

			bool Draw()override;
		protected:
			void Update_box_size(){
				if(m_maxchars > 0){
					// Constrain max amount of characters.
					m_textrectanglebox.Set_size(jetfuel::draw::Vector2d_int(
									(m_maxchars+1)*m_textboxtextchars.fontsize,
									m_textboxtextchars.fontsize));
									//^ m_maxchars+1 for extra space.
				}else{
					// Don't constrain max amount of characters
					// through scrolling.
					// TODO(Bobby): Support scrolling for no max char \
					// limit.
				}
			}
		private:
			int m_maxchars;
			bool m_focusedon = false;

			std::string m_currenttext;

			jetfuel::draw::Text::Text_characteristics m_textboxtextchars;
			jetfuel::draw::Text m_textentered;
			jetfuel::draw::Rectangle_2d_shape m_textrectanglebox;
		};
	}
}

#endif
