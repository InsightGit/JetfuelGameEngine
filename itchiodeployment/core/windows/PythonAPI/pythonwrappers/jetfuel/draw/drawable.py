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

class drawable(object):
    _jetfuel = None;
    drawableref = None;
    
    def get_position_x(self):
        self._jetfuel.Drawable_get_position_x.argtypes = [c_void_p];
        self._jetfuel.Drawable_get_position_x.restype = c_int;
        
        return self._jetfuel.Drawable_get_position_x(self.drawableref);
    
    def get_position_y(self):
        self._jetfuel.Drawable_get_position_y.argtypes = [c_void_p];
        self._jetfuel.Drawable_get_position_y.restype = c_int;
        
        return self._jetfuel.Drawable_get_position_y(self.drawableref);
    
    def set_position(self, x, y):
        self._jetfuel.Drawable_set_position.argtypes = [c_void_p, c_int, c_int];
        
        self._jetfuel.Drawable_set_position(self.drawableref, x, y);
    
    def delete_ref(self):
        if(self.drawableref != None):
            self._jetfuel.Drawable_delete.argtypes = [c_void_p];
            self._jetfuel.Drawable_delete(self.drawableref);

    
    def draw(self):
        self._jetfuel.Drawable_draw.argtypes = [c_void_p];
        self._jetfuel.Drawable_draw.restype = c_bool;
        
        return self._jetfuel.Drawable_draw(self.drawableref);