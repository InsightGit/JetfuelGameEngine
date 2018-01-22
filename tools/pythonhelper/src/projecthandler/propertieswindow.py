from tkinter import Tk
from tkinter import Text
from tkinter import Button
from tkinter import Label

from json import dumps
from projecthandler import tkinterbuttoncallbacks

from platform import system

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

    _projectlocation = None;

    def _windowsMakePropertiesFileHidden(self):
        import win32api
        import win32con
        win32api.SetFileAttributes('.properties.json',
                                    win32con.FILE_ATTRIBUTE_HIDDEN);

    def _createProjectPropertiesCommand(self):
        projectname = self._projectnametext.get('1.0', "end");
        projectauthor = self._authortext.get('1.0', "end");
        projectdescription = self._authortext.get('1.0', "end");

        if(projectname is not None and projectauthor is not None and
           projectdescription is not None):
            jsonpropertiesfile = open(self._projectlocation+"/.properties.json",
                                      "w");

            jsonpropertiesfile.write(dumps({
                        "projectname": projectname,
                        "author": projectauthor,
                        "description": projectdescription
                        }, sort_keys=True, indent=4));

            jsonpropertiesfile.close();

            if(system() == "Windows"):
                self._windowsMakePropertiesFileHidden();

            self._propertywindow.destroy();

            tkinterbuttoncallbacks.createProject(self._progressbarwindow,
                                                 self._projectlocation);

    def _cancelCommand(self):
        self._propertywindow.destroy();
        self._progressbarwindow.destroy();

    def __init__(self, projectlocation, progressbarwindow):
        self._projectlocation = projectlocation;
        self._progressbarwindow = progressbarwindow;

        self._propertywindow = Tk();

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

        self._submitbutton = Button(self._propertywindow,
                                  bg='green',
                                  text="Create Project",
                                  command=self._createProjectPropertiesCommand);
        self._cancelbutton = Button(self._propertywindow,
                                  bg='red',
                                  text="Cancel",
                                  command=self._cancelCommand);


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
