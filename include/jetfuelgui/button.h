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

#ifndef JETFUELGUI_BUTTON_H_
#define JETFUELGUI_BUTTON_H_

#include <memory>

#include <jetfueldraw.h>
#include <jetfuelgui/iclickable.h>
#include <jetfuelinspire.h>
#include <jetfuelcontrol/UISinterpreter.h>

namespace jetfuel {
    namespace gui {

        class Button : public jetfuel::draw::Drawable,
                       public jetfuel::draw::Rectangle_interface,
                       public IClickable{
        public:

            /// \brief Default constructor
            ///
            /// Constructs an empty Button object.
            Button(){}

            /// \brief Loads a base button image to serve as the
            /// button's background.
            ///
            /// Loads a base button image to serve as the
            /// button's background placed underneath the button's
            /// text and color overlay.
            ///
            /// \param jetfuel::draw::Image image
            bool Load_base_button_image(jetfuel::draw::Image image){
                bool returnvalue = m_buttonsprite.Load_from_image(image);

                if(returnvalue){
                    m_buttonoverlay.Set_position(Get_position());
                    m_buttonoverlay.Set_size(image.Get_size_of_image());

                    jetfuel::draw::Vector2d_int textposition(m_buttonoverlay.
                    Get_rect_to_draw().x+
                    m_buttonoverlay.Get_rect_to_draw().width/2,
                    m_buttonoverlay.Get_rect_to_draw().y+
                    m_buttonoverlay.Get_rect_to_draw().height/2);

                    textposition.x -= m_buttontext.Get_rect_to_draw().width;
                    textposition.y -= m_buttontext.Get_rect_to_draw().height;

                    m_buttontext.Set_position(textposition);

                    m_readytodraw = true;
                }

                return returnvalue;
            }

            /// \brief Dynamically load a base button to serve as the
            /// button's background.
            ///
            /// Dynamically load a base button to serve as the
            /// button's background placed underneath the button's
            /// text and color overlay.
            ///
            /// \param jetfuel::draw::Image image
            void Dynamic_load_base_button_image(jetfuel::draw::Image image){
                m_buttonsprite.Dynamic_load_from_image(image);

                m_buttonoverlay.Set_position(Get_position());
                m_buttonoverlay.Set_size(image.Get_size_of_image());

                jetfuel::draw::Vector2d_int textposition(m_buttonoverlay.
                Get_rect_to_draw().x+
                m_buttonoverlay.Get_rect_to_draw().width/2,
                m_buttonoverlay.Get_rect_to_draw().y+
                m_buttonoverlay.Get_rect_to_draw().height/2);

                textposition.x -= m_buttontext.Get_rect_to_draw().width;
                textposition.y -= m_buttontext.Get_rect_to_draw().height;

                m_buttontext.Set_position(textposition);

                m_readytodraw = true;
            }

            /// \brief Sets the button's color overlay to be overlaid
            /// over the background's image.
            ///
            /// Sets the button's color overlay to be overlaid
            /// over the background's image.
            ///
            /// \param jetfuel::draw::Color color
            void Set_button_color(jetfuel::draw::Color color);

            /// \brief Sets the button's text characteristics when
            /// displaying text.
            ///
            /// Sets the button's text characteristics when
            /// displaying text. Text characteristics are text options
            /// like Font, font hinting, text size, and text color
            /// that can easily be set via this one function!
            ///
            /// \param jetfuel::draw::Text::Text_characteristics
            void Set_button_text_characteristics(
                    jetfuel::draw::Text::Text_characteristics
                    buttontextchars){
                m_buttontext.Set_render_mode(buttontextchars.rendermode);
                m_buttontext.Set_string(buttontextchars.textstring);
                m_buttontext.Set_text_color(buttontextchars.textcolor);
                m_buttontext.Set_background_color(
                                       buttontextchars.backgroundcolor);
				
                if(buttontextchars.fontoutlinewidth != 0){
                    m_buttontext.Set_font_outline_width(
                            buttontextchars.fontoutlinewidth);
                }

                m_buttontext.Set_kerning_status(buttontextchars.kerningstatus);
                m_buttontext.Set_font_style(buttontextchars.fontstyle);
                m_buttontext.Set_font_size(buttontextchars.fontsize);
                m_buttontext.Set_font_hinting(buttontextchars.fonthinting);
                m_buttontext.Set_font(buttontextchars.font);
            }

            /// \brief Sets the message to send to the message bus
            /// passed into this function when this button is clicked.
            ///
            /// Sets the message to send to the message bus
            /// passed into this function when this button is clicked.
            ///
            /// \param std::string message
            /// \param jetfuel::core::Message_bus *bus
            void Set_clicked_message(const std::string message,
                                     jetfuel::core::Message_bus *bus){
                m_messagebus = bus;
                m_messagetopostonclick = message;
            }

            /// \brief Sets the Universal Input System(UIS) action to
            /// watch for clicks.
            ///
            /// Sets the Universal Input System(UIS) action to
            /// watch for clicks.
            ///
            /// \param std::string action
            void Set_UIS_action_to_watch(const std::string action){
                m_actiontolistenfor = action;
            }

            /// \brief Checks for clicks.
            ///
            /// Checks for clicks. If click is detected, the
            /// specified message specified in the Set_clicked_message
            /// function will be sent to the specified message bus.
            ///
            /// \param jetfuel::control::Action UISinterpreterdata
            void Check_for_clicks(jetfuel::control::Action
                                  UISinterpreterdata)override;

            /// \brief Assigns renderer to this button's Drawables.
            ///
            /// Assigns renderer to this button's Drawables, including
            /// the Button's text, rectangle, and sprite Drawables.
            ///
            /// \param SDL_Renderer *renderer
            void Assign_renderer(SDL_Renderer *renderer)override;

            /// \brief Returns whether this Button has been assigned a
            /// renderer.
            ///
            /// Returns whether this Button has been assigned a
            /// renderer.
            bool Has_been_assigned_renderer(){
                return m_renderready;
            }

            /// \brief Gets this Button's position on the screen.
            ///
            /// Gets this Button's position on the screen.
            jetfuel::draw::Vector2d_int Get_position()override{
                return m_buttonposition;
            }

            /// \brief Sets this Button's position on the screen.
            ///
            /// Sets this Button's position on the screen.
            ///
            /// \param jetfuel::draw::Vector2d_int position
            void Set_position(jetfuel::draw::Vector2d_int position) override{
                m_buttonposition = position;

                m_buttonsprite.Set_position(m_buttonposition);

                m_buttonoverlay.Set_position(m_buttonposition);

                jetfuel::draw::Vector2d_int textposition(
                m_buttonoverlay.Get_rect_to_draw().width/2,
                m_buttonoverlay.Get_rect_to_draw().height/2);

                textposition += m_buttonposition;

                textposition.x -= m_buttontext.Get_rect_to_draw().width;
                textposition.y -= m_buttontext.Get_rect_to_draw().height;

                m_buttontext.Set_position(textposition);
            }

            /// \brief Gets this Button's rectangle that will be drawn
            /// on the screen.
            ///
            /// Gets this Button's rectangle that will be drawn on the
            /// Draw function being called.
            jetfuel::draw::Rect2d_int Get_rect_to_draw() override{
                return m_buttonsprite.Get_rect_to_draw();
            }

            /// \brief Force loads the Button's dynamic image, if any.
            ///
            /// Force loads the Button's dynamic image, if any. It
            /// will re-load the image also when the Draw function is
            /// called even if you call this function. This function
            /// is mainly to find out the height and width of the
            /// sprite's image and not much else.
            void Force_load_dynamic_image(){
                m_buttonsprite.Force_load_dynamic_image();
            }

            /// \brief Draws this Button to the screen.
            ///
            /// Draws this Button to the screen. This WILL fail if
            /// either the renderer has not been assigned(which
            /// happens when you attach a Button to a
            /// jetfuel::draw::Scene), or the
            /// image has not been loaded. If it does, this
            /// function will return a boolean of false. Otherwise,
            /// it will return a boolean of true.
            bool Draw() override;
        protected:
            /// \brief Returns whether this Button's Drawables are
            /// ready to be drawn.
            ///
            /// Returns whether this Button's Drawables are
            /// ready to be drawn.
            bool Is_ready_to_draw() const {
                return m_readytodraw;
            }

            /// \brief Draws this Button's Sprite object and returns
            /// the result.
            ///
            /// Draws this Button's Sprite object and returns
            /// the result.
            bool Draw_button_sprite(){
                return m_buttonsprite.Draw();
            }

            /// \brief Draws this Button's color overlay object and
            /// returns the result.
            ///
            /// Draws this Button's color overlay object and returns
            /// the result.
            bool Draw_button_overlay(){
				return m_buttonoverlay.Draw();
            }

            /// \brief Draws this Button's text object and returns the
            /// result.
            ///
            /// Draws this Button's text object and returns the
            /// result.
            bool Draw_button_text(){
                return m_buttontext.Draw();
            }

            /// \brief Returns whether the renderer is ready.
            ///
            /// Returns whether the renderer is ready.
            bool Is_render_ready() const {
                return m_renderready;
            }

        private:
            bool m_readytodraw = false; ///< Whether this Button is
                                        ///< ready to be drawn
            bool m_renderready = false; ///< Whether this Button is
                                        ///< ready to be rendered.

            std::string m_actiontolistenfor; ///< What action to
                                             ///< listen for possible
                                             ///< clicks.
            std::string m_messagetopostonclick; ///< What message to
                                                ///< post to the
                                                ///< message bus
                                                ///< when this button
                                                ///< is clicked.

            jetfuel::draw::Text::Text_characteristics
                             m_buttontextchars; ///< What text options
                                                ///< should be
                                                ///< implemented.

            jetfuel::core::Message_bus *m_messagebus; ///< Which
                                                      ///< message bus
                                                      ///< to send
                                                      ///< messages
                                                      ///< to.

            jetfuel::draw::Vector2d_int
                           m_buttonposition; ///< Where the button is
                                             ///< on the screen.
            jetfuel::draw::Sprite m_buttonsprite; ///< The button's
                                                  ///< background.
            jetfuel::draw::Rectangle_2d_shape
                          m_buttonoverlay; ///< The button's color
                                           ///< overlay.
            jetfuel::draw::Color m_overlaycolor; ///< The button's
                                                 ///< color for it's
                                                 ///< overlay.
            jetfuel::draw::Text m_buttontext; ///< The button's text.
        };
        /// \class jetfuel::gui::Button
        ///
        /// A clickable button with a Sprite background displaying an
        /// image, a color overlay, and text.
        ///
        /// Code Example:
        ///     jetfuel::draw::Scene_manager scenemanager;
        ///     jetfuel::draw::Scene scene1(1);
        ///     jetfuel::core::Message_bus messagebus;
        ///     jetfuel::gui::Button button;
        ///     jetfuel::draw::Image buttonimage("button.png",
        ///                                      &scenemanager);
        ///     jetfuel::control::UIS_manager UISmanager(&messagebus,
        ///                                       scenemanager.Get_window_id());
        ///     jetfuel::control::UIS_interpreter UISinterpreter(&messagebus);
        ///     jetfuel::draw::Text::Text_characteristics textchars;
        ///     jetfuel::draw::Font font("default.ttf");
        ///
        ///     if(!scenemanager.Create_window("Hello Buttons!",
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
        ///     scene1.Attach_drawable(&button,1);
        ///
        ///     if(!button.Load_base_button_image(backgroundimage)){
        ///         std::cerr << "[!]ERROR with loading from image! Error is:" <<
        ///         IMG_GetError() << "\n";
        ///     }
        ///
        ///     button.Set_position(jetfuel::draw::Vector2d_int(0,0));
        ///
        ///     textchars.textstring = "hello";
        ///     textchars.font = font;
        ///
        ///     button.Set_button_text_characteristics(textchars);
        ///
        ///     scenemanager.Draw_current_scene();
    } /* namespace gui */
} /* namespace jetfuel */

#endif /* JETFUELGUI_BUTTON_H_ */
