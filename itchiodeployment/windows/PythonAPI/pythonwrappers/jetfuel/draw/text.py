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
from ctypes import c_wchar_p

from jetfuel.draw.rectangleinterface import rectangle_interface
from jetfuel.draw.color import color

class text(rectangle_interface):

    def __init__(self, jetfuelsoloader, font=None):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        if(font is not None):
            self._jetfuel.Text_new_from_font.argtypes = [c_void_p];
            self._jetfuel.Text_new_from_font.restype = c_void_p;
            
            self.drawableref = self._jetfuel.Text_new_from_font(font.fontref);
        else:
            self._jetfuel.Text_new.restype = c_void_p;
            
            self.drawableref = self._jetfuel.Text_new();
        
    def get_text_render_mode(self):
        self._jetfuel.Text_get_text_render_mode.argtypes = [c_void_p];
        self._jetfuel.Text_get_text_render_mode.restype = c_int;
        
        return self._jetfuel.Text_get_text_render_mode(self.drawableref);
    
    def set_text_render_mode(self, textrendermode):
        self._jetfuel.Text_set_render_mode.argtypes = [c_void_p, c_int];
        
        self._jetfuel.Text_set_render_mode(self.drawableref, textrendermode);
        
    def get_string(self):
        self._jetfuel.Text_get_string.argtypes = [c_void_p];
        self._jetfuel.Text_get_string.restype = c_wchar_p;
        
        return self._jetfuel.Text_get_string(self.drawableref);
    
    def set_string(self, textstring):
        self._jetfuel.Text_set_string.argtypes = [c_void_p, c_wchar_p];
        
        self._jetfuel.Text_set_string(self.drawableref, textstring);
        
    def get_text_color(self):
        self._jetfuel.Text_get_text_color.argtypes = [c_void_p];
        self._jetfuel.Text_get_text_color.restype = c_void_p;
        
        currentcolor = color();
        
        self._jetfuel.Color_delete.argtypes = [c_void_p];
        
        self._jetfuel.Color_delete(currentcolor.colorref);
        
        currentcolor.colorref = self._jetfuel.Text_get_text_color(
                                                 self.drawableref);
                                                 
        return currentcolor;
    
    def set_text_color(self, textcolor):
        self._jetfuel.Text_set_text_color.argtypes = [c_void_p, c_void_p];
        
        self._jetfuel.Text_set_text_color(self.drawableref, textcolor.colorref);
        
    def get_background_color(self):
        self._jetfuel.Text_get_background_color.argtypes = [c_void_p];
        self._jetfuel.Text_get_background_color.restype = c_void_p;
        
        currentcolor = color();
        
        self._jetfuel.Color_delete.argtypes = [c_void_p];
        
        self._jetfuel.Color_delete(currentcolor.colorref);
        
        currentcolor.colorref = self._jetfuel.Text_get_background_color(
                                                 self.drawableref);
                                                 
        return currentcolor;
    
    def set_background_color(self, backgroundcolor):
        self._jetfuel.Text_set_background_color.argtypes = [c_void_p, c_void_p];
        
        self._jetfuel.Text_set_background_color(self.drawableref, 
                                          backgroundcolor.colorref);
                                          
    def get_font_outline_width(self):
        self._jetfuel.Text_get_font_outline_width.argtypes = [c_void_p];
        self._jetfuel.Text_get_font_outline_width.restype = c_int;
        
        return self._jetfuel.Text_get_font_outline_width(self.drawableref);
    
    def set_font_outline_width(self, fontoutline):
        self._jetfuel.Text_set_font_outline_width.argtypes = [c_void_p, c_int];
        
        self._jetfuel.Text_set_font_outline_width(self.drawableref, fontoutline);
        
    def get_kerning_status(self):
        self._jetfuel.Text_get_kerning_status.argtypes = [c_void_p];
        self._jetfuel.Text_get_kerning_status.restype = c_bool;
        
        return self._jetfuel.Text_get_kerning_status(self.drawableref);
    
    def set_kerning_status(self, kerningstatus):
        self._jetfuel.Text_set_kerning_status.argtypes = [c_void_p, c_bool];
        
        self._jetfuel.Text_set_kerning_status(self.drawableref, 
                                                  kerningstatus);
                                                  
    def get_font_style(self):
        self._jetfuel.Text_get_font_style.argtypes = [c_void_p];
        self._jetfuel.Text_get_font_style.restype = c_int;
        
        return self._jetfuel.Text_get_font_style(self.drawableref);
    
    def set_font_style(self, fontstyle):
        self._jetfuel.Text_set_font_outline_width.argtypes = [c_void_p, c_int];
        
        self._jetfuel.Text_set_font_outline_width(self.drawableref, fontstyle);
    
    def get_font_size(self):
        self._jetfuel.Text_get_font_size.argtypes = [c_void_p];
        self._jetfuel.Text_get_font_size.restype = c_int;
        
        return self._jetfuel.Text_get_font_size(self.drawableref);
    
    def set_font_size(self, fontsize):
        self._jetfuel.Text_set_font_size.argtypes = [c_void_p, c_int];
        
        self._jetfuel.Text_set_font_size(self.drawableref, fontsize);
            
    def get_font_hinting(self):
        self._jetfuel.Text_get_font_hinting.argtypes = [c_void_p];
        self._jetfuel.Text_get_font_hinting.restype = c_int;
        
        return self._jetfuel.Text_get_font_hinting(self.drawableref);
    
    def set_font_hinting(self, fonthinting):
        self._jetfuel.Text_set_font_hinting.argtypes = [c_void_p, c_int];
        
        self._jetfuel.Text_set_font_size(self.drawableref, fonthinting);
        
    def set_font(self, font):
        self._jetfuel.Text_set_font.argtypes = [c_void_p, c_void_p];
        
        return self._jetfuel.Text_set_font(self.drawableref, font.fontref); 