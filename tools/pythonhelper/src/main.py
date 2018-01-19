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

import pickle

import PIL.Image
import PIL.ImageTk

from projecthandler import tkinterbuttoncallbacks
from projecthandler import jetfueldetectors

def createBaseLayout(windowparent):
    welcometext = tkinter.Label(windowparent,
                                text="Jetfuel Game Engine project helper",
                                font="-weight bold");
    jetfueliconimage = PIL.ImageTk.PhotoImage(PIL.Image.\
                                              open("jetfuellogosmall.png"));
    jetfuelicon = tkinter.Label(windowparent, image=jetfueliconimage);
    jetfuelicon.image = jetfueliconimage;

    welcometext.grid(row=0, column=2);
    jetfuelicon.grid(row=0, column=0);

def createButtons(tkinterwindow):
    projectbutton = tkinter.Button(tkinterwindow, text="Create new Project",
                                   bg='green',
                                   command=tkinterbuttoncallbacks.\
                                   createProjectCallback);
    quitbutton = tkinter.Button(tkinterwindow, text="Quit", bg='red',
                                command= lambda:
                                tkinterbuttoncallbacks.quitWindowCallback(
                                                                tkinterwindow));

    projectbutton.grid(row=3, column=0, columnspan=2);
    quitbutton.grid(row=3, column=3)

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
    window.wm_title("Jetfuel Game Engine Project Helper")
    window.iconbitmap("icon.ico");

    doesrefsexist = os.path.exists("prefs");
    if(doesrefsexist):
        picklereadfile = open("prefs", "rb");
    picklefile = open("prefs", "wb");

    createBaseLayout(window);
    createButtons(window);

    if(not jetfueldetectors.isJetfuel("../../../")):
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
