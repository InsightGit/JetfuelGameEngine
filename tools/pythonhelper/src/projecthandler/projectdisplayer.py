class ProjectDisplayer:
    _projectlocation = None;
    _parsedjsondict = None;

    _projectnamelabel = None;

    def __init__(self, projectlocation):
        self._projectlocation = projectlocation;

        self._parsedjsondict = json.load(open(self._projectlocation+
                                              "/.properties.json"));

        #self._projectnamelabel =
