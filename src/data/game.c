#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <stdint.h>

#include "../data.c"
#include "modules/screen/screen.c"
#include "modules/math/math.c"
#include "modules/player/player.c"

/************************************* [DATA] *************************************************/
_Bool game_loaded = false;
float game_current_time = 0;
unsigned char game_character_animation_knight_run   = 0;
unsigned char game_character_animation_knight_idle  = 0;

#define game_character_animation_knight_idle_start_idx 0

/************************************* [PROCEDURES] *******************************************/
static inline void game_load(void)
{
    screen_data_textures_loaded_count = 0;
    /* 0 */ screen_texture_load("data/character/knight/idle_top.png");
    /* 1 */ screen_texture_load("data/character/knight/idle_top_right.png");
    /* 2 */ screen_texture_load("data/character/knight/idle_right.png");
    /* 3 */ screen_texture_load("data/character/knight/idle_bottom_right.png");
    /* 4 */ screen_texture_load("data/character/knight/idle_bottom.png");
    /* 5 */ screen_texture_load("data/character/knight/idle_bottom_left.png");
    /* 6 */ screen_texture_load("data/character/knight/idle_left.png");
    /* 7 */ screen_texture_load("data/character/knight/idle_top_left.png");
    
    screen_data_render_textures_loaded_count = 0;
    // screen_render_texture_load(ui_arrow_width, ui_arrow_height);

    game_loaded = true;
}

static inline void game_unload(void)
{
    screen_render_textures_unload();
    screen_textures_unload();
    game_loaded = false;
}

void game_draw(void)
{
    screen_data_textures_current_idx        = 0;
    screen_data_render_textures_current_idx = 0;


    { 
        int current_texture_id = screen_data_textures_ids[game_character_animation_knight_idle_start_idx + player_data_direction];
        Texture2D knight_texture = { current_texture_id, character_knight_idle_textures_widths[player_data_direction], character_knight_idle_textures_heights[player_data_direction], 1, 7 };

        Vector2 adjusted_position = character_adjust_positions[(character_knight_idle_start_idx + player_data_direction) * character_knight_idle_animations + game_character_animation_knight_idle];
        Vector2 position = {300 + adjusted_position.x + player_data_x, 300 + adjusted_position.y + player_data_y};
        
        Rectangle current_sprite = character_rectangles[(character_knight_idle_start_idx + player_data_direction) * character_knight_idle_animations + game_character_animation_knight_idle];
        DrawTextureRec(knight_texture, current_sprite, position, WHITE);
    }

    /* TMP TIMER FOR ANIMATIONS */
    game_current_time += GetFrameTime();
    if(game_current_time >= 0.04){
        game_character_animation_knight_run     += 1;
        game_character_animation_knight_idle    += 1;
        if(game_character_animation_knight_run > 23){
            game_character_animation_knight_run = 0;
        }
        if(game_character_animation_knight_idle > 76){
            game_character_animation_knight_idle = 0;
        }
        game_current_time = 0;
    }
}

#endif // GAME_H