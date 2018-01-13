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
from ctypes import c_bool

from jetfuel.draw.circleinterface import circle_interface
from jetfuel.draw.color import color

class circle_2d_shape(circle_interface):

    def __init__(self, jetfuelsoloader, x=None, y=None, radius=None):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        self._jetfuel.Circle_2d_shape_new.restype = c_void_p;
        
        if(x is not None and y is not None and radius is not None):
            self._jetfuel.Circle_2d_shape_new_from_circle.restype = c_void_p;
            self.drawableref = self._jetfuel.Circle_2d_shape_new_from_circle(
                                                             x, y, radius);
        else:
            self.drawableref = self._jetfuel.Circle_2d_shape_new();
            
    def get_position_x(self):
        self._jetfuel.Circle_2d_shape_get_position_x.argtypes = [c_void_p];
        self._jetfuel.Circle_2d_shape_get_position_x.restype = c_int;
        
        return self._jetfuel.Circle_2d_shape_get_position_x(self.drawableref);
    
    def get_position_y(self):
        self._jetfuel.Circle_2d_shape_get_position_y.argtypes = [c_void_p];
        self._jetfuel.Circle_2d_shape_get_position_y.restype = c_int;
        
        return self._jetfuel.Circle_2d_shape_get_position_y(self.drawableref);
    
    def set_radius(self, radius):
        self._jetfuel.Circle_2d_shape_set_radius.argtypes = [c_void_p,
                                                             c_int];
        
        self._jetfuel.Circle_2d_shape_set_radius(self.drawableref, radius);
        
    def get_anti_aliasing_status(self):
        self._jetfuel.Circle_2d_shape_get_anti_aliasing_status.argtypes = [
                                                                c_void_p];
        self._jetfuel.Circle_2d_shape_get_anti_aliasing_status.restype = c_bool;
        
        return self._jetfuel.Circle_2d_shape_get_anti_aliasing_status(
                                                     self.drawableref);
    
    def set_anti_aliasing_status(self, aastatus):
        self._jetfuel.Circle_2d_shape_set_anti_aliasing_status.argtypes = [
                                                               c_void_p, c_bool];
        
        self._jetfuel.Circle_2d_shape_set_anti_aliasing_status(self.drawableref, 
                                                               aastatus);
                                                               
    def get_filled_circle_status(self):
        self._jetfuel.Circle_2d_shape_get_filled_circle_status.argtypes = [
                                                                c_void_p];
        self._jetfuel.Circle_2d_shape_get_filled_circle_status.restype = c_bool;
        
        return self._jetfuel.Circle_2d_shape_get_filled_circle_status(
                                                     self.drawableref);
                                                               
    def set_filled_circle_status(self, filledincircle):
        self._jetfuel.Circle_2d_shape_set_filled_circle_status.argtypes = [
                                                               c_void_p, c_bool];
        
        self._jetfuel.Circle_2d_shape_set_filled_circle_status(self.drawableref, 
                                                               filledincircle);
        
    def get_color(self):
        self._jetfuel.Circle_2d_shape_get_color.argtypes = [c_void_p];
        self._jetfuel.Circle_2d_shape_get_color.restype = c_void_p;
        
        returnvalue = color();
        
        self._jetfuel.Color_delete.argtypes = [c_void_p];
        
        self._jetfuel.Color_delete(returnvalue.colorref);
        
        returnvalue.colorref = self._jetfuel.Circle_2d_shape_get_color(
                                                               self.drawableref);
        
        return returnvalue;
    
    def set_color(self, color):
        self._jetfuel.Circle_2d_shape_set_color.argtypes = [c_void_p,
                                                            c_void_p];
        self._jetfuel.Circle_2d_shape_set_color(self.drawableref,
                                                color.colorref);