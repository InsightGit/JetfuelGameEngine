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
from ctypes import c_wchar_p
from ctypes import c_bool
from ctypes import c_int

from jetfuel.draw.rectangleinterface import rectangle_interface

class text_box(rectangle_interface):
    _jetfuel = None;

    def __init__(self, jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        self._jetfuel.Text_box_new.restype = c_void_p;
        
        self.drawableref = self._jetfuel.Text_box_new();
        
    def is_focused_on(self):
        self._jetfuel.Text_box_is_focused_on.argtypes = [c_void_p];
        
        self._jetfuel.Text_box_is_focused_on.restype = c_bool;
        
        return self._jetfuel.Text_box_is_focused_on(self.drawableref);
        
    def get_current_text(self):
        self._jetfuel.Text_box_get_current_text.argtypes = [c_void_p];
        
        self._jetfuel.Text_box_get_current_text.restype = c_wchar_p;
        
    def get_text_chars(self, jetfuelsoloader):
        self._jetfuel.Text_box_get_text_chars.argtypes = [c_void_p];
        self._jetfuel.Text_box_get_text_chars.restype = c_void_p;

        returnvalue = text_characteristics_replacement(jetfuelsoloader);

        returnvalue.delete_ref();

        returnvalue.textcharsref = self._jetfuel. Text_box_get_text_chars(self.\
                                                                    drawableref);

        return returnvalue;
        
    def set_text_chars(self, textchars):
        self._jetfuel.Text_box_set_text_chars.argtypes = [c_void_p,
                                                          c_void_p];

        self._jetfuel.Text_box_set_text_chars(self.drawableref, 
                                            textchars.textcharsref);
                     
    def get_text_box_box_fill_color(self):
        self._jetfuel.Text_box_get_text_box_box_fill_color.argtypes = [c_void_p\
                                                                              ];
        
        self._jetfuel.Text_box_get_text_box_box_fill_color.restype = c_void_p;
    
        return self._jetfuel.Text_box_get_text_box_box_fill_color(self.\
                                                                drawableref);
                                            
    def set_text_box_box_fill_color(self, color):
        self._jetfuel.Text_box_set_text_box_box_fill_color.argtypes = [c_void_p,
                                                                     c_void_p]; 
        
        self._jetfuel.Text_box_set_text_box_box_fill_color(self.drawableref,
                                                            color.colorref);
                                                            
    def get_position_x(self):
        self._jetfuel.Text_box_get_position_x.argtypes = [c_void_p];

        self._jetfuel.Text_box_get_position_x.restype = c_int;

        return self._jetfuel.Text_box_get_position_x(self.drawableref);

    def get_position_y(self):
        self._jetfuel.Text_box_get_position_y.argtypes = [c_void_p];

        self._jetfuel.Text_box_get_position_y.restype = c_int;

        return self._jetfuel.Text_box_get_position_y(self.drawableref);

    def set_position(self, x, y):
        self._jetfuel.Text_box_set_position.argtypes = [c_void_p, c_int, c_int];

        self._jetfuel.Text_box_set_position(self.drawableref, x, y);
        
    def get_rect_to_draw_x(self):
        self._jetfuel.Text_box_get_rect_to_draw_x.argtypes = [c_void_p];

        self._jetfuel.Text_box_get_rect_to_draw_x.restype = c_int;

        return self._jetfuel.Text_box_get_rect_to_draw_x(self.drawableref);

    def get_rect_to_draw_y(self):
        self._jetfuel.Text_box_get_rect_to_draw_y.argtypes = [
                                                     c_void_p];

        self._jetfuel.Text_box_get_rect_to_draw_y.restype = c_int;

        return self._jetfuel.Text_box_get_rect_to_draw_y(self.drawableref);

    def get_rect_to_draw_width(self):
        self._jetfuel.Text_box_get_rect_to_draw_width.argtypes = [
                                                     c_void_p];

        self._jetfuel.Text_box_get_rect_to_draw_width.restype = c_int;

        return self._jetfuel.Text_box_get_rect_to_draw_width(self.drawableref);

    def get_rect_to_draw_height(self):
        self._jetfuel.Text_box_get_rect_to_draw_height.argtypes = [
                                                     c_void_p];

        self._jetfuel.Text_box_get_rect_to_draw_height.restype = c_int;

        return self._jetfuel.Text_box_get_rect_to_draw_height(self.drawableref);
    
    def get_max_char_limit(self):
        self._jetfuel.Text_box_get_max_char_limit.argtypes = [c_void_p];

        self._jetfuel.Text_box_get_max_char_limit.restype = c_int;

        return self._jetfuel.Text_box_get_max_char_limit(self.drawableref);
    
    def set_max_char_limit(self, maxcharlimit):
        self._jetfuel.Text_box_set_max_char_limit.argtypes = [c_void_p, c_int];
        
        self._jetfuel.Text_box_set_max_char_limit(self.drawableref, \
                                                  maxcharlimit);
