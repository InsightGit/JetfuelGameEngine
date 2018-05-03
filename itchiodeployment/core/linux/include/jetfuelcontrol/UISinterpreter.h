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

#ifndef JETFUELCONTROL_UISINTERPRETER_H
#define JETFUELCONTROL_UISINTERPRETER_H
#include <sstream>
#include <mutex>
#include <algorithm>

#include <jetfuelcore/messagebus.h>

#include <jetfueldraw/vector2d.h>

namespace jetfuel {
    namespace control {
        struct Action{
            std::string action;
            enum Input_state{
                Up,
                Down
            };
            enum Input_type{
                Mouse,
                Keyboard,
                Joystick,
                Touch
            };
            Input_state inputstate;
            Input_type inputtype;
        };    
        /// \struct jetfuel::control::Action
        ///
        /// An interpreted Action produced from an Universal Input
        /// System Interpreter(jetfuel::control::UIS_interpreter).
        ///
        /// For a code example, refer to the code sample provided with
        /// jetfuel::control::UIS_interpreter.
        
        struct UIS_input_actions{
            std::string keyboardmessagetowatch;
            std::string mousemessagetowatch;
            std::string joystickmessagetowatch;
            std::string touchmessagetowatch;
            
            std::string messagetosenduponclick;
            jetfuel::core::Message_bus *messagebustosendmessageto;
        };
        /// \struct jetfuel::control::UIS_input_actions
        ///
        /// A collection of messagess to watch from differing input
        /// methods, what message to send upon the message to watch
        /// being existent, then a pointer to which Message_bus to
        /// send the message to.

        
        class UIS_interpreter {
        public:
            /// \brief Constructs an Universal Input System
            /// interpreter with a Message_bus pointer.
            ///
            /// Constructs an Universal Input System
            /// interpreter with a Message_bus pointer.
            ///
            /// \param jetfuel::core::Message_bus *bus
            UIS_interpreter(jetfuel::core::Message_bus *bus);

            /// \brief Interprets Universal Input System manager
            /// messages from the assigned message bus.
            ///
            /// Interprets Universal Input System manager
            /// messages from the assigned message bus and returns
            /// the first interpreted action.
            Action Interpret();
        protected:
            /// \brief Checks whether a message exists in the assigned
            /// message bus.
            ///
            /// Checks whether a message exists in the assigned
            /// message bus.
            ///
            /// \param std::string message
            bool Does_a_UIS_message_exist(std::string *firstmessage){
                return m_messagebus->Does_a_UIS_message_exist(firstmessage);
            }

            /// \brief Gets the next message in the assigned
            /// message bus.
            ///
            /// Gets the next message in the assigned
            /// message bus.
            std::string Get_next_message(){
                return m_messagebus->Get_next_message();
            }
        private:
            ///////////////////
            /// member data ///
            ///////////////////

            jetfuel::core::Message_bus *m_messagebus; ///< Message bus to
            ///^ interpret messages from.
        };

        /// \class jetfuel::control::UIS_interpreter
        ///
        /// An interpreter for the messages produced by the Universal
        /// Input System manager, or jetfuel::control::UIS_manager.
        /// When used in tandem with the Universal Input System
        ///(or UIS) manager, it allows your players to
        /// modify the bindings for certain in-game actions
        /// via a simple JSON file, makes implementing a control
        /// binding option in-game easier, and allows your program
        /// to perform the same action regardless if the player is
        /// playing with a Keyboard & Mouse, a controller, or even a
        /// touch-screen.
        ///
        /// Code example:
        ///
        ///     C++ Code File:
        /// 	\code
        ///            jetfuel::core::Message_bus messagebus;
        ///            jetfuel::draw::Scene_manager scenemanager;
        ///            jetfuel::draw::Scene scene1(1);
        ///            jetfuel::control::UIS_manager UISmanager(&messagebus,
        ///                                                  scenemanager.
        ///                                                  Get_window_id());
        ///            jetfuel::control::UIS_interpreter UISinterpreter(&messagebus
        ///                                                                   );
        ///
        ///            if(!scenemanager.Create_window(windowlabel,
        ///                                           windowposition,
        ///                                           windowsize)){
        ///                 std::cerr << "[!]ERROR with creating sdl window!"
        ///                 << "Error is:" << SDL_GetError() << "\n";
        ///                 // Quit the application
        ///            }
        ///
        ///            if(!scenemanager.Create_renderer()){
        ///                 std::cerr << "[!]ERROR with creating sdl renderer!"
        ///                 << "Error is:" << SDL_GetError() << "\n";
        ///                 // Quit the application
        ///            }
        ///
        ///            UISmanager.Open_controller_config_file("UISConfig.json");
        ///
        ///            while(true){
        ///                jetfuel::control::Action UISactions =
        ///                UISinterpreter.Interpret();
        ///                if(UISactions.action != "Nothing to interpret."
        ///                   ){
        ///                        if(UISactions.action == "Say_hello"){
        ///                            if(UISactions.inputstate ==
        ///                              UISactions.Down){
        ///                               std::cout << "Why hello there!\n";
        ///                            }else if(UISactions.inputstate ==
        ///                                     UISactions.Up){
        ///                                std::cout
        ///                                << "Why goodbye there!\n";
        ///                            }
        ///                        }
        ///                    }
        ///            }
        ///            for(int i = 0; messagebus.Get_SDL_events_size() > i; ++i){
        ///                SDL_Event event = messagebus.Get_SDL_event(i);
        ///                if(event.type = SDL_QUIT){
        ///                    // Quit the application
        ///                }else{
        ///                    UISmanager.Process_input_event(&event);
        ///                }
        ///            }
        /// 	\endcode
        ///
        ///     JSON file(UISConfig.json):
        /// 	\code
        ///         {
        ///             "keyidnumber": 1,
        ///             "Keys": [
        ///               {
        ///                 "key": "A",
        ///                 "action": "Say_hello"
        ///               }
        ///             ]
        ///         }
        /// 	\endcode

    } /* namespace control */
} /* namespace jetfuel */

#endif /* JETFUELCONTROL_UISINTERPRETER_H */
