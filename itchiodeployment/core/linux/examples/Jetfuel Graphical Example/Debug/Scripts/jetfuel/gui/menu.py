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

from ctypes import c_uint
from ctypes import c_int 
from ctypes import c_void_p
from ctypes import c_bool
from ctypes import c_wchar_p

from jetfuel.draw.rectangleinterface import rectangle_interface
from jetfuel.draw.image import image

class menu(rectangle_interface):
    def __init__(self, jetfuelsoloader, maxheight=None, columngap=None, 
                 buttongap=None):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        if(maxheight is not None and columngap is not None and 
           buttongap is not None):
            self._jetfuel.Menu_new_from_heights_and_gaps.argtypes = [c_uint,
                                                                     c_uint,
                                                                     c_uint];
            self._jetfuel.Menu_new_from_heights_and_gaps.restype = c_void_p;
            
            self.drawableref = self._jetfuel.Menu_new_from_heights_and_gaps(
                                                                    maxheight,
                                                                    columngap,
                                                                    buttongap);
        else:
            self._jetfuel.Menu_new.restype = c_void_p;
            
            self.drawableref = self._jetfuel.Menu_new();
            print("Constructed empty drawableref!");
                
    def get_max_height(self):
        self._jetfuel.Menu_get_max_height.argtypes = [c_void_p];
        self._jetfuel.Menu_get_max_height.restype = c_uint;
        
        return self._jetfuel.Menu_get_max_height(self.drawableref);
    
    def set_max_height(self, maxheight):
        self._jetfuel.Menu_set_max_height.argtypes = [c_void_p, c_uint];
        
        self._jetfuel.Menu_set_max_height(self.drawableref, maxheight);
        
    def get_column_gap(self):
        self._jetfuel.Menu_get_column_gap.argtypes = [c_void_p];
        self._jetfuel.Menu_get_column_gap.restype = c_uint;
        
        return self._jetfuel.Menu_get_column_gap(self.drawableref);
    
    def set_column_gap(self, columngap):
        self._jetfuel.Menu_set_column_gap.argtypes = [c_void_p, c_uint];
        
        self._jetfuel.Menu_set_column_height(self.drawableref, columngap);
        
    def get_button_gap(self):
        self._jetfuel.Menu_get_button_gap.argtypes = [c_void_p];
        self._jetfuel.Menu_get_button_gap.restype = c_uint;
        
        return self._jetfuel.Menu_get_column_gap(self.drawableref);
    
    def set_button_gap(self, buttongap):
        self._jetfuel.Menu_set_max_height.argtypes = [c_void_p, c_uint];
        
        self._jetfuel.Menu_set_max_height(self.drawableref, buttongap); 
        
    def get_container_box_image(self, jetfuelsoloader):
        self._jetfuel.Menu_get_container_box_image.argtypes = [c_void_p];
        self._jetfuel.Menu_get_container_box_image.restype = c_void_p;
        
        containerboximage = image(jetfuelsoloader);
        
        self._jetfuel.Image_delete.argtypes = [c_void_p];
        
        self._jetfuel.Image_delete(containerboximage.imageref);
        
        containerboximage.imageref = self._jetfuel.Menu_get_container_box_image(
                                                               self.drawableref);
                                                               
        return containerboximage;
    
    def set_container_box_image(self, image, borderwidth, borderheight):
        self._jetfuel.Menu_set_container_box_image.argtypes = [c_void_p, 
                                                               c_void_p, c_uint,
                                                               c_uint];
                                                               
        self._jetfuel.Menu_set_container_box_image(image.imageref, borderwidth,
                                                   borderheight);
                                                   
    def get_container_box_border_width(self):
        self._jetfuel.Menu_get_container_box_border_width.argtypes = [c_void_p];
        self._jetfuel.Menu_get_container_box_border_width.restype = c_uint;
        
        return self._jetfuel.Menu_get_container_box_border_width(
                                                        self.drawableref);
                                                        
    def get_container_box_border_height(self):
        self._jetfuel.Menu_get_container_box_border_height.argtypes = [c_void_p];
        self._jetfuel.Menu_get_container_box_border_height.restype = c_uint;
        
        return self._jetfuel.Menu_get_container_box_border_height(
                                                        self.drawableref);
                                                        
    def add_button(self, buttoncharsreplacement, uisactiontowatchfor, 
                   messagetosenduponclick, messagebus):
        self._jetfuel.Menu_add_button.argtypes = [c_void_p, c_void_p, 
                                                  c_wchar_p, c_wchar_p, 
                                                  c_void_p];
        self._jetfuel.Menu_add_button.restype = c_bool;
        
        return self._jetfuel.Menu_add_button(self.drawableref, 
                                         buttoncharsreplacement.buttoncharsref,
                                         uisactiontowatchfor,
                                         messagetosenduponclick,
                                         messagebus.messagebusref);
        
    def get_position_x(self):
        self._jetfuel.Menu_get_position_x.argtypes = [c_void_p];
        self._jetfuel.Menu_get_position_x.restype = c_int;
        
        return self.Menu_get_position_x(self.drawableref);
    
    def get_position_y(self):
        self._jetfuel.Menu_get_position_y.argtypes = [c_void_p];
        self._jetfuel.Menu_get_position_y.restype = c_int;
        
        return self.Menu_get_position_y(self.drawableref);
    
    def set_position(self, x, y):
        self._jetfuel.Menu_set_position.argtypes = [c_void_p, c_int, c_int];
        
        self._jetfuel.Menu_set_position(self.drawableref, x, y);
        
    def get_rect_to_draw_width(self):
        self._jetfuel.Menu_get_rect_to_draw_width.argtypes = [c_void_p];
        self._jetfuel.Menu_get_rect_to_draw_width.restype = c_int;
        
        return self.Menu_get_rect_to_draw_width(self.drawableref);
    
    def get_rect_to_draw_height(self):
        self._jetfuel.Menu_get_rect_to_draw_height.argtypes = [c_void_p];
        self._jetfuel.Menu_get_rect_to_draw_height.restype = c_int;
        
        return self.Menu_get_rect_to_draw_height(self.drawableref);
