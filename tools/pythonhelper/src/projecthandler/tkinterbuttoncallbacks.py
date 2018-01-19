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

from os import getcwd
from os import path
from os import makedirs

from platform import system

from shutil import copyfile

from distutils.dir_util import copy_tree

from threading import Thread

from tkinter import filedialog
from tkinter import messagebox
from tkinter import ttk
from tkinter import Tk
from tkinter import Label
from tkinter import StringVar

import pickle

import jetfueldetectors

def disable_event():
    pass;

def copyGameEngineFiles(location, jetfueldir):
    copy_tree(jetfueldir+"/PythonAPI/pythonwrappers/jetfuel",
            location+"/Scripts/jetfuel/");

    #copy_tree(jetfueldir+"/windowsdependencies",
    #         location+"/runtimelibs/windowsdependencies/");

    if(system() == 'Windows'):
        copy_tree(jetfueldir+"/externalDLLstoinclude",
                 location+"/runtimelibs/DLLs,SOs,etc./");

    copy_tree(jetfueldir+"/include",location+"/jetfuelengine/include/");

    if(path.isdir(jetfueldir+"/lib")):
        copy_tree(jetfueldir+"/lib",location+"/jetfuelengine/lib/");

def generateProjectFiles(location, templatename, jetfueldir):
    copy_tree(jetfueldir+"/templatecode/"+templatename, location+"/");

def createProject(windowparent, location):
    picklereadfile = open("prefs", "rb");

    doesrefsexist = path.exists("prefs");

    if(doesrefsexist):
        try:
            jetfueldir = pickle.load(picklereadfile);
        except EOFError:
            jetfueldir = "../../../";
    else:
        jetfueldir = "../../../";

    copyGameEngineFiles(location, jetfueldir);

    generateProjectFiles(location, "default", jetfueldir);

    windowparent.destroy();

def startCreatingProject(projectlocation):
    barwindow = Tk();
    progressbar = ttk.Progressbar(barwindow, orient="horizontal", length=100,
                              mode='indeterminate');
    progressbar.pack();
    progressbar.start(50);

    barupdatetext = Label(barwindow,
                            text="Creating project...");
    barupdatetext.pack();

    thread = Thread(target = createProject, args = (barwindow,
                                                    projectlocation));
    thread.start();

    barwindow.protocol("WM_DELETE_WINDOW", disable_event);
    barwindow.mainloop();

def createProjectCallback():
    projectlocation = filedialog.askdirectory(initialdir=getcwd(),
                                            title="Select a Project location");
    if(projectlocation==""):
        messagebox.showinfo(message="Cancel button was hit, "+
                            "no project will be made.");
    elif(jetfueldetectors.isProject(projectlocation)):
        if(messagebox.askyesno(message="Project files exist here. "+
           "Do you want to overwrite them?", icon='question',
           title='Overwrite existing project files?') == True):
           startCreatingProject(projectlocation);
    else:
        startCreatingProject(projectlocation);

def quitWindowCallback(tkinterwindow):
    tkinterwindow.destroy();
