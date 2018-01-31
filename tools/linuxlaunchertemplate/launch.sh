#!/bin/bash 

#     Jetfuel Game Engine Linux Launcher Script - A simple Linux
#     launcher bash script that launches your game with it's SO files.
#     Copyright (C) 2017 InfernoStudios
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

SOPATH="" # SO file path inside current working directory
EXECUTABLEPATH="Jetfuel Graphical Example" # Executable file path inside  
                # current working directory

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd):"$SOPATH"

chmod +x "$EXECUTABLEPATH"

./"$EXECUTABLEPATH"
