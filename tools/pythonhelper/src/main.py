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

import os
import sys

import tkinter

from tkinter import filedialog
from tkinter import messagebox
import tkinterbuttoncallbacks

import pickle

def createButtons(tkinterwindow):
    projectButton = tkinter.Button(tkinterwindow, text="Create new Project",
                                   bg='green',
                                   command=tkinterbuttoncallbacks.\
                                   createProjectCallback);

    projectButton.pack();

def retrieveJetfuelDir():
    done = False;

    messagebox.showinfo(message="Default Jetfuel Game Engine directories"+
                        " do not exist. Please specify the directory"+
                        " where Jetfuel Game Engine is.");

    while(not done):

        projectlocation = filedialog.askdirectory(initialdir=os.getcwd(),
                                                  title="Select where"+
                                                  " Jetfuel Game Engine is");
        if(not projectlocation == ""):
            if(os.path.isdir(projectlocation+"/PythonAPI/pythonwrappers") and
               os.path.isdir(projectlocation+"/src")):
               done = True;
            else:
               messagebox.showinfo(message="Code template files not found!"+
                                   "Please re-select the files.")
        else:
            done = True;

    return projectlocation;

def main():
    window = tkinter.Tk();
    doesrefsexist = os.path.exists("prefs");
    if(doesrefsexist):
        picklereadfile = open("prefs", "rb");
    picklefile = open("prefs", "wb");

    createButtons(window);

    if(not os.path.isdir("../../../PythonAPI/pythonwrappers") or
       not os.path.isdir("../../../src")):
       if(not doesrefsexist):
           jetfueldir = retrieveJetfuelDir();

           if(jetfueldir==""):
               window.quit();

               picklefile.close();
               os.remove("prefs");

               sys.exit(0);

           pickle.dump(jetfueldir, picklefile);
       else:
           jetfueldir = pickle.load(picklereadfile);

    window.mainloop();

if __name__ == "__main__":
    main()
