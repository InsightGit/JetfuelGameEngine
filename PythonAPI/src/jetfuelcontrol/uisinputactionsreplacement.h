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

#ifndef JETFUELCONTROL_UISINPUTACTIONSREPLACEMENT_H_
#define JETFUELCONTROL_UISINPUTACTIONSREPLACEMENT_H_

#include <string>
#include <locale>
#include <codecvt>

#include <jetfuelcontrol.h>

namespace jetfuel {
    namespace control {
        class Uis_input_actions_replacement {
        public:
            Uis_input_actions_replacement() {}

            Uis_input_actions_replacement(
                    jetfuel::control::UIS_input_actions inputactions){
                std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>
                                                    wstringconvertor;

                keyboardmessagetowatch = wstringconvertor.from_bytes(
                                inputactions.keyboardmessagetowatch);
                mousemessagetowatch = wstringconvertor.from_bytes(
                                inputactions.mousemessagetowatch);
                joystickmessagetowatch = wstringconvertor.from_bytes(
                                inputactions.joystickmessagetowatch);
                touchmessagetowatch = wstringconvertor.from_bytes(
                                inputactions.touchmessagetowatch);
                messagetosenduponclick = wstringconvertor.from_bytes(
                                inputactions.messagetosenduponclick);

                messagebustosendmessageto =
                inputactions.messagebustosendmessageto;
            }

            jetfuel::control::UIS_input_actions
              Convert_to_uis_input_actions(){
                jetfuel::control::UIS_input_actions returnvalue;

                returnvalue.keyboardmessagetowatch =
                        std::string(keyboardmessagetowatch.begin(),
                                    keyboardmessagetowatch.end());;
                returnvalue.mousemessagetowatch =
                        std::string(mousemessagetowatch.begin(),
                                    mousemessagetowatch.end());
                returnvalue.joystickmessagetowatch =
                        std::string(joystickmessagetowatch.begin(),
                                    joystickmessagetowatch.end());
                returnvalue.touchmessagetowatch =
                        std::string(touchmessagetowatch.begin(),
                                    touchmessagetowatch.end());

                returnvalue.messagetosenduponclick =
                        std::string(messagetosenduponclick.begin(),
                                    messagetosenduponclick.end());
                returnvalue.messagebustosendmessageto =
                              messagebustosendmessageto;

                return returnvalue;
            }

            std::wstring keyboardmessagetowatch;
            std::wstring mousemessagetowatch;
            std::wstring joystickmessagetowatch;
            std::wstring touchmessagetowatch;

            std::wstring messagetosenduponclick;
            jetfuel::core::Message_bus *messagebustosendmessageto;
        };
    } /* namespace control */
} /* namespace jetfuel */

#endif /* JETFUELCONTROL_UISINPUTACTIONSREPLACEMENT_H_ */
