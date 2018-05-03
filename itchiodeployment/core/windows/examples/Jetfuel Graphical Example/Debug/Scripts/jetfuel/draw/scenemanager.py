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
from ctypes import c_int

class scene_manager(object):
    _jetfuel = None;
    scenemanagerref = None;

    def __init__(self, jetfuelsoloader, scenemanagerpointer):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        self.scenemanagerref = scenemanagerpointer;

    def attach_drawable(self, drawable, drawableweight):
        self._jetfuel.Scene_attach_drawable.argtypes = [c_void_p,
                                                        c_void_p,
                                                        c_int];
        print("Refs:"+str(self.scenemanagerref)+":"+str(drawable.drawableref));
        self._jetfuel.Scene_attach_drawable(self.scenemanagerref,
                                           drawable.drawableref,
                                           drawableweight);
    def disable_drawable(self, drawable):
        self._jetfuel.Scene_disable_drawable.argtypes = [c_void_p,
                                                        c_void_p];

        self._jetfuel.Scene_disable_drawable(self.scenemanagerref,
                                             drawable.drawableref);
