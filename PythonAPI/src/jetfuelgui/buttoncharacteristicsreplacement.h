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

#include <jetfuelgui.h>

#include "../jetfueldraw/textcharacteristicsreplacement.h"

namespace jetfuel{
    namespace gui{
        class Button_characteristics_replacement{
        public:
            Button_characteristics_replacement(){}

            Button_characteristics_replacement(jetfuel::gui::Menu::
                                      Button_characteristics buttonchars){
                image = buttonchars.image;
                color = buttonchars.color;

                textcharsreplacement =
                 jetfuel::draw::Text_characteristics_replacement(buttonchars.
                                                             buttontextchars);
            }

            jetfuel::gui::Menu::Button_characteristics
             Convert_to_button_chars_struct(){
                jetfuel::gui::Menu::Button_characteristics returnvalue;

                returnvalue.image = image;
                returnvalue.color = color;
                returnvalue.buttontextchars = textcharsreplacement.
                                        Convert_to_text_chars_struct();

                return returnvalue;
            }

            jetfuel::draw::Image image;
            jetfuel::draw::Color color;
            jetfuel::draw::Text_characteristics_replacement textcharsreplacement;
        };
    }
}

