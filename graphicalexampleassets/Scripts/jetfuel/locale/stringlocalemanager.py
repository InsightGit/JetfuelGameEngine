#    Project Neon- A moddable 2D RPG game engine
#    Copyright (C) 2018 InfernoStudios
# 
#   Project Neon is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
# 
#   Project Neon is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
# 
#   You should have received a copy of the GNU General Public License
#   along with Project Neon.  If not, see <http://www.gnu.org/licenses/>.

from ctypes import c_void_p  
from ctypes import c_bool 
from ctypes import c_wchar_p

from jetfuel.locale.stringlocalefile import string_locale_file

class string_locale_manager(object):
    _jetfuel = None;
    _stringlocalemanagerref = None;

    def __init__(self, jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        self._jetfuel.String_locale_manager_new.restype = c_void_p;
        
        self._stringlocalemanagerref = self._jetfuel.String_locale_manager_new();
        
    def load_string_locale_file(self, stringlocalefile):
        self._jetfuel.String_locale_manager_load_string_locale_file.argtypes = [
                                                            c_void_p, c_void_p];
        self._jetfuel.String_locale_manager_load_string_locale_file.restype = \
                                                                        c_bool;
                                                                        
        return self._jetfuel.String_locale_manager_load_string_locale_file(
                                            self._stringlocalemanagerref, 
                                    stringlocalefile.stringlocalefileref);
                                    
    def get_active_locale(self):
        self._jetfuel.String_locale_manager_get_active_locale.argtypes = [
                                                                c_void_p];
        self._jetfuel.String_locale_manager_get_active_locale.restype = \
                                                            c_wchar_p;
                                                            
        return self._jetfuel.String_locale_manager_get_active_locale(
                                        self._stringlocalemanagerref);
                                        
    def set_active_locale(self, localename):
        self._jetfuel.String_locale_manager_set_active_locale.argtypes = [
                                                    c_void_p, c_wchar_p];
                                                            
        self._jetfuel.String_locale_manager_set_active_locale(
                                        self._stringlocalemanagerref,
                                        localename);
                                        
    def get_active_string_locale_file(self):
        self._jetfuel.String_locale_manager_get_active_string_locale_file.\
                                                    argtypes = [c_void_p];
        self._jetfuel.String_locale_manager_get_active_string_locale_file.\
                                                    restype = c_void_p;
        
        returnvalue = string_locale_file(                                            
        self._jetfuel.String_locale_manager_get_active_string_locale_file(
        self._stringlocalemanagerref));
        
        return returnvalue;
    
    def get_string_from_id(self, stringid):
        self._jetfuel.String_locale_manager_get_string_from_id.argtypes = [
                                                    c_void_p, c_wchar_p];
        self._jetfuel.String_locale_manager_get_string_from_id.\
                                            restype = c_wchar_p;
                                            
        return self._jetfuel.String_locale_manager_get_string_from_id(
                                self._stringlocalemanagerref,stringid);