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
from ctypes import c_wchar_p

class locale_string(object):
    _jetfuel = None;
    localestringref = None;

    def __init__(self, jetfuelsoloader, localestringref):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        
        self._jetfuel.Locale_string_new.restype = c_void_p;
        
        if(localestringref is not None):
            self.localestringref = localestringref;
        else:
            self.localestringref = self._jetfuel.Locale_string_new();
        
    def get_locale_string_id(self):
        self._jetfuel.Locale_string_get_locale_string_id.argtypes = [c_void_p];
        self._jetfuel.Locale_string_get_locale_string_id.restype = c_wchar_p;
        
        return self._jetfuel.Locale_string_get_locale_string_id(
                                        self.localestringref);
                                        
    def set_locale_string_id(self, localestringid):
        self._jetfuel.Locale_string_set_locale_string_id.argtypes = [c_void_p, 
                                                         c_wchar_p];
                                                         
        self._jetfuel.Locale_string_set_locale_string_id(localestringid);
        
    def get_locale_string(self):
        self._jetfuel.Locale_string_get_locale_string.argtypes = [c_void_p];
        self._jetfuel.Locale_string_get_locale_string.restype = c_wchar_p;
        
        return self._jetfuel.Locale_string_get_locale_string(
                                        self.localestringref);
                                        
    def set_locale_string(self, localestring):
        self._jetfuel.Locale_string_set_locale_string.argtypes = [c_void_p, 
                                                      c_wchar_p];
                                                         
        self._jetfuel.Locale_string_set_locale_string(localestring);