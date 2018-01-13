#     Jetfuel Game Engine- A SDL-based 2D game-engine
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

from ctypes import cdll
from ctypes import c_wchar_p

class jetfuelsoloader(object):
    jetfuelso = None;
    
    def __init__(self, jetfuelsofilepath):
        self.jetfuelso = cdll.LoadLibrary(jetfuelsofilepath);
        
    def get_sdl_error(self):
        self.jetfuelso.Get_sdl_error.restype = c_wchar_p;
        
        sdlerror = self.jetfuelso.Get_sdl_error();
        
        if (sdlerror == None):
            return "";
        else:
            return sdlerror;