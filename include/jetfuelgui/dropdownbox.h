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

#ifndef JETFUELGUI_DROPDOWNBOX_H_
#define JETFUELGUI_DROPDOWNBOX_H_

#include <jetfueldraw.h>
#include <jetfuelgui/iclickable.h>


namespace jetfuel {
    namespace gui {
        class Drop_down_box: public jetfuel::draw::Drawable,
                             public jetfuel::draw::Rectangle_interface,
                             public IClickable {
        public:
        	/// \brief Default constructor.
        	///
        	/// Constructs an empty Drop_down_box.
            Drop_down_box() {}

            /// \brief Loads the base box image of the Drop_down_box.
            ///
            /// Loads the base box image of the Drop_down_box, including
            /// the color of the image and the border sizes of the
            /// base box image.
            ///
            /// \param jetfuel::draw::Image baseboximage
            /// \param jetfuel::draw::Color baseboxcolor
            /// \param jetfuel::draw::Vector2d_uint bordersizes
            bool Load_base_box_image(jetfuel::draw::Image baseboximage,
                                 const jetfuel::draw::Color baseboxcolor,
                                 const jetfuel::draw::Vector2d_uint bordersizes){
                bool returnvalue = m_basebox.Load_from_image(baseboximage);
                if(returnvalue){
                    m_boxcolor = baseboxcolor;
                    m_baseboxsize = baseboximage.Get_size_of_image();
                    m_bordersizes = bordersizes;

                    Regenerate_options();
                }

                return returnvalue;
            }

            /// \brief Dynamically loads the base box image of the Drop_down_box.
            ///
            /// Dynamically loads the base box image of the Drop_down_box,
            /// including the color of the image and the border sizes of the
            /// base box image. The image are not loaded until right before it is
            /// needed in the Draw() function.
            ///
            /// \param jetfuel::draw::Image baseboximage
            /// \param jetfuel::draw::Color baseboxcolor
            /// \param jetfuel::draw::Vector2d_uint bordersizes
            void Dynamic_load_base_box_image(jetfuel::draw::Image baseboximage,
                                           const jetfuel::draw::Color baseboxcolor,
                                           const jetfuel::draw::Vector2d_uint bordersizes){
                m_baseboxsize = baseboximage.Get_size_of_image();

                m_baseboxdynamicimage = baseboximage;
                m_imagedynamicallyloaded = true;
                m_boxcolor = baseboxcolor;
                m_bordersizes = bordersizes;
            }

            /// \brief Gets the active option of the Drop_down_box.
            ///
            /// Gets the active option of the Drop_down_box.
            std::string Get_active_option() const{
                return m_baseboxtext.Get_string();
            }

            /// \brief Gets the text characteristics of the
            /// Drop_down_box's options.
            ///
            /// Gets the text characteristics of the
            /// Drop_down_box's options.
            jetfuel::draw::Text::Text_characteristics
            Get_option_text_characteristics() const{
                return m_textcharacteristics;
            }

            /// \brief Sets the text characteristics of the
            /// Drop_down_box's options.
            ///
            /// Sets the text characteristics of the
            /// Drop_down_box's options.
            ///
            /// \param jetfuel::draw::Text::Text_characteristics
            /// textcharacteristics
            void Set_option_text_characteristics(jetfuel::draw::Text::
                                                 Text_characteristics
                                                 textcharacteristics){
                m_textcharacteristics = textcharacteristics;
                m_textcharsset = true;

                Regenerate_options();
            }

            /// \brief Gets the UIS action to listen for triggers.
            ///
            /// Gets the Universal Input System action to listen for
            /// triggers.
            std::string Get_UIS_action_to_listen_for() const{
                return m_UISactiontolistenfor;
            }

            /// \brief Sets the UIS action to listen for triggers.
            ///
            /// Sets the Universal Input System action to listen for
            /// triggers.
            ///
            /// \param std::string UISaction
            void Set_UIS_action_to_listen_for(const std::string UISaction){
                m_UISactiontolistenfor = UISaction;
            }

            /// \brief Assigns a renderer to this Drop_down_box.
            ///
            /// Assigns a renderer to this Drop_down_box.
            /// It is recommended that you let jetfuel::draw::Scene
            /// and jetfuel::draw::Scene_manager call this unless
            /// you are not using either of them.
            ///
            /// \param SDL_Renderer *renderer
            void Assign_renderer(SDL_Renderer *renderer)override{
                m_internalrenderer = renderer;

                m_baseboxtext.Assign_renderer(m_internalrenderer);
                m_basebox.Assign_renderer(m_internalrenderer);

                Set_assigned_renderer(true);

                Regenerate_options();
            }

            /// \brief Adds an option to this Drop_down_box.
            ///
            /// Adds an option to this Drop_down_box.
            ///
            /// \param std::string option
            void Add_option(const std::string option);

            /// \brief Gets this Drop_down_box's position.
            ///
            /// Gets this Drop_down_box's position.
            jetfuel::draw::Vector2d_int Get_position()override{
                return m_basebox.Get_position();
            }

            /// \brief Sets this Drop_down_box's position.
            ///
            /// Sets this Drop_down_box's position.
            ///
            /// \param jetfuel::draw::Vector2d_int position
            void Set_position(const jetfuel::draw::Vector2d_int position)override{
                m_basebox.Set_position(position);

                Regenerate_options();
            }

            /// \brief Gets this Drop_down_box's rect to draw.
            ///
            /// Gets this Drop_down_box's rect to draw.
            ///
            /// \warning THIS DOES NOT INCLUDE OPTIONS SHOWN IF IT IS
            /// CLICKED.
            jetfuel::draw::Rect2d_int Get_rect_to_draw()override{
                return m_basebox.Get_rect_to_draw();
            }

            /// \brief Checks for clicks on this Drop_down_box.
            ///
            /// Checks for clicks on this Drop_down_box.
            ///
            /// \param jetfuel::control::Action UISinterpreterdata
            void Check_for_clicks(jetfuel::control::Action
                                  UISinterpreterdata)override;

            /// \brief Draws this Drop_down_box onto the screen.
            ///
            /// Draws this Drop_down_box onto the screen.
            bool Draw()override;
        protected:
            struct Drop_down_option{
                jetfuel::draw::Rectangle_2d_shape containerbox;
                jetfuel::draw::Text text;
            };
            /// \struct jetfuel::gui::Drop_down_option
            ///
            /// A simple struct representing a option in a
            /// Drop_down_box.

            /// \brief Returns whether this Drop_down_box has been
            /// clicked on recently and option boxes have been shown.
            ///
            /// Returns whether this Drop_down_box has been
            /// clicked on recently and option boxes have been shown.
            bool Is_active() const{
                return m_active;
            }

            /// \brief Returns whether this Drop_down_box has had
            /// it's base drop down box option set.
            ///
            /// Returns whether this Drop_down_box has had
            /// it's base drop down box option set.
            bool Is_base_box_set() const{
                return m_baseboxset;
            }

            /// \brief Sets whether this Drop_down_box has been
            /// clicked on recently and option boxes have been shown.
            ///
            /// Sets whether this Drop_down_box has been
            /// clicked on recently and option boxes have been shown.
            ///
            /// \param bool active
            void Set_active(const bool active){
                m_active = active;
            }

            /// \brief Gets the border sizes of this Drop_down_box.
            ///
            /// Gets the border sizes of this Drop_down_box.
            jetfuel::draw::Vector2d_uint Get_border_sizes() const{
                return m_bordersizes;
            }

            /// \brief Returns whether this Drop_down_box's option
            /// text characteristics been set.
            ///
            ///  Returns whether this Drop_down_box's option
            ///  text characteristics been set.
            bool Is_text_chars_set() const{
                return m_textcharsset;
            }

            /// \brief Sets the option text characteristics on a Text
            /// object.
            ///
            /// Sets the option text characteristics on a Text
            /// object.
            ///
            /// \param jetfuel::draw::Text *textobject
            void Set_text_characteristics_to_text_object(jetfuel::draw::Text
                                                         *textobject){
                textobject->Set_font(m_textcharacteristics.font);
                textobject->Set_font_size(m_textcharacteristics.fontsize);
                textobject->Set_font_style(m_textcharacteristics.fontstyle);
                textobject->Set_render_mode(m_textcharacteristics.rendermode);
                textobject->Set_text_color(m_textcharacteristics.textcolor);
                textobject->Set_background_color(m_textcharacteristics.
                                             backgroundcolor);
                if(m_textcharacteristics.fontoutlinewidth != 0){
                    textobject->Set_font_outline_width(m_textcharacteristics.
                                                   fontoutlinewidth);
                }
                textobject->Set_kerning_status(m_textcharacteristics.
                                               kerningstatus);

                textobject->Set_font_hinting(m_textcharacteristics.fonthinting);
            }

            /// \brief Gets this Drop_down_box's color.
            ///
            /// Gets this Drop_down_box's color (from the base box
            /// color).
            jetfuel::draw::Color Get_box_color(){
                return m_boxcolor;
            }

            /// \brief Gets the size of this Drop_down_box's size of
            /// it's base box.
            ///
            /// Gets the size of this Drop_down_box's size of
            /// it's base box.
            jetfuel::draw::Vector2d_int Get_size_of_base_box(){
                return m_baseboxsize;
            }

            /// \brief Adds a Drop_down_option to this Drop_down_box's
            /// private m_dropdownoptions vector.
            ///
            /// Adds a Drop_down_option to this Drop_down_box's
            /// private m_dropdownoptions vector.
            ///
            /// \param jetfuel::gui::Drop_down_box::Drop_down_option
            /// option
            void Add_drop_down_option_to_vector(Drop_down_option option){
                m_dropdownoptions.push_back(option);
            }

            /// \brief Adds an std::string option to the
            /// private m_options vector.
            ///
            /// Adds an std::string option to the
            /// private m_options vector.
            ///
            /// \param std::string option
            void Add_option_to_vector(const std::string option){
                bool optionexists = false;
                for(int i = 0; m_options.size() > i; ++i){
                    if(m_options[i] == option){
                        optionexists = true;
                        break;
                    }
                }
                if(!optionexists){
                    m_options.push_back(option);
                }
            }

            /// \brief Gets the size of the private
            /// m_dropdownoptions vector.
            ///
            /// Gets the size of the private
            /// m_dropdownoptions vector.
            size_t Get_size_of_dropdown_options_vector() const{
                return m_dropdownoptions.size();
            }

            Drop_down_option Get_dropdown_option_in_vector(const size_t which){
                if(which >= m_dropdownoptions.size()){
                    throw jetfuel::core::exceptions::
                    Out_of_vector_range_exception();
                }else{
                    return m_dropdownoptions[which];
                }
            }

            /// \brief Sets which option to be first and displayed in
            /// this Drop_down_box's base box.
            ///
            /// Sets which option to be first and displayed in
            /// this Drop_down_box's base box.
            ///
            /// \param size_t which
            void Set_active_drop_down(const size_t which){
                std::string previousfirstoption = m_options[0];
                std::string optiontobefirst = m_options[which+1];

                m_options[0] = optiontobefirst;
                m_options[which+1] = previousfirstoption;

                Regenerate_options();
            }

            /// \brief Sets the base box's option
            ///
            /// Sets the base box's option, used for the first option
            /// given to this class via Add_option.
            ///
            /// \param std::string option
            void Set_base_box_option(std::string option){
                m_baseboxtext = jetfuel::draw::Text();
                Set_text_characteristics_to_text_object(&m_baseboxtext);
                m_baseboxtext.Set_string(option);

                m_baseboxtext.Set_position(Get_position()+
                jetfuel::draw::Vector2d_int(Get_border_sizes().x,
                Get_border_sizes().y));

                m_baseboxset = true;
            }

            /// \brief Returns whether the base box's image has been
            /// dynamically loaded or not.
            ///
            /// Returns whether the base box's image has been
            /// dynamically loaded or not.
            bool Is_image_dynamically_loaded() const{
                return m_imagedynamicallyloaded;
            }

            /// \brief Loads the base box's dynamic image.
            ///
            /// Loads the base box's dynamic image specified in
            /// m_baseboxdynamicimage.
            bool Load_dynamic_image(){
                bool returnvalue = m_basebox.Load_from_image(
                                        m_baseboxdynamicimage);

                m_imagedynamicallyloaded = !returnvalue;

                return returnvalue;
            }

            /// \brief Gets the SDL renderer.
            ///
            /// Gets the SDL renderer.
            SDL_Renderer *Get_renderer()override{
                return m_internalrenderer;
            }

            /// \brief Draws this Drop_down_box's base box.
            ///
            /// Draws this Drop_down_box's base box.
            bool Draw_base_box(){
                m_baseboxtext.Assign_renderer(m_internalrenderer);
                return m_basebox.Draw() && m_baseboxtext.Draw();
            }

            /// \brief Draws all of this Drop_down_box's option boxes.
            ///
            /// Draws all of this Drop_down_box's option boxes.
            bool Draw_all_option_boxes(){
                for(int i = 0; m_dropdownoptions.size() > i; ++i){
                    if(!m_dropdownoptions[i].containerbox.Draw() ||
                       !m_dropdownoptions[i].text.Draw()){
                        return false;
                    }
                }

                return true;
            }
        private:
            bool m_active = false; ///< Whether this Drop_down_box has
								   ///< been clicked on recently and
								   ///< option boxes have been shown.

            bool m_baseboxset = false; ///< Whether this
									  ///< Drop_down_box's base box
									  ///< has been setup.

            jetfuel::draw::Vector2d_uint m_bordersizes; ///< The base
            											///< box's
            											///< border
            											///< sizes.

            SDL_Renderer *m_internalrenderer; ///< The renderer.

            jetfuel::draw::Color m_boxcolor; ///< The base box's color.
            jetfuel::draw::Sprite m_basebox; ///< The base box's
            								 ///< sprite.
            jetfuel::draw::Text m_baseboxtext; ///< The base box's
											   ///< text.
            jetfuel::draw::Vector2d_int m_baseboxsize; ///< The base
            										   ///< box's size.

            jetfuel::draw::Image m_baseboxdynamicimage; ///< The base
            											///< box's
            											///< dynamic
														///< image.
            bool m_imagedynamicallyloaded = false; ///< Whether the
												   ///< base box's
												   ///< image has been
												   ///< dynamically
												   ///< loaded.

            std::string m_UISactiontolistenfor; ///< The UIS action to
            									///< listen for.

            bool m_textcharsset = false; ///< Whether the option text
										 ///< chars have been set.
            jetfuel::draw::Text::Text_characteristics m_textcharacteristics;
									///< The option text
									///< characteristics.

            std::vector<Drop_down_option> m_dropdownoptions; ///< The
															 ///< drop
															 ///< down
															 ///< options
															 ///< (with
															 ///< Text
															 ///< object).
            std::vector<std::string> m_options; ///< The drop
											    ///< down options
											    ///< (without Text
											    ///< object).

            /// \brief Regenerates the m_dropdownoptions vector from
            /// the m_options vector..
            ///
            /// Regenerates the m_dropdownoptions vector from the
            /// m_options vector.
            void Regenerate_options(){
                m_baseboxset = false;

                m_dropdownoptions.clear();

                for(int i = 0; m_options.size() > i; ++i){
                    if(i==0){
                        Set_base_box_option(m_options[0]);
                    }else{
                        Add_option(m_options[i]);
                    }
                }
            }
        };
        /// \class jetfuel::gui::Drop_down_box
        ///
        /// A simple Drop down box with user-specified options.
        ///
        /// Code Example:
        /// 	jetfuel::draw::Scene_manager scenemanager;
        ///     jetfuel::draw::Scene scene1(1);
        ///     jetfuel::core::Message_bus messagebus;
        ///     jetfuel::gui::Drop_down_box dropdownbox;
        ///     jetfuel::draw::Image dropdownbaseboximage("basebox.png",
        ///                                      		  &scenemanager);
        ///     jetfuel::control::UIS_manager UISmanager(&messagebus,
        ///                                       scenemanager.Get_window_id());
        ///     jetfuel::control::UIS_interpreter UISinterpreter(&messagebus);
        ///     jetfuel::draw::Text::Text_characteristics textchars;
        ///     jetfuel::draw::Font font("default.ttf");
        ///
        ///     if(!scenemanager.Create_window("Hello Dropdownboxes!",
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
        ///     scene1.Attach_drawable(&dropdownbox,1);
        ///
        ///     if(!dropdownbox.Load_base_box_image(dropdownbaseboximage,
        ///											jetfuel::draw::Color::White,
		///											jetfuel::draw::Vector2d_uint(
        ///                                         45,20))){
        ///         std::cerr << "[!]ERROR with loading from image! Error is:" <<
        ///         IMG_GetError() << "\n";
        ///     }
        ///
        ///     dropdownbox.Set_position(jetfuel::draw::Vector2d_int(0,0));
        ///
        ///     textchars.textstring = "hello";
        ///     textchars.font = font;
		///    
        ///
        ///     dropdownbox.Set_option_text_characteristics(textchars);
        ///
        ///     dropdownbox.Add_option("A");
        ///     dropdownbox.Add_option("B");
        ///     dropdownbox.Add_option("C");
        ///
        ///     scenemanager.Draw_current_scene();
    } /* namespace gui */
} /* namespace jetfuel */

#endif /* JETFUELGUI_DROPDOWNBOX_H_ */