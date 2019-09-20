/************************************* [DATA] *************************************************/
int inputs_data_keys[5];

const unsigned short inputs_data_key_up = 0;
const unsigned short inputs_data_key_down = 1;
const unsigned short inputs_data_key_right = 2;
const unsigned short inputs_data_key_left = 3;
const unsigned short inputs_data_key_space = 4;

/************************************* [PROCEDURES] *******************************************/
void inputs_action_handle(int out_actions[2]){
    out_actions[0] = -1;
    out_actions[1] = -1;

    int number_keys_pressed = 0;

    // get the action coresponding to each key pressed if it exists
    for(int i = 0; i < sizeof(inputs_data_keys)/sizeof(inputs_data_keys[0]); ++i){
        // const int current_key = in_keys[i];
        if(number_keys_pressed < 2){
            out_actions[number_keys_pressed] = i;
            number_keys_pressed++;
        }
    }
}
