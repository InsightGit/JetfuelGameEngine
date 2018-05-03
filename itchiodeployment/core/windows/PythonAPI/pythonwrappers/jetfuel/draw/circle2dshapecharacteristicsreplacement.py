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
from ctypes import c_int
from ctypes import c_bool

from jetfuel.draw.color import color

class circle_2d_shape_characteristics_replacement(object):
    _jetfuel = None;
    circle2dshapecharsref = None;
    
    def __init__(self, jetfuelsoloader, customref=None):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        if(customref is None):
            self._jetfuel.Circle_2d_shape_characteristics_replacement_new.restype = \
                c_void_p;
                
            self.circle2dshapecharsref = self._jetfuel.\
            Circle_2d_shape_characteristics_replacement_new();
        else:
            self.circle2dshapecharsref = customref;
            
    def get_position_x(self):
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_position_x.argtypes = [
                                                                    c_void_p];
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_position_x.restype = \
                                                                        c_int;
                                                                        
        return self._jetfuel.\
            Circle_2d_shape_characteristics_replacement_get_position_x(
                                            self.circle2dshapecharsref);
                                            
    def get_position_y(self):
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_position_y.argtypes = [
                                                                    c_void_p];
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_position_y.restype = \
                                                                        c_int;
                                                                        
        return self._jetfuel.\
            Circle_2d_shape_characteristics_replacement_get_position_y(
                                            self.circle2dshapecharsref);
                                            
    def set_position(self, x, y):
        self._jetfuel.Circle_2d_shape_characteristics_replacement_set_position.\
                                            argtypes = [c_void_p, c_int, c_int];
        self._jetfuel.Circle_2d_shape_characteristics_replacement_set_position(
                                            self.circle2dshapecharsref, x, y);
                                            
    def get_radius(self):
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_radius.argtypes = [
                                                                    c_void_p];
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_radius.restype = c_int;
                                                                        
        return self._jetfuel.\
            Circle_2d_shape_characteristics_replacement_get_radius(
                                            self.circle2dshapecharsref);
                                            
    def set_radius(self, radius):
        self._jetfuel.Circle_2d_shape_characteristics_replacement_set_radius.\
                                                    argtypes = [c_void_p, c_int];
        self._jetfuel.Circle_2d_shape_characteristics_replacement_set_radius(
                                            self.circle2dshapecharsref, radius);
                                            
    def get_aa_status(self):
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_aa_status.argtypes = [
                                                                    c_void_p];
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_aa_status.restype = \
                                                                        c_bool;
                                                                        
        return self._jetfuel.\
            Circle_2d_shape_characteristics_replacement_get_aa_status(
                                            self.circle2dshapecharsref);
                                            
    def set_aa_status(self, aastatus):
        self._jetfuel.Circle_2d_shape_characteristics_replacement_set_aa_status.\
                                                    argtypes = [c_void_p, c_bool];
        self._jetfuel.Circle_2d_shape_characteristics_replacement_set_aa_status(
                                        self.circle2dshapecharsref, aastatus);
                                        
    def get_filled_ciricle_status(self):
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_filled_circle_status.\
                                                        argtypes = [c_void_p];
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_filled_circle_status.\
                                                            restype = c_bool;
                                                                        
        return self._jetfuel.\
            Circle_2d_shape_characteristics_replacement_get_filled_circle_status(
                                                    self.circle2dshapecharsref);
                                            
    def set_filled_circle_status(self, filledcirclestatus):
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_set_filled_circle_status.\
                                                argtypes = [c_void_p, c_bool];
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_set_filled_circle_status(
                                self.circle2dshapecharsref, filledcirclestatus);
                                
                                
    def get_color(self, jetfuelsoloader):
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_color.\
        argtypes = [c_void_p];
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_color.restype = c_void_p;
        
        returnvalue = color(jetfuelsoloader.jetfuelso);
        
        self._jetfuel.Color_delete.argtypes = [c_void_p];
        
        self._jetfuel.Color_delete(returnvalue.colorref);
        
        returnvalue.colorref = self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_get_color(
                                    self.circle2dshapecharsref);
                                                 
        return returnvalue;
    
    def set_color(self, color):
        self._jetfuel.\
        Circle_2d_shape_characteristics_replacement_set_color.argtypes = [
                                                        c_void_p, c_void_p];
        
        self._jetfuel.Circle_2d_shape_characteristics_replacement_set_color(
                                self.circle2dshapecharsref, color.colorref);
                                            
    