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

from jetfuel.draw.color import color

class rectangle_2d_shape_characteristics_replacement(object):
    _jetfuel = None;
    rect2dshapecharsref = None;
    
    def __init__(self, jetfuelsoloader, customref=None):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        if(customref is None):
            self._jetfuel.\
            Rectangle_2d_shape_characteristics_replacement_new.restype = \
                                                                c_void_p;                                                
            self.rect2dshapecharsref = self._jetfuel.\
            Rectangle_2d_shape_characteristics_replacement_new();
        else:
            self.rect2dshapecharsref = customref;
                        
    def get_position_x(self):
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_position_x.\
        argtypes = [c_void_p];
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_position_x.\
        restype = c_int;
        
        return self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_position_x(
                                                 self.rect2dshapecharsref);
            
    def get_position_y(self):
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_position_y.\
        argtypes = [c_void_p];
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_position_y.\
        restype = c_int;
        
        return self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_position_y(
                                                self.rect2dshapecharsref);
            
    def set_position(self, x, y):
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_set_position.argtypes = [
                                                        c_void_p, c_int, c_int];
                                                        
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_set_position(
                                    self.rect2dshapecharsref, x, y);
                                    
    def get_size_width(self):
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_size_width.\
        argtypes = [c_void_p];
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_size_width.\
        restype = c_int;
        
        return self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_size_width(
                                                 self.rect2dshapecharsref);
            
    def get_size_height(self):
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_size_height.\
        argtypes = [c_void_p];
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_size_height.\
        restype = c_int;
        
        return self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_size_height(
                                                self.rect2dshapecharsref);
            
    def set_size(self, width, height):
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_set_size.argtypes = [
                                                        c_void_p, c_int, c_int];
                                                        
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_set_size(
                        self.rect2dshapecharsref, width, height);
                        
    def get_fill_color(self, jetfuelsoloader):
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_fill_color.\
        argtypes = [c_void_p];
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_fill_color.\
        restype = c_void_p;
        
        returnvalue = color(jetfuelsoloader.jetfuelso);
        
        self._jetfuel.Color_delete.argtypes = [c_void_p];
        
        self._jetfuel.Color_delete(returnvalue.colorref);
        
        returnvalue.colorref = self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_fill_color(
                                                self.rect2dshapecharsref);
                                                 
        return returnvalue;
    
    def set_fill_color(self, fillcolor):
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_set_fill_color.\
        argtypes = [c_void_p, c_void_p];
        
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_set_fill_color(
                        self.rect2dshapecharsref, fillcolor.colorref);
                        
    def get_outline_color(self, jetfuelsoloader):
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_outline_color.\
        argtypes = [c_void_p];
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_outline_color.\
        restype = c_void_p;
        
        returnvalue = color(jetfuelsoloader.jetfuelso);
        
        self._jetfuel.Color_delete.argtypes = [c_void_p];
        
        self._jetfuel.Color_delete(returnvalue.colorref);
        
        returnvalue.colorref = self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_get_outline_color(
                                                self.rect2dshapecharsref);
                                                 
        return returnvalue;
    
    def set_outline_color(self, outlinecolor):
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_set_outline_color.\
        argtypes = [c_void_p, c_void_p];
        
        self._jetfuel.\
        Rectangle_2d_shape_characteristics_replacement_set_outline_color(
                        self.rect2dshapecharsref, outlinecolor.colorref);
                            