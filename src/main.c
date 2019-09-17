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

#include "modules/math.c"

#include "data/data_colors.c"
#include "data/data_ui_main_menu.c"

void custom_tracelog(const int in_msg_type, const char* in_text, const va_list in_args){
    logging_open(data_logging.file, data_logging.file_name);

    switch (in_msg_type){
        case LOG_INFO: logging.write(data_logging.file, "<u style='font-weight: bold;'>[INFO] : </u>"); break;
        case LOG_ERROR: logging.write(data_logging.file, "<u style='font-weight: bold'>[ERROR]: </u>"); break;
        case LOG_WARNING: logging.write(data_logging.file, "<u style='font-weight: bold'>[WARN] : </u>"); break;
        case LOG_DEBUG: logging.write(data_logging.file, "<u style='font-weight: bold'> [DEBUG]: </u>"); break;
        default: break;
    }
    logging.write(data_logging.file, in_text, in_args);
    logging.close(data_logging.file);
}

int main(int argc, char** argv){
    /* INITIALIZE LOGGING SYSTEM (ONLY FOR DEBUGGING)*/
    logging.flush(data_logging.file_name);
    logging.open(data_logging.file, data_logging.file_name);
    logging.write(data_logging.file, "<h1>[LOG]</h2>\n");
    logging.close(data_logging.file);
    

    /* INITIALIZE RAYLIB AND OPENGL CONTEXT */
    InitWindow(0, 0, "hacknslash");
    SetTraceLogLevel(LOG_NONE);
    SetTraceLogCallback(custom_tracelog);
    SetTargetFPS(60);
    
    Font test = LoadFontEx("./data/ui/Fonts/constantia_regular.ttf", 48, 0L, 95);
    // Color color_ui = GetColor(data_colors.light_gray_ui);

    /* LOAD THE TEXTURES FOR THE UI */
    {
        Texture2D background_tex = LoadTexture("data/ui/main_menu/background.jpg");
        *(data_ui_main_menu.ids + *data_ui_main_menu.current_loaded) = background_tex.id;
        *data_ui_main_menu.current_loaded += 1;
        logging.open(data_logging.file, data_logging.file_name);
        logging.write(data_logging.file, "<strong style='color: purple;' name='texture' id='texture_load_%d'>background_tex loaded : %d</strong>", background_tex.id, background_tex.id);
        logging.close(data_logging.file);
    }
    {
        Image left_arrow_img = LoadImage("data/ui/main_menu/character_selection/trim_textures/trim_arrow_left_select.png");
        Texture2D left_arrow_tex = LoadTextureFromImage(left_arrow_img);
        *(data_ui_main_menu.ids + *data_ui_main_menu.current_loaded) = left_arrow_tex.id;
        *data_ui_main_menu.current_loaded += 1;
        logging.open(data_logging.file, data_logging.file_name);
        logging.write(data_logging.file, "<strong style='color: purple;'>left_arrow_tex loaded : %d</strong>", left_arrow_tex.id);
        logging.close(data_logging.file);

        ImageFlipHorizontal(&left_arrow_img);
        Texture2D right_arrow_tex = LoadTextureFromImage(left_arrow_img);
        *(data_ui_main_menu.ids + *data_ui_main_menu.current_loaded) = right_arrow_tex.id;
        *data_ui_main_menu.current_loaded += 1;
        logging.open(data_logging.file, data_logging.file_name);
        logging.write(data_logging.file, "<strong style='color: purple;'>right_arrow_tex loaded : %d</strong>", right_arrow_tex.id);
        logging.close(data_logging.file);
        UnloadImage(left_arrow_img);
    }
    {
        Texture2D bottom_bar_tex = LoadTexture("data/ui/main_menu/bottom_bar.png");
        *(data_ui_main_menu.ids + *data_ui_main_menu.current_loaded) = bottom_bar_tex.id;
        *data_ui_main_menu.current_loaded += 1;
        logging.open(data_logging.file, data_logging.file_name);
        logging.write(data_logging.file, "<strong style='color: purple;'>bottom_bar_tex loaded : %d</strong>", bottom_bar_tex.id);
        logging.close(data_logging.file);
    }
    {
        Texture2D play_button_tex = LoadTexture("data/ui/main_menu/character_selection/trim_textures/trim_play_button.png");
        *(data_ui_main_menu.ids + *data_ui_main_menu.current_loaded) = play_button_tex.id;
        *data_ui_main_menu.current_loaded += 1;
        logging.open(data_logging.file, data_logging.file_name);
        logging.write(data_logging.file, "<strong style='color: purple;'>play_button_tex loaded : %d</strong>", play_button_tex.id);
        logging.close(data_logging.file);
    }
    {
        Image symbols_right_img = LoadImage("data/ui/main_menu/trim_textures/trim_symbols_right.png");
        Texture2D symbols_right_tex = LoadTextureFromImage(symbols_right_img);
        *(data_ui_main_menu.ids + *data_ui_main_menu.current_loaded) = symbols_right_tex.id;
        *data_ui_main_menu.symbols_idx_id = *data_ui_main_menu.current_loaded;
        *data_ui_main_menu.current_loaded += 1;
        logging.open(data_logging.file, data_logging.file_name);
        logging.write(data_logging.file, "<strong style='color: purple;'>symbols_right_tex loaded : %d</strong>", symbols_right_tex.id);
        logging.close(data_logging.file);

        RenderTexture2D ui_symbols_render_tex = LoadRenderTexture(ui_symbols_width, ui_symbols_height);
        *data_ui_main_menu.symbols_fbo_id = ui_symbols_render_tex.id;
        logging.open(data_logging.file, data_logging.file_name);
        logging.write(data_logging.file, "<strong style='color: purple;'>ui_symbols_render_tex loaded : %d</strong>", ui_symbols_render_tex.id);
        logging.close(data_logging.file);
        UnloadImage(symbols_right_img);
    }
    logging.open(data_logging.file, data_logging.file_name);
    logging.write(data_logging.file, "<h3 style='color: darkgrey;'>number textures loaded : %d</h3>", *data_ui_main_menu.current_loaded);
    logging.close(data_logging.file);
    Shader shader = LoadShader(0, "data/shaders/grayscale.fs");
    
    /* INITIALIZE DEFAULT KEYS BINDING */
    data_inputs.keys[data_inputs.key_up]    = KEY_Z;
    data_inputs.keys[data_inputs.key_down]  = KEY_S;
    data_inputs.keys[data_inputs.key_right] = KEY_D;
    data_inputs.keys[data_inputs.key_left]  = KEY_Q;
    data_inputs.keys[data_inputs.key_space] = KEY_SPACE;
    

    float current_time = 0;

    /* MAIN LOOP */
    while(!WindowShouldClose()){
        {
            Texture2D symbols_right = { *(data_ui_main_menu.ids + *data_ui_main_menu.symbols_idx_id), ui_symbols_width, ui_symbols_height, 1, 7 };
            BeginTextureMode((RenderTexture2D){ *data_ui_main_menu.symbols_fbo_id, symbols_right, {0,0,0,0,0}, 0});
                // Vector2 position = { 1920 - (symbols_right.width/2), 1080 - (symbols_right.height) };
                Vector2 position = {0, 0};
                DrawTextureRec(symbols_right, ui_symbols_rectangle, position, WHITE);
                DrawTextureRec(symbols_right, ui_symbols_rectangle_mask, position, WHITE);
            EndTextureMode();
        }
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
                Texture2D bottom_bar = { *(data_ui_main_menu.ids + *data_ui_main_menu.current_idx), ui_bottom_bar_width, ui_bottom_bar_height, 1, 7 };
                *data_ui_main_menu.current_idx += 1;
                DrawTexture(bottom_bar, 0, 1080 - bottom_bar.height, WHITE);
            }
            {
                Texture2D play_button = { *(data_ui_main_menu.ids + *data_ui_main_menu.current_idx), ui_play_button_width, ui_play_button_height, 1, 7 };
                *data_ui_main_menu.current_idx += 1;
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
                DrawTextEx(test, "PLAY", (Vector2){ position.x + (play_button.width/3)/2 - 2*(48/math.phi), position.y + 25}, 48, 1, WHITE);
            }
            
            {
                Texture2D symbols_right = { *(data_ui_main_menu.ids + *data_ui_main_menu.symbols_idx_id), ui_symbols_width, ui_symbols_height, 1, 7 };
                RenderTexture2D symbols_render_tex = (RenderTexture2D){ *data_ui_main_menu.symbols_fbo_id, symbols_right, {0,0,0,0,0}, 0};
                // Texture2D symbols_right = { *(data_ui_main_menu.ids + *data_ui_main_menu.current_idx), ui_symbols_width, ui_symbols_height, 1, 7 };
                *data_ui_main_menu.current_idx += 1;
                Vector2 position = { 1920 - (symbols_right.width/2), 1080 - (symbols_right.height) };
                // BeginShaderMode(shader);
                DrawTextureRec(symbols_render_tex.texture, ui_symbols_rectangle, position, WHITE);
                    // DrawTextureRec(symbols_right, ui_symbols_rectangle_mask, position, WHITE);
                // EndShaderMode();
            }
            
            DrawFPS(1800, 40);
        EndDrawing();

        /* TMP TIMER FOR ANIMATIONS */
        // current_time += GetFrameTime();
        // logging.write(data_logging.file, "green", "<em style='font-weight: bold'>current_time: %f]</em>", current_time);
        // if(current_time >= 0.16){
        //     *data_ui_main_menu.current_symbols_anim += 1;
        //     if(*data_ui_main_menu.current_symbols_anim > 15){
        //         *data_ui_main_menu.current_symbols_anim = 0;
        //     }
        //     current_time = 0;
        // }
    }

    {
        RenderTexture2D symbols_render_tex = (RenderTexture2D){ *data_ui_main_menu.symbols_fbo_id, {0,0,0,0,0}, {0,0,0,0,0}, 0};
        logging.open(data_logging.file, data_logging.file_name);
        logging.write(data_logging.file, "<strong style='color: purple;'>unload render texture : %d</strong>", symbols_render_tex.id);
        logging.close(data_logging.file);
        UnloadRenderTexture(symbols_render_tex);
    }

    // {
    //     Texture2D symbols_right = (Texture2D){ *(data_ui_main_menu.ids + *data_ui_main_menu.current_loaded - 1), 0, 0, 1, 7 };
    //     logging.open(data_logging.file, data_logging.file_name);
    //     logging.write(data_logging.file, "purple", "<strong>unload texture : %d</strong>", symbols_right.id);
    //     logging.close(data_logging.file);
    //     UnloadTexture(symbols_right);
    //     *data_ui_main_menu.current_loaded -= 1;
    // }

    {
        /* UNLOAD EVERY UI_MAIN_MENU TEXTURES */
        for(unsigned short i = *data_ui_main_menu.current_loaded; i > 0; --i){
            Texture2D texture = (Texture2D){ *(data_ui_main_menu.ids + i - 1), 0, 0, 1, 7 };
            logging.open(data_logging.file, data_logging.file_name);
            logging.write(data_logging.file, "<strong style='color: purple;' name='texture_%d'>unload texture : %d</strong>", i-1, texture.id);
            logging.close(data_logging.file);
            UnloadTexture(texture);
        }
    }
    UnloadFont(test);
    CloseWindow();

    logging.open(data_logging.file, data_logging.file_name);
    logging.write(data_logging.file, "<script>\n\
        for(let i = 0; i < document.getElementsByName('texture').length; ++i){\n\
            console.log('elem: ' + i);\n\
            let texture_elem = document.getElementsByName('texture')[i];\n\
            let associated_elems = document.getElementsByName('texture_'+i);\n\
            let previous_color = texture_elem.style.color;\n\
            texture_elem.addEventListener('mouseover', function(){\n\
                console.log('overed!!!');\n\
                for(let i = 0; i < associated_elems.length; ++i){\n\
                    associated_elems[0].style.color = 'red';\n\
                }\n\
            });\n\
            texture_elem.addEventListener('mouseout', function(){\n\
                for(let i = 0; i < associated_elems.length; ++i){\n\
                    associated_elems[0].style.color = previous_color;\n\
                }\n\
            });\n\
        }</script>\n");
    logging.close(data_logging.file);
    return 0;
}