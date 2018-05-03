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

from ctypes import c_wchar_p
from ctypes import c_void_p
from ctypes import c_long
from ctypes import c_bool

class font(object):
    _jetfuel = None;
    fontref = None;

    def __init__(self, jetfuelsoloader, fontfilename=None, faceindex=None):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        if(fontfilename is not None):
            if(faceindex is not None):
                self._jetfuel.Font_new_from_face_index.argtypes = [c_void_p,
                                                                   c_wchar_p,
                                                                   c_long];
                self._jetfuel.Font_new_from_face_index.restype = c_void_p;
                
                self.fontref = self._jetfuel.Font_new_from_face_index(
                                                            fontfilename, 
                                                            faceindex);
            else:
                self._jetfuel.Font_new_from_file_name.argtypes = [c_wchar_p];
                self._jetfuel.Font_new_from_file_name.restype = c_void_p;
                
                self.fontref = self._jetfuel.Font_new_from_file_name(
                                                            fontfilename);
        else:
            self._jetfuel.Font_new.restype = c_void_p;
                
            self.fontref = self._jetfuel.Font_new();
    
    def delete_ref(self):
        if(self.fontref != None):
            self._jetfuel.Font_delete.argtypes = [c_void_p];
            self._jetfuel.Font_delete(self.fontref);
            
    def is_font_loaded(self):
        self._jetfuel.Font_is_font_loaded.argtypes = [c_void_p];
        self._jetfuel.Font_is_font_loaded.restype = c_bool;
        
        return self._jetfuel.Font_is_font_loaded(self.fontref);
    
    def get_file_name(self):
        self._jetfuel.Font_get_file_name.argtypes = [c_void_p];
        self._jetfuel.Font_get_file_name.restype = c_wchar_p;
        
        return self._jetfuel.Font_get_file_name(self.fontref);
    
    def get_face_index(self):
        self._jetfuel.Font_get_face_index.argtypes = [c_void_p];
        self._jetfuel.Font_get_face_index.restype = c_long;
        
        return self._jetfuel.Font_get_face_index(self.fontref);
    
    def load_font(self, fontfilename, faceindex=None):
        if(faceindex is not None):
            self._jetfuel.Font_load_font_face_index.argtypes = [c_void_p,
                                                                c_wchar_p,
                                                                c_long];
            self._jetfuel.Font_load_font_face_index(self.fontref,
                                                    fontfilename,
                                                    faceindex);
        else:
            self._jetfuel.Font_load_font.argtypes = [c_void_p,
                                                     c_wchar_p];
            self._jetfuel.Font_load_font(self.fontref,
                                        fontfilename);                                           