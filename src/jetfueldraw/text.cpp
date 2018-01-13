/*
* Jetfuel Game Engine- A SDL-based 2D game-engine
* Copyright (C) 2017 InfernoStudios
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <jetfueldraw/text.h>

#define winnull 0xCCCCCCCC

namespace jetfuel {
    namespace draw {

        void Text::Pre_render_text(){
            // Renders text into a SDL_Surface that will later be
            // converted to a SDL_Texture to be drawn on the screen.

			if (Get_text_surface() != nullptr && 
				reinterpret_cast<long int>(Get_text_surface()) != winnull &&
				!Has_text_surface_been_freed() && !Is_font_rendering_for_first_time()) {
				SDL_FreeSurface(Get_text_surface());
				Set_text_surface_been_freed(true);
			}

            switch(Get_render_mode()){
                case Render_mode::Solid:
                    Set_text_surface(TTF_RenderUTF8_Solid(
                                         Get_internal_font().Get_ttf_font(),
                                         Get_string().c_str(),
                                         Convert_Color_to_SDL_Color(
                                                 Get_text_color())));
                    break;
                case Render_mode::Shaded:
                    Set_text_surface(TTF_RenderUTF8_Shaded(
                                         Get_internal_font().Get_ttf_font(),
                                         Get_string().c_str(),
                                         Convert_Color_to_SDL_Color(
                                                 Get_text_color()),
                                         Convert_Color_to_SDL_Color(
                                                 Get_background_color())));
                    break;
                case Render_mode::Blended:
                    Set_text_surface(TTF_RenderUTF8_Blended(
                                         Get_internal_font().Get_ttf_font(),
                                         Get_string().c_str(),
                                         Convert_Color_to_SDL_Color(
                                                 Get_text_color())));
                    break;
            }

        }

        void Text::Pre_render(){
            // Changes font size if it has changed

            if(Get_past_font_size() != Get_font_size()){
                Font font = Get_internal_font();
                font.Change_size(Get_font_size());
                Set_internal_font(font);

                Set_is_font_created(true);
            }

            // If font is ready, set the font style,
            // create the SDL_TTF text surface, set the kerning status
            // and set font hinting and font kerning if not set.

            if(Is_ready_for_pre_rendering() && Is_font_created() &&
               Get_internal_font().Get_ttf_font() != nullptr){
                Set_is_ready_to_be_drawn(false);

                TTF_SetFontStyle(Get_internal_font().Get_ttf_font(),
                                                  Get_font_style());

                int hinting = static_cast<typename
                 std::underlying_type<Font_hinting>::type>(Get_font_hinting());
                  TTF_SetFontHinting(Get_internal_font().Get_ttf_font(),
                                     hinting);

                Pre_render_text();

                if(this->Get_text_surface() == nullptr){
                    throw exceptions::Nullptr_SDL_ttf_exception();
				} else {
					if (Waiting_to_set_kerning_status()) {
						Set_past_kerning_status();
					}

					if (Waiting_to_set_font_hinting()) {
						Set_past_font_hinting();
					}

					Set_is_ready_to_be_drawn(true);
					Set_is_surface_copied(false);
					Set_text_surface_been_freed(false);
				}
            }

            Set_past_font_size(Get_font_size());
        }

        Text::Text(Font font) {
            // Load font if initialized, otherwise throw exception.

            if(font.Is_font_loaded()){
                m_font = font;
            }else{
               throw exceptions::Font_not_init_exception();
            }

            Pre_render();
        }

        Text::~Text(){
            if(Get_text_surface() != nullptr && Is_surface_copied() &&
               Get_string() != "" && !Has_text_surface_been_freed()
			   && reinterpret_cast<long int>(Get_text_surface()->format->palette)
				  == 0x00000101){
                SDL_FreeSurface(Get_text_surface());
            }
        }

        void Text::Set_font(Font font){
            // Load font if initialized, otherwise throw exception.

            if(font.Is_font_loaded()){
                font.Change_size(Get_font_size());
                Set_internal_font(font);
            }else{
               throw exceptions::Font_not_init_exception();
            }

            Pre_render();
        }

        bool Text::Draw(){
            // If ready to be drawn, create SDL_TTF texture from
            // SDL_TTF surface (if not done yet), calculate
            // pixel size of text, then draw texture onto screen.

            if(Is_ready_to_be_drawn() && 
				reinterpret_cast<long int>(Get_text_surface()) != 0xCCCCCCCC){
                SDL_Rect dest;
                if(!Is_surface_copied() && Get_text_surface() != nullptr){
                    if(Is_font_rendering_for_first_time()){
                        Set_font_rendering_for_first_time(false);
                        return true;
                    }

                    SDL_Texture *texturefromsurface =
                     SDL_CreateTextureFromSurface(Get_renderer(),
                                                  Get_text_surface());

                    Set_text_rendered(texturefromsurface);

                    if(Get_text_rendered() != nullptr){
                        Set_is_surface_copied(true);
                    }else{
                        throw exceptions::Nullptr_SDL_ttf_exception();
                    }
                }


                dest.x = Get_dest().x;
                dest.y = Get_dest().y;

                int width;
                int height;

                if(Get_internal_font().Get_ttf_font() != nullptr){
                    TTF_SizeUTF8(Get_internal_font().Get_ttf_font(),
                                 Get_string().c_str(), &width, &height);
                }

                dest.w = width;
                dest.h = height;

                Set_rect_to_draw(dest.x,dest.y,dest.w,dest.h);

                SDL_RenderCopy(Get_renderer(), Get_text_rendered(), NULL, &dest);

                return true;
            }
            return false;
        }
    } /* namespace draw */
} /* namespace jetfuel */
