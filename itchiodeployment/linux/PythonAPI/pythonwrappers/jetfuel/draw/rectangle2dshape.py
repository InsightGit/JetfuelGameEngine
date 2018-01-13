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

from jetfuel.draw.rectangleinterface import rectangle_interface

from ctypes import c_void_p
from ctypes import c_int

from jetfuel.draw.color import color

class rectangle_2d_shape(rectangle_interface):

    def __init__(self, jetfuelsoloader, x=None, y=None, width=None,
                 height=None):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        if(x is not None and y is not None and width is not None and 
           height is not None):
            self._jetfuel.Rectangle_2d_shape_new_from_rect.restype = c_void_p;
            self._jetfuel.Rectangle_2d_shape_new_from_rect.argtypes = [c_int,      
                                                            c_int, c_int, c_int];
            self.drawableref = self._jetfuel.Rectangle_2d_shape_new_from_rect(
                                                            x, y, width, height);
        else:
            self._jetfuel.Rectangle_2d_shape_new.restype = c_void_p;
            
            self.drawableref = self._jetfuel.Rectangle_2d_shape_new();                                                  
            
    def get_fill_color(self):
        self._jetfuel.Rectangle_2d_shape_get_fill_color.argtypes = [c_void_p];
        self._jetfuel.Rectangle_2d_shape_get_fill_color.restype = c_void_p;
        
        returnvalue = color();
        
        self._jetfuel.Color_delete.argtypes = [c_void_p];
        
        self._jetfuel.Color_delete(returnvalue.colorref);
        
        returnvalue.colorref = self._jetfuel.Rectangle_2d_shape_get_fill_color(
                                                               self.drawableref);
        
        return returnvalue;
    
    def set_fill_color(self, fillcolor):
        self._jetfuel.Rectangle_2d_shape_set_fill_color.argtypes = [c_void_p,
                                                                    c_void_p];
        self._jetfuel.Rectangle_2d_shape_set_fill_color(self.drawableref,
                                                        fillcolor.colorref);
                                                        
    def get_outline_color(self):
        self._jetfuel.Rectangle_2d_shape_get_outline_color.argtypes = [c_void_p];
        self._jetfuel.Rectangle_2d_shape_get_outline_color.restype = c_void_p;
        
        returnvalue = color();
        
        self._jetfuel.Color_delete.argtypes = [c_void_p];
        
        self._jetfuel.Color_delete(returnvalue.colorref);
        
        returnvalue.colorref = self._jetfuel.Rectangle_2d_shape_get_outline_color(
                                                               self.drawableref);
        
        return returnvalue;
    
    def set_outline_color(self, outlinecolor):
        self._jetfuel.Rectangle_2d_shape_set_outline_color.argtypes = [c_void_p,
                                                                       c_void_p];
        self._jetfuel.Rectangle_2d_shape_set_outline_color(self.drawableref,
                                                        outlinecolor.colorref);
                                                        
    def disable_drawing_outline_color(self):
        self._jetfuel.Rectangle_2d_shape_disable_drawing_outline_color.argtypes =[
                                                                     c_void_p];
        
        self._jetfuel.Rectangle_2d_shape_disable_drawing_outline_color(
                                                    self._drawableref);
                                                        
    def get_position_x(self):
        self._jetfuel.Rectangle_2d_shape_get_position_x.argtypes = [c_void_p];
        self._jetfuel.Rectangle_2d_shape_get_position_x.restype = c_int;
        
        return self._jetfuel.Rectangle_2d_shape_get_position_x(self.drawableref);
    
    def get_position_y(self):
        self._jetfuel.Rectangle_2d_shape_get_position_y.argtypes = [c_void_p];
        self._jetfuel.Rectangle_2d_shape_get_position_y.restype = c_int;
        
        return self._jetfuel.Rectangle_2d_shape_get_position_y(self.drawableref);
    
    def set_position(self, x, y):
        self._jetfuel.Rectangle_2d_shape_set_position.argtypes = [c_void_p, 
                                                                  c_int,
                                                                  c_int];
                                                                  
        self._jetfuel.Rectangle_2d_shape_set_position(self.drawableref, x, y);
        
    def get_size_width(self):
        self._jetfuel.Rectangle_2d_shape_get_size_width.argtypes = [c_void_p];
        self._jetfuel.Rectangle_2d_shape_get_size_width.restype = c_int;
        
        return self._jetfuel.Rectangle_2d_shape_get_size_width(self.drawableref);
    
    def get_size_height(self):
        self._jetfuel.Rectangle_2d_shape_get_size_height.argtypes = [c_void_p];
        self._jetfuel.Rectangle_2d_shape_get_size_height.restype = c_int;
        
        return self._jetfuel.Rectangle_2d_shape_get_size_height(
                                                 self.drawableref);
    
    def set_size(self, width, height):
        self._jetfuel.Rectangle_2d_shape_set_size.argtypes = [c_void_p, 
                                                                  c_int,
                                                                  c_int];
                                                                  
        self._jetfuel.Rectangle_2d_shape_set_size(self.drawableref, width, 
                                                      height);
        