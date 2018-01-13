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

from jetfuel.core.message_bus import message_bus
from jetfuel.jetfuelsoloader import jetfuelsoloader


def testmessagebus(messagebuspointer):
    jetfuelpythonapiso = abspath("libJetfuel Game Engine Python API.so");
    
    print("jetfuelso="+jetfuelpythonapiso+" type="+
          type(messagebuspointer).__name__);
    
    jetfuelso = jetfuelsoloader(jetfuelpythonapiso);
    
    currentmessagebus = message_bus(jetfuelso,messagebuspointer);
    
    if(currentmessagebus.post_message("Test from python.") == True):
        print("Posted message.");
    else:
        print("Test failed because of no message bus passed");
    
    if(currentmessagebus.does_message_exist("Test from python.") == True):
        print("Test passed.");
    else:
        print("Test failed because of no message existing.");
