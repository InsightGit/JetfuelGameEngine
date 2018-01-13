#     Jetfuel Game Engine Graphical Example - An example of Jetfuel,
#     the SDL-based 2D game-engine
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
from sys import path
from os.path import abspath
from ctypes import c_char_p

from jetfuel.media.music import music
from jetfuel.jetfuelsoloader import jetfuelsoloader

def playmusic():
    jetfuelpythonapiso = abspath("libJetfuel Game Engine Python API.so");
    musicpath = abspath("music.ogg");
    
    print("jetfuelso="+jetfuelpythonapiso+
      " musicpath="+musicpath);
    
    jetfuelso = jetfuelsoloader(jetfuelpythonapiso);
    
    currentmusic = music(jetfuelso);
    
    if(currentmusic.load_audio_file(musicpath) == False):
        print("Could not open music file. Error was: "+
              jetfuelso.get_sdl_error());
    
    if(currentmusic.play() == False):
        print("Could not play music. Error was: "+
              jetfuelso.get_sdl_error());
              
    #while(currentmusic.is_music_playing() == True):
        #print("Music is playing");
        
if(__name__== "__main__"):
    playmusic()
