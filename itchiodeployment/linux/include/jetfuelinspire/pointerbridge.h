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

#ifndef JETFUELINSPIRE_POINTERBRIDGE_H_
#define JETFUELINSPIRE_POINTERBRIDGE_H_

#include <vector>
#include <string>

#include <mutex>

namespace jetfuel {
    namespace inspire {
        class Pointer_bridge {
        public:
            Pointer_bridge() {}

            void *Recieve_pointer(std::string id, bool *found){
                m_vectormutex.lock();

                for(int i = 0; m_pointerids.size() > i; ++i){
                    if(id == m_pointerids[i]){
                        void *returnvalue = m_pointers[i];

                        m_pointers.erase(m_pointers.begin()+i);
                        m_pointerids.erase(m_pointerids.begin()+i);

                        *found = true;

                        m_vectormutex.unlock();

                        return returnvalue;
                    }
                }

                m_vectormutex.unlock();

                *found = false;

                return nullptr;
            }

            void Send_pointer(std::string id, void *pointer){
                m_vectormutex.lock();

                m_pointers.push_back(pointer);
                m_pointerids.push_back(id);

                m_vectormutex.unlock();
            }
        private:
            std::mutex m_vectormutex;

            std::vector<std::string> m_pointerids;

            std::vector<void*> m_pointers;
        };
    } /* namespace inspire */
} /* namespace jetfuel */

#endif /* JETFUELINSPIRE_POINTERBRIDGE_H_ */
