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
from ctypes import c_wchar_p
from ctypes import c_bool

class message_bus(object):
    _jetfuel = None;
    messagebusref = None;

    def __init__(self, jetfuelsoloader, messagebuspointer):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        self.messagebusref = messagebuspointer;
        
    def post_message(self, message):
        if(self.messagebusref is None):
            return False;
        else:
            self._jetfuel.Message_bus_post_message_to_message_bus.argtypes = [
                          c_void_p, c_wchar_p];
                          
            self._jetfuel.Message_bus_post_message_to_message_bus(
                self.messagebusref, message);
            
            return True;
        
    def does_message_exist(self, message):
        if(self.messagebusref is None):
            return "NULL message bus pointer";
        else:
            self._jetfuel.Message_bus_does_message_exist.argtypes = [
              c_void_p, c_wchar_p];
                          
            self._jetfuel.Message_bus_does_message_exist.restype = c_bool;
                          
            return self._jetfuel.Message_bus_does_message_exist(
                  self.messagebusref, message);