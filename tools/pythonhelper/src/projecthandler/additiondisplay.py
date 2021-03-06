#     Jetfuel Game Engine Python Project Manager- A simple python program
#     to manage your projects using the Jetfuel Game Engine
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

from os import path

from json import load

class AdditionDisplay:
    _projectlocation = None;

    _additionsfile = None;
    _existingadditions = None;

    _currentAdditionsLabel = None;
    #_current

    def __init__(self, projectlocation):
        self._projectlocation = projectlocation;

        if(path.exists(self._projectlocation+"/.additions.json")):
            self._existingadditions = load(open(self._projectlocation+
                                                "/.additions.json"));
        else:
            None;

        self._additionsfile = open(self._projectlocation+"/.additions.json",
                                   'a'));
        #
