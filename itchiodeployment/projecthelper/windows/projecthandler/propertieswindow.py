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

from platform import system

from tkinter import Tk
from tkinter import Text
from tkinter import Button
from tkinter import Label

from json import dumps
from json import load

from projecthandler import tkinterbuttoncallbacks

# from projecthandler.projectdisplayer import ProjectDisplayer
# Actual import statement down in _createProjectPropertiesCommand()

class PropertiesWindow:
    _propertywindow = None;
    _progressbarwindow = None;

    _projectnamelabel = None;
    _authorlabel = None;
    _descriptionlabel = None;

    _projectnametext = None;
    _authortext = None;
    _descriptiontext = None;

    _submitbutton = None;
    _cancelbutton = None;

    _existingproperties = None;

    _projectlocation = None;
    _triggerprojectcreation = None;
    _projectdisplayer = None;

    def __windowsMakePropertiesFileHidden(self):
        import win32api
        import win32con
        win32api.SetFileAttributes('.properties.json',
                                    win32con.FILE_ATTRIBUTE_HIDDEN);

    def __createProjectPropertiesCommand(self):
        projectname = self._projectnametext.get('1.0', "end");
        projectauthor = self._authortext.get('1.0', "end");
        projectdescription = self._descriptiontext.get('1.0', "end");

        if(projectname != "\n" and projectauthor != "\n" and
           projectdescription != "\n"):
            jsonpropertiesfile = open(self._projectlocation+"/.properties.json",
                                      "w");

            jsonpropertiesfile.write(dumps({
                        "projectname": projectname,
                        "author": projectauthor,
                        "description": projectdescription
                        }, sort_keys=True, indent=4));

            jsonpropertiesfile.close();

            if(system() == "Windows"):
                #TODO(Bobby): Implement making properties file hidden
                # on Windows.
                #self._windowsMakePropertiesFileHidden();
                None;

            self._propertywindow.destroy();

            if(self._triggerprojectcreation):
                tkinterbuttoncallbacks.createProject(self._progressbarwindow,
                                                     self._projectlocation);
            else:
                from projecthandler.projectdisplayer import ProjectDisplayer

                self._projectdisplayer.destroyWindow();

                self._projectdisplayer = ProjectDisplayer(self._projectlocation);

                self._projectdisplayer.gridAndLoop();

    def __cancelCommand(self):
        self._propertywindow.destroy();
        if(self._triggerprojectcreation):
            self._progressbarwindow.destroy();

    def __fillTextsWithExistingProperties(self):
        self._projectnametext.insert(1.0,
                                    self._existingproperties["projectname"]);
        self._authortext.insert(1.0, self._existingproperties["author"]);
        self._descriptiontext.insert(1.0,
                                    self._existingproperties["description"]);

    def __init__(self, projectlocation, progressbarwindow,
                 triggerprojectcreation=True, projectdisplayer=None):
        self._projectlocation = projectlocation;
        self._progressbarwindow = progressbarwindow;
        self._triggerprojectcreation = triggerprojectcreation;
        self._projectdisplayer = projectdisplayer;

        if(self._triggerprojectcreation):
            positivebuttonstring = "Create project";
        else:
            positivebuttonstring = "Change project properties";
            self._existingproperties = load(open(self._projectlocation+
                                                 "/.properties.json"));

        self._propertywindow = Tk();
        self._propertywindow.wm_title("Jetfuel Game Engine Project Helper");
        if(system() != "Linux"):
            self._propertywindow.iconbitmap("icon.ico");

        self._propertywindow.resizable(0,0);

        self._projectnamelabel = Label(self._propertywindow,
                                       text="Project name");
        self._projectnametext = Text(self._propertywindow,width=20,
                                      height=1);

        self._authorlabel = Label(self._propertywindow,
                                       text="Project author");
        self._authortext = Text(self._propertywindow,width=20,
                                height=1);

        self._descriptionlabel = Label(self._propertywindow,
                                       text="Project description");
        self._descriptiontext = Text(self._propertywindow, width=35,
                                     height=8);

        if(not self._triggerprojectcreation):
            self.__fillTextsWithExistingProperties();

        self._submitbutton = Button(self._propertywindow,
                                  bg='green',
                                  text=positivebuttonstring,
                                  command=self.__createProjectPropertiesCommand);
        self._cancelbutton = Button(self._propertywindow,
                                  bg='red',
                                  text="Cancel",
                                  command=self.__cancelCommand);


        self._propertywindow.protocol("WM_DELETE_WINDOW",
                                      tkinterbuttoncallbacks.disableEvent);

    def gridAndLoop(self):
        self._projectnamelabel.grid(row=0, column=0, rowspan=2, columnspan=2);
        self._projectnametext.grid(row=0, column=2);

        self._authorlabel.grid(row=2, column=0, rowspan=2, columnspan=2);
        self._authortext.grid(row=2, column=2);

        self._descriptionlabel.grid(row=4, column=0, rowspan=3, columnspan=2);
        self._descriptiontext.grid(row=4, column=2);

        self._submitbutton.grid(row=7, column=1, columnspan=3);
        self._cancelbutton.grid(row=7, column=4);

        self._propertywindow.mainloop();
