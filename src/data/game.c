#ifndef GAME_H
#define GAME_H

#include <raylib.h>

#include "../data.c"
#include "modules/screen/screen.c"
#include "modules/math/math.c"

/************************************* [DATA] *************************************************/
_Bool game_loaded = false;
float game_current_time = 0;
unsigned char game_character_animation_knight_run   = 0;
unsigned char game_character_animation_idle         = 0;


/************************************* [PROCEDURES] *******************************************/
static inline void game_load(void){
    screen_data_textures_loaded_count = 0;
    /* 1 */ screen_texture_load("data/character/knight/run_left.png");
    /* 2 */ screen_texture_load("data/character/knight/idle_left.png");
    /* 3 */ screen_texture_load("data/character/knight/idle_right.png");
    
    screen_data_render_textures_loaded_count = 0;
    // screen_render_texture_load(ui_arrow_width, ui_arrow_height);

    game_loaded = true;
}

static inline void game_unload(void){
    screen_render_textures_unload();
    screen_textures_unload();
    game_loaded = false;
}

void game_draw(void){
    screen_data_textures_current_idx = 0;
    screen_data_render_textures_current_idx = 0;

    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D knight_run_left = { current_texture_id, character_knight_run_left_width, character_knight_run_left_height, 1, 7 };
        screen_data_textures_current_idx += 1;

        Vector2 adjusted_position = character_knight_run_left_adjust_positions[game_character_animation_knight_run];
        Vector2 position = {300 + adjusted_position.x, 300 + adjusted_position.y};
        DrawTextureRec(knight_run_left, character_knight_run_left_rectangles[game_character_animation_knight_run], position, WHITE);
    }
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D knight_idle_left = { current_texture_id, character_knight_idle_left_width, character_knight_idle_left_height, 1, 7 };
        screen_data_textures_current_idx += 1;

        Vector2 adjusted_position = character_knight_idle_left_adjust_positions[game_character_animation_idle];
        Vector2 position = {600 + adjusted_position.x, 300 + adjusted_position.y};
        DrawTextureRec(knight_idle_left, character_knight_idle_left_rectangles[game_character_animation_idle], position, WHITE);
    }
    {
        int current_texture_id = screen_data_textures_ids[screen_data_textures_current_idx];
        Texture2D knight_idle_right = { current_texture_id, character_knight_idle_right_width, character_knight_idle_right_height, 1, 7 };
        screen_data_textures_current_idx += 1;

        Vector2 adjusted_position = character_knight_idle_right_adjust_positions[game_character_animation_idle];
        Vector2 position = {900 + adjusted_position.x, 300 + adjusted_position.y};
        DrawTextureRec(knight_idle_right, character_knight_idle_right_rectangles[game_character_animation_idle], position, WHITE);
    }

    /* TMP TIMER FOR ANIMATIONS */
    game_current_time += GetFrameTime();
    if(game_current_time >= 0.04){
        game_character_animation_knight_run += 1;
        game_character_animation_idle       += 1;
        if(game_character_animation_knight_run > 23){
            game_character_animation_knight_run = 0;
        }
        if(game_character_animation_idle > 76){
            game_character_animation_idle = 0;
        }
        game_current_time = 0;
    }
}

#endif // GAME_H