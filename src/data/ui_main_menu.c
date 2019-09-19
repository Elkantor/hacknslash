#if !defined RAYLIB_H
    #include <raylib.h>
#endif

/************************************* [DATA] *************************************************/
struct data_ui_main_menu {
    unsigned int textures_ids[7];
    unsigned short textures_loaded_count;
    unsigned short textures_current_idx;
    unsigned int render_textures_ids[1];
    unsigned short render_textures_loaded_count;
    unsigned short render_textures_current_idx;
} data_ui_main_menu = {
    .textures_ids                   = {0},
    .textures_loaded_count          = 0,
    .textures_current_idx           = 0,
    .render_textures_ids            = {0},
    .render_textures_loaded_count   = 0,
    .render_textures_current_idx    = 0,
};

/************************************* [PROCEDURES] *******************************************/
/* 
    Load a texture and add its id to the out_textures_ids table, at the in_textures_loaded_count position.
    Return the new number of textures loaded (previous in_textures_loaded_count + 1).
*/
void ui_main_menu_texture_load(const char* in_path, struct data_ui_main_menu* out_data){
    Texture2D texture = LoadTexture(in_path);
    out_data->textures_ids[out_data->textures_loaded_count] = texture.id;
    out_data->textures_loaded_count += 1;
}

void ui_main_menu_textures_unload(struct data_ui_main_menu* out_data){
    for(unsigned short i = data_ui_main_menu.textures_loaded_count; i > 0; --i){
        Texture2D texture = (Texture2D){ data_ui_main_menu.textures_ids[i-1], 0, 0, 1, 7 };
        UnloadTexture(texture);
    }
}

void ui_main_menu_render_texture_load(const int in_width, const int in_height, struct data_ui_main_menu* out_data){
    RenderTexture2D render_texture = LoadRenderTexture(ui_symbols_width, ui_symbols_height);
    out_data->render_textures_ids[out_data->textures_loaded_count] = render_texture.id;
    out_data->render_textures_loaded_count += 1;
}

void ui_main_menu_render_textures_unload(struct data_ui_main_menu* out_data){
    for(unsigned short i = data_ui_main_menu.render_textures_loaded_count; i > 0; --i){
        RenderTexture2D symbols_render_tex = (RenderTexture2D){ data_ui_main_menu.render_textures_ids[i-1], {0,0,0,0,0}, {0,0,0,0,0}, 0};
        UnloadRenderTexture(symbols_render_tex);
    }
}


const struct ui_main_menu {
    struct data_ui_main_menu* const data;
    void (*const texture_load)(const char* in_path, struct data_ui_main_menu* out_data);
    void (*const textures_unload)(struct data_ui_main_menu* out_data);
    void (*const render_texture_load)(const int in_width, const int in_height, struct data_ui_main_menu* out_data);
    void (*const render_textures_unload)(struct data_ui_main_menu* out_data);
} ui_main_menu = {
    .data                   = &data_ui_main_menu,
    .texture_load           = ui_main_menu_texture_load,
    .textures_unload        = ui_main_menu_render_textures_unload,
    .render_texture_load    = ui_main_menu_render_texture_load,
    .render_textures_unload = ui_main_menu_render_textures_unload,
};