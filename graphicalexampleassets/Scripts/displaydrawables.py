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

from os.path import abspath
from platform import system
from time import sleep

from jetfuel.jetfuelsoloader import jetfuelsoloader

from jetfuel.control.uisinputactionsreplacement import \
                        uis_input_actions_replacement

from jetfuel.core.messagebus import message_bus

from jetfuel.inspire.pointerbridge import pointer_bridge

from jetfuel.draw.image import image
from jetfuel.draw.sprite import sprite
from jetfuel.draw.scenemanager import scene_manager
from jetfuel.draw.rectangle2dshape import rectangle_2d_shape
from jetfuel.draw.color import color
from jetfuel.draw.circle2dshape import circle_2d_shape
from jetfuel.draw.font import font
from jetfuel.draw.text import text
from jetfuel.draw.textchars import textchars
from jetfuel.draw.rectangle2dshapecharacteristicsreplacement import \
                    rectangle_2d_shape_characteristics_replacement
from jetfuel.draw.circle2dshapecharacteristicsreplacement import \
                    circle_2d_shape_characteristics_replacement

from jetfuel.gui.button import button
from jetfuel.gui.checkbox import check_box
from jetfuel.gui.dropdownbox import drop_down_box
from jetfuel.gui.menu import menu
from jetfuel.gui.buttoncharacteristicsreplacement import \
     button_characteristics_replacement
from jetfuel.gui.progressbar import progress_bar
from jetfuel.gui.slider import slider

from jetfuel.locale.stringlocalefile import string_locale_file
from jetfuel.locale.localestring import locale_string
from jetfuel.locale.stringlocalemanager import string_locale_manager

def create_slider(jetfuelso, scenemanager, pointerbridge, messagebus):
    slidertouse = slider(jetfuelso);

    scenemanager.attach_drawable(slidertouse, 52);

    rect2dchars = rectangle_2d_shape_characteristics_replacement(jetfuelso);
    rect2dchars.set_size(200, 20);
    rect2dchars.set_fill_color(color(jetfuelso, 0, 255, 0));
    slidertouse.set_slider_rail_characteristics(rect2dchars);
    print("Set slider rail");

    circle2dchars = circle_2d_shape_characteristics_replacement(jetfuelso);
    circle2dchars.set_radius(30);
    circle2dchars.set_filled_circle_status(True);
    circle2dchars.set_color(color(jetfuelso, 0, 0, 255));
    print("Set slider button chars");
    slidertouse.set_slider_button_characteristics(circle2dchars);
    print("Set slider button");

    slidercontrolscheme = uis_input_actions_replacement(jetfuelso);
    slidercontrolscheme.set_mouse_message_to_watch("Mouse_click");
    slidercontrolscheme.set_message_bus_to_send_message_to(messagebus);
    slidertouse.set_control_scheme(slidercontrolscheme);

    print("Set slider control scheme");

    slidertouse.set_number_of_statuses(50);
    slidertouse.set_current_status(0);
    slidertouse.set_position(1750, 400);

    pointerbridge.send_pointer("pythonslider", slidertouse.drawableref);

    print("Done with creating slider.");

def create_progress_bar(jetfuelso, scenemanager):
    progressbarimagefilepath = abspath("progressbarholder.png");

    progressbarimage = image(jetfuelso);
    progressbarimage.set_image_location(progressbarimagefilepath, 500, 200);

    print("Constructed image");

    progressbar = progress_bar(jetfuelso, progressbarimage,
                               color(jetfuelso, 255, 0, 0), 20,20,20,20,400);

    scenemanager.attach_drawable(progressbar, 59);

    progressbar.set_position(1400,100);

    print("Attached progressbar");

    while(not progressbar.has_progress_bar_completed()):
        progressbar.set_progress_bar_progress(
                                    progressbar.get_progress_bar_progress()+1);
        print("Incrementing progress");
        sleep(0.1);

def create_menu(jetfuelso, scenemanager, pointerbridge, messagebus):
    print("Creating menu...");

    buttonimagefilepath = abspath("button.png");
    fontfilepath = abspath("default.ttf");

    currentmenu = menu(jetfuelso, 500, 100, 50);
    scenemanager.attach_drawable(currentmenu, 101);
    print("Menu attachment passed")

    currentmenu.set_position(1500,500);
    print("Menu position setting passed");

    buttonchars = button_characteristics_replacement(jetfuelso);
    buttonimage = image(jetfuelso);
    buttonfont = font(jetfuelso, fontfilepath);
    buttontextchars = textchars(jetfuelso);
    buttontextchars.set_font(buttonfont);

    buttonimage.set_image_location(buttonimagefilepath, 200, 100);
    buttontextchars.set_font_size(15);
    buttontextchars.set_text_string("Quits maybe");

    print("Set universal values");

    buttonchars.set_image(buttonimage);
    print("Set first image");
    buttonchars.set_color(color(jetfuelso, 150, 0, 150, 100));
    print("Set first color");
    buttonchars.set_text_chars(buttontextchars);
    print("Set text chars");
    currentmenu.add_button(buttonchars, "Mouse_click", "quit", messagebus);

    print("First button passed");

    buttonimage = image(jetfuelso);
    buttonimage.set_image_location(buttonimagefilepath, 200, 100);

    print("Buttonimage passed");

    buttontextchars.set_text_string("Pointless button");
    buttonchars.set_color(color(jetfuelso, 255, 0, 255, 100));
    buttonchars.set_text_chars(buttontextchars);

    print("buttonchars passed");

    currentmenu.add_button(buttonchars, "Mouse_click", "POINTLESS", messagebus);

    print("Second button passed");

    buttonchars.delete_ref();
    buttontextchars.delete_ref();
    #buttonimage.delete_ref();

    pointerbridge.send_pointer("pythonmenu", currentmenu.drawableref);

    print("Done with creating menu.");

def create_drop_down_box(jetfuelso, scenemanager, pointerbridge):
    dropdownboximagefilepath = abspath("dropdownbox.png");
    fontfilepath = abspath("default.ttf");

    dropdownboxfont = font(jetfuelso, fontfilepath);

    dropdownimage = image(jetfuelso);

    dropdownimage.set_image_location(dropdownboximagefilepath, 200, 66);

    dropdownbox = drop_down_box(jetfuelso);

    scenemanager.attach_drawable(dropdownbox, 98);

    print("Attached drop down box");

    dropdownbox.load_base_box_image(dropdownimage, color(jetfuelso,255,255,255),
                                    45, 20);

    print("Loaded base box image");

    dropdownbox.set_uis_action_to_listen_for("Mouse_click");

    print("Set UIS action to listen for");

    dropdownboxtextchars = textchars(jetfuelso);

    dropdownboxtextchars.set_font(dropdownboxfont);
    dropdownboxtextchars.set_text_color(color(jetfuelso,255,0,0));
    dropdownboxtextchars.set_font_size(15);

    print("Made textchars replacement");

    dropdownbox.set_option_text_characteristics(dropdownboxtextchars);

    print("Set textchars replacement");

    dropdownbox.add_option("Why");
    dropdownbox.add_option("hello");
    dropdownbox.add_option("there");

    print("Added options");

    dropdownbox.set_position(1200,500);

    pointerbridge.send_pointer("pythondropdownbox", dropdownbox.drawableref);

    dropdownboxtextchars.delete_ref();

def create_check_box(jetfuelso, scenemanager, pointerbridge):
    checkboxactiveimagefilepath = abspath("checkboxactive.png");
    checkboxdisabledimagefilepath = abspath("checkboxdisabled.png");
    fontfilepath = abspath("default.ttf");

    currentcheckbox = check_box(jetfuelso);

    scenemanager.attach_drawable(currentcheckbox, 78);

    checkboxactiveimage = image(jetfuelso);
    checkboxdisabledimage = image(jetfuelso);

    checkboxactiveimage.set_image_location(checkboxactiveimagefilepath,
                                           128, 128);
    checkboxdisabledimage.set_image_location(checkboxdisabledimagefilepath,
                                             128, 128);
    currentcheckbox.load_check_box_images(checkboxactiveimage,
                                          checkboxdisabledimage);

    checkboxlabelfont = font(jetfuelso, fontfilepath);
    checkboxlabeltextchars = textchars(jetfuelso);

    checkboxlabeltextchars.set_font(checkboxlabelfont);
    checkboxlabeltextchars.set_text_color(color(jetfuelso,0,0,0));
    checkboxlabeltextchars.set_text_string("Python Checkbox");
    currentcheckbox.set_label_characteristics(checkboxlabeltextchars, False, 50);

    currentcheckbox.set_position(800, 600);

    currentcheckbox.set_uis_action_to_watch("Mouse_click");

    pointerbridge.send_pointer("pythoncheckbox", currentcheckbox.drawableref);

def create_quit_button(jetfuelso, scenemanager, messagebus, pointerbridge):
    imagefilepath = abspath("button.png");
    fontfilepath = abspath("default.ttf");

    print("Passed paths");

    currentbutton = button(jetfuelso);

    scenemanager.attach_drawable(currentbutton, 55);

    print("Passed attachment");

    print("Pointer="+hex(currentbutton.drawableref));

    buttonimage = image(jetfuelso);

    buttonimage.set_image_location(imagefilepath, 200, 100);

    if(currentbutton.load_base_button_image(buttonimage) == True):
        print("Passed base button loading");
    else:
        print("Failed base button loading");

    buttoncolor = color(jetfuelso, 15, 255, 135, 100);

    print("Passed image construction");

    buttonfont = font(jetfuelso, fontfilepath);

    buttontextchars = textchars(jetfuelso);

    buttontextchars.set_font(buttonfont);

    print("Constructed textchars");

    buttontextchars.set_text_string("Hello");

    print("Set textchars string");

    textcolor = color(jetfuelso,0,0,0);

    print("Done with textchars construction!");

    buttontextchars.set_text_color(buttoncolor);

    print("Setting text color for textchars...");

    currentbutton.set_button_text_characteristics(buttontextchars);

    print("Passed textchars button setting.");

    currentbutton.set_clicked_message("quit", messagebus);

    currentbutton.set_button_color(buttoncolor);

    currentbutton.set_position(1000,500);

    print("Passed clicked message set.")

    currentbutton.set_uis_action_to_watch("Mouse_click");

    pointerbridge.send_pointer("pythonbutton", currentbutton.drawableref);

def drawabledisplay(scenemanagerpointer, messagebuspointer,
                    pointerbridgepointer):
    print("Passed imports")

    if(system() == "Windows"):
        jetfuelpythonapiso = abspath("PythonAPI.dll");
    else:
        jetfuelpythonapiso = abspath("libJetfuel Game Engine Python API.so");
    imagefilepath = abspath("button.png");
    fontfilepath = abspath("default.ttf");

    print("jetfuelso="+jetfuelpythonapiso+" imagepath="+imagefilepath+"\n"+
          "scenemanagerpointer="+str(scenemanagerpointer));

    jetfuelso = jetfuelsoloader(jetfuelpythonapiso);

    scenemanager = scene_manager(jetfuelso, scenemanagerpointer);

    messagebus = message_bus(jetfuelso, messagebuspointer);

    pointerbridge = pointer_bridge(jetfuelso, pointerbridgepointer);

    print("Passed everything but image construction");

    currentimage = image(jetfuelso);

    print("Passed image construction");

    currentimage.set_image_location(imagefilepath, 200, 100);

    print("Passed image location");

    print("currentimage path="+str(currentimage.get_image_location())+
           " currentimage size= ("+str(currentimage.get_image_size_x())+","+
           str(currentimage.get_image_size_y())+")");

    currentsprite = sprite(jetfuelso);

    print("Passed sprite construction");

    currentsprite.set_position(500,500);

    print("Passed set position");

    scenemanager.attach_drawable(currentsprite, 5);

    if(currentsprite.load_from_image(currentimage) == True):
        print("Passed image loading");
    else:
        print("Failed image loading");

    currentrectangle = rectangle_2d_shape(jetfuelso, 600, 600, 100, 100);

    print("Passed rectangle construction");

    scenemanager.attach_drawable(currentrectangle, 6);

    currentcolor = color(jetfuelso, 0, 175, 255, 255);

    print("Passed color construction");

    currentrectangle.set_fill_color(currentcolor);

    currentcircle = circle_2d_shape(jetfuelso, 800, 800, 150);

    print("Passed circle construction");

    scenemanager.attach_drawable(currentcircle, 5);

    currentcircle.set_color(currentcolor);

    currentcircle.set_filled_circle_status(True);

    print("Passed circle drawing");

    currentfont = font(jetfuelso, fontfilepath);
    currenttext = text(jetfuelso, currentfont);

    scenemanager.attach_drawable(currenttext, 10);

    currenttext.set_position(100, 0);
    currenttext.set_text_color(currentcolor);
    currenttext.set_font_size(35);

    germanlocale = string_locale_file(jetfuelso);
    localemanager = string_locale_manager(jetfuelso);

    error = germanlocale.load_string_locale_file("GermanLocale.json", "german");
    if(error != ""):
        print("String locale error! Error is:"+error);

    localemanager.load_string_locale_file(germanlocale);

    localemanager.set_active_locale("german");

    currenttext.set_string(localemanager.get_string_from_id("pythontext"));

    print("Passed text construction");

    create_quit_button(jetfuelso, scenemanager, messagebus,
                        pointerbridge);
    create_check_box(jetfuelso, scenemanager, pointerbridge);
    create_drop_down_box(jetfuelso, scenemanager, pointerbridge);
    create_menu(jetfuelso, scenemanager, pointerbridge, messagebus);
    create_slider(jetfuelso, scenemanager, pointerbridge, messagebus);
    create_progress_bar(jetfuelso, scenemanager);

    print("Finished python tasks!");
