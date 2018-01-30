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
                                      "distutils.dir_util", "shutil",
                                      "tkinter.ttk", "json", "pickle"],
                         "include_files": ["src/icon.ico",
                         "src/jetfuellogosmall.png"]};

os.environ['TCL_LIBRARY'] = "dependencies/tcl8.6";
os.environ['TK_LIBRARY'] = "dependencies/tk8.6";

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
    executables = [Executable("src/main.py", base = base)])
