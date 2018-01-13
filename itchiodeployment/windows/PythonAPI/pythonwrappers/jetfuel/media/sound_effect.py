#     Jetfuel Game Engine- A SDL-based 2D game-engine
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

from ctypes import c_void_p
from ctypes import c_bool
from ctypes import c_wchar_p
from ctypes import c_uint
from ctypes import c_char_p

class sound_effect(object):
    _jetfuel = None;
    _soundeffectref = None;

    def __init__(self, jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;
        self._jetfuel.Sound_effect_new.restype = c_void_p;
        self._soundeffectref = self._jetfuel.Sound_effect_new();
        
    def __enter__(self):
        return self;
    
    def __exit__(self, exc_type, exc_value, traceback):
        if(self._musicref != None):
            self._jetfuel.Sound_effect_delete.argtypes = [c_void_p];
            self._jetfuel.Sound_effect_delete(self._soundeffectref);
            
    @staticmethod
    def is_sound_effect_or_music_playing(jetfuelsoloader):
        jetfuelsoloader.jetfuelso.Sound_effect_is_sound_effect_or_music_playing.restype = (
                                                                    c_bool);
        
        return jetfuelsoloader.jetfuelso.Sound_effect_is_sound_effect_or_music_playing();

    def get_loaded_sound_effect_file(self):
        self._jetfuel.Sound_effect_get_loaded_sound_effect_file.argtypes = [
                        c_void_p];
        self._jetfuel.Sound_effect_get_loaded_sound_effect_file.restype = ( 
                c_wchar_p);
        return self._jetfuel.Sound_effect_get_loaded_sound_effect_file(
                        self._soundeffectref);
    
    def load_audio_file(self, audiofilepath):
        self._jetfuel.Sound_effect_load_audio_file.argtypes = [c_void_p,
                                                               c_wchar_p];
        self._jetfuel.Sound_effect_load_audio_file.restype = (c_bool);
        
        
        return self._jetfuel.Sound_effect_load_audio_file(self._soundeffectref,
                                                          audiofilepath);
    
    def get_times_to_repeat(self):
        self._jetfuel.Sound_effect_get_times_to_repeat.argtypes = [c_void_p];
        self._jetfuel.Sound_effect_get_times_to_repeat.argtypes = c_uint;
        return self._jetfuel.Sound_effect_get_times_to_repeat(
                                        self._soundeffectref);
    
    def set_times_to_repeat(self, timestorepeat):
        self._jetfuel.Sound_effect_set_times_to_repeat.argtypes = [c_void_p, 
                                                                   c_uint];
        self._jetfuel.Sound_effect_set_times_to_repeat(self._soundeffectref,
                                                       timestorepeat);
                                                       
    def play(self):
        self._jetfuel.Sound_effect_play.argtypes = [c_void_p];
        self._jetfuel.Sound_effect_play.restype = c_bool;
        return self._jetfuel.Sound_effect_play(self._soundeffectref);
        
    def pause(self):
        self._jetfuel.Sound_effect_pause.argtypes = [c_void_p];
        self._jetfuel.Sound_effect_pause(self._soundeffectref);
        
    def resume(self):
        self._jetfuel.Sound_effect_pause.argtypes = [c_void_p];
        self._jetfuel.Sound_effect_pause(self._soundeffectref);
        
    def get_sound_effect_error(self):
        self._jetfuel.Get_sdl_error.restype = c_char_p;
        return self._jetfuel.Get_sdl_error();   
        