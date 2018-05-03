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
		}

		void Text_box::Update_text(){
			keyboardaction.action
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
				}else{
					// Clicked on something else. not focused on this
					// text box.
					rectangleoutlinecolor = jetfuel::draw::Color::Black;
				}


				m_textrectanglebox.Set_outline_color(rectangleoutlinecolor);
				m_focusedon = Get_rect_to_draw().Has_mouse_collided();
			}
		}

		void Text_box::Draw(){
			//
		}
	}
}
