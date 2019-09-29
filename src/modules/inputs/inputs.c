#ifndef MODULE_INPUTS_H
#define MODULE_INPUTS_H

#include <stdint.h>
#include <raylib.h>

/************************************* [DATA] *************************************************/
int inputs_data_actions[5];

#define inputs_data_action_up    1
#define inputs_data_action_down  2
#define inputs_data_action_right 3
#define inputs_data_action_left  4
#define inputs_data_action_space 5

/************************************* [PROCEDURES] *******************************************/
static inline void inputs_action_bind(const int in_action, const int in_key){
    inputs_data_actions[in_action-1] = in_key;
}

static inline uint16_t inputs_actions_get(){
    /*
        16 actions can be performed in the same frame (so uint16_t type)
        Each action is represented by a single bit (a flag)
        0 if not activated, 1 if activated
    */
    uint16_t actions_bitwise = 0;
    int number_keys_pressed = 0;

    // get the action coresponding to each key pressed if it exists
    for(int i = 0; i < sizeof(inputs_data_actions)/sizeof(inputs_data_actions[0]); ++i){
        if(number_keys_pressed < 2){
            if(IsKeyDown(inputs_data_actions[i])){
                actions_bitwise = (1 << i) | actions_bitwise; // set the i bit (action flag) of the actions variable to 1
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