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
from ctypes import c_int

from jetfuel.draw.rectangleinterface import rectangle_interface
from jetfuel.draw.rectangle2dshapecharacteristicsreplacement import \
                    rectangle_2d_shape_characteristics_replacement
from jetfuel.draw.circle2dshapecharacteristicsreplacement import \
                    circle_2d_shape_characteristics_replacement
from jetfuel.control.uisinputactionsreplacement import \
                        uis_input_actions_replacement

class slider(rectangle_interface):
    def __init__(self, jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        self._jetfuel.Slider_new.restype = c_void_p;
        
        self.drawableref = self._jetfuel.Slider_new();
        
    def get_slider_rail_characteristics(self, jetfuelsoloader):
        self._jetfuel.Slider_get_slider_rail_characteristics.argtypes = [
                                                                c_void_p];
        self._jetfuel.Slider_get_slider_rail_characteristics.restype = c_void_p;                                                    
                                                                
        sliderrailchars = self._jetfuel.\
        Slider_get_slider_rail_characteristics(self.drawableref);
        
        return rectangle_2d_shape_characteristics_replacement(jetfuelsoloader,
                                                              sliderrailchars);
                                                              
    def set_slider_rail_characteristics(self, sliderrailchars):
        self._jetfuel.Slider_set_slider_rail_characteristics.argtypes = [
                                                    c_void_p, c_void_p];
                                                    
        self._jetfuel.Slider_set_slider_rail_characteristics(self.drawableref,
                                         sliderrailchars.rect2dshapecharsref);
                                         
    def get_slider_button_characteristics(self, jetfuelsoloader):
        self._jetfuel.Slider_get_slider_button_characteristics.argtypes = [
                                                                c_void_p];
        self._jetfuel.Slider_get_slider_button_characteristics.restype = \
                                                                c_void_p;                                                    
                                                                
        sliderbuttonchars = self._jetfuel.\
        Slider_get_slider_button_characteristics(self.drawableref);
        
        return circle_2d_shape_characteristics_replacement(jetfuelsoloader,
                                                           sliderbuttonchars);
                                                              
    def set_slider_button_characteristics(self, sliderbuttonchars):
        self._jetfuel.Slider_set_slider_button_characteristics.argtypes = [
                                                    c_void_p, c_void_p];
                                                    
        self._jetfuel.Slider_set_slider_button_characteristics(self.drawableref,
                                     sliderbuttonchars.circle2dshapecharsref);
                                     
    def get_number_of_statuses(self):
        self._jetfuel.Slider_get_number_of_statuses.argtypes = [c_void_p];
        self._jetfuel.Slider_get_number_of_statuses.restype = c_uint;
        
        return self._jetfuel.Slider_get_number_of_statuses(self.drawableref);
    
    def set_number_of_statuses(self, statusnumber):
        self._jetfuel.Slider_set_number_of_statuses.argtypes = [c_void_p, 
                                                                c_uint];
                                                                
        self._jetfuel.Slider_set_number_of_statuses(self.drawableref,
                                                    statusnumber);
                                                    
    def get_current_status(self):
        self._jetfuel.Slider_get_current_status.argtypes = [c_void_p];
        self._jetfuel.Slider_get_current_status.restype = c_uint;
        
        return self._jetfuel.Slider_get_current_status(self.drawableref);
    
    def set_current_status(self, currentstatus):
        self._jetfuel.Slider_set_current_status.argtypes = [c_void_p, 
                                                            c_uint];
                                                                
        self._jetfuel.Slider_set_current_status(self.drawableref,
                                                currentstatus);
                                                
    def get_control_scheme(self, jetfuelsoloader):
        self._jetfuel.Slider_get_control_scheme.argtypes = [c_void_p];
        self._jetfuel.Slider_get_control_scheme.restype = c_void_p;
        
        uisinputactionsref = self._jetfuel.Slider_get_control_scheme(
                                                    self.drawableref);
                                                    
        return uis_input_actions_replacement(jetfuelsoloader, 
                                         uisinputactionsref);
                                         
    def set_control_scheme(self, controlscheme):
        self._jetfuel.Slider_set_control_scheme.argtypes = [c_void_p, c_void_p];
        
        self._jetfuel.Slider_set_control_scheme(self.drawableref, 
                                controlscheme.uisinputactionsref);
                                
    def get_position_x(self):
        self._jetfuel.Slider_get_position_x.argtypes = [c_void_p];
        self._jetfuel.Slider_get_position_x.restype = c_int;
        
        return self._jetfuel.Slider_get_position_x(self.drawableref);
    
    def get_position_y(self):
        self._jetfuel.Slider_get_position_y.argtypes = [c_void_p];
        self._jetfuel.Slider_get_position_y.restype = c_int;
        
        return self._jetfuel.Slider_get_position_y(self.drawableref);
    
    def set_position(self, x, y):
        self._jetfuel.Slider_set_position.argtypes = [c_void_p, c_int, c_int];
        
        self._jetfuel.Slider_set_position(self.drawableref, x, y);
        
    def get_size_width(self):
        self._jetfuel.Slider_get_rect_to_draw_width.argtypes = [c_void_p];
        self._jetfuel.Slider_get_rect_to_draw_width.restype = c_int;
        
        return self._jetfuel.Slider_get_rect_to_draw_width(self.drawableref);
    
    def get_size_height(self):
        self._jetfuel.Slider_get_rect_to_draw_height.argtypes = [c_void_p];
        self._jetfuel.Slider_get_rect_to_draw_height.restype = c_int;
        
        return self._jetfuel.Slider_get_rect_to_draw_height(self.drawableref);
