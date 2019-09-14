#include <raylib.h>
#include <stdio.h>

#include "config.c"
#include "config/windows.c"

#include "modules/inputs.c"
#include "data/data_inputs.c"

#include "modules/logging.c"
#include "data/data_logging.c"

#include "data/data_colors.c"
#include "data/data_ui.c"

void custom_tracelog(const int in_msg_type, const char* in_text, const va_list in_args){
    logging_open(data_logging.file, data_logging.file_name);

    switch (in_msg_type){
        case LOG_INFO: logging.write(data_logging.file, "#21610B", "<u style='font-weight: bold'>[RAYLIB INFO] : </u>"); break;
        case LOG_ERROR: logging.write(data_logging.file, "#21610B", "<u style='font-weight: bold'>[RAYLIB ERROR]: </u>"); break;
        case LOG_WARNING: logging.write(data_logging.file, "#21610B", "<u style='font-weight: bold'>[RAYLIB WARN] : </u>"); break;
        case LOG_DEBUG: logging.write(data_logging.file, "#21610B", "<u style='font-weight: bold'> [RAYLIB DEBUG]: </u>"); break;
        default: break;
    }
    logging.write(data_logging.file, "darkgrey", in_text, in_args);
    logging.close(data_logging.file);
}


int main(int argc, char** argv){
    /* INITIALIZE LOGGING SYSTEM */
    logging.flush(data_logging.file_name);
    logging.open(data_logging.file, data_logging.file_name);
    logging.write(data_logging.file, "red", "<h1>[LOG]</h2>");
    logging.close(data_logging.file);
    

    /* INITIALIZE RAYLIB AND OPENGL CONTEXT */
    InitWindow(0, 0, "hacknslash");
    SetTraceLogLevel(LOG_INFO);
    SetTraceLogCallback(custom_tracelog);
    SetTargetFPS(60);
    
    Font test = LoadFontEx("./data/ui/Fonts/palatino_linotype_regular.ttf", 32, 0L, 95);
    Color color_ui = GetColor(data_colors.light_gray_ui);
    
    /* INITIALIZE DEFAULT KEYS BINDING */
    data_inputs.keys[data_inputs.key_up]    = KEY_Z;
    data_inputs.keys[data_inputs.key_down]  = KEY_S;
    data_inputs.keys[data_inputs.key_right] = KEY_D;
    data_inputs.keys[data_inputs.key_left]  = KEY_Q;
    data_inputs.keys[data_inputs.key_space] = KEY_SPACE;
    
    /* MAIN LOOP */
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            DrawFPS(80, 80);

            /* DRAW A GRID */
            for(int i = 0; i < 1920; i+= 1920/64){ // x lines
                DrawLine(0, i, 1920, i, GREEN);
            }
            for(int i = 0; i < 1980; i+= 1920/64){ // y lines
                DrawLine(i, 0, i, 1280, GREEN);
            }
            DrawTextEx(test, "ceci est un test", (Vector2){800, 120}, 32, 10, (Color){10, 187, 172});

        EndDrawing();
    }

    UnloadFont(test);

    CloseWindow();
    return 0;
}