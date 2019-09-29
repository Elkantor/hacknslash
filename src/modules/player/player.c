#ifndef MODULE_PLAYER_H
#define MODULE_PLAYER_H

#include <stdint.h>

/************************************* [DATA] *************************************************/
#define player_data_width 150
#define player_data_height 150

/* 
    There are 8 directions, stored clock-wise.
    0 is top, 1 is top-right, 2 is right... 7 is top-left
*/
uint8_t player_data_direction            = 4; // set the direction to bottom by default
uint8_t player_data_previous_direction   = 0;

float player_data_x = 150;
float player_data_y = 150;
unsigned short player_data_idx_color = 0;

/************************************* [PROCEDURES] *******************************************/

static inline void player_movements_handle(const int8_t in_directions_bitwise)
{
    if((in_directions_bitwise >> 1) & 1){           // direction == up
        player_data_y += 1;
    }else if((in_directions_bitwise >> 2) & 1){     // direction == down
        player_data_y -= 1;
    }else if((in_directions_bitwise >> 3) & 1){     // direction == right
        player_data_x -= 1;
    }else if((in_directions_bitwise >> 4) & 1){     // direction == left
        player_data_x += 1;
    }

    int8_t tmp_direction = -1;
    logging_open();
    switch(in_directions_bitwise){
        case 1:
            tmp_direction = 0; // top
            break;
        case 2:
            tmp_direction = 4; // bottom
            break;
        case 4:
            tmp_direction = 2; // right
            break;
        case 5:
            tmp_direction = 1; // top-right
            break;
        case 6:
            tmp_direction = 3; // bottom-right
            break;
        case 8:
            tmp_direction = 6; // left
            break;
        case 9:
            tmp_direction = 7; // top-left
            break;
        case 10:
            tmp_direction = 5; // bottom-left
    }
    if(tmp_direction != -1){
        player_data_direction = tmp_direction;
        player_data_previous_direction = player_data_direction;
    }
}

#endif // MODULE_PLAYER_H