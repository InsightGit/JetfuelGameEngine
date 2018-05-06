/*
 * textbox.cpp
 *
 *  Created on: May 2, 2018
 *      Author: bobby
 */

#include <jetfuelgui/textbox.h>

namespace jetfuel{
	namespace gui{
		Text_box::Text_box(int maxchars){
			m_textrectanglebox.Set_outline_color(jetfuel::draw::Color::Black);

			m_maxchars = maxchars;

			Update_box_size();
		}

		void Text_box::Process_text_input_event(SDL_Event *event){
			bool updatetext = false;

			if(event->type == SDL_KEYDOWN){
				if(event->key.keysym.sym == SDLK_BACKSPACE &&
					m_currenttext.length() > 0){
					m_currenttext.pop_back();
					updatetext = true;
				}
			}else if(event->type == SDL_TEXTINPUT){
				m_currenttext += event->text.text;
				updatetext = true;
			}

			if(updatetext){
				m_textentered.Set_string(m_currenttext);
			}
		}

		void Text_box::Check_for_clicks(jetfuel::control::Action
							  UISinterpreterdata){
			if(UISinterpreterdata.inputstate ==
			   jetfuel::control::Action::Input_state::Down &&
			   UISinterpreterdata.inputtype ==
			   jetfuel::control::Action::Input_type::Mouse){
				// If clicked down with a mouse...
				jetfuel::draw::Color rectangleoutlinecolor;

				if(Get_rect_to_draw().Has_mouse_collided()){
					// Clicked on this Text_box. Focused on this text box.
					rectangleoutlinecolor = jetfuel::draw::Color::Cyan;
					SDL_StartTextInput();
				}else{
					// Clicked on something else. not focused on this
					// text box.
					rectangleoutlinecolor = jetfuel::draw::Color::Black;
					SDL_StopTextInput();
				}


				m_textrectanglebox.Set_outline_color(rectangleoutlinecolor);
				m_focusedon = Get_rect_to_draw().Has_mouse_collided();
			}
		}

		bool Text_box::Draw(){
			return m_textrectanglebox.Draw() && m_textentered.Draw();
		}
	}
}
