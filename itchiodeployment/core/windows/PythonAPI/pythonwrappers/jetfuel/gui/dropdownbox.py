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
from ctypes import c_uint
from ctypes import c_wchar_p
from ctypes import c_int

from jetfuel.draw.rectangleinterface import rectangle_interface

class drop_down_box(rectangle_interface):

    def __init__(self, jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;

        self._jetfuel.Drop_down_box_new.restype = c_void_p;

        self.drawableref = self._jetfuel.Drop_down_box_new();

    def load_base_box_image(self, baseboximage, color, xbordersize, ybordersize):
        self._jetfuel.Drop_down_box_load_base_box_image.argtypes = [c_void_p,
                                                                    c_void_p,
                                                                    c_void_p,
                                                                    c_uint,
                                                                    c_uint];

        self._jetfuel.Drop_down_box_load_base_box_image(self.drawableref,
                                                        baseboximage.\
                                                        imageref,
                                                        color.colorref,
                                                        xbordersize,
                                                        ybordersize);

    def get_active_option(self):
        self._jetfuel.Drop_down_box_get_active_option.argtypes = [c_void_p];
        self._jetfuel.Drop_down_box_get_active_option.restype = c_wchar_p;

        return self._jetfuel.Drop_down_box_get_active_option(self.drawableref);

    def get_option_text_characteristics(self):
        self._jetfuel.Drop_down_box_get_option_text_characteristics.argtypes = [
                                                                    c_void_p];
        self._jetfuel.Drop_down_box_get_option_text_characteristics.restype = \
                                                                    c_void_p;

        return self._jetfuel.Drop_down_box_get_option_text_characteristics(
                                                            self.drawableref);

    def set_option_text_characteristics(self, textcharsreplacement):
        self._jetfuel.Drop_down_box_set_option_text_characteristics.argtypes = [
                                                                    c_void_p,
                                                                    c_void_p];

        self._jetfuel.Drop_down_box_set_option_text_characteristics(
                                                        self.drawableref,
                                                        textcharsreplacement.\
                                                        textcharsref);

    def get_uis_action_to_listen_for(self):
        self._jetfuel.Drop_down_box_get_uis_action_to_listen_for.argtypes = [
                                                                    c_void_p];
        self._jetfuel.Drop_down_box_get_uis_action_to_listen_for.restype = \
                                                                   c_wchar_p;

        return self._jetfuel.Drop_down_box_get_uis_action_to_listen_for(
                                                            self.drawableref);

    def set_uis_action_to_listen_for(self, uisaction):
        self._jetfuel.Drop_down_box_set_uis_action_to_listen_for.argtypes = [
                                                                    c_void_p,
                                                                    c_wchar_p];

        self._jetfuel.Drop_down_box_set_uis_action_to_listen_for(
                                                            self.drawableref,
                                                            uisaction);

    def add_option(self, option):
        self._jetfuel.Drop_down_box_add_option.argtypes = [c_void_p, c_wchar_p];

        self._jetfuel.Drop_down_box_add_option(self.drawableref, option);

    def get_position_x(self):
        self._jetfuel.Drop_down_box_get_position_x.argtypes = [c_void_p];
        self._jetfuel.Drop_down_box_get_position_x.restype = c_int;

        return self._jetfuel.Drop_down_box_get_position_x(self.drawableref);

    def get_position_y(self):
        self._jetfuel.Drop_down_box_get_position_y.argtypes = [c_void_p];
        self._jetfuel.Drop_down_box_get_position_y.restype = c_int;

        return self._jetfuel.Drop_down_box_get_position_y(self.drawableref);

    def set_position(self, x, y):
        self._jetfuel.Drop_down_box_set_position.argtypes = [c_void_p, c_int,
                                                               c_int];

        self._jetfuel.Drop_down_box_set_position(self.drawableref, x, y);

    def get_rect_to_draw_width(self):
        self._jetfuel.Drop_down_box_get_rect_to_draw_width.argtypes = [c_void_p];
        self._jetfuel.Drop_down_box_get_rect_to_draw_width.restype = c_int;

        return self._jetfuel.Drop_down_box_get_rect_to_draw_width(
                                                            self.drawableref);

    def get_rect_to_draw_height(self):
        self._jetfuel.Drop_down_box_get_rect_to_draw_height.argtypes = [c_void_p];
        self._jetfuel.Drop_down_box_get_rect_to_draw_height.restype = c_int;

        return self._jetfuel.Drop_down_box_get_rect_to_draw_height(
                                                            self.drawableref);
