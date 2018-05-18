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
from ctypes import c_bool
from ctypes import c_int
from ctypes import c_wchar_p
from ctypes import c_uint

from jetfuel.draw.rectangleinterface import rectangle_interface

class check_box(rectangle_interface):
    _jetfuel = None;

    def __init__(self, jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;

        self._jetfuel.Check_box_new.restype = c_void_p;

        self.drawableref = self._jetfuel.Check_box_new();

    def load_check_box_images(self, activeimage, disabledimage):
        self._jetfuel.Check_box_load_check_box_images.argtypes = [c_void_p,
                                                                  c_void_p,
                                                                  c_void_p];

        self._jetfuel.Check_box_load_check_box_images(self.drawableref,
                                                      activeimage.imageref,
                                                      disabledimage.imageref);

    def is_checked(self):
        self._jetfuel.Check_box_is_checked.argtypes = [c_void_p];

        self._jetfuel.Check_box_is_checked.restype = c_bool;

        return self._jetfuel.Check_box_is_checked(self.drawableref);

    def get_position_x(self):
        self._jetfuel.Check_box_get_position_x.argtypes = [c_void_p];

        self._jetfuel.Check_box_get_position_x.restype = c_int;

        return self._jetfuel.Check_box_get_position_x(self.drawableref);

    def get_position_y(self):
        self._jetfuel.Check_box_get_position_y.argtypes = [c_void_p];

        self._jetfuel.Check_box_get_position_y.restype = c_int;

        return self._jetfuel.Check_box_get_position_y(self.drawableref);

    def set_position(self, x, y):
        self._jetfuel.Check_box_set_position.argtypes = [c_void_p, c_int, c_int];

        self._jetfuel.Check_box_set_position(self.drawableref, x, y);

    def get_label_characteristics(self):
        self._jetfuel.Check_box_get_label_characteristics.argtypes = [c_void_p];

        self._jetfuel.Check_box_get_label_characteristics.restype = c_void_p;

        return self._jetfuel.Check_box_get_label_characteristics(
                                                        self.drawableref);

    def set_label_characteristics(self, labelchars, left, labelgap):
        self._jetfuel.Check_box_set_label_characteristics.argtypes = [c_void_p,
                                                                      c_void_p,
                                                                      c_bool,
                                                                      c_uint];

        self._jetfuel.Check_box_set_label_characteristics(self.drawableref,
                                        labelchars.textcharsref, left,
                                        labelgap);

    def set_uis_action_to_watch(self, action):
        self._jetfuel.Check_box_set_UIS_action_to_watch.argtypes = [c_void_p,
                                                                    c_wchar_p];

        self._jetfuel.Check_box_set_UIS_action_to_watch(self.drawableref,
                                                        action);

    def get_rect_to_draw_x(self):
        self._jetfuel.Check_box_get_checkbox_rect_to_draw_x.argtypes = [
                                                     c_void_p];

        self._jetfuel.Check_box_get_checkbox_rect_to_draw_x.restype = c_int;

        return self._jetfuel.Check_box_get_checkbox_rect_to_draw_x(self.drawableref);

    def get_rect_to_draw_y(self):
        self._jetfuel.Check_box_get_checkbox_rect_to_draw_y.argtypes = [
                                                     c_void_p];

        self._jetfuel.Check_box_get_checkbox_rect_to_draw_y.restype = c_int;

        return self._jetfuel.Check_box_get_checkbox_rect_to_draw_y(self.drawableref);

    def get_rect_to_draw_width(self):
        self._jetfuel.Check_box_get_checkbox_rect_to_draw_width.argtypes = [
                                                     c_void_p];

        self._jetfuel.Check_box_get_checkbox_rect_to_draw_width.restype = c_int;

        return self._jetfuel.Check_box_get_checkbox_rect_to_draw_width(
                                                      self.drawableref);

    def get_rect_to_draw_height(self):
        self._jetfuel.Check_box_get_checkbox_rect_to_draw_height.argtypes = [
                                                     c_void_p];

        self._jetfuel.Check_box_get_checkbox_rect_to_draw_height.restype = c_int;

        return self._jetfuel.Check_box_get_checkbox_rect_to_draw_height(
                                                       self.drawableref);
