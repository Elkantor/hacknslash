#include <raylib.h>
#include <stdio.h>
#include <string.h>

#include "data.c"

#include "modules/inputs/inputs.c"
#include "modules/logging/logging.c"
#include "modules/math/math.c"
#include "modules/colors/colors.c"
#include "modules/screen/screen.c"
#include "data/game.c"
#include "data/ui_main_menu.c"

void custom_tracelog(const int in_msg_type, const char* in_text, const va_list in_args){
    logging_open(logging_data_file_name);
    
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

int main(int argc, char** argv){
    /* INITIALIZE LOGGING SYSTEM (ONLY FOR DEBUGGING)*/
    logging_flush(logging_data_file_name);
    logging_open(logging_data_file_name);
    logging_write("<h1>[LOG]</h2>\n");
    logging_close();

    /* INITIALIZE RAYLIB AND OPENGL CONTEXT */
    InitWindow(0, 0, "hacknslash");
    SetTraceLogLevel(LOG_NONE);
    SetTraceLogCallback(custom_tracelog);
    SetTargetFPS(60);
    
    screen_data_font = LoadFontEx("./data/ui/Fonts/constantia_regular.ttf", 48, 0L, 95);
    // Color color_ui = GetColor(data_colors.light_gray_ui);
    ui_main_menu_load();

    Shader shader = LoadShader(0, "data/shaders/grayscale.fs");
    
    /* INITIALIZE DEFAULT KEYS BINDING */
    inputs_data_keys[inputs_data_key_up]    = KEY_Z;
    inputs_data_keys[inputs_data_key_down]  = KEY_S;
    inputs_data_keys[inputs_data_key_right] = KEY_D;
    inputs_data_keys[inputs_data_key_left]  = KEY_Q;
    inputs_data_keys[inputs_data_key_space] = KEY_SPACE;

    /* MAIN LOOP */
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(WHITE);
            switch(screen){
                case SCREEN_MAIN_MENU: 
                    if(ui_main_menu_loaded) ui_main_menu_draw();
                    else ui_main_menu_load();
                    break;
                case SCREEN_GAME: 
                    if(game_loaded) game_draw();
                    else game_load();
                    break;
                default: break;
            }
            DrawFPS(1800, 40);
        EndDrawing();
    }

    screen_render_textures_unload();
    screen_textures_unload();
    UnloadFont(screen_data_font);
    CloseWindow();
    return 0;
}