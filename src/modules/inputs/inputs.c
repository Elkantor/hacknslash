#ifndef MODULE_INPUTS_H
#define MODULE_INPUTS_H

#include <stdint.h>
#include <raylib.h>
#include "data.c"

/************************************* [PROCEDURES] *******************************************/
static inline void inputs_action_bind(const int in_action, const int in_key){
    inputs_data_actions[in_action-1] = in_key;
}

static inline void inputs_mouse_handle(void)
{
    if(IsMouseButtonDown(0)){
        player_data_target_x = GetMouseX();
        player_data_target_y = GetMouseY();
    }
}

static inline uint16_t inputs_actions_get(){
    /*
        16 actions can be performed in the same frame (store in a uint16_t type)
        Each action is represented by a single bit (a flag)
        0 if not activated, 1 if activated
    */
    uint16_t actions_bitwise = 0;
    int number_keys_pressed = 0;
    _Bool mouse_movement = false;

    if(player_data_target_x > player_data_x + player_data_width/2){
        // need to go on the right
        actions_bitwise = (1 << inputs_data_action_right) | actions_bitwise;
        mouse_movement = true;
    } else if(player_data_target_x < player_data_x + player_data_width/2){
        // need to go on the left
        actions_bitwise = (1 << inputs_data_action_left) | actions_bitwise;
        mouse_movement = true;
    }
    if(player_data_target_y > player_data_y + player_data_height/2){
        // need to go down
        actions_bitwise = (1 << inputs_data_action_down) | actions_bitwise;
        mouse_movement = true;
    } else if(player_data_target_y < player_data_y + player_data_height/2){
        // need to go up
        actions_bitwise = (1 << inputs_data_action_up) | actions_bitwise;
        mouse_movement = true;
    }

    // get the action coresponding to each key pressed if it exists
    for(int i = 0; i < sizeof(inputs_data_actions)/sizeof(inputs_data_actions[0]); ++i){
        if(number_keys_pressed < 2){
            if(IsKeyDown(inputs_data_actions[i])){
                if(mouse_movement){
                    mouse_movement = false;
                    player_data_target_x = player_data_x + player_data_width/2;     // reset the target position x
                    player_data_target_y = player_data_y + player_data_height/2;    // reset the target position y
                    actions_bitwise = 0; // reset the actions
                }
                actions_bitwise = (1 << (i+1)) | actions_bitwise; // set the i bit (action flag) of the actions variable to 1
                number_keys_pressed += 1;
            }
        }else{
            break;
        }
    }    

    return actions_bitwise;
}


static inline int8_t inputs_actions_directions_calculate(const uint16_t in_current_actions)
{
    int8_t directions_bitwise = 0;

    if((in_current_actions >> inputs_data_action_up) & 1){          // action == up
        directions_bitwise = (1 << inputs_data_action_up) | directions_bitwise;
    }else if((in_current_actions >> inputs_data_action_down) & 1){  // action == down
        directions_bitwise = (1 << inputs_data_action_down) | directions_bitwise;
    }else if((in_current_actions >> inputs_data_action_right) & 1){ // action == right
        directions_bitwise = (1 << inputs_data_action_right) | directions_bitwise;
    }else if((in_current_actions >> inputs_data_action_left) & 1){  // action == left
        directions_bitwise = (1 << inputs_data_action_left) | directions_bitwise;
    }
    return directions_bitwise;
}

#endif // MODULE_INPUTS_H