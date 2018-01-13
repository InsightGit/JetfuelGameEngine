/*
* Jetfuel Game Engine- A SDL-based 2D game-engine
* Copyright (C) 2017 InfernoStudios
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

#include "UISinterpreter.h"

namespace jetfuel {
    namespace control {

        UIS_interpreter::UIS_interpreter(jetfuel::core::Message_bus *bus) {
            m_messagebus = bus;
        }

        Action UIS_interpreter::Interpret(){
            // Checks whether a UIS action exists
            // and if so, it looks at that
            // action's input state (up or down) and input_type.
            Action returnvalue;

            std::string actionword;

            if(Does_a_UIS_message_exist(&actionword)){
                    std::string action;

                    std::string inputtype(&actionword[actionword.size()-2]);

                    // Input type detection

                    if(inputtype == "Kb"){
                       returnvalue.inputtype = Action::Input_type::Keyboard;
                    }else if(inputtype == "Mo"){
                        returnvalue.inputtype = Action::Input_type::Mouse;
                    }else{
                        returnvalue.action = "Nothing to interpret.";
                    }

                    // Input state detection

                    for(int i = 0; actionword.length() > i; ++i){

                        if(actionword[i] == '['){
                            i += 11;
                        }else if(actionword[i] != 'S'){
                            action += actionword[i];
                        }else{
                            std::string currentword = std::string()+
                                                      actionword[i]+
                                                      actionword[i+1]+
                                                      actionword[i+2]+
                                                      actionword[i+3]+
                                                      actionword[i+4]+
                                                      actionword[i+5];
                            if(currentword=="State="){
                                if(actionword[i+6] == 'U'){
                                    returnvalue.inputstate =
                                    Action::Input_state::Up;
                                }else if(actionword[i+6] == 'D'){
                                    returnvalue.inputstate =
                                    Action::Input_state::Down;                                
                                }else{
                                    returnvalue.action = "Nothing to interpret.";
                                }
                                
                                break;
                            }else{
                                action += actionword[i];
                            }
                        }
                    }

                    action.erase(remove_if(action.begin(), action.end(),
                                          isspace),action.end());

                    returnvalue.action = action;
            }else{
                returnvalue.action = "Nothing to interpret.";
            }


            return returnvalue;
        }

    } /* namespace control */
} /* namespace jetfuel */
