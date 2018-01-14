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

#include <jetfuelcontrol/UISmanager.h>

namespace jetfuel {
    namespace control {
        UIS_manager::UIS_manager(jetfuel::core::Message_bus *bus,
                                 Uint32 *currentwindowid) {
            m_messagebus = bus;
            m_windowid = currentwindowid;
        }

        void UIS_manager::Open_controller_config_file(
                               const std::string configfilepath){
            Set_file_name(configfilepath);
        }

        void UIS_manager::Process_key_down_event(SDL_Event *event){
            // Gets amount of keys in controller config file, then
            // loops until there are no more actions to process,
            // comparing key names to tell whether a key was
            // pressed, and if it was post a message indicating that
            // that action was activated with a keyboard.

            const int keyidnumber = jsondoc["keyidnumber"].GetInt();

            for(int i = 0; keyidnumber > i; ++i){
                const char *key = SDL_GetKeyName(event->key.keysym.sym);

                char *jsonkey;
                if(jsondoc["Keys"][i]["key"].IsInt()){
                    jsonkey = const_cast<char *>(std::to_string(jsondoc["Keys"]
                    [i]["key"].GetInt()).c_str());
                }else{
                    jsonkey = const_cast<char *>(jsondoc["Keys"][i]
                    ["key"].GetString());
                }

                if(*key == *jsonkey){
                    // Key was pressed, notify message bus

                    Post_message_to_message_bus(std::string("[UIS Action]")+
                    jsondoc["Keys"][i]["action"].GetString()+
                    " State=Down Input_type=Kb");

                    UIS_previous_key previouskey;
                    previouskey.previouskey = jsonkey;
                    previouskey.previousaction = jsondoc["Keys"][i]
                    ["action"].GetString();
                    Push_key_to_past_keys_entered_vector(previouskey);
                }
            }
        }

        void UIS_manager::Process_key_up_event(SDL_Event *event){
            // Loops through the past keys entered vector, comparing
            // key names until it finds the previousaction which
            // the input state has changed from down to up, resulting
            // in that previous action being indicated to the message
            // bus as the state being equal to Up, the input type
            // being equal to a keyboard, and then that past
            // key being erased from the past keys entered vector.

            for(int i = 0; Get_size_of_past_keys_entered_vector() > i; ++i){
                if(SDL_GetKeyName(event->key.keysym.sym) ==
                   Get_past_key_in_vector(i).previouskey){
                      Post_message_to_message_bus(std::string("[UIS Action]")+
                       Get_past_key_in_vector(i).previousaction
                       +std::string(" State=Up")+" Input_type=Kb");
                      Erase_place_in_past_keys_vector(i);
                      break;
                }
            }
        }

        void UIS_manager::Process_mouse_down_event(SDL_Event *event){
            // Finds the mousemove action, then indicates it has
            // changed it's state to Down and that this is a Mouse
            // action to the message bus. It then sets the last mouse
            // action to that action.

            std::string message = std::string("[UIS Action] Mouse_")+
                    jsondoc["Mousemove"]["action"].GetString();

            Post_message_to_message_bus(message+" State=Down Input_type=Mo");
            Set_last_mouse_action(message);
        }

        void UIS_manager::Process_mouse_up_event(){
            // Indicates to the message bus that the last mouse action
            // has changed it's input state from down to up and that
            // this is a mouse action.

            Post_message_to_message_bus("[UIS Action] "+Get_last_mouse_action()+
                                         " State=Up Input_type=Mo");
        }

        void UIS_manager::Process_controller_button_down_event(SDL_Event *event){
            // TODO(Bobby): Implement controller support

            /*const int controllerbuttonidnumber = jsondoc
            ["controllerbuttonidnumber"].GetInt();

            for(int i = 0; controllerbuttonidnumber > i; ++i){
                const char *buttonpressed = SDL_GameControllerGetStringForButton
                (event->cbutton.button);
                if(buttonpressed ==
                   SDL_GameControllerGetButtonFromString(jsondoc
                   ["Controllerbuttons"][i]["button"].GetString())) {
                    Post_message_to_message_bus(jsondoc["Controllerbuttons"][i]
                    ["action"].GetString()+std::string(" State=Down"));
                }
            }*/
        }

        void UIS_manager::Detect_desktop_event(SDL_Event *event){
            // Launches any of the input-specific event processes
            // if need be and the window is active,
            // and updates the window's status if it finds it has
            // changed.

            switch(event->type){
                // Launches input-specific event processes

                if(Is_window_active()){
                    case SDL_KEYDOWN:
                    {
                        Process_key_down_event(event);
                        break;
                    }
                    case SDL_MOUSEBUTTONDOWN:
                    {
                        Process_mouse_down_event(event);
                        break;
                    }
                    case SDL_KEYUP:
                    {
                        Process_key_up_event(event);
                        break;
                    }
                    case SDL_MOUSEBUTTONUP:
                    {
                        Process_mouse_up_event();
                        break;
                    }
                }

                // Updates windows status

                case SDL_WINDOWEVENT_ENTER:
                {
                    if(event->window.windowID == *Get_window_id()){
                        Set_window_active(true);
                    }
                    break;
                }

                case SDL_WINDOWEVENT_LEAVE:
                {
                    if(event->window.windowID == *Get_window_id()){
                        Set_window_active(false);
                    }
                    break;
                }
            }
        }

        void UIS_manager::Detect_mobile_event(SDL_Event *event){
            // Launches any of the input-specific event processes
            // if need be and the window is active,
            // and updates the window's status if it finds it has
            // changed.

            // Updates window's status

            switch(event->type){
                case SDL_APP_WILLENTERFOREGROUND:
                {
                    if(event->window.windowID == *Get_window_id()){
                        Set_window_active(true);
                    }
                    break;
                }
                case SDL_APP_WILLENTERBACKGROUND:
                {
                    if(event->window.windowID == *Get_window_id()){
                        Set_window_active(false);
                    }
                    break;
                }
            }
        }

        void UIS_manager::Process_input_event(SDL_Event *event){
            // Loads up a new version of the JSON file if need be,
            // then begins by posting the beginning UIS message.
            // It then invokes the Detect_desktop_event if running on
            // a desktop system and Detect_mobile_event if running on
            // a mobile system. At the end, it posts the concluding
            // UIS message, and sets the past file name to the current
            // file name.

            // JSON file loading

            if(Get_file_name() != Get_past_file_name()){
                Load_json_file(Get_file_name());
            }

            // Detect platform event function invokation

            if(NEON_COMPILED_OS!="Android" && NEON_COMPILED_OS!="iOS"
                               && NEON_COMPILED_OS != "iOS Simulator"){
                Detect_desktop_event(event);
            }else{
                Detect_mobile_event(event);
            }

            // Process controller button down events

            switch(event->type){
                case SDL_CONTROLLERBUTTONDOWN:
                {
                    Process_controller_button_down_event(event);
                    break;
                }
            }

            Set_past_file_name(Get_file_name());
        }
    } /* namespace control */
} /* namespace jetfuel */
