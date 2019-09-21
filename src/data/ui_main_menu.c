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
    screen_texture_load("data/ui/main_menu/background.jpg");
    screen_texture_load("data/ui/main_menu/character_selection/trim_textures/trim_arrow_left_select.png");
    screen_texture_load("data/ui/main_menu/bottom_bar.png");
    screen_texture_load("data/ui/main_menu/character_selection/trim_textures/trim_play_button.png");
    screen_texture_load("data/ui/main_menu/trim_textures/trim_symbols_right.png");

    screen_render_texture_load(ui_arrow_width, ui_arrow_height);

    ui_main_menu_loaded = true;
}

static inline void ui_main_menu_unload(void){
    screen_render_textures_unload();
    screen_textures_unload();
    ui_main_menu_loaded = false;
}

void ui_main_menu_draw(void){
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D background = { current_texture_id, ui_background_width, ui_background_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        DrawTexture(background, 0, 0, WHITE);
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

        Vector2 position_right_arrow = { (1920/40)*38, 500 };
        Rectangle dest = (Rectangle){position_right_arrow.x, position_right_arrow.y - ((left_arrow.height/3) *2), ui_arrow_rectangle.width, ui_arrow_rectangle.height};
        DrawTexturePro(left_arrow, ui_arrow_rectangle, dest, (Vector2){left_arrow.width, left_arrow.height}, 180, WHITE);
        Rectangle right_arrow_rec = { position_right_arrow.x, position_right_arrow.y, left_arrow.width, left_arrow.height/3 };
        if(CheckCollisionPointRec(GetMousePosition(), right_arrow_rec)){
            if(IsMouseButtonDown(0)){
                DrawTexturePro(left_arrow, ui_arrow_rectangle_pressed, dest, (Vector2){left_arrow.width, left_arrow.height}, 180, WHITE);
            }else{
                DrawTexturePro(left_arrow, ui_arrow_rectangle_hovered, dest, (Vector2){left_arrow.width, left_arrow.height}, 180, WHITE);
            }
        }
    }
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D bottom_bar = { current_texture_id, ui_bottom_bar_width, ui_bottom_bar_height, 1, 7 };
        screen_data_textures_current_idx += 1;
        DrawTexture(bottom_bar, 0, 1080 - bottom_bar.height, WHITE);
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
        Vector2 position = { 1920 - (symbols_right.width/2), 1080 - (symbols_right.height) };
        DrawTextureRec(symbols_right, ui_symbols_rectangle, position, WHITE);
    }
}

#endif // UI_MAIN_MENU_H