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

def playsfx():
    jetfuelpythonapi = abspath("../PythonAPIWrappers/");
    jetfuelpythonapiso = abspath("../libJetfuel Game Engine Python API.so");
    musicpath = abspath("../sfx.ogg");
    
    path.append(jetfuelpythonapi);
    
    print("jetfuelso="+jetfuelpythonapiso+" jetfuelapi="+jetfuelpythonapi+
      " musicpath="+musicpath);
    
    from jetfuel.media.sound_effect import sound_effect
    from jetfuel.jetfuelsoloader import jetfuelsoloader
    
    jetfuelso = jetfuelsoloader(jetfuelpythonapiso);
    
    currentsfx = sound_effect(jetfuelso);
    
    if(currentsfx.load_audio_file(musicpath) == False):
        print("Could not open sound effect. Error was: "+
              jetfuelso.get_sdl_error());
              
    if(currentsfx.play() == False):
        print("Could not play sound effect. Error was: "+
              jetfuelso.get_sdl_error());
              
    while(sound_effect.is_sound_effect_or_music_playing(jetfuelso) == True):
        print("Sound effect is playing");
    
if(__name__== "__main__"):
    playsfx()