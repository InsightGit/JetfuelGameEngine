from time import sleep

from platform import system

from threading import Thread

from shutil import rmtree

from tkinter import Tk
from tkinter import Label
from tkinter import Button
from tkinter import messagebox

from json import load

from projecthandler.propertieswindow import PropertiesWindow

class ProjectDisplayer:
    _projectlocation = None;
    _parsedjsondict = None;

    _projectdisplaywindow = None;

    _projectnamelabel = None;
    _authorlabel = None;
    _descriptionlabel = None;

    _projectadditonsbutton = None;
    _deleteprojectbutton = None;

    _editprojectpropertiesbutton = None;

    def __deleteProjectCallback(self):
        if(messagebox.askyesno(message="Are you sure you want to delete the "+
                            "entire project folder?(This cannot be undone!)",
                            title="Deletion Confirmation")):
            self._projectdisplaywindow.destroy();

            try:
                rmtree(self._projectlocation);

                messagebox.showinfo(message="Project deletion Successful!");
            except(OSError, e):
                messagebox.showinfo(message="Something went wrong during"+
                                    "deletion. The specific error was:"+
                                    e.strerror,icon="error");


    def __editProjectPropertiesCallback(self):
        projectPropertiesWindow = PropertiesWindow(self._projectlocation, None,
                                                   False, self);
        projectPropertiesWindow.gridAndLoop();

    def __init__(self, projectlocation):
        self._projectlocation = projectlocation;

        self._parsedjsondict = load(open(self._projectlocation+
                                         "/.properties.json"));

        self._projectdisplaywindow = Tk();
        self._projectdisplaywindow.resizable(0,0);
        self._projectdisplaywindow.wm_title("Jetfuel Game Engine Project "+
                                            "Helper");
        if(system() != "Linux"):
            self._projectdisplaywindow.iconbitmap("icon.ico");

        self._projectnamelabel = Label(self._projectdisplaywindow,
                                      text="Project name: "+
                                      self._parsedjsondict["projectname"]);
        self._authorlabel = Label(self._projectdisplaywindow,
                                  text="Project author: "+
                                  self._parsedjsondict["author"]);
        self._descriptionlabel = Label(self._projectdisplaywindow,
                                       text="Project description: "+
                                       self._parsedjsondict["description"]);

        self._editprojectpropertiesbutton = Button(self._projectdisplaywindow,
                                                 text="Edit Project Properties",
                                                 bg='yellow', command=self.\
                                                __editProjectPropertiesCallback);
        self._projectadditonsbutton = Button(self._projectdisplaywindow,
                                             text="Project Additions"+
                                                  "(To Be Implemented)",
                                             bg='green');
        self._deleteprojectbutton = Button(self._projectdisplaywindow,
                                           text="Delete Project", bg='red',
                                           command=self.__deleteProjectCallback);

    def gridAndLoop(self):
        self._projectnamelabel.grid(row=0, column=0);
        self._authorlabel.grid(row=1, column=0);
        self._descriptionlabel.grid(row=2, column=0, rowspan=4);

        self._editprojectpropertiesbutton.grid(row=6, column=0);
        self._projectadditonsbutton.grid(row=6, column=1, padx=50);
        self._deleteprojectbutton.grid(row=6, column=2);

        self._projectdisplaywindow.mainloop();

    def destroyWindow(self):
        self._projectdisplaywindow.destroy();
