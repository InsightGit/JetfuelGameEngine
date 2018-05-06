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

from jetfuel.draw.image import image
from jetfuel.draw.color import color
from jetfuel.draw.textcharacteristicsreplacement import \
     text_characteristics_replacement

class button_characteristics_replacement(object):
    _jetfuel = None;
    buttoncharsref = None;

    def __init__(self, jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;

        self._jetfuel.Button_characteristics_replacement_new.\
             restype = c_void_p;

        self.buttoncharsref = self._jetfuel.\
                Button_characteristics_replacement_new();

    def delete_ref(self):
        self._jetfuel.Button_characteristics_replacement_delete.\
                    argtypes = [c_void_p];

        self._jetfuel.Button_characteristics_replacement_delete(
                                            self.buttoncharsref);

    def get_image(self, jetfuelsoloader):
        self._jetfuel.Button_characteristics_replacement_get_image.\
                                               argtypes = [c_void_p];
        self._jetfuel.Button_characteristics_replacement_get_image.\
                                                restype = c_void_p;

        returnvalue = image(jetfuelsoloader);

        returnvalue.delete_ref();

        returnvalue.imageref = self._jetfuel.\
            Button_characteristics_replacement_get_image(self.buttoncharsref);

        return returnvalue;

    def set_image(self, image):
        self._jetfuel.Button_characteristics_replacement_set_image.argtypes = [
                                                                   c_void_p,
                                                                   c_void_p];

        self._jetfuel.Button_characteristics_replacement_set_image(
                                                       self.buttoncharsref,
                                                       image.imageref);

    def get_color(self, jetfuelsoloader):
        self._jetfuel.Button_characteristics_replacement_get_color.\
             argtypes = [c_void_p];
        self._jetfuel.Button_characteristics_get_color.restype = c_void_p;

        returnvalue = color(jetfuelsoloader);

        returnvalue.delete_ref();

        returnvalue.colorref = self._jetfuel.Button_characteristics_get_color(
                                                          self.buttoncharsref);

        return returnvalue;

    def set_color(self, color):
        self._jetfuel.Button_characteristics_replacement_set_color.\
                                            argtypes = [c_void_p, c_void_p];

        self._jetfuel.Button_characteristics_replacement_set_color(
                                    self.buttoncharsref,color.colorref);

    def get_text_chars(self, jetfuelsoloader):
        self._jetfuel.Button_characteristics_replacement_get_text_chars.\
                                                    argtypes = [c_void_p];
        self._jetfuel.Button_characteristics_replacement_get_text_chars.\
                                                    restype = c_void_p;

        returnvalue = text_characteristics_replacement(jetfuelsoloader);

        returnvalue.delete_ref();

        returnvalue.textcharsref = self._jetfuel.\
            Button_characteristics_replacement_get_text_chars(self.\
                                                        buttoncharsref);

        return returnvalue;

    def set_text_chars(self, textchars):
        self._jetfuel.Button_characteristics_replacement_set_text_chars.\
                                                        argtypes = [c_void_p,
                                                                    c_void_p];

        self._jetfuel.Button_characteristics_replacement_set_text_chars(
                        self.buttoncharsref, textchars.textcharsref);
