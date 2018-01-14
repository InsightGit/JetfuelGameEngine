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

#include <jetfuelcore.h>

#define MAX_MESSAGE_SIZE 131072

#if defined(_MSC_VER)
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT 
#endif

extern "C"{
    // Wrappers for jetfuel::core::Message_bus

    EXPORT void Message_bus_post_message_to_message_bus(
		jetfuel::core::Message_bus *messagebus, const wchar_t *message){
        char cstringmessage[MAX_MESSAGE_SIZE];

        wcstombs(cstringmessage,message,
                 MAX_MESSAGE_SIZE);

        messagebus->Post_message(cstringmessage);
    }

	EXPORT bool Message_bus_does_message_exist(jetfuel::core::Message_bus *messagebus,
                                        const wchar_t *message){
        char cstringmessage[MAX_MESSAGE_SIZE];

        wcstombs(cstringmessage,message,
                 MAX_MESSAGE_SIZE);

        return messagebus->Does_message_exist(cstringmessage);
    }
}
