#ifndef GAME_H
#define GAME_H

#if !defined RAYLIB_H
    #include <raylib.h>
#endif

#include "../data.c"
#include "../modules/screen/screen.c"
#include "../modules/math/math.c"

/************************************* [DATA] *************************************************/
_Bool game_loaded = false;
float game_current_time = 0;
unsigned char game_character_animation = 0;


/************************************* [PROCEDURES] *******************************************/
static inline void game_load(void){
    screen_data_textures_loaded_count = 0;
    /* 1 */ screen_texture_load("data/character/knight/run_left.png");
    
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

        Vector2 adjusted_position = character_knight_run_left_adjust_position[game_character_animation];
        Vector2 position = {300 + adjusted_position.x, 300 + adjusted_position.y};
        DrawTextureRec(knight_run_left, character_knight_run_left_rectangles[game_character_animation], position, WHITE);
    }
    /* TMP TIMER FOR ANIMATIONS */
    game_current_time += GetFrameTime();
    if(game_current_time >= 0.04){
        game_character_animation += 1;
        if(game_character_animation > 23){
            game_character_animation = 0;
        }
        game_current_time = 0;
    }
}

#endif // GAME_H