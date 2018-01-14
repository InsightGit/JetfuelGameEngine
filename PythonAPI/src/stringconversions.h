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

#ifndef STRINGCONVERSIONS_H_
#define STRINGCONVERSIONS_H_

#include <cstdlib>
#include <cstring>
#include <wchar.h>

class String_conversions {
public:
	static char *Convert_wide_char_to_narrow_char(const wchar_t *widechar);
	static wchar_t *Convert_narrow_char_to_wide_char(const char *narrowchar);
};

#endif
