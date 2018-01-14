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

#include "messagebus.h"

namespace jetfuel {
    namespace core {
        Message_bus::Message_bus(const bool disablelogging) {
            m_loggingdisabled = disablelogging;
        }

        void Message_bus::Post_message(const std::string message){
            // Add message to internal message vector.
            Queue_message(message);

            // Log posted message if logging is not disabled.
            if(!Is_logging_disabled()){
                std::clog << "[i]New message posted. Message is: '"<< message << "'\n";
            }
        }

        bool Message_bus::Does_a_UIS_message_exist(std::string *message){
            // Checks whether any message begins with "[UIS"(without
            // the quotes of course)

            int messagesize = Get_message_size();

            for(int i = 0; messagesize > i; ++i){
                if(Get_message(i)[0] == char('[') && std::string()+
                   Get_message(i)[1]+Get_message(i)[2]+
                   Get_message(i)[3]=="UIS"){
                    *message = Get_message(i);

                    Erase_message(i);

                    return true;
                }

                messagesize = Get_message_size();
            }

            return false;
        }

        bool Message_bus::Does_message_exist(const std::string message){
            // Get size of message vector and then check if message exists via for loop.

            for(int i = 0;Get_message_size() > i; ++i){
                if(&Get_message(i) != nullptr){
                    if(Get_message(i)==message){
                        Erase_message(i);

                        // Log processed posted message if logging is not disabled.
                        if(!Is_logging_disabled()){
                            std::clog << "[i]Processed posted message. Message is: '"<< message << "'\n";
                        }
                        return true;
                    }
                }else{
                    Erase_message(i);
                }
            }
            return false;
        }

        std::string Message_bus::Get_next_message(){
            const int nextmessageplacement = Get_last_message_placement()+1;
            if(Get_message_size() <= nextmessageplacement){
                return "No next message";
            }else{
                Erase_message(nextmessageplacement);

                // Log processed posted message if logging is not disabled.
                if(!Is_logging_disabled()){
                    std::clog << "[i]Processed posted message. Message is: '"<< Get_message(nextmessageplacement) << "'\n";
                }

                return Get_message(nextmessageplacement);
            }
        }

        void Message_bus::Prepare(){
            // Clear all previous SDL_Events
            m_currentsdlevents.clear();

            // Fill vector with current SDL_Events
            SDL_Event event;
            while(SDL_PollEvent(&event)){
                if(event.type != 1024){
                    m_currentsdlevents.push_back(event);
                }
            }
        }
    } /* namespace core */
} /* namespace jetfuel */
