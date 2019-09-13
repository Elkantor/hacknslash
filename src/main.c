#include <stdio.h>
#include <raylib.h>

#include "config.c"
#include "config/windows.c"

#include "data/inputs.c"
#include "data/player.c"

#include "modules/logging.c"
#include "modules/inputs.c"
#include "modules/math.c"

int main(int argc, char** argv){
    fclose(fopen("log.txt", "w")); // flush the content from the log file
    FILE* log_file = NULL;
    logging.open(log_file, "log.txt");
    fprintf(log_file, "- Screens: %d\n", GetMonitorCount());

    InitWindow(0, 0, "hacknslash");
    SetTargetFPS(60);
    
    data_inputs.keys[data_inputs_key_up] = KEY_W;
    
    while(!WindowShouldClose()){


        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            DrawFPS(80, 80);

            // draw the grid
            // draw the X lines
            for(int i = 0; i < 1920; i+= 1920/64){
                DrawLine(0, i, 1920, i, GREEN);
            }
            // Draw the Y lines
            for(int i = 0; i < 1980; i+= 1920/64){
                DrawLine(i, 0, i, 1280, GREEN);
            }
        EndDrawing();
    }


    CloseWindow();
    fclose(log_file);
}