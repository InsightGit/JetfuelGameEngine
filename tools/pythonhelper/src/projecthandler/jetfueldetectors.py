from os import path

from platform import system

def isJetfuel(location):
    if(system() == 'Windows'):
        return (path.isdir(location+"/PythonAPI/pythonwrappers/jetfuel") and
               path.isdir(location+"/externalDLLstoinclude") and
               path.isdir(location+"/include/") and
               path.isdir(location+"/templatecode/"));

def isProject(location):
    return (path.isdir(location+"/Scripts/jetfuel/") and
           path.isdir(location+"/jetfuelengine/include/") and
           path.isdir(location+"/src/") and
           path.isdir(location+"/Scripts") and
           path.isdir(location+"/Scripts/jetfuel") and
           path.isdir(location+"/runtimelibs/DLLs,SOs,etc") and
           path.isfile(location+"/.properties.json"));
