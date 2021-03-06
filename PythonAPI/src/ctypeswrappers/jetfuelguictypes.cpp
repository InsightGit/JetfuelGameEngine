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

#include <jetfuelgui.h>

#include "../stringconversions.h"

#include "../jetfuelcontrol/uisinputactionsreplacement.h"
#include "../jetfueldraw/rectangle2dshapecharacteristicsreplacement.h"
#include "../jetfueldraw/circle2dshapecharacteristicsreplacement.h"
#include "../jetfuelgui/buttoncharacteristicsreplacement.h"

#if defined(_MSC_VER)
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT 
#endif

extern "C" {
	// jetfuel::gui::Button wrappers

    EXPORT jetfuel::gui::Button *Button_new(){
        return new jetfuel::gui::Button();
    }

	EXPORT void Button_load_base_button_image(jetfuel::gui::Button *button,
                                       jetfuel::draw::Image *buttonbaseimage){
        button->Dynamic_load_base_button_image(*buttonbaseimage);
    }

	EXPORT void Button_set_button_color(jetfuel::gui::Button *button,
                                 jetfuel::draw::Color *color){
        button->Set_button_color(*color);
    }
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	EXPORT void Button_set_button_text_characteristics(jetfuel::gui::Button *button,
          jetfuel::draw::Text::Text_characteristics *textchars){
        button->Set_button_text_characteristics(*textchars);
    }

	EXPORT void Button_set_clicked_message(jetfuel::gui::Button *button,
                                    wchar_t *clickedmessage,
                                    jetfuel::core::Message_bus *messagebus){
        button->Set_clicked_message(
			String_conversions::Convert_wide_char_to_narrow_char(clickedmessage), 
																	messagebus);
    }

	EXPORT void Button_set_UIS_action_to_watch(jetfuel::gui::Button *button,
                                        wchar_t *uisaction){
        button->Set_UIS_action_to_watch(
			String_conversions::Convert_wide_char_to_narrow_char(uisaction));
    }

	EXPORT int Button_get_position_x(jetfuel::gui::Button *button){
        return button->Get_position().x;
    }

	EXPORT int Button_get_position_y(jetfuel::gui::Button *button){
        return button->Get_position().y;
    }

	EXPORT void Button_set_position(jetfuel::gui::Button *button, int x, int y){
        button->Set_position(jetfuel::draw::Vector2d_int(x,y));
    }

    // jetfuel::gui::Check_box wrappers

	EXPORT jetfuel::gui::Check_box *Check_box_new(){
        return new jetfuel::gui::Check_box();
    }

	EXPORT void Check_box_load_check_box_images(
										jetfuel::gui::Check_box *checkbox,
                                         jetfuel::draw::Image *activeimage,
                                         jetfuel::draw::Image *disabledimage){
        checkbox->Dynamic_load_check_box_images(*activeimage, *disabledimage);
    }

	EXPORT bool Check_box_is_checked(jetfuel::gui::Check_box *checkbox){
        return checkbox->Is_checked();
    }

	EXPORT int Check_box_get_position_x(jetfuel::gui::Check_box *checkbox){
        return checkbox->Get_position().x;
    }

	EXPORT int Check_box_get_position_y(jetfuel::gui::Check_box *checkbox){
        return checkbox->Get_position().y;
    }

	EXPORT void Check_box_set_position(jetfuel::gui::Check_box *checkbox, int x, 
										int y){
        checkbox->Set_position(jetfuel::draw::Vector2d_int(x,y));
    }
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	EXPORT jetfuel::draw::Text::Text_characteristics
     *Check_box_get_label_characteristics(jetfuel::gui::Check_box *checkbox){
        jetfuel::draw::Text::Text_characteristics *returnvalue = new
                jetfuel::draw::Text::Text_characteristics();

        *returnvalue = jetfuel::draw::Text::Text_characteristics(
						checkbox->Get_label_characteristics());

        return returnvalue;
    }
	/////////////////////////////////////////////////////////////////////////////////////////////////
	EXPORT void Check_box_set_label_characteristics(
					jetfuel::gui::Check_box *checkbox,
                    jetfuel::draw::Text::Text_characteristics *textchars,
                    bool left, unsigned int labelgap){
        jetfuel::gui::Check_box::Label_position labelpos;

        if(left){
            labelpos = jetfuel::gui::Check_box::Label_position::Left;
        }else{
            labelpos = jetfuel::gui::Check_box::Label_position::Right;
        }

        checkbox->Set_label_characteristics(*textchars, labelpos, labelgap);
    }

	EXPORT void Check_box_set_UIS_action_to_watch(
				jetfuel::gui::Check_box *checkbox,
                                 wchar_t *action) {
        checkbox->Set_UIS_action_to_watch(
			String_conversions::Convert_wide_char_to_narrow_char(action));
    }

	EXPORT int Check_box_get_checkbox_rect_to_draw_x(
                                       jetfuel::gui::Check_box *checkbox){
        return checkbox->Get_checkbox_rect_to_draw().x;
    }

	EXPORT int Check_box_get_checkbox_rect_to_draw_y(
                                       jetfuel::gui::Check_box *checkbox){
        return checkbox->Get_checkbox_rect_to_draw().y;
    }

	EXPORT int Check_box_get_checkbox_rect_to_draw_width(
                                       jetfuel::gui::Check_box *checkbox){
        return checkbox->Get_checkbox_rect_to_draw().width;
    }

	EXPORT int Check_box_get_checkbox_rect_to_draw_height(
                                       jetfuel::gui::Check_box *checkbox){
        return checkbox->Get_checkbox_rect_to_draw().height;
    }
    
	EXPORT jetfuel::gui::Drop_down_box *Drop_down_box_new(){
        return new jetfuel::gui::Drop_down_box();
    }
    
	EXPORT void Drop_down_box_load_base_box_image(jetfuel::gui::
                                           Drop_down_box *dropdownbox, 
                                           jetfuel::draw::Image *baseboximage,
                                           jetfuel::draw::Color *color,
                                           unsigned int xbordersize, 
                                           unsigned int ybordersize){    
        dropdownbox->Dynamic_load_base_box_image(*baseboximage,*color,
                                                jetfuel::draw::Vector2d_uint(
                                                 xbordersize, ybordersize));
    }
    
	EXPORT wchar_t *Drop_down_box_get_active_option(jetfuel::gui::Drop_down_box
                                                    *dropdownbox){
        return String_conversions::String_conversions::
		Convert_narrow_char_to_wide_char(dropdownbox->
						Get_active_option().c_str());
    }
	
	EXPORT jetfuel::draw::Text::Text_characteristics
     *Drop_down_box_get_option_text_characteristics(jetfuel::gui::Check_box
                                                    *dropdownbox){
        jetfuel::draw::Text::Text_characteristics *returnvalue = new
						jetfuel::draw::Text::Text_characteristics();

        *returnvalue = dropdownbox->Get_label_characteristics();

        return returnvalue;
    }

	EXPORT void Drop_down_box_set_option_text_characteristics(jetfuel::gui::
                                                        Drop_down_box
                                                        *dropdownbox,
      jetfuel::draw::Text::Text_characteristics *textchars){
        dropdownbox->Set_option_text_characteristics(*textchars);
    }

	EXPORT wchar_t *Drop_down_box_get_uis_action_to_listen_for(jetfuel::gui::
                                                        Drop_down_box
                                                        *dropdownbox) {
        return String_conversions::Convert_narrow_char_to_wide_char(dropdownbox->
										Get_UIS_action_to_listen_for().c_str());
    }

	EXPORT void Drop_down_box_set_uis_action_to_listen_for(jetfuel::gui::
													Drop_down_box
                                                    *dropdownbox,
                                                    wchar_t *uisaction){
        dropdownbox->Set_UIS_action_to_listen_for(
			String_conversions::Convert_wide_char_to_narrow_char(uisaction));
    }

	EXPORT void Drop_down_box_add_option(jetfuel::gui::Drop_down_box 
									*dropdownbox,
                                  wchar_t *option){
        dropdownbox->Add_option(String_conversions::
			Convert_wide_char_to_narrow_char(option));
    }

	EXPORT int Drop_down_box_get_position_x(jetfuel::gui::Drop_down_box 
											*dropdownbox){
        return dropdownbox->Get_position().x;
    }

	EXPORT int Drop_down_box_get_position_y(jetfuel::gui::Drop_down_box 
											*dropdownbox){
        return dropdownbox->Get_position().y;
    }

	EXPORT void Drop_down_box_set_position(jetfuel::gui::Drop_down_box 
									*dropdownbox,
                                    int x, int y){
        dropdownbox->Set_position(jetfuel::draw::Vector2d_int(x,y));
    }

	EXPORT int Drop_down_box_get_rect_to_draw_width(jetfuel::gui::Drop_down_box
                                             *dropdownbox){
        return dropdownbox->Get_rect_to_draw().width;
    }

	EXPORT int Drop_down_box_get_rect_to_draw_height(jetfuel::gui::Drop_down_box
                                             *dropdownbox){
        return dropdownbox->Get_rect_to_draw().height;
    }

	EXPORT jetfuel::gui::Button_characteristics_replacement 
     *Button_characteristics_replacement_new(){
		jetfuel::gui::Button_characteristics_replacement *returnvalue = new
							jetfuel::gui::Button_characteristics_replacement();

        return returnvalue;
    }

	EXPORT void Button_characteristics_replacement_delete(jetfuel::gui::
                Button_characteristics_replacement *buttoncharsreplacement){
        delete buttoncharsreplacement;
    }

	EXPORT jetfuel::draw::Image *Button_characteristics_replacement_get_image(
      jetfuel::gui::Button_characteristics_replacement *buttoncharsreplacement){
        jetfuel::draw::Image *returnvalue = new jetfuel::draw::Image();

        *returnvalue = buttoncharsreplacement->image;

        return returnvalue;
    }

	EXPORT void Button_characteristics_replacement_set_image(jetfuel::gui::
            Button_characteristics_replacement *buttoncharsreplacement,
            jetfuel::draw::Image *image){
        buttoncharsreplacement->image = *image;
    }

	EXPORT jetfuel::draw::Color *Button_characteristics_replacement_get_color(
      jetfuel::gui::Button_characteristics_replacement *buttoncharsreplacement){
        jetfuel::draw::Color *returnvalue = new jetfuel::draw::Color();

        *returnvalue = buttoncharsreplacement->color;

        return returnvalue;
    }

	EXPORT void Button_characteristics_replacement_set_color(jetfuel::gui::
            Button_characteristics_replacement *buttoncharsreplacement,
            jetfuel::draw::Color *color){
        buttoncharsreplacement->color = *color;
    }

	EXPORT jetfuel::draw::Color 
	*Button_characteristics_replacement_get_text_chars(
      jetfuel::gui::Button_characteristics_replacement *buttoncharsreplacement){
        jetfuel::draw::Color *returnvalue = new jetfuel::draw::Color();

        *returnvalue = buttoncharsreplacement->color;

        return returnvalue;
    }

	EXPORT void Button_characteristics_replacement_set_text_chars(jetfuel::gui::
            Button_characteristics_replacement *buttoncharsreplacement,
         jetfuel::draw::Text::Text_characteristics *textchars){
        buttoncharsreplacement->textcharsreplacement = *textchars;
    }

	EXPORT jetfuel::gui::Menu *Menu_new(){
        return new jetfuel::gui::Menu();
    }

	EXPORT jetfuel::gui::Menu *Menu_new_from_heights_and_gaps(
									unsigned int maxheight,
                                    unsigned int columngap,
									unsigned int buttongap){
        return new jetfuel::gui::Menu(maxheight, columngap, buttongap);
    }

	EXPORT unsigned int Menu_get_max_height(jetfuel::gui::Menu *menu){
        return menu->Get_max_height();
    }

	EXPORT void Menu_set_max_height(jetfuel::gui::Menu *menu, 
									unsigned int maxheight){
        menu->Set_max_height(maxheight);
    }

	EXPORT unsigned int Menu_get_column_gap(jetfuel::gui::Menu *menu){
        return menu->Get_column_gap();
    }

	EXPORT void Menu_set_column_gap(jetfuel::gui::Menu *menu, 
									unsigned int columngap){
        menu->Set_column_gap(columngap);
    }

	EXPORT unsigned int Menu_get_button_gap(jetfuel::gui::Menu *menu){
        return menu->Get_button_gap();
    }

	EXPORT void Menu_set_button_gap(jetfuel::gui::Menu *menu, 
									unsigned int buttongap){
        menu->Set_button_gap(buttongap);
    }

	EXPORT jetfuel::draw::Image *Menu_get_container_box_image(
										jetfuel::gui::Menu *menu){
        jetfuel::draw::Image *returnvalue = new jetfuel::draw::Image();

        *returnvalue = menu->Get_container_box_image();

        return returnvalue;
    }

	EXPORT void Menu_set_container_box_image(jetfuel::gui::Menu *menu,
                                      jetfuel::draw::Image *image,
                                      unsigned int borderwidth,
                                      unsigned int borderheight){
        menu->Set_container_box_image(*image, jetfuel::draw::Vector2d_uint(
                                      borderwidth, borderheight));
    }

	EXPORT unsigned int Menu_get_container_box_border_width(jetfuel::gui::Menu 
																		*menu){
        return menu->Get_container_box_border().x;
    }

	EXPORT unsigned int Menu_get_container_box_border_height(jetfuel::gui::Menu 
																		*menu){
        return menu->Get_container_box_border().y;
    }

	EXPORT bool Menu_add_button(jetfuel::gui::Menu *menu,
                    jetfuel::gui::Button_characteristics_replacement
                    *buttoncharsreplacement, wchar_t *uisactiontowatchfor,
                    wchar_t *messagetosenduponclick,
                    jetfuel::core::Message_bus *messagebus){
        return menu->Add_button(buttoncharsreplacement->
                         Convert_to_button_chars_struct(),
						 String_conversions::Convert_wide_char_to_narrow_char(
														uisactiontowatchfor),
						 String_conversions::Convert_wide_char_to_narrow_char(
								messagetosenduponclick),
                         messagebus, true);
    }

	EXPORT int Menu_get_position_x(jetfuel::gui::Menu *menu){
        return menu->Get_position().x;
    }

	EXPORT int Menu_get_position_y(jetfuel::gui::Menu *menu){
        return menu->Get_position().y;
    }

	EXPORT void Menu_set_position(jetfuel::gui::Menu *menu, int x, int y){
        menu->Set_position(jetfuel::draw::Vector2d_int(x,y));
    }

	EXPORT int Menu_get_rect_to_draw_height(jetfuel::gui::Menu *menu){
        return menu->Get_rect_to_draw().height;
    }

	EXPORT int Menu_get_rect_to_draw_width(jetfuel::gui::Menu *menu){
        return menu->Get_rect_to_draw().width;
    }

	EXPORT jetfuel::gui::Progress_bar *Progress_bar_new(){
        return new jetfuel::gui::Progress_bar();
    }

	EXPORT jetfuel::gui::Progress_bar *Progress_bar_new_set_progress_bar(
								jetfuel::draw::Image *progressbarimage,
                                 jetfuel::draw::Color *progressbarcolor,
                                          int progressbarholderborderx,
                                          int progressbarholderbordery,
                                          int progressbarholderborderwidth,
                                          int progressbarholderborderheight,
                                          int progressbarmax){
        return new jetfuel::gui::Progress_bar(*progressbarimage,
                    *progressbarcolor,
                    jetfuel::draw::Rect2d_int(progressbarholderborderx,
                        progressbarholderbordery, progressbarholderborderwidth,
                        progressbarholderborderheight),progressbarmax);
    }

	EXPORT unsigned int Progress_bar_get_progress_bar_progress(jetfuel::gui::
                                              Progress_bar *progressbar){
        return progressbar->Get_progress_bar_progress();
    }

	EXPORT void Progress_bar_set_progress_bar_progress(jetfuel::gui::Progress_bar
                                               *progressbar,
                                               unsigned int progressbarprogress){
        progressbar->Set_progress_bar_progress(progressbarprogress);
    }

	EXPORT unsigned int Progress_bar_get_max_progress_bar(jetfuel::gui::Progress_bar 
															*progressbar){
        return progressbar->Get_max_progress_bar();
    }

	EXPORT bool Progress_bar_has_progress_bar_completed(jetfuel::gui::Progress_bar 
														*progressbar){
        return progressbar->Has_progress_bar_completed();
    }

	EXPORT int Progress_bar_get_position_x(jetfuel::gui::Progress_bar 
											*progressbar){
        return progressbar->Get_position().x;
    }

	EXPORT int Progress_bar_get_position_y(jetfuel::gui::Progress_bar 
											*progressbar){
        return progressbar->Get_position().y;
    }

	EXPORT void Progress_bar_set_position(jetfuel::gui::Progress_bar 
										*progressbar, int x, int y){
        progressbar->Set_position(jetfuel::draw::Vector2d_int(x,y));
    }

	EXPORT int Progress_bar_get_rect_to_draw_width(jetfuel::gui::Progress_bar
                                            *progressbar){
        return progressbar->Get_rect_to_draw().width;
    }

	EXPORT int Progress_bar_get_rect_to_draw_height(jetfuel::gui::Progress_bar
                                            *progressbar){
        return progressbar->Get_rect_to_draw().height;
    }

	EXPORT jetfuel::gui::Slider *Slider_new(){
        return new jetfuel::gui::Slider();
    }

	EXPORT jetfuel::draw::
    Rectangle_2d_shape_characteristics_replacement
    Slider_get_slider_rail_characteristics(jetfuel::gui::Slider *slider){
        return jetfuel::draw::Rectangle_2d_shape_characteristics_replacement(
                                    slider->Get_slider_rail_characteristics());
    }

	EXPORT void Slider_set_slider_rail_characteristics(
	jetfuel::gui::Slider *slider,
    jetfuel::draw::Rectangle_2d_shape_characteristics_replacement *rect2dchars){
        slider->Set_slider_rail_characteristics(rect2dchars->
                        Convert_to_rectangle_2d_shape_chars());
    }

	EXPORT jetfuel::draw::
    Circle_2d_shape_characteristics_replacement
    Slider_get_slider_button_characteristics(jetfuel::gui::Slider *slider){
        return jetfuel::draw::Circle_2d_shape_characteristics_replacement(
                                    slider->Get_slider_button_characteristics());
    }

	EXPORT void Slider_set_slider_button_characteristics(
		jetfuel::gui::Slider *slider, jetfuel::draw::
                    Circle_2d_shape_characteristics_replacement *circle2dchars){
        slider->Set_slider_button_characteristics(circle2dchars->
                            Convert_to_circle_2d_shape_chars());
    }

	EXPORT unsigned int Slider_get_number_of_statuses(jetfuel::gui::Slider 
													  *slider){
        return slider->Get_number_of_statuses();
    }

	EXPORT void Slider_set_number_of_statuses(jetfuel::gui::Slider *slider,
                                        unsigned int statusnumber){
        slider->Set_number_of_statuses(statusnumber);
    }

	EXPORT unsigned int Slider_get_current_status(jetfuel::gui::Slider *slider){
        return slider->Get_current_status();
    }

	EXPORT void Slider_set_current_status(jetfuel::gui::Slider *slider,
                                   unsigned int currentstatus){
        slider->Set_current_status(currentstatus);
    }

	EXPORT jetfuel::control::Uis_input_actions_replacement 
		*Slider_get_control_scheme(jetfuel::gui::Slider *slider){
        jetfuel::control::Uis_input_actions_replacement *returnvalue = new
                        jetfuel::control::Uis_input_actions_replacement(
                                        slider->Get_control_scheme());

        return returnvalue;
    }

	EXPORT void Slider_set_control_scheme(jetfuel::gui::Slider *slider,
            jetfuel::control::Uis_input_actions_replacement *uisinputactions){
        slider->Set_control_scheme(
        uisinputactions->Convert_to_uis_input_actions());
    }

	EXPORT int Slider_get_position_x(jetfuel::gui::Slider *slider){
        return slider->Get_position().x;
    }

	EXPORT int Slider_get_position_y(jetfuel::gui::Slider *slider){
        return slider->Get_position().y;
    }

	EXPORT void Slider_set_position(jetfuel::gui::Slider *slider, int x, int y){
        slider->Set_position(jetfuel::draw::Vector2d_int(x,y));
    }

	EXPORT int Slider_get_rect_to_draw_width(jetfuel::gui::Slider *slider){
        return slider->Get_rect_to_draw().width;
    }

	EXPORT int Slider_get_rect_to_draw_height(jetfuel::gui::Slider *slider){
        return slider->Get_rect_to_draw().height;
    }
}
