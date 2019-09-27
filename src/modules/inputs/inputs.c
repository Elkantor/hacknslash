#ifndef MODULE_INPUTS_H
#define MODULE_INPUTS_H

/************************************* [DATA] *************************************************/
int inputs_data_actions[5];
int inputs_data_current_actions[2];

#define inputs_data_action_up    0
#define inputs_data_action_down  1
#define inputs_data_action_right 2
#define inputs_data_action_left  3
#define inputs_data_action_space 4

/************************************* [PROCEDURES] *******************************************/
static inline void inputs_action_bind(const int in_action, const int in_key){
    inputs_data_actions[in_action] = in_key;
}

static inline int inputs_actions_get_current(){
    inputs_data_current_actions[0] = -1;
    inputs_data_current_actions[1] = -1;

    int number_keys_pressed = 0;

    // get the action coresponding to each key pressed if it exists
    for(int i = 0; i < sizeof(inputs_data_actions)/sizeof(inputs_data_actions[0]); ++i){
        // const int current_key = in_keys[i];
        if(number_keys_pressed < 2){
            inputs_data_current_actions[number_keys_pressed] = i;
            number_keys_pressed++;
        }
    }
    return number_keys_pressed;
}

#endif // MODULE_INPUTS_H