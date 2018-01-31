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

import sys
import os

from cx_Freeze import setup, Executable

# Dependencies are automatically detected, but it might need fine tuning.

sys.path.append(".");

if sys.platform == "win32":
    build_exe_options = {"includes": ["tkinter","PIL", "win32api","win32con",
                                      "distutils.dir_util", "shutil",
                                      "tkinter.ttk", "json", "pickle"],
                         "include_files": ["dependencies/tcl86t.dll",
                         "dependencies/tk86t.dll","src/icon.ico",
                         "src/jetfuellogosmall.png"]};
else:
    build_exe_options = {"includes": ["tkinter","PIL", "PIL.ImageTk",
                                      "PIL._tkinter_finder",
                                      "distutils.dir_util", "shutil",
                                      "tkinter.ttk", "json", "pickle"],
                         "include_files": ["icon.ico",
                         "jetfuellogosmall.png", "projecthandler"],
                         "build_exe": "../build/exe.linux_x86_64-3.6"};

os.environ['TCL_LIBRARY'] = "../dependencies/tcl8.6";
os.environ['TK_LIBRARY'] = "../dependencies/tk8.6";

# GUI applications require a different base on Windows (the default is for a
# console application).
base = None
#if sys.platform == "win32":
    #base = "Win32GUI"

setup(
    name = "JetfuelProjectHelper",
    version = "0.1b",
    description = "A project helper tool for the Jetfuel Game Engine.",
    options = {"build_exe": build_exe_options},
    executables = [Executable("main.py", base = base)])
