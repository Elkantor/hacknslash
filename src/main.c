#include <raylib.h>
#include <stdio.h>
#include <string.h>

#include "config.c"
#include "config/windows.c"

#include "data.c"

#include "modules/inputs.c"
#include "data/data_inputs.c"

#include "modules/logging.c"
#include "data/data_logging.c"

#include "data/data_colors.c"
#include "data/data_ui_main_menu.c"

void custom_tracelog(const int in_msg_type, const char* in_text, const va_list in_args){
    logging_open(data_logging.file, data_logging.file_name);

    switch (in_msg_type){
        case LOG_INFO: logging.write(data_logging.file, "#21610B", "<u style='font-weight: bold'>[INFO] : </u>"); break;
        case LOG_ERROR: logging.write(data_logging.file, "#21610B", "<u style='font-weight: bold'>[ERROR]: </u>"); break;
        case LOG_WARNING: logging.write(data_logging.file, "#21610B", "<u style='font-weight: bold'>[WARN] : </u>"); break;
        case LOG_DEBUG: logging.write(data_logging.file, "#21610B", "<u style='font-weight: bold'> [DEBUG]: </u>"); break;
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
    
    Font test = LoadFontEx("./data/ui/Fonts/constantia_regular.ttf", 48, 0L, 95);
    // Color color_ui = GetColor(data_colors.light_gray_ui);

    /* LOAD THE TEXTURES FOR THE UI */
    {
        Texture2D left_arrow_tex = LoadTexture("data/ui/main_menu/background.jpg");
        *(data_ui_main_menu.ids + *data_ui_main_menu.current_loaded) = left_arrow_tex.id;
        *data_ui_main_menu.current_loaded += 1;
    }
    {
        Image left_arrow_img = LoadImage("data/ui/main_menu/character_selection/trim_textures/trim_arrow_left_select.png");
        Texture2D left_arrow_tex = LoadTextureFromImage(left_arrow_img);
        *(data_ui_main_menu.ids + *data_ui_main_menu.current_loaded) = left_arrow_tex.id;
        *data_ui_main_menu.current_loaded += 1;

        ImageFlipHorizontal(&left_arrow_img);
        Texture2D right_arrow_tex = LoadTextureFromImage(left_arrow_img);
        *(data_ui_main_menu.ids + *data_ui_main_menu.current_loaded) = right_arrow_tex.id;
        *data_ui_main_menu.current_loaded += 1;
    }
    {
        Texture2D play_button_tex = LoadTexture("data/ui/main_menu/character_selection/trim_textures/trim_play_button.png");
        *(data_ui_main_menu.ids + *data_ui_main_menu.current_loaded) = play_button_tex.id;
        *data_ui_main_menu.current_loaded += 1;
    }
    
    /* INITIALIZE DEFAULT KEYS BINDING */
    data_inputs.keys[data_inputs.key_up]    = KEY_Z;
    data_inputs.keys[data_inputs.key_down]  = KEY_S;
    data_inputs.keys[data_inputs.key_right] = KEY_D;
    data_inputs.keys[data_inputs.key_left]  = KEY_Q;
    data_inputs.keys[data_inputs.key_space] = KEY_SPACE;
    
    /* MAIN LOOP */
    while(!WindowShouldClose()){
        BeginDrawing();
            *data_ui_main_menu.current_idx = 0;
            ClearBackground(WHITE);

            /* DRAW A GRID */
            // for(int i = 0; i < 1920; i+= 1920/64){ // x lines
            //     DrawLine(0, i, 1920, i, GREEN);
            // }
            // for(int i = 0; i < 1980; i+= 1920/64){ // y lines
            //     DrawLine(i, 0, i, 1280, GREEN);
            // }
            {
                Texture2D background = { *(data_ui_main_menu.ids + *data_ui_main_menu.current_idx), ui_background_width, ui_background_height, 1, 7 };
                *data_ui_main_menu.current_idx += 1;
                DrawTexture(background, 0, 0, WHITE);
            }
            {
                Texture2D left_arrow = { *(data_ui_main_menu.ids + *data_ui_main_menu.current_idx), ui_arrow_width, ui_arrow_height, 1, 7 };
                *data_ui_main_menu.current_idx += 1;
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
                Texture2D right_arrow = { *(data_ui_main_menu.ids + *data_ui_main_menu.current_idx), ui_arrow_width, ui_arrow_height, 1, 7 };
                *data_ui_main_menu.current_idx += 1;
                Vector2 position = { (1920/40)*39 - right_arrow.width, 500 };
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
                Texture2D play_button = { *(data_ui_main_menu.ids + *data_ui_main_menu.current_idx), ui_play_button_width, ui_play_button_height, 1, 7 };
                *data_ui_main_menu.current_idx += 1;
                Vector2 position = { ((1920)/2) - ((ui_play_button_width/3)/2), (1080/40)*38 - play_button.height };
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
                DrawTextEx(test, "PLAY", (Vector2){ position.x + (play_button.width/3)/2 - 2*(48/1.6180339887), position.y + 25}, 48, 1, WHITE);
            }
            DrawFPS(1800, 40);
        EndDrawing();
    }

    /* UNLOAD EVERY UI_MAIN_MENU TEXTURES */
    for(unsigned short i = 0; i > *data_ui_main_menu.current_loaded; i--){
        Texture2D texture = (Texture2D){ *(data_ui_main_menu.ids + i), 0, 0, 1, 7 };
        UnloadTexture(texture);
    }
    UnloadFont(test);
    CloseWindow();
    return 0;
}