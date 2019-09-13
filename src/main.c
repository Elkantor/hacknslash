#include <stdio.h>
#include <raylib.h>

#include "config.c"
#include "config/windows.c"

#include "data/inputs.c"

#include "modules/inputs.c"
#include "modules/math.c"

int main(int argc, char** argv){
    InitWindow(1920, 1080, "hacknslash");
    SetTargetFPS(60);
    
    data_inputs.keys[data_inputs_key_up] = KEY_W;
    
    while(!WindowShouldClose()){


        BeginDrawing();
            ClearBackground(LIGHTGRAY);
            DrawFPS(1800, 40);

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
}