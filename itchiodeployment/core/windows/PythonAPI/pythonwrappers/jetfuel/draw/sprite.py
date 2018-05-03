#     Jetfuel Game Engine- A SDL-based 2D game-engine
#     Copyright (C) 2018 InfernoStudios
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

from jetfuel.draw.rectangleinterface import rectangle_interface

class sprite(rectangle_interface):
    
    def __init__(self, jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        self._jetfuel.Sprite_new.restype = c_void_p;
        
        self.drawableref = self._jetfuel.Sprite_new();
        
    def load_from_image(self, image):
        self._jetfuel.Sprite_dynamic_load_from_image.argtypes = [c_void_p,
                                                                 c_void_p];
        
        self._jetfuel.Sprite_dynamic_load_from_image(self.drawableref, 
                                       image.imageref);