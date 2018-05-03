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
from ctypes import c_wchar_p
from ctypes import c_bool

from jetfuel.draw.color import color 

class text_characteristics_replacement(object):
    _jetfuel = None;
    textcharsreplacementref = None;

    def __init__(self, jetfuelsoloader, font=None):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        if(font is not None):
            self._jetfuel.Text_characteristics_new_from_font.argtypes = [
                                                             c_void_p]
            
            self._jetfuel.Text_characteristics_new_from_font.restype = c_void_p;
            
            self.textcharsreplacementref = self._jetfuel.\
              Text_characteristics_new_from_font(font.fontref);
        else:
            self._jetfuel.Text_characteristics_new.restype = c_void_p;
        
            self.textcharsreplacementref = self._jetfuel.\
             Text_characteristics_new();       
    
    def delete_ref(self):
        if(self.textcharsreplacementref is not None): 
            self._jetfuel.Text_characteristics_delete.argtypes = [c_void_p];
            
            self._jetfuel.Text_characteristics_delete(
                                             self.textcharsreplacementref);
             
    def get_render_mode(self):
        self._jetfuel.Text_characteristics_get_render_mode.\
             argtypes = [c_void_p];
        self._jetfuel.Text_characteristics_get_render_mode.\
            restype = c_int;
            
        return self._jetfuel.Text_characteristics_get_render_mode(
                    self.textcharsreplacementref);
            
    def set_render_mode(self, rendermode):
        self._jetfuel.Text_characteristics_set_render_mode.\
             argtypes = [c_void_p, c_int];
             
        self._jetfuel.Text_characteristics_set_render_mode(
            self.textcharsreplacementref, rendermode);
             
    def get_text_string(self):
        self._jetfuel.Text_characteristics_get_text_string.\
             argtypes = [c_void_p];
        self._jetfuel.Text_characteristics_get_text_string.\
             restype = c_wchar_p;
             
        return self._jetfuel.Text_characteristics_get_text_string(
             self.textcharsreplacementref);
             
    def set_text_string(self, textstring):
        self._jetfuel.Text_characteristics_set_text_string.\
             argtypes = [c_void_p, c_wchar_p];
             
        self._jetfuel.Text_characteristics_set_text_string(
            self.textcharsreplacementref, textstring);
            
    def get_text_color(self, jetfuelsoloader):
        self._jetfuel.Text_characteristics_get_text_color.argtypes = [c_void_p];
        self._jetfuel.Text_characteristics_get_text_color.restype = c_void_p;
        
        currentcolor = color(jetfuelsoloader.jetfuelso);
        
        self._jetfuel.Color_delete.argtypes = [c_void_p];
        
        self._jetfuel.Color_delete(currentcolor.colorref);
        
        currentcolor.colorref = self._jetfuel.\
         Text_characteristics_get_text_color(self.textcharsreplacementref);
                                                 
        return currentcolor;
    
    def set_text_color(self, textcolor):
        self._jetfuel.Text_characteristics_set_text_color.argtypes = [c_void_p, 
                                                                      c_void_p];
        
        self._jetfuel.Text_characteristics_set_text_color(
                  self.textcharsreplacementref, textcolor.colorref);
                                          
    def get_background_color(self, jetfuelsoloader):
        self._jetfuel.Text_characteristics_get_background_color.argtypes = [
                                                                c_void_p];
        self._jetfuel.Text_characteristics_get_background_color.restype = \
                                                                c_void_p;
        
        currentcolor = color(jetfuelsoloader.jetfuelso);
        
        self._jetfuel.Color_delete.argtypes = [c_void_p];
        
        self._jetfuel.Color_delete(currentcolor.colorref);
        
        currentcolor.colorref = self._jetfuel.\
        Text_characteristics_get_background_color(self.textcharsreplacementref);
                                                 
        return currentcolor;
    
    def set_background_color(self, backgroundcolor):
        self._jetfuel.Text_set_background_color.argtypes = [c_void_p, c_void_p];
        
        self._jetfuel.Text_set_background_color(self.textcharsreplacementref,
                                                backgroundcolor.colorref);
                                                
    def get_font_outline_width(self):
        self._jetfuel.Text_characteristics_get_font_outline_width.\
             argtypes = [c_void_p];
        self._jetfuel.Text_characteristics_get_font_outline_width.\
             restype = c_int;
            
        return self._jetfuel.\
            Text_characteristics_get_font_outline_width(
                self.textcharsreplacementref);
            
    def set_font_outline_width(self, fontoutline):
        self._jetfuel.Text_characteristics_set_font_outline_width.\
             argtypes = [c_void_p, c_int];
             
        self._jetfuel.Text_characteristics_set_font_outline_width(
            self.textcharsreplacementref, fontoutline);
            
    def get_font_kerning_status(self):
        self._jetfuel.Text_characteristics_get_font_kerning_status.\
             argtypes = [c_void_p];
        self._jetfuel.Text_characteristics_get_font_kerning_status.\
             restype = c_bool;
            
        return self._jetfuel.\
            Text_characteristics_get_font_kerning_status(
                self.textcharsreplacementref);
            
    def set_font_kerning_status(self, kerningstatus):
        self._jetfuel.Text_characteristics_set_font_kerning_status.\
             argtypes = [c_void_p, c_bool];
             
        self._jetfuel.Text_characteristics_set_font_kerning_status(
            self.textcharsreplacementref, kerningstatus);
            
    def get_font_style(self):
        self._jetfuel.Text_characteristics_get_font_style.\
             argtypes = [c_void_p];
        self._jetfuel.Text_characteristics_get_font_style.\
             restype = c_int;
            
        return self._jetfuel.\
            Text_characteristics_get_font_style(
                self.textcharsreplacementref);
            
    def set_font_style(self, fontstyle):
        self._jetfuel.Text_characteristics_set_font_style.\
             argtypes = [c_void_p, c_int];
             
        self._jetfuel.Text_characteristics_set_font_style(
            self.textcharsreplacementref, fontstyle);
            
    def get_font_size(self):
        self._jetfuel.Text_characteristics_get_font_size.\
             argtypes = [c_void_p];
        self._jetfuel.Text_characteristics_get_font_size.\
             restype = c_int;
            
        return self._jetfuel.\
            Text_characteristics_get_font_size(
                self.textcharsreplacementref);
            
    def set_font_size(self, fontsize):
        self._jetfuel.Text_characteristics_set_font_size.\
             argtypes = [c_void_p, c_int];
             
        self._jetfuel.Text_characteristics_set_font_size(
            self.textcharsreplacementref, fontsize);
            
    def get_font_hinting(self):
        self._jetfuel.Text_characteristics_get_font_hinting.\
             argtypes = [c_void_p];
        self._jetfuel.Text_characteristics_get_font_hinting.\
             restype = c_int;
            
        return self._jetfuel.\
            Text_characteristics_get_font_hinting(
                self.textcharsreplacementref);
            
    def set_font_hinting(self, fonthinting):
        self._jetfuel.Text_characteristics_set_font_hinting.\
             argtypes = [c_void_p, c_int];
             
        self._jetfuel.Text_characteristics_set_font_hinting(
            self.textcharsreplacementref, fonthinting);
            
    def get_font(self):
        self._jetfuel.Text_characteristics_get_font.\
             argtypes = [c_void_p];
        self._jetfuel.Text_characteristics_get_font.\
             restype = c_void_p;
            
        return self._jetfuel.\
            Text_characteristics_get_font(
                self.textcharsreplacementref);
