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

#include <jetfuellocale.h>

#include "../stringconversions.h"

#if defined(_MSC_VER) // If on Visual Studio, export function
	#define EXPORT __declspec(dllexport)
#else
	#define EXPORT 
#endif

extern "C"{

    // jetfuel::locale::Locale_string wrappers

	EXPORT jetfuel::locale::Locale_string *Locale_string_new(){
        return new jetfuel::locale::Locale_string();
    }

	EXPORT wchar_t *Locale_string_get_locale_string_id(jetfuel::locale::
											Locale_string *localestring) {
        return String_conversions::Convert_narrow_char_to_wide_char(
									localestring->stringid.c_str());
    }

	EXPORT void Locale_string_set_locale_string_id(
		jetfuel::locale::Locale_string *localestring, wchar_t *stringid){
        localestring->stringid = String_conversions::
			Convert_wide_char_to_narrow_char(stringid);
    }

	EXPORT wchar_t *Locale_string_get_locale_string(
								jetfuel::locale::Locale_string *localestring){
        return String_conversions::Convert_narrow_char_to_wide_char(
										localestring->string.c_str());
    }

	EXPORT void Locale_string_set_locale_string(jetfuel::locale::Locale_string
                                            *localestring, wchar_t *string){
        localestring->string = String_conversions::
			Convert_wide_char_to_narrow_char(string);
    }

    // jetfuel::locale::String_locale_file wrappers

	EXPORT jetfuel::locale::String_locale_file *String_locale_file_new(){
        return new jetfuel::locale::String_locale_file();
    }

	EXPORT wchar_t *String_locale_file_load_string_locale_file(jetfuel::locale::
            String_locale_file *stringlocalefile, wchar_t *filename,
            wchar_t *localename){
        const char *errorresult = stringlocalefile->Load_string_locale_file(
			String_conversions::Convert_wide_char_to_narrow_char(filename),
		String_conversions::Convert_wide_char_to_narrow_char(localename));
		
		wchar_t *returnvalue;

		if (errorresult[0] != '\0') {
			returnvalue =
				String_conversions::Convert_narrow_char_to_wide_char(errorresult);
		} else {
			returnvalue = L"None";
		}

		delete errorresult;

        return returnvalue;
    }

	EXPORT bool String_locale_file_is_locale_file_set(jetfuel::locale::
            String_locale_file *stringlocalefile){
        return stringlocalefile->Is_locale_file_set();
    }

	EXPORT int String_locale_file_get_locale_string_vector_size(jetfuel::locale::
                                        String_locale_file *stringlocalefile){
        return stringlocalefile->Get_locale_string_vector().size();
    }

	EXPORT jetfuel::locale::Locale_string
    *String_locale_file_get_locale_string_vector_element(jetfuel::locale::
            String_locale_file *stringlocalefile, int place){
        jetfuel::locale::Locale_string *localestring = new jetfuel::locale::
                                                       Locale_string();

        if(stringlocalefile->Get_locale_string_vector().size() <= place){
            throw jetfuel::core::exceptions::Out_of_vector_range_exception();
        }
        *localestring = stringlocalefile->Get_locale_string_vector().at(place);

        return localestring;
    }

	EXPORT wchar_t *String_locale_file_get_string_locale_file_name(
						jetfuel::locale::String_locale_file *stringlocalefile){
        return String_conversions::Convert_narrow_char_to_wide_char(
					stringlocalefile->Get_string_locale_file_name().c_str());
    }

	EXPORT wchar_t *String_locale_file_get_string_locale_file_locale_name(
					jetfuel::locale::String_locale_file *stringlocalefile){
        return String_conversions::Convert_narrow_char_to_wide_char(
			stringlocalefile->Get_string_locale_file_locale_name().c_str());
    }

    // jetfuel::locale::String_locale_manager wrappers

	EXPORT jetfuel::locale::String_locale_manager 
		*String_locale_manager_new(){
        return new jetfuel::locale::String_locale_manager();
    }

	EXPORT bool String_locale_manager_load_string_locale_file(jetfuel::locale::
                            String_locale_manager *stringlocalemanager,
                            jetfuel::locale::String_locale_file
                            *stringlocalefile){
        return stringlocalemanager->Load_string_locale_file(*stringlocalefile);
    }

	EXPORT wchar_t *String_locale_manager_get_active_locale(jetfuel::locale::
                                    String_locale_manager *stringlocalemanager){
        return String_conversions::Convert_narrow_char_to_wide_char(
				stringlocalemanager->Get_active_locale().c_str());
    }

	EXPORT bool String_locale_manager_set_active_locale(jetfuel::locale::
                                String_locale_manager *stringlocalemanager,
                                wchar_t *localename){
        return stringlocalemanager->Set_active_locale(
			String_conversions::Convert_wide_char_to_narrow_char(localename));
    }

	EXPORT jetfuel::locale::String_locale_file
    *String_locale_manager_get_active_string_locale_file(jetfuel::locale::
                                String_locale_manager *stringlocalemanager){
        jetfuel::locale::String_locale_file *returnvalue =
                new jetfuel::locale::String_locale_file();

        *returnvalue = stringlocalemanager->Get_active_string_locale_file();

        return returnvalue;
    }

	EXPORT wchar_t *String_locale_manager_get_string_from_id(jetfuel::locale::
                                String_locale_manager *stringlocalemanager,
                                wchar_t *stringid){
        return String_conversions::Convert_narrow_char_to_wide_char(
							stringlocalemanager->Get_string_from_id(
                         String_conversions::
				Convert_wide_char_to_narrow_char(stringid)).c_str());
    }
}
