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

#include "../jetfuelcontrol/uisinputactionsreplacement.h"

#if defined(_MSC_VER)
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT 
#endif

extern "C" {
    // jetfuel::control::Uis_input_actions_replacement

    EXPORT jetfuel::control::Uis_input_actions_replacement
    *Uis_input_actions_replacement_new(){
        return new jetfuel::control::Uis_input_actions_replacement();
    }

	EXPORT wchar_t *Uis_input_actions_replacement_get_keyboard_message_to_watch(
               jetfuel::control::Uis_input_actions_replacement *uisinputactions){
        std::wstring messagetowatch = uisinputactions->keyboardmessagetowatch;

        wchar_t *returnvalue = new wchar_t[messagetowatch.size()+1];

        wcscpy(returnvalue, messagetowatch.c_str());

        return returnvalue;
    }

	EXPORT void Uis_input_actions_replacement_set_keyboard_message_to_watch(
            jetfuel::control::Uis_input_actions_replacement *uisinputactions,
            wchar_t *keyboardmessagetowatch){
        uisinputactions->keyboardmessagetowatch = std::wstring(
                                                     keyboardmessagetowatch);
    }

	EXPORT wchar_t *Uis_input_actions_replacement_get_mouse_message_to_watch(
               jetfuel::control::Uis_input_actions_replacement *uisinputactions){
        std::wstring messagetowatch = uisinputactions->mousemessagetowatch;

        wchar_t *returnvalue = new wchar_t[messagetowatch.size()+1];

        wcscpy(returnvalue, messagetowatch.c_str());

        return returnvalue;
    }

	EXPORT void Uis_input_actions_replacement_set_mouse_message_to_watch(
            jetfuel::control::Uis_input_actions_replacement *uisinputactions,
            wchar_t *mousemessagetowatch){
        uisinputactions->mousemessagetowatch = std::wstring(mousemessagetowatch);
    }

	EXPORT wchar_t *Uis_input_actions_replacement_get_joystick_message_to_watch(
               jetfuel::control::Uis_input_actions_replacement *uisinputactions){
        std::wstring messagetowatch = uisinputactions->joystickmessagetowatch;

        wchar_t *returnvalue = new wchar_t[messagetowatch.size()+1];

        wcscpy(returnvalue, messagetowatch.c_str());

        return returnvalue;
    }

	EXPORT void Uis_input_actions_replacement_set_joystick_message_to_watch(
            jetfuel::control::Uis_input_actions_replacement *uisinputactions,
            wchar_t *joystickmessagetowatch){
        uisinputactions->joystickmessagetowatch = std::wstring(
                                                    joystickmessagetowatch);
    }

	EXPORT wchar_t *Uis_input_actions_replacement_get_touch_message_to_watch(
               jetfuel::control::Uis_input_actions_replacement *uisinputactions){
        std::wstring messagetowatch = uisinputactions->touchmessagetowatch;

        wchar_t *returnvalue = new wchar_t[messagetowatch.size()+1];

        wcscpy(returnvalue, messagetowatch.c_str());

        return returnvalue;
    }

	EXPORT void Uis_input_actions_replacement_set_touch_message_to_watch(
            jetfuel::control::Uis_input_actions_replacement *uisinputactions,
            wchar_t *touchmessagetowatch){
        uisinputactions->touchmessagetowatch = std::wstring(touchmessagetowatch);
    }

	EXPORT wchar_t *Uis_input_actions_replacement_get_message_to_send_upon_click(
               jetfuel::control::Uis_input_actions_replacement *uisinputactions){
        std::wstring messagetosend = uisinputactions->messagetosenduponclick;

        wchar_t *returnvalue = new wchar_t[messagetosend.size()+1];

        wcscpy(returnvalue, messagetosend.c_str());

        return returnvalue;
    }

	EXPORT void Uis_input_actions_replacement_set_message_to_send_upon_click(
            jetfuel::control::Uis_input_actions_replacement *uisinputactions,
            wchar_t *messagetosenduponclick){
        uisinputactions->messagetosenduponclick = std::wstring(
                                                    messagetosenduponclick);
    }

	EXPORT jetfuel::core::Message_bus
     *Uis_input_actions_replacement_get_message_bus_to_send_message_to(jetfuel::
                     control::Uis_input_actions_replacement *uisinputactions){
        return uisinputactions->messagebustosendmessageto;
    }

	EXPORT void Uis_input_actions_replacement_set_message_bus_to_send_message_to(
            jetfuel::control::Uis_input_actions_replacement *uisinputactions,
                          jetfuel::core::Message_bus *messagebustosendmessageto){
        uisinputactions->messagebustosendmessageto = messagebustosendmessageto;
    }
}
