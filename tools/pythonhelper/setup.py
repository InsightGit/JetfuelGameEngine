import sys
import os

from cx_Freeze import setup, Executable

# Dependencies are automatically detected, but it might need fine tuning.
build_exe_options = {"includes": ["tkinter","PIL"], "include_files":
                                                ["dependencies/tcl86t.dll",
                                                "dependencies/tk86t.dll"]};
packages = ['projecthandler'];

os.environ['TCL_LIBRARY'] = "dependencies/tcl8.6";
os.environ['TK_LIBRARY'] = "dependencies/tk8.6";

# GUI applications require a different base on Windows (the default is for a
# console application).
base = None
if sys.platform == "win32":
    base = "Win32GUI"

setup(
    name = "simple_Tkinter",
    version = "0.1",
    description = "Sample cx_Freeze Tkinter script",
    options = {"build_exe": build_exe_options},
    executables = [Executable("src/main.py", base = base)])
