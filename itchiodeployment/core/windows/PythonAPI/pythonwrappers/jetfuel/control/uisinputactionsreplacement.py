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

from jetfuel.core.messagebus import message_bus

class uis_input_actions_replacement(object):
    _jetfuel = None;
    uisinputactionsref = None;
    
    def __init__(self, jetfuelsoloader, customref=None):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        self._jetfuel.Uis_input_actions_replacement_new.restype = c_void_p;
        
        if(customref is None):
            self.uisinputactionsref = self._jetfuel.\
                Uis_input_actions_replacement_new();
        else:
            self.uisinputactionsref = customref;
                                        
    def get_keyboard_message_to_watch(self):
        self._jetfuel.\
        Uis_input_actions_replacement_get_keyboard_message_to_watch.argtypes = [
                                                                    c_void_p];
        self._jetfuel.\
        Uis_input_actions_replacement_get_keyboard_message_to_watch.restype = \
                                                                    c_wchar_p;
        
        return self._jetfuel.\
        Uis_input_actions_replacement_get_keyboard_message_to_watch(
                                            self.uisinputactionsref);
                                            
    def set_keyboard_message_to_watch(self, keyboardmessage):
        self._jetfuel.\
        Uis_input_actions_replacement_set_keyboard_message_to_watch.argtypes = [
                                                            c_void_p, c_wchar_p];
                                                            
        self._jetfuel.\
        Uis_input_actions_replacement_set_keyboard_message_to_watch(
                            self.uisinputactionsref, keyboardmessage);
                    
    def get_mouse_message_to_watch(self):
        self._jetfuel.\
        Uis_input_actions_replacement_get_mouse_message_to_watch.argtypes = [
                                                                    c_void_p];
        self._jetfuel.\
        Uis_input_actions_replacement_get_mouse_message_to_watch.restype = \
                                                                    c_wchar_p;
        
        return self._jetfuel.\
        Uis_input_actions_replacement_get_mouse_message_to_watch(
                                            self.uisinputactionsref);
                                            
    def set_mouse_message_to_watch(self, mousemessage):
        self._jetfuel.\
        Uis_input_actions_replacement_set_mouse_message_to_watch.argtypes = [
                                                        c_void_p, c_wchar_p];
                                                            
        self._jetfuel.\
        Uis_input_actions_replacement_set_mouse_message_to_watch(
                            self.uisinputactionsref, mousemessage);
                            
    def get_joystick_message_to_watch(self):
        self._jetfuel.\
        Uis_input_actions_replacement_get_joystick_message_to_watch.argtypes = [
                                                                    c_void_p];
        self._jetfuel.\
        Uis_input_actions_replacement_get_joystick_message_to_watch.restype = \
                                                                    c_wchar_p;
        
        return self._jetfuel.\
        Uis_input_actions_replacement_get_joystick_message_to_watch(
                                            self.uisinputactionsref);
                                            
    def set_joystick_message_to_watch(self, joystickmessage):
        self._jetfuel.\
        Uis_input_actions_replacement_set_joystick_message_to_watch.argtypes = [
                                                         c_void_p, c_wchar_p];
                                                            
        self._jetfuel.\
        Uis_input_actions_replacement_set_joystick_message_to_watch(
                            self.uisinputactionsref, joystickmessage);
                            
    def get_touch_message_to_watch(self):
        self._jetfuel.\
        Uis_input_actions_replacement_get_touch_message_to_watch.argtypes = [
                                                                    c_void_p];
        self._jetfuel.\
        Uis_input_actions_replacement_get_touch_message_to_watch.restype = \
                                                                    c_wchar_p;
        
        return self._jetfuel.\
        Uis_input_actions_replacement_get_touch_message_to_watch(
                                            self.uisinputactionsref);
                                            
    def set_touch_message_to_watch(self, touchmessage):
        self._jetfuel.\
        Uis_input_actions_replacement_set_touch_message_to_watch.argtypes = [
                                                         c_void_p, c_wchar_p];
                                                            
        self._jetfuel.\
        Uis_input_actions_replacement_set_touch_message_to_watch(
                                self.uisinputactionsref, touchmessage);
                                
    def get_message_to_send_upon_click(self):
        self._jetfuel.\
        Uis_input_actions_replacement_get_message_to_send_upon_click.argtypes = [
                                                                    c_void_p];
        self._jetfuel.\
        Uis_input_actions_replacement_get_message_to_send_upon_click.restype = \
                                                                    c_wchar_p;
        
        return self._jetfuel.\
        Uis_input_actions_replacement_get_message_to_send_upon_click(
                                                self.uisinputactionsref);
                                            
    def set_message_to_send_upon_click(self, messagetosenduponclick):
        self._jetfuel.\
        Uis_input_actions_replacement_set_message_to_send_upon_click.argtypes = [
                                                            c_void_p, c_wchar_p];
                                                            
        self._jetfuel.\
        Uis_input_actions_replacement_set_message_to_send_upon_click(
                                self.uisinputactionsref, messagetosenduponclick);

    def get_message_bus_to_send_message_to(self, jetfuelsoloader):
        self._jetfuel.\
        Uis_input_actions_replacement_get_message_bus_to_send_message_to.\
                                                        argtypes = [c_void_p];
        self._jetfuel.\
        Uis_input_actions_replacement_get_message_bus_to_send_message_to.\
                                                        restype = c_void_p;
        
        messagebuspointer = self._jetfuel.\
        Uis_input_actions_replacement_get_message_bus_to_send_message_to(
                                                    self.uisinputactionsref);
                                                    
        return message_bus(jetfuelsoloader.jetfuelso, messagebuspointer);
                                            
    def set_message_bus_to_send_message_to(self, messagebustosendmessageto):
        self._jetfuel.\
        Uis_input_actions_replacement_set_message_bus_to_send_message_to.\
                                                argtypes = [c_void_p, c_void_p];
                                                            
        self._jetfuel.\
        Uis_input_actions_replacement_set_message_bus_to_send_message_to(
        self.uisinputactionsref, messagebustosendmessageto.messagebusref);