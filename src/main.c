#include <raylib.h>
#include <string.h>
#include <stdint.h>

#include "data.c"

#include "modules/logging/logging.c"
#include "modules/inputs/inputs.c"
#include "modules/player/player.c"
#include "modules/math/math.c"
#include "modules/colors/colors.c"
#include "modules/screen/screen.c"
#include "data/game.c"
#include "data/ui_main_menu.c"

void custom_tracelog(const int in_msg_type, const char* in_text, const va_list in_args)
{
    logging_open();
    
    switch (in_msg_type){
        case LOG_INFO: logging_write("<u style='font-weight: bold;'>[INFO] : </u>"); break;
        case LOG_ERROR: logging_write("<u style='font-weight: bold'>[ERROR]: </u>"); break;
        case LOG_WARNING: logging_write("<u style='font-weight: bold'>[WARN] : </u>"); break;
        case LOG_DEBUG: logging_write("<u style='font-weight: bold'> [DEBUG]: </u>"); break;
        default: break;
    }
    logging_write(in_text, in_args);
    logging_close();
}

int main(int argc, char** argv)
{
    /* INITIALIZE LOGGING SYSTEM (ONLY FOR DEBUGGING)*/
    logging_flush();
    logging_open();
    logging_write("<h1>[LOG]</h2>\n");
    logging_close();
    
    
    inputs_action_bind(inputs_data_action_up, 87);          // Z in azerty
    inputs_action_bind(inputs_data_action_down, 83);        // S in azerty
    inputs_action_bind(inputs_data_action_right, 68);       // D in azerty  
    inputs_action_bind(inputs_data_action_left, 65);        // Q in azerty
    inputs_action_bind(inputs_data_action_space, KEY_SPACE);

    InitWindow(0, 0, "hacknslash");
    SetTraceLogLevel(LOG_NONE);
    SetTraceLogCallback(custom_tracelog);
    SetTargetFPS(200);
    
    screen_data_font = LoadFontEx("./data/ui/Fonts/constantia_regular.ttf", 48, 0L, 95);
    ui_main_menu_load();

    /* MAIN LOOP */
    while(!WindowShouldClose()){
        if(screen == screen_data_game){
            uint16_t actions_bitwise = inputs_actions_get();
            player_movements_handle(actions_bitwise);
        }

        BeginDrawing();
            ClearBackground(WHITE);
            switch(screen){
                case screen_data_main_menu:  
                    if(ui_main_menu_loaded) ui_main_menu_draw();
                    else ui_main_menu_load();
                    break;
                case screen_data_game: 
                    if(game_loaded) game_draw();
                    else game_load();
                    break;
                default: break;
            }
            DrawFPS(1800, 40);
        EndDrawing();
    }

    /* UNLOAD THE SCREEN RESSOURCES */
    screen_render_textures_unload();
    screen_textures_unload();

    UnloadFont(screen_data_font);
    CloseWindow();
    return 0;
}