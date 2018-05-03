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

class pointer_bridge(object):
    
    _jetfuel = None;
    _pointerbridgeref = None;

    def __init__(self, jetfuelsoloader, pointerbridgeref):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        self._pointerbridgeref = pointerbridgeref;
        
    def recieve_pointer(self, pointerid, found):
        self._jetfuel.Pointer_bridge_recieve_pointer.argtypes = [c_void_p,
                                                                 c_wchar_p,
                                                                 c_void_p];
        self._jetfuel.Pointer_bridge_recieve_pointer.restype = c_void_p;
        
        return self._jetfuel.Pointer_bridge_recieve_pointer(
                                     self._pointerbridgeref, pointerid,
                                     id(found));
                                     
    def send_pointer(self, pointerid, pointer):
        self._jetfuel.Pointer_bridge_send_pointer.argtypes = [c_void_p,
                                                              c_wchar_p,
                                                              c_void_p];
        self._jetfuel.Pointer_bridge_send_pointer(self._pointerbridgeref,
                                                  pointerid, pointer);