#ifndef SCREEN_H
#define SCREEN_H

#include <raylib.h>
#include <stdint.h>

#include "modules/logging/logging.c"

/************************************* [DATA] *************************************************/
#define screen_data_main_menu   0
#define screen_data_game        1    

uint8_t screen                                              = screen_data_main_menu;
Font screen_data_font;
unsigned int screen_data_textures_ids[20]                   = {0};
unsigned short screen_data_textures_loaded_count            = 0;
unsigned short screen_data_textures_current_idx             = 0;
unsigned int screen_data_render_textures_ids[1]             = {0};
unsigned short screen_data_render_textures_loaded_count     = 0;
unsigned short screen_data_render_textures_current_idx      = 0;


/************************************* [PROCEDURES] *******************************************/
static inline void screen_texture_load(const char* in_path)
{
    Texture2D texture = LoadTexture(in_path);
    screen_data_textures_ids[screen_data_textures_loaded_count] = texture.id;
    screen_data_textures_loaded_count += 1;
    logging_open();
    logging_write("</br><div style='display: flex;'>");
    logging_write("<div style='flex: 1 1 auto; color: blue;'>texture loaded\t%d</div>\n", texture.id);
    logging_write("<div style='flex: 1 1 auto; color: darkgray;'>%s</div>\n", in_path);
    logging_write("</div>");
    logging_close();
}

static inline void screen_texture_load_flip_horizontal(const char* in_path)
{
    Image image = LoadImage(in_path);
    ImageFlipHorizontal(&image);
    Texture texture = LoadTextureFromImage(image);
    screen_data_textures_ids[screen_data_textures_loaded_count] = texture.id;
    screen_data_textures_loaded_count += 1;
    logging_open();
    logging_write("<div style='display: flex;'>");
    logging_write("<div style='flex: 1 1 auto; color: blue;'>texture flip horizontal loaded\t%d</div>\n", texture.id);
    logging_write("<div style='flex: 1 1 auto; color: darkgray;'>%s</div>\n", in_path);
    logging_write("</div>");
    logging_close();
}

static inline void screen_texture_load_flip_vertical(const char* in_path)
{
    Image image = LoadImage(in_path);
    ImageFlipVertical(&image);
    Texture texture = LoadTextureFromImage(image);
    screen_data_textures_ids[screen_data_textures_loaded_count] = texture.id;
    screen_data_textures_loaded_count += 1;
    logging_open();
    logging_write("<div style='display: flex;'>");
    logging_write("<div style='flex: 1 1 auto; color: blue;'>texture flip vertical loaded\t%d</div>\n", texture.id);
    logging_write("<div style='flex: 1 1 auto; color: darkgray;'>%s</div>\n", in_path);
    logging_write("</div>");
    logging_close();
}

static inline void screen_textures_unload()
{
    logging_open();
    logging_write("</br>\n");
    for(unsigned short i = screen_data_textures_loaded_count; i > 0; --i){
        Texture2D texture = (Texture2D){ screen_data_textures_ids[i-1], 0, 0, 1, 7 };
        logging_write("<em style='color: green;'>texture unloaded\t%d</em>\n", texture.id);
        UnloadTexture(texture);
         screen_data_textures_ids[i-1] = 0;
    }
    logging_close();
}

static inline void screen_render_texture_load(const int in_width, const int in_height)
{
    RenderTexture2D render_texture = LoadRenderTexture(in_width, in_height);
    screen_data_render_textures_ids[screen_data_textures_loaded_count] = render_texture.id;
    screen_data_render_textures_loaded_count += 1;
}

static inline void screen_render_textures_unload()
{
    for(unsigned short i = screen_data_render_textures_loaded_count; i > 0; --i){
        RenderTexture2D render_texture = (RenderTexture2D){ screen_data_render_textures_ids[i-1], {0,0,0,0,0}, {0,0,0,0,0}, 0};
        UnloadRenderTexture(render_texture);
        screen_data_render_textures_ids[i-1] = 0;
    }
}

#endif // SCREEN_H