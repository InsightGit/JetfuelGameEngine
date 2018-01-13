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

#ifndef JETFUELGUI_ICLICKABLE_H_
#define JETFUELGUI_ICLICKABLE_H_
#include "../jetfuelcontrol/UISinterpreter.h"

namespace jetfuel {
    namespace gui {
        class IClickable{
        public:
			virtual ~IClickable() {};

            virtual void Check_for_clicks(jetfuel::control::Action
                                          UISinterpreterdata) = 0;
        };
    } /* namespace gui */
} /* namespace jetfuel */

#endif /* JETFUELGUI_ICLICKABLE_H_ */
