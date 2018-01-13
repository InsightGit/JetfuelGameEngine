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

#ifndef JETFUELLOCALE_STRINGLOCALEFILE_H
#define JETFUELLOCALE_STRINGLOCALEFILE_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include <rapidjson/document.h>

namespace jetfuel {
    namespace locale {

        namespace mingwtostringpatch{
            template <typename T>
            std::string to_string(const T objecttoconvert){
                std::ostringstream outputstringstream;

                outputstringstream << objecttoconvert;

                return outputstringstream.str();
            }
        }

        struct Locale_string{
            std::string stringid;
            std::string string;
        };

        class String_locale_file {
        public:
            String_locale_file() {}

            bool Load_string_locale_file(const std::string filename,
                                         const std::string localename,
                                         std::string *error);
			char *Load_string_locale_file(const std::string filename,
										  const std::string localename);

            bool Is_locale_file_set() const{
                return m_localefileset;
            }

            std::vector<Locale_string> Get_locale_string_vector() const{
                return m_localestrings;
            }

            std::string Get_string_locale_file_name() const{
                return m_filename;
            }

            std::string Get_string_locale_file_locale_name() const{
                return m_localename;
            }
        protected:
            std::string Convert_json_file_to_string(const std::string filepath){
                std::ifstream file(filepath);

                std::stringstream buffer;

                buffer << file.rdbuf();

                return buffer.str();
            }

            void Set_locale_file_set(const bool localefileset){
                m_localefileset = localefileset;
            }

            void Clear_locale_string_vector(){
                m_localestrings.clear();
            }

            void Push_back_locale_string_into_vector(Locale_string localestring){
                m_localestrings.push_back(localestring);
            }

        private:
            bool m_localefileset;

            std::vector<Locale_string> m_localestrings;

            std::string m_localename;
            std::string m_filename;
        };

    } /* namespace locale */
} /* namespace jetfuel */

#endif /* JETFUELLOCALE_STRINGLOCALEFILE_H_ */
