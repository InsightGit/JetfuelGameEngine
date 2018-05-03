from ctypes import c_void_p
from ctypes import c_int
from ctypes import c_bool
from ctypes import c_wchar_p

class textchars(object):
    _jetfuel = None;
    textcharsref = None;

    def __init__(self, jetfuelsoloader):
        self._jetfuel = jetfuelsoloader.jetfuelso;

        self._jetfuel.Text_chars_new.restype = c_void_p;

        self.textcharsref = self._jetfuel.Text_chars_new();

    def delete_ref(self):
        if(self.textcharsref is not None):
            self._jetfuel.Text_chars_delete.argtypes = [c_void_p];

            self._jetfuel.Text_chars_delete(self.textcharsref);

    def get_render_mode(self):
        self._jetfuel.Text_chars_get_render_mode.\
             argtypes = [c_void_p];
        self._jetfuel.Text_chars_get_render_mode.\
            restype = c_int;

        return self._jetfuel.Text_chars_get_render_mode(
                            self.textcharsref);

    def set_render_mode(self, rendermode):
        self._jetfuel.Text_chars_set_render_mode.\
                        argtypes = [c_void_p, c_int];

        self._jetfuel.Text_chars_set_render_mode(
        self.textcharsref, rendermode);

    def get_text_string(self):
       self._jetfuel.Text_chars_get_text_string.\
            argtypes = [c_void_p];
       self._jetfuel.Text_chars_get_text_string.\
            restype = c_wchar_p;

       return self._jetfuel.Text_chars_get_text_string(
                        self.textcharsref);

    def set_text_string(self, textstring):
       self._jetfuel.Text_chars_set_text_string.\
                argtypes = [c_void_p, c_wchar_p];

       self._jetfuel.Text_chars_set_text_string(
       self.textcharsref, textstring);

    def get_text_color(self, jetfuelsoloader):
        self._jetfuel.Text_chars_get_text_color.argtypes = [c_void_p];
        self._jetfuel.Text_chars_get_text_color.restype = c_void_p;

        currentcolor = color(jetfuelsoloader.jetfuelso);

        self._jetfuel.Color_delete.argtypes = [c_void_p];

        self._jetfuel.Color_delete(currentcolor.colorref);

        currentcolor.colorref = self._jetfuel.\
         Text_chars_get_text_color(self.textcharsref);

        return currentcolor;

    def set_text_color(self, textcolor):
        self._jetfuel.Text_chars_set_text_color.argtypes = [c_void_p, c_void_p];

        self._jetfuel.Text_chars_set_text_color(
          self.textcharsref, textcolor.colorref);

    def get_background_color(self, jetfuelsoloader):
        self._jetfuel.Text_chars_get_background_color.argtypes = [
                                                                c_void_p];
        self._jetfuel.Text_chars_get_background_color.restype = c_void_p;

        currentcolor = color(jetfuelsoloader.jetfuelso);

        self._jetfuel.Color_delete.argtypes = [c_void_p];

        self._jetfuel.Color_delete(currentcolor.colorref);

        currentcolor.colorref = self._jetfuel.\
        Text_chars_get_background_color(self.textcharsref);

        return currentcolor;

    def set_background_color(self, backgroundcolor):
        self._jetfuel.Text_set_background_color.argtypes = [c_void_p, c_void_p];

        self._jetfuel.Text_set_background_color(self.textcharsref,
                                                backgroundcolor.colorref);

    #here

    def get_font_outline_width(self):
        self._jetfuel.Text_chars_get_font_outline_width.\
             argtypes = [c_void_p];
        self._jetfuel.Text_chars_get_font_outline_width.\
             restype = c_int;

        return self._jetfuel.\
            Text_chars_get_font_outline_width(
                self.textcharsref);

    def set_font_outline_width(self, fontoutline):
        self._jetfuel.Text_chars_set_font_outline_width.\
             argtypes = [c_void_p, c_int];

        self._jetfuel.Text_chars_set_font_outline_width(
            self.textcharsref, fontoutline);

    def get_font_kerning_status(self):
        self._jetfuel.Text_chars_get_font_kerning_status.\
             argtypes = [c_void_p];
        self._jetfuel.Text_chars_get_font_kerning_status.\
             restype = c_bool;

        return self._jetfuel.\
            Text_chars_get_font_kerning_status(
                self.textcharsref);

    def set_font_kerning_status(self, kerningstatus):
        self._jetfuel.Text_chars_set_font_kerning_status.\
             argtypes = [c_void_p, c_bool];

        self._jetfuel.Text_chars_set_font_kerning_status(
            self.textcharsref, kerningstatus);

    def get_font_style(self):
        self._jetfuel.Text_chars_get_font_style.\
             argtypes = [c_void_p];
        self._jetfuel.Text_chars_get_font_style.\
             restype = c_int;

        return self._jetfuel.\
            Text_chars_get_font_style(
                self.textcharsref);

    def set_font_style(self, fontstyle):
        self._jetfuel.Text_chars_set_font_style.\
             argtypes = [c_void_p, c_int];

        self._jetfuel.Text_chars_set_font_style(
            self.textcharsref, fontstyle);

    def get_font_size(self):
        self._jetfuel.Text_chars_get_font_size.\
             argtypes = [c_void_p];
        self._jetfuel.Text_chars_get_font_size.\
             restype = c_int;

        return self._jetfuel.\
            Text_chars_get_font_size(
                self.textcharsref);

    def set_font_size(self, fontsize):
        self._jetfuel.Text_chars_set_font_size.\
             argtypes = [c_void_p, c_int];

        self._jetfuel.Text_chars_set_font_size(
            self.textcharsref, fontsize);

    def get_font_hinting(self):
        self._jetfuel.Text_chars_get_font_hinting.\
             argtypes = [c_void_p];
        self._jetfuel.Text_chars_get_font_hinting.\
             restype = c_int;

        return self._jetfuel.\
            Text_chars_get_font_hinting(
                self.textcharsref);

    def set_font_hinting(self, fonthinting):
        self._jetfuel.Text_chars_set_font_hinting.\
             argtypes = [c_void_p, c_int];

        self._jetfuel.Text_chars_set_font_hinting(
            self.textcharsref, fonthinting);

    def get_font(self):
        self._jetfuel.Text_chars_get_font.argtypes = [c_void_p];
        self._jetfuel.Text_chars_get_font.restype = c_void_p;

        return self._jetfuel.Text_chars_get_font(self.textcharsref);

    def set_font(self, font):
        self._jetfuel.Text_chars_set_font.argtypes = [c_void_p, c_void_p];

        self._jetfuel.Text_chars_set_font(self.textcharsref, font.fontref);
