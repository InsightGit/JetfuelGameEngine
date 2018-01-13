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
from ctypes import c_uint

class color(object):
    _jetfuel = None;
    colorref = None;

    def __init__(self, jetfuelsoloader, red=None, green=None, blue=None, 
                 alpha=255):
        self._jetfuel = jetfuelsoloader.jetfuelso;  
        self._jetfuel.Color_new.restype = c_void_p;
        
        if(red is not None and green is not None and blue is not None):
            self._jetfuel.Color_new_from_rgba.restype = c_void_p;
            self._jetfuel.Color_new_from_rgba.argtypes = [c_uint, c_uint,
                                                          c_uint, c_uint];
            self.colorref = self._jetfuel.Color_new_from_rgba(red, green, blue,
                                                              alpha);
        else:
            self.colorref = self._jetfuel.Color_new();
                  
    #TODO: Make this exit and quit NOT delete_ref!
    def delete_ref(self):
        if(self.colorref != None):
            self._jetfuel.Color_delete.argtypes = [c_void_p];
            self._jetfuel.Color_delete(self.colorref);
            
    def get_red_color(self):
        self._jetfuel.Color_get_red.restype = c_uint;
        self._jetfuel.Color_get_red.argtypes = [c_void_p];
        
        return self._jetfuel.Color_get_red(self.colorref);

    def set_red_color(self, redcolor):
        self._jetfuel.Color_set_red.argtypes = [c_void_p,
                                                c_uint];
                                                
        return self._jetfuel.Color_set_red(self.colorref,
                                           redcolor);
  
    def get_green_color(self):
        self._jetfuel.Color_get_green.restype = c_uint;
        self._jetfuel.Color_get_green.argtypes = [c_void_p];
        
        return self._jetfuel.Color_get_green(self.colorref);

    def set_green_color(self, greencolor):
        self._jetfuel.Color_set_green.argtypes = [c_void_p,
                                                c_uint];
                                                
        self._jetfuel.Color_set_green(self.colorref,
                                      greencolor);  
                                           
    def get_blue_color(self):
        self._jetfuel.Color_get_blue.restype = c_uint;
        self._jetfuel.Color_get_blue.argtypes = [c_void_p];
        
        return self._jetfuel.Color_get_blue(self.colorref);
    
    def set_blue_color(self, bluecolor):
        self._jetfuel.Color_set_blue.argtypes = [c_void_p,
                                                 c_uint];
                                                
        self._jetfuel.Color_set_blue(self.colorref,
                                     bluecolor);

    def get_alpha_layer(self):
        self._jetfuel.Color_get_alpha.argtypes = [c_void_p]
        self._jetfuel.Color_get_alpha.restype = c_uint;                                       
                                            
        return self._jetfuel.Color_get_alpha(self.colorref);

    def set_alpha_layer(self, alphalayer):
        self._jetfuel.Color_set_alpha.argtypes = [c_void_p,
                                                 c_uint];
                                                
        self._jetfuel.Color_set_alpha(self.colorref,
                                     alphalayer);