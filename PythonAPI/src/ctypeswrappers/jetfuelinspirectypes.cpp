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

#include <jetfuelinspire/pointerbridge.h>

#if defined(_MSC_VER)
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT 
#endif

extern "C"{
    EXPORT void *Pointer_bridge_recieve_pointer(jetfuel::inspire::Pointer_bridge
                                         *pointerbridge, wchar_t *id,
                                         bool *found){
        std::wstring idwstring(id);

        std::string idstring(idwstring.begin(), idwstring.end());

        return pointerbridge->Recieve_pointer(idstring, found);
    }

	EXPORT void Pointer_bridge_send_pointer(jetfuel::inspire::Pointer_bridge
                                     *pointerbridge, wchar_t *id,
                                     void *pointer){
        std::wstring idwstring(id);

        std::string idstring(idwstring.begin(), idwstring.end());

        return pointerbridge->Send_pointer(idstring, pointer);
    }
}
