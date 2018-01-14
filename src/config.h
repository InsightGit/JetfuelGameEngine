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

#ifndef CONFIG_H_
#define CONFIG_H_

// This is the configuration header file. Preprocessor macros are defined here.
// These macros provide various useful stuff, including the library version number,
// the Operating System, and whether the program was compiled in Debug mode.

// Version number definitions
#define NEON_VERSION_MAJOR 0
#define NEON_VERSION_MINOR 1
#define NEON_VERSION_PATCH 0

// Operating System definitions

#if defined(_WIN32)
    #define NEON_COMPILED_OS "Windows"
	#undef main
#elif defined(unix) || defined(__unix__) || defined(__unix)
  #if defined(__APPLE__) || defined(__MACH__)
    #include "TargetConditionals.h"
    #if defined(TARGET_IPHONE_SIMULATOR)
         #define NEON_COMPILED_OS "iOS Simulator"
    #elif defined(TARGET_OS_IPHONE)
        #define NEON_COMPILED_OS "iOS"
    #elif defined(TARGET_OS_MAC)
          #define NEON_COMPILED_OS "macOS"
    #else
        #error "Unknown Apple platform"
    #endif

  #elif defined(__linux__) || defined(linux) || defined(__linux)
    #if defined(__ANDROID__)
        #define NEON_COMPILED_OS "Android"
    #else
        #define NEON_COMPILED_OS "Linux"
    #endif
  #elif defined(__FreeBSD__)
    #define NEON_COMPILED_OS "FreeBSD"
  #endif
#else
    #error "Unknown platform"
#endif


#endif /* CONFIG_H_ */
