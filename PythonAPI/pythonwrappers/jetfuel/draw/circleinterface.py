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

from ctypes import c_void_p
from ctypes import c_int

from jetfuel.draw.drawable import drawable

class circle_interface(drawable):

    def get_radius(self):
        self._jetfuel.Circle_interface_get_radius.argtypes = [c_void_p];
        self._jetfuel.Circle_interface_get_radius.restype = c_int;
        
        return self._jetfuel.Circle_interface_get_radius(self.drawableref);