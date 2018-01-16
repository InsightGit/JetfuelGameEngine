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

#include <jetfuellocale/stringlocalefile.h>

namespace jetfuel {
    namespace locale {

        bool String_locale_file::Load_string_locale_file(
                const std::string filename,
                const std::string localename,
                std::string *error){
            rapidjson::Document jsondoc;

            m_filename = filename;

            if(localename != "NoLocale"){
                m_localename = localename;
            }else{
                *error = "Cannot name locale \"NoLocale\".";
                return false;
            }

            std::string jsonfilecontents =
                    Convert_json_file_to_string(m_filename);

            jsondoc.Parse(jsonfilecontents.c_str());

            Set_locale_file_set(false);

            Clear_locale_string_vector();

            if(jsondoc.IsObject()){
                if(jsondoc["strings"].IsArray()){
                    for(rapidjson::SizeType i = 0; jsondoc["strings"].Size() > i;
                        ++i){
                        if(jsondoc["strings"][i]["stringid"].IsString()){
                            if(jsondoc["strings"][i]["string"].IsString()){
                                Locale_string currentlocalestring;
                                currentlocalestring.stringid =
                                 jsondoc["strings"][i]["stringid"].GetString();
                                currentlocalestring.string =
                                 jsondoc["strings"][i]["string"].GetString();

                                Push_back_locale_string_into_vector(
                                                            currentlocalestring);
                            }else{
                                *error =
                                 std::string("Could not find \"string\"")+
                                 "JSON String in "+mingwtostringpatch
                                 ::to_string(i)+
                                 " array position";
                                return false;
                            }
                        }else{
                            *error =
                             std::string("Could not find \"stringid\"")+
                             "JSON String in "+mingwtostringpatch
                             ::to_string(i)+
                             " array position";
                            return false;
                        }
                    }

                    Set_locale_file_set(true);
                    return true;
                }else{
                    *error = "No \"strings\" JSON array found";
                }
            }else{
                *error = "No root JSON object found";
            }

            return false;
        }

		char *String_locale_file::Load_string_locale_file(
		const std::string filename, const std::string localename) {
			std::string error = "None";

			Load_string_locale_file(filename, localename, &error);

			char *returnvalue = new char[error.length() + 1];

			strcpy(returnvalue, error.c_str());

			return returnvalue;
		}
    } /* namespace locale */
} /* namespace jetfuel */
