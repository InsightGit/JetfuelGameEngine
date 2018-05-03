#     Jetfuel Game Engine- A SDL-based 2D game-engine
#     Copyright (C) 2018 InfernoStudios
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

from ctypes import c_wchar_p
from ctypes import c_void_p
from ctypes import c_bool
from ctypes import c_char_p

class music():  
    
    _jetfuel = None;
    _musicref = None;
    
    def __init__(self,jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        self._jetfuel.Music_new.restype = c_void_p;
        self._musicref = self._jetfuel.Music_new();
        
    def __enter__(self):
        return self;
    
    def __exit__(self, exc_type, exc_value, traceback):
        if(self._musicref != None):
            self._jetfuel.Music_delete.argtypes = [c_void_p];
            self._jetfuel.Music_delete(self._musicref);

    def is_music_playing(self):
        return self._jetfuel.Music_is_music_playing();
        
    def is_music_paused(self):
        return self._jetfuel.Music_is_music_paused();

    def load_audio_file(self, musicfilepath):
        loadmusicfile = self._jetfuel.Music_load_audio_file;
        loadmusicfile.argtypes = [c_void_p, c_wchar_p];
        loadmusicfile.restype = c_bool;
        
        return loadmusicfile(self._musicref, 
                             musicfilepath);

    def play(self):
        self._jetfuel.Music_play.argtypes = [c_void_p];
        self._jetfuel.Music_play.restype = c_bool;
        return self._jetfuel.Music_play(self._musicref);
           
    def pause(self):
        self._jetfuel.Music_pause.argtypes = [c_void_p];
        self._jetfuel.Music_pause(self._musicref);
        
    def resume(self):
        self._jetfuel.Music_resume.argtypes = [c_void_p];
        self._jetfuel.Music_resume(self._musicref);
        
    def print_debug(self):
        print("Music ref is ="+str(self._musicref));
        
    def get_sdl_error(self):
        self._jetfuel.Get_sdl_error.restype = c_char_p;
        
        return self._jetfuel.Get_sdl_error();
