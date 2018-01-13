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
from ctypes import c_bool
from ctypes import c_wchar_p
from ctypes import c_int

from jetfuel.draw.rectangleinterface import rectangle_interface


class button(rectangle_interface):

    def __init__(self, jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;

        self._jetfuel.Button_new.restype = c_void_p;

        self.drawableref = self._jetfuel.Button_new();

    def load_base_button_image(self, buttonimage):
        self._jetfuel.Button_load_base_button_image.argtypes = [c_void_p,
                                                                c_void_p];

        self._jetfuel.Button_load_base_button_image(self.drawableref,
                                                    buttonimage.imageref);

    def set_button_text_characteristics(self,
                                        buttontextcharacteristicsreplacement):
        self._jetfuel.Button_set_button_text_characteristics.argtypes = [
                                                    c_void_p, c_void_p];
        self._jetfuel.Button_set_button_text_characteristics.restype = c_bool;

        self._jetfuel.Button_set_button_text_characteristics(
                self.drawableref,
                buttontextcharacteristicsreplacement.textcharsref);

    def set_clicked_message(self, clickedmessage, messagebus):
        self._jetfuel.Button_set_clicked_message.argtypes = [c_void_p, c_wchar_p,
                                                             c_void_p];

        self._jetfuel.Button_set_clicked_message(self.drawableref,
                                                 clickedmessage,
                                                 messagebus.messagebusref);

    def set_button_color(self, color):
        self._jetfuel.Button_set_button_color.argtypes = [c_void_p,
                                                          c_void_p];

        self._jetfuel.Button_set_button_color(self.drawableref,
                                              color.colorref);


    def set_uis_action_to_watch(self, uisaction):
        self._jetfuel.Button_set_UIS_action_to_watch.argtypes = [c_void_p,
                                                                 c_wchar_p];

        self._jetfuel.Button_set_UIS_action_to_watch(self.drawableref,
                                                            uisaction);
    def get_position_x(self):
        self._jetfuel.Button_get_position_x.argtypes = [c_void_p];
        self._jetfuel.Button_get_position_x.restype = c_int;

        return self._jetfuel.Button_get_position_x(self.drawableref);

    def get_position_y(self):
        self._jetfuel.Button_get_position_y.argtypes = [c_void_p];
        self._jetfuel.Button_get_position_y.restype = c_int;

        return self._jetfuel.Button_get_position_y(self.drawableref);

    def set_position(self, x, y):
        self._jetfuel.Button_set_position.argtypes = [c_void_p, c_int, c_int];

        self._jetfuel.Button_set_position(self.drawableref, x, y);
