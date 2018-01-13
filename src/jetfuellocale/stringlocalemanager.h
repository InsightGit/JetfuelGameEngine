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

#ifndef JETFUELLOCALE_STRINGLOCALEMANAGER_H
#define JETFUELLOCALE_STRINGLOCALEMANAGER_H

#include <jetfuellocale/stringlocalefile.h>

namespace jetfuel {
    namespace locale {

        class String_locale_manager {
        public:
            String_locale_manager(){}

            bool Load_string_locale_file(String_locale_file localefile){
                if(localefile.Is_locale_file_set()){
                    m_localefiles.push_back(localefile);

                    return true;
                }

                return false;
            }

            std::string Get_active_locale(){
                return m_activelocale;
            }

            String_locale_file Get_active_string_locale_file() const{
                return *m_currentlocalefile;
            }

            bool Set_active_locale(const std::string localename){
                bool foundlocale = false;

                for(int i = 0; m_localefiles.size() > i; ++i){
                    if(localename == m_localefiles[i].
                       Get_string_locale_file_locale_name()){
                        m_currentlocalefile = &m_localefiles[i];
                        m_activelocale =
                         m_currentlocalefile->
                         Get_string_locale_file_locale_name();
                        foundlocale=true;
                        break;
                    }
                }

                return foundlocale;
            }

            std::string Get_string_from_id(const std::string stringid) const{
                std::vector<Locale_string> stringidindex = m_currentlocalefile->
                                                      Get_locale_string_vector();
                for(int i = 0; stringidindex.size() > i; ++i){
                    if(stringidindex[i].stringid == stringid){
                        return stringidindex[i].string;
                    }
                }

                return "";
            }
        private:
            std::string m_activelocale = "NoLocale";

            std::vector<String_locale_file> m_localefiles;

            String_locale_file *m_currentlocalefile;
        };

    } /* namespace locale */
} /* namespace jetfuel */

#endif /* JETFUELLOCALE_STRINGLOCALEMANAGER_H */
