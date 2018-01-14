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

#include "stringconversions.h"

char *String_conversions::Convert_wide_char_to_narrow_char(
								const wchar_t *widechar){
	const size_t charsize = wcslen(widechar)+1;

	char *returnvalue = new char[charsize];

	wcstombs(returnvalue, widechar, charsize);

	return returnvalue;
}

wchar_t *String_conversions::Convert_narrow_char_to_wide_char(
									const char *narrowchar){
	const size_t charsize = strlen(narrowchar)+1;

	wchar_t *returnvalue = new wchar_t[charsize-1];

	mbstowcs(returnvalue, narrowchar, charsize);

	return returnvalue;
}