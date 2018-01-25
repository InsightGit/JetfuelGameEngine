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
