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

#ifndef JETFUELDRAW_TEXTCHARACTERISTICSREPLACEMENT_H_
#define JETFUELDRAW_TEXTCHARACTERISTICSREPLACEMENT_H_

#include <string>

#include <jetfueldraw/text.h>

namespace jetfuel {
    namespace draw {

        class Text_characteristics_replacement {
        public:
            Text_characteristics_replacement(){}

            Text_characteristics_replacement(jetfuel::draw::Font *fonttouse) {
                font = *fonttouse;
            }

            Text_characteristics_replacement(jetfuel::draw::Text::
                                             Text_characteristics textchars){
                switch(textchars.rendermode){
                    case jetfuel::draw::Text::Render_mode::Solid:
                        rendermode = 1;
                        break;
                    case jetfuel::draw::Text::Render_mode::Shaded:
                        rendermode = 2;
                        break;
                    case jetfuel::draw::Text::Render_mode::Blended:
                        rendermode = 3;
                        break;
                }

                textstring = textchars.textstring;
                textcolor = textchars.textcolor;
                backgroundcolor = textchars.backgroundcolor;
                fontoutlinewidth = textchars.fontoutlinewidth;
                kerningstatus = textchars.kerningstatus;
                fontstyle = textchars.fontstyle;
                fontsize = textchars.fontsize;

                switch(textchars.fonthinting){
                    case jetfuel::draw::Text::Font_hinting::Normal:
                        rendermode = 1;
                        break;
                    case jetfuel::draw::Text::Font_hinting::Light:
                        rendermode = 2;
                        break;
                    case jetfuel::draw::Text::Font_hinting::Mono:
                        rendermode = 3;
                        break;
                    case jetfuel::draw::Text::Font_hinting::None:
                        rendermode = 3;
                        break;
                }

                font = textchars.font;

                previousfont = font;
            }

            jetfuel::draw::Text::Text_characteristics
             Convert_to_text_chars_struct(){
                jetfuel::draw::Text::Text_characteristics returnvalue;

                switch(rendermode){
                    case 1:
                        returnvalue.rendermode = jetfuel::draw::Text::
                                                 Render_mode::Solid;
                        break;
                    case 2:
                        returnvalue.rendermode = jetfuel::draw::Text::
                                                 Render_mode::Shaded;
                        break;
                    case 3:
                        returnvalue.rendermode = jetfuel::draw::Text::
                                                 Render_mode::Blended;
                        break;
                }

                returnvalue.textstring = textstring;
                returnvalue.textcolor = textcolor;
                returnvalue.backgroundcolor = backgroundcolor;
                returnvalue.fontoutlinewidth = fontoutlinewidth;
                returnvalue.kerningstatus = kerningstatus;
                returnvalue.fontstyle = fontstyle;
                returnvalue.fontsize = fontsize;

                switch(fonthinting){
                    case 1:
                        returnvalue.fonthinting = jetfuel::draw::Text::
                                                  Font_hinting::Normal;
                        break;
                    case 2:
                        returnvalue.fonthinting = jetfuel::draw::Text::
                                                 Font_hinting::Light;
                        break;
                    case 3:
                        returnvalue.fonthinting = jetfuel::draw::Text::
                                                  Font_hinting::Mono;
                        break;
                    case 4:
                        returnvalue.fonthinting = jetfuel::draw::Text::
                                                  Font_hinting::None;
                        break;
                }

                returnvalue.font = previousfont;

                return returnvalue;
            }

            int rendermode = 1;
            std::string textstring;

            jetfuel::draw::Color textcolor;
            jetfuel::draw::Color backgroundcolor;
            unsigned int fontoutlinewidth = 0;
            bool kerningstatus = true;
            int fontstyle = FONTSTYLE_NORMAL;
            unsigned int fontsize = 20;
            int fonthinting = 1;
            Font font;

            Font previousfont;
        };



    } /* namespace draw */
} /* namespace jetfuel */

#endif /* JETFUELDRAW_TEXTCHARACTERISTICSREPLACEMENT_H_ */
