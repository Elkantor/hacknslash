#if defined _WIN32 && defined module_export
    #define INPUTS __declspec(dllexport) // We are building logging as a win32 shared library (.dll)
#elif defined _WIN32 && defined module_import
    #define INPUTS __declspec(dllimport) // we are using logging as a win32 shared library (.dll)
#else
    #define INPUTS // We are building or using logging as a static library (or a shared one on linux)
#endif

void action_handle(
    const unsigned short in_keys_count,
    const int in_keys[],
    int out_actions[2],
    _Bool (*const in_is_key_down)(const int in_key)
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


const struct INPUTS inputs {
    void (*const action_handle)(
        const unsigned short in_keys_count,
        const int in_keys[],
        int out_actions[2],
        _Bool (*const in_is_key_down)(const int in_key)
    );
} inputs = {
    .action_handle = action_handle
};
