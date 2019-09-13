#if !defined RAYLIB_H
    typedef enum { false, true }
#endif

void action_handle(
    const unsigned short in_keys_count,
    const int in_keys[],
    int out_actions[2],
    bool (*const in_is_key_down)(const int in_key)
){
    out_actions[0] = -1;
    out_actions[1] = -1;

    int number_keys_pressed = 0;

    // get the action coresponding to each key pressed if it exists
    for(int i = 0; i < in_keys_count; ++i){
        // const int current_key = in_keys[i];
        if(number_keys_pressed < 2){
            out_actions[number_keys_pressed] = i;
            number_keys_pressed++;
        }
    }
}


#if !defined module_inputs
    const
#endif
    struct inputs {
        void (*const action_handle)(
            const unsigned short in_keys_count,
            const int in_keys[],
            int out_actions[2],
            bool (*const in_is_key_down)(const int in_key)
        );
    }
#if defined module_inputs
    ;
#else
    inputs = {
        .action_handle = action_handle
    };
#endif