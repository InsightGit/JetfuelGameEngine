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
from ctypes import c_int

class image(object):
    _jetfuel = None;
    imageref = None;

    def __init__(self, jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        self._jetfuel.Image_new.restype = c_void_p;

        self.imageref = self._jetfuel.Image_new();

    def delete_ref(self):
        if(self.imageref != None):
            self._jetfuel.Image_delete.argtype = [c_void_p];

            self._jetfuel.Image_delete(self.imageref);

    def get_image_size_x(self):
        self._jetfuel.Image_get_image_size_x.argtypes = [c_void_p];
        self._jetfuel.Image_get_image_size_x.restype = c_int;

        return self._jetfuel.Image_get_image_size_x(self.imageref);

    def get_image_size_y(self):
        self._jetfuel.Image_get_image_size_y.argtypes = [c_void_p];
        self._jetfuel.Image_get_image_size_y.restype = c_int;

        return self._jetfuel.Image_get_image_size_y(self.imageref);

    def get_image_location(self):
        self._jetfuel.Image_get_image_location.argtypes = [c_void_p];
        self._jetfuel.Image_get_image_location.restype = c_wchar_p;

        return  self._jetfuel.Image_get_image_location(self.imageref);

    def set_image_location(self, imagefilepath, imagesizex, imagesizey):
        self._jetfuel.Image_set_image_location.argtypes = [c_void_p,
                                                           c_wchar_p,
                                                           c_int, c_int];
        self._jetfuel.Image_set_image_location(self.imageref,
                                               imagefilepath,
                                               imagesizex, imagesizey);

    #def set_image_location_and_size(self, imagefilepath, imagesizex,
    #                                imagesizey):
    #    self._jetfuel.Image_set_image_location.argtypes = [c_void_p,
    #                                                       c_wchar_p,
    #                                                       c_int,
    #                                                       c_int];
    #    self._jetfuel.Image_set_image_location(self.imageref,
    #                                           imagefilepath,
    #                                           imagesizex,
    #                                           imagesizey);
