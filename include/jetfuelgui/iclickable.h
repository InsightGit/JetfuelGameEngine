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

#ifndef JETFUELGUI_ICLICKABLE_H_
#define JETFUELGUI_ICLICKABLE_H_
#include "../jetfuelcontrol/UISinterpreter.h"

namespace jetfuel {
    namespace gui {
        class IClickable{
        public:
        	// TODO(Bobby): Verify we need this destructor here.
			virtual ~IClickable() {};

			/// \brief Checks for clicks on this object.
			///
			/// Checks for clicks on this object, based upon the
			/// Universal Input System Action.
			///
			/// This is a pure virtual function that must be
			/// implemented by any children of this interface.
			///
			/// \param jetfuel::control::Action UISinterpreterdata
            virtual void Check_for_clicks(jetfuel::control::Action
                                          UISinterpreterdata) = 0;
        };
        /// \class jetfuel::gui::IClickable
        ///
        /// A simple interface that clickable object should inherit.
        ///
        /// \see jetfuel::gui::Button
        /// \see jetfuel::gui::Check_box
        /// \see jetfuel::gui::Drop_down_box
    } /* namespace gui */
} /* namespace jetfuel */

#endif /* JETFUELGUI_ICLICKABLE_H_ */
