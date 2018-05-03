#    Project Neon- A moddable 2D RPG game engine
#    Copyright (C) 2017 InfernoStudios
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
from ctypes import c_int

from jetfuel.locale.localestring import locale_string

class string_locale_file(object):
    _jetfuel = None;
    stringlocalefileref = None;

    def __init__(self, jetfuelsoloader, stringlocaleref=None):
        self._jetfuel = jetfuelsoloader.jetfuelso;

        self._jetfuel.String_locale_file_new.restype = c_void_p;

        if(stringlocaleref is not None):
            self.stringlocalefileref = stringlocaleref;
        else:
            self.stringlocalefileref = self._jetfuel.String_locale_file_new();

    def load_string_locale_file(self, filename, localename):
        self._jetfuel.String_locale_file_load_string_locale_file.argtypes = [
                                            c_void_p, c_wchar_p, c_wchar_p];
        self._jetfuel.String_locale_file_load_string_locale_file.restype = \
                                                                c_wchar_p;
        error = self._jetfuel.String_locale_file_load_string_locale_file(
                        self.stringlocalefileref, filename, localename);

        if(error == "None"):
            return "";
        else:
            return error;

    def is_locale_file_set(self):
        self._jetfuel.String_locale_file_is_locale_file_set.argtypes = [
                                                            c_void_p];
        self._jetfuel.String_locale_file_is_locale_file_set.restype = c_bool;

        return self._jetfuel.String_locale_file_is_locale_file_set(
                                        self.stringlocalefileref);

    def get_locale_string_vector_size(self):
        self._jetfuel.String_locale_file_get_locale_string_vector_size.\
                                                argtypes = [c_void_p];
        self._jetfuel.String_locale_file_get_locale_string_vector_size.\
                                                        restype = c_int;

        return self._jetfuel.String_locale_file_get_locale_string_vector_size(
                                                    self.stringlocalefileref);

    def get_locale_string_vector_element(self, place, jetfuelsoloader):
        self._jetfuel.String_locale_file_get_locale_string_vector_element.\
                                            argtypes = [c_void_p, c_int];
        self._jetfuel.String_locale_file_get_locale_string_vector_element.\
                                            restype = c_void_p;

        localestring = locale_string(jetfuelsoloader,
                     self._jetfuel.\
        String_locale_file_get_locale_string_vector_element(
                        self.stringlocalefileref, place));

        return localestring;

    def get_string_locale_file_name(self):
        self._jetfuel.String_locale_file_get_string_locale_file_name.argtypes = [
                                                                    c_void_p];
        self._jetfuel.String_locale_file_get_string_locale_file_name.restype = \
                                                                    c_wchar_p;

        return self._jetfuel.String_locale_file_get_string_locale_file_name(
                                                self.stringlocalefileref);

    def get_string_locale_file_locale_name(self):
        self._jetfuel.String_locale_file_get_string_locale_file_locale_name.\
                                                        argtypes = [c_void_p];
        self._jetfuel.String_locale_file_get_string_locale_file_locale_name.\
                                                        restype = c_wchar_p;

        return self._jetfuel.\
        String_locale_file_get_string_locale_file_locale_name(
                                    self.stringlocalefileref);
