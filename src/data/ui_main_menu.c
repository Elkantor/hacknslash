#ifndef UI_MAIN_MENU_H
#define UI_MAIN_MENU_H

#if !defined RAYLIB_H
    #include <raylib.h>
#endif

#include "../data.c"
#include "../modules/screen/screen.c"
#include "../modules/math/math.c"

/************************************* [DATA] *************************************************/
_Bool ui_main_menu_loaded = false;

/************************************* [PROCEDURES] *******************************************/
static inline void ui_main_menu_load(void){
    screen_data_textures_loaded_count = 0;
    /* 1 */ screen_texture_load("data/ui/main_menu/background.jpg");
    /* 2 */ screen_texture_load("data/ui/main_menu/logo.png");
    /* 3 */ screen_texture_load("data/ui/main_menu/character_selection/trim_textures/trim_arrow_left_select.png");
    /* 4 */ screen_texture_load_flip_horizontal("data/ui/main_menu/character_selection/trim_textures/trim_arrow_left_select.png");
    /* 5 */ screen_texture_load("data/ui/main_menu/character_selection/character.png");
    /* 6 */ screen_texture_load("data/ui/main_menu/bottom_bar.png");
    /* 7 */ screen_texture_load("data/ui/main_menu/character_selection/glow_color.png");
    /* 8 */ screen_texture_load("data/ui/main_menu/character_selection/trim_textures/trim_play_button.png");
    /* 9 */ screen_texture_load("data/ui/main_menu/symbols_right.png");
    /* 10 */ screen_texture_load_flip_horizontal("data/ui/main_menu/symbols_right.png");

    screen_data_render_textures_loaded_count = 0;
    screen_render_texture_load(ui_arrow_width, ui_arrow_height);

    ui_main_menu_loaded = true;
}

static inline void ui_main_menu_unload(void){
    screen_render_textures_unload();
    screen_textures_unload();
    ui_main_menu_loaded = false;
    logging_open();
    logging_write("<strong>ui_main_menu successfully unloaded</strong>");
    logging_close();
}

void ui_main_menu_draw(void){
    screen_data_textures_current_idx = 0;
    screen_data_render_textures_current_idx = 0;

    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D background = { current_texture_id, ui_background_width, ui_background_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        DrawTexture(background, 0, 0, WHITE);
    }
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D logo = { current_texture_id, ui_logo_width, ui_logo_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        Vector2 position = {1920/2 - logo.width/2, 1080/40};
        DrawTexture(logo, position.x, position.y, WHITE);
    }
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D left_arrow = { current_texture_id, ui_arrow_width, ui_arrow_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        Vector2 position = { (1920/40), 500 };
        Rectangle left_arrow_rec = { position.x, position.y, left_arrow.width, left_arrow.height/3 };
        DrawTextureRec(left_arrow, ui_arrow_rectangle, position, WHITE);
        if(CheckCollisionPointRec(GetMousePosition(), left_arrow_rec)){
            if(IsMouseButtonDown(0)){
                DrawTextureRec(left_arrow, ui_arrow_rectangle_pressed, position, WHITE);
            }else{
                DrawTextureRec(left_arrow, ui_arrow_rectangle_hovered, position, WHITE);
            }
        }
    }
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D right_arrow = { current_texture_id, ui_arrow_width, ui_arrow_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        Vector2 position = { (1920/40)*38, 500  };
        Rectangle right_arrow_rec = { position.x, position.y, right_arrow.width, right_arrow.height/3 };
        DrawTextureRec(right_arrow, ui_arrow_rectangle, position, WHITE);
        if(CheckCollisionPointRec(GetMousePosition(), right_arrow_rec)){
            if(IsMouseButtonDown(0)){
                DrawTextureRec(right_arrow, ui_arrow_rectangle_pressed, position, WHITE);
            }else{
                DrawTextureRec(right_arrow, ui_arrow_rectangle_hovered, position, WHITE);
            }
        }
    }
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D character = { current_texture_id, ui_character_width, ui_character_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        DrawTexture(character, 1920/2 - (ui_character_width/30)*16, 1080 - (ui_character_height/30)*29, WHITE);
    }
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D bottom_bar = { current_texture_id, ui_bottom_bar_width, ui_bottom_bar_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        DrawTexture(bottom_bar, 0, 1080 - bottom_bar.height, WHITE);
    }
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D glow_color = { current_texture_id, ui_glow_color_width, ui_glow_color_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        Vector2 position = { (1920/2) - (glow_color.width/2), 1080 - 62 - ui_glow_color_height };
        DrawTextureRec(glow_color, ui_glow_color_rectangle, position, WHITE);
    }
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D play_button = { current_texture_id, ui_play_button_width, ui_play_button_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        Vector2 position = { ((1920)/2) - ((ui_play_button_width/3)/2), 1080 - 62 - play_button.height/2 + 5 };
        Rectangle button_rec = { position.x, position.y, play_button.width/3, play_button.height };
        if(CheckCollisionPointRec(GetMousePosition(), button_rec)){
            if(IsMouseButtonDown(0)){
                DrawTextureRec(play_button, ui_play_button_rectangle_pressed, position, WHITE);
                screen = SCREEN_GAME;
                ui_main_menu_unload();
                return;
            }else{
                DrawTextureRec(play_button, ui_play_button_rectangle_hovered, position, WHITE);
            }
        }else{
            DrawTextureRec(play_button, ui_play_button_rectangle, position, WHITE);
        }
        DrawTextEx(screen_data_font, "PLAY", (Vector2){ position.x + (play_button.width/3)/2 - 2*(48/math_data_phi), position.y + 25}, 48, 1, WHITE);
    }

    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D symbols_right = { current_texture_id, ui_symbols_width, ui_symbols_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        Vector2 position = { 1920 - (symbols_right.width), 1080 - (symbols_right.height) };
        DrawTextureRec(symbols_right, ui_symbols_rectangle, position, WHITE);
    }
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D symbols_left = { current_texture_id, ui_symbols_width, ui_symbols_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        Vector2 position = { 0, 1080 - (symbols_left.height) };
        DrawTextureRec(symbols_left, ui_symbols_rectangle, position, WHITE);
    }
}

#endif // UI_MAIN_MENU_H