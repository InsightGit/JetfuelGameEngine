/*
 *   Project Neon Graphical Example - An example of Project Neon, the moddable 2D RPG game engine
 *   Copyright (C) 2018 InfernoStudios
 *
 *  Project Neon Graphical Example is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Project Neon Graphical Example is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Project Neon Graphical Example.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#define ASSETS false

#ifdef _WIN32
#define getcwd _getcwd
	#define _CRTDBG_MAP_ALLOC  
    #include <stdlib.h>  
    #include <crtdbg.h>
#else
#include <unistd.h>

#endif
#define winnull 0xcccccccc

#include <jetfueldraw.h>
#include <jetfuelcontrol.h>
#include <jetfuelgui.h>
#include <jetfuelmedia.h>
#include <jetfuellocale.h>

int main(int argc, char **argv){
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    const std::string windowlabel = "Jetfuel Game Engine Graphical Example";
    const jetfuel::draw::Vector2d_int windowposition(50,50);
    const jetfuel::draw::Vector2d_int windowsize(1920,1080);
    const jetfuel::draw::Image windowicon("exampleicon.png",
                                          jetfuel::draw::Vector2d_int(16, 16));

    jetfuel::core::Message_bus messagebus(true);
    jetfuel::draw::Scene_manager scenemanager;
    jetfuel::draw::Scene scene2(2);

    jetfuel::draw::Sprite background;
    jetfuel::draw::Image backgroundimage;
    jetfuel::draw::Circle_2d_shape circle(jetfuel::draw::Circle2d_int(300,300,30));
    jetfuel::draw::Font globalfont("default.ttf");

    jetfuel::control::UIS_interpreter UISinterpreter(&messagebus);

    jetfuel::gui::Menu menu(500,100,50);
    jetfuel::gui::Check_box checkbox;
    jetfuel::gui::Drop_down_box dropdownbox;
    jetfuel::gui::Progress_bar progressbar;
    jetfuel::gui::Slider slider;

    jetfuel::gui::Menu::Button_characteristics resumebutton;
    jetfuel::gui::Menu::Button_characteristics quitbutton;
    jetfuel::draw::Text::Text_characteristics checkboxlabelchars;
    jetfuel::draw::Text::Text_characteristics dropdownboxchars;
    jetfuel::draw::Rectangle_2d_shape::Rectangle_2d_shape_characteristics
            sliderrailchars;
    jetfuel::draw::Circle_2d_shape::Circle_2d_shape_characteristics
            sliderbuttonchars;
    jetfuel::control::UIS_input_actions sliderinputactions;

    jetfuel::media::Sound_effect soundeffect;
    jetfuel::media::Music music;

    jetfuel::locale::String_locale_file englishlocalefile;
    jetfuel::locale::String_locale_file germanlocalefile;
    jetfuel::locale::String_locale_manager localemanager;

    bool limitclickstimerset = false;
    jetfuel::core::Timer limitclickstimer(0.1);

    char buffer[4096];
    char *cwdchar = getcwd(buffer, sizeof(buffer));
    std::string currentworkingdirectory = cwdchar;

    std::cout << "Current working directory is " << currentworkingdirectory <<
              "\n";

    bool checkboxspawned = false;

    if(!scenemanager.Create_window(windowlabel, windowposition, windowsize)){
        SDL_Log("%s",SDL_GetError());
        return 1;
    }

    if(!scenemanager.Create_renderer()){
        SDL_Log("%s",SDL_GetError());
        return 2;
    }

    jetfuel::control::UIS_manager UISmanager(&messagebus,
                                             scenemanager.Get_window_id());

    jetfuel::draw::Image buttonimage;
    jetfuel::draw::Image checkboxactiveimage("checkboxactive.png",
                                             &scenemanager);
    jetfuel::draw::Image checkboxdisabledimage("checkboxdisabled.png",
                                               &scenemanager);
    jetfuel::draw::Image dropdownboximage("dropdownbox.png", &scenemanager);
    jetfuel::draw::Image progressbarholderimage(
            "progressbarholder.png", &scenemanager);

    UISmanager.Open_controller_config_file("UISConfig.json");

    messagebus.Post_message("initwindow");

    while(true){
        if(messagebus.Do_messages_exist()){
            if(messagebus.Does_message_exist("initwindow")){
                scenemanager.Set_universal_background_color(jetfuel::draw::
                                                             Color::White);
                bool executedstatus;
                std::string error;
                jetfuel::draw::Scene scene1(1);

                backgroundimage.Set_image("background.jpg", &scenemanager);
                scenemanager.Switch_current_scene(&scene1);
                scene1.Attach_drawable(&background,1);

                if(!background.Load_from_image(backgroundimage)){
                    std::cerr << "[!]ERROR with loading from image! Error is:"
                              << backgroundimage.Get_error() << "\n";
                    return 1;
                }
                background.Set_position(jetfuel::draw::Vector2d_int(0,0));

                scene1.Attach_drawable(&circle,4);
                circle.Set_anti_aliasing_status(true);
                circle.Set_filled_circle_status(true);
                circle.Set_color(jetfuel::draw::Color::Green);

                scenemanager.Switch_current_scene(&scene2);

                if(!soundeffect.Load_audio_file("sfx.ogg")){
                    SDL_Log("%s",Mix_GetError());
                    return 5;
                }

                if(!music.Load_audio_file("music.ogg")){
                    SDL_Log("%s",Mix_GetError());
                    return 6;
                }

                if(!englishlocalefile.Load_string_locale_file("EnglishLocale.json",
                                                              "english",&error)){
                    SDL_Log("%s",error.c_str());
                    return 7;
                }

                if(!germanlocalefile.Load_string_locale_file(
                        "GermanLocale.json",
                        "german",&error)){
                    SDL_Log("%s",error.c_str());
                    return 7;
                }

                localemanager.Load_string_locale_file(englishlocalefile);
                localemanager.Load_string_locale_file(germanlocalefile);

                localemanager.Set_active_locale("english");

                messagebus.Post_message("menudraw");
            }else if(messagebus.Does_message_exist("menudraw")){
                scene2.Attach_drawable(&menu,3);
                menu.Set_position(jetfuel::draw::Vector2d_int(460,340));

                buttonimage.Set_image("button.png",&scenemanager);
                resumebutton.image = buttonimage;
                quitbutton.image = buttonimage;

                resumebutton.color = jetfuel::draw::Color(0,255,0,100);
                quitbutton.color = jetfuel::draw::Color(255,0,0,100);

                resumebutton.buttontextchars.font = globalfont;
                quitbutton.buttontextchars.font = globalfont;

                resumebutton.buttontextchars.rendermode =
                        jetfuel::draw::Text::Render_mode::Blended;
                quitbutton.buttontextchars.rendermode =
                        jetfuel::draw::Text::Render_mode::Blended;
                resumebutton.buttontextchars.textstring = "Resume";
                quitbutton.buttontextchars.textstring = "Quit";

                if(!menu.Add_button(resumebutton,"Mouse_click","resume",
                                    &messagebus, false) ||
                   !menu.Add_button(quitbutton,"Mouse_click","quit",
                                    &messagebus, false)){
                    SDL_Log("%s",buttonimage.Get_error().c_str());
                    return 1;
                }
            }else if(messagebus.Does_message_exist("spawncheckbox")){
                scene2.Attach_drawable(&checkbox,2);
                checkbox.Dynamic_load_check_box_images(checkboxactiveimage,
                                               checkboxdisabledimage);
                checkbox.Set_UIS_action_to_watch("Mouse_click");
                checkbox.Set_position(jetfuel::draw::Vector2d_int(500,300));
                checkboxspawned = true;

                checkboxlabelchars.rendermode =
                        jetfuel::draw::Text::Render_mode::Blended;
                checkboxlabelchars.textstring = localemanager.
                        Get_string_from_id("checkboxlabel");
                checkboxlabelchars.font = globalfont;
                checkboxlabelchars.textcolor = jetfuel::draw::Color::White;
                checkbox.Set_label_characteristics(checkboxlabelchars,
                                                   jetfuel::gui::Check_box::
                                                   Label_position::Right,
                                                   50);
                messagebus.Post_message("dropdownboxspawn");
            }else if(messagebus.Does_message_exist("dropdownboxspawn")){
                scene2.Attach_drawable(&dropdownbox,2);
                if(!dropdownbox.Load_base_box_image(dropdownboximage,
                                                    jetfuel::draw::Color::White,
                                                    jetfuel::draw::Vector2d_uint(
                                                            45,20))){
                    SDL_Log("%s",dropdownboximage.Get_error().c_str());
                    return 1;
                }
                dropdownbox.Set_UIS_action_to_listen_for("Mouse_click");
                dropdownbox.Set_position(jetfuel::draw::Vector2d_int(750,300));

                dropdownboxchars.font = globalfont;
                dropdownboxchars.textcolor = jetfuel::draw::Color::Cyan;
                dropdownboxchars.rendermode = jetfuel::draw::Text::Render_mode::
                Blended;
                dropdownbox.Set_option_text_characteristics(dropdownboxchars);
                dropdownbox.Add_option("Default");
                dropdownbox.Add_option("Linux");
                dropdownbox.Add_option("macOS");
                dropdownbox.Add_option("Windows");

                messagebus.Post_message("progressbarspawn");
            }else if(messagebus.Does_message_exist("progressbarspawn")){
                scene2.Attach_drawable(&progressbar,2);

                progressbar.Set_progress_bar(progressbarholderimage,
                                             jetfuel::draw::Color::Magenta,
                                             jetfuel::draw::Rect2d_int(20,20,20,20),400);
                progressbar.Set_position(jetfuel::draw::Vector2d_int(900,100));
                progressbar.Set_progress_bar_progress(200);

                messagebus.Post_message("sliderspawn");
            }else if(messagebus.Does_message_exist("sliderspawn")){
                scene2.Attach_drawable(&slider, 6);

                slider.Set_position(jetfuel::draw::Vector2d_int(600,500));
                slider.Set_number_of_statuses(5);

                sliderrailchars.size = jetfuel::draw::Vector2d_int(200,10);
                sliderrailchars.fillcolor = jetfuel::draw::Color::White;
                slider.Set_slider_rail_characteristics(sliderrailchars);

                sliderbuttonchars.radius = 20;
                sliderbuttonchars.color = jetfuel::draw::Color::Green;
                sliderbuttonchars.filledcirclestatus = true;
                slider.Set_slider_button_characteristics(sliderbuttonchars);

                sliderinputactions.mousemessagetowatch = "Mouse_click";
                slider.Set_control_scheme(sliderinputactions);
            }else if(messagebus.Does_message_exist("resume")){
                if(!limitclickstimerset){
                    scene2.Disable_drawable(&menu);
                    messagebus.Post_message("dropdownboxspawn");
                    checkboxspawned = true;

                    limitclickstimer.Start();
                    limitclickstimerset = true;
                }else if(limitclickstimer.Has_timer_finished()){
                    limitclickstimerset = false;
                }

            }else if(messagebus.Does_message_exist("quit")){
                return 0;
            }else if(messagebus.Does_message_exist("draw")){
                scenemanager.Draw_current_scene();
            }

            for(int i = 0; messagebus.Get_SDL_events_size() > i; ++i){
                SDL_Event event = messagebus.Get_SDL_event(i);

                if(event.type == SDL_QUIT){
                    return 0;
                }else{
                    UISmanager.Process_input_event(&event);
                }
            }

            jetfuel::control::Action UISaction =
                    UISinterpreter.Interpret();
            if(UISaction.action != "Nothing to interpret."){
                if(UISaction.action == "Say_hello"){
                    if(UISaction.inputstate == UISaction.Down){
                        std::cout << "Why hello there!\n";
                    }else if(UISaction.inputstate ==
                             UISaction.Up){
                        std::cout << "Why goodbye there!\n";
                    }
                }else if(UISaction.inputstate == UISaction.Down){
                    if(UISaction.action == "Bar_Down"){
                        progressbar.Set_progress_bar_progress(progressbar.
                                Get_progress_bar_progress()-5);
                    }else if(UISaction.action == "Bar_Up"){
                        progressbar.Set_progress_bar_progress(progressbar.
                                Get_progress_bar_progress()+5);
                    }else if(UISaction.action == "Play_Sfx"){
                        soundeffect.Play();
                    }else if(UISaction.action == "Play_music"){
                        music.Play();
                    }
                }
            }

            if(checkboxspawned){
                checkbox.Check_for_clicks(UISaction);
                dropdownbox.Check_for_clicks(UISaction);
                slider.Check_for_clicks(UISaction);
            }else{
                menu.Check_for_clicks(UISaction);
            }

            messagebus.Post_message("draw");
        }
    }
}