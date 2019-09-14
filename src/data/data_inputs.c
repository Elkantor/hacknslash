#if defined _WIN32 && defined data_colors_build_dll
    #define DATA_INPUTS __declspec(dllexport) // We are building data_colors as a win32 shared library (.dll)
#elif defined _WIN32 && defined data_colors 
    #define DATA_INPUTS __declspec(dllimport) // we are using data_colors as a win32 shared library (.dll)
#else
    #define DATA_INPUTS // We are building or using data_colors as a static library (or a shared one on linux)
#endif

#define count 5

int data_inputs_keys[count];

#if !defined data_inputs
    const
#endif
    struct DATA_INPUTS data_inputs {
        int *keys;
        unsigned short keys_count;
        const unsigned short key_up;
        const unsigned short key_down;
        const unsigned short key_right;
        const unsigned short key_left;
        const unsigned short key_space;
    } 
#if defined data_inputs
    ;
#else
    data_inputs = {
        .keys       = data_inputs_keys,
        .keys_count = count,
        .key_up     = 0,
        .key_down   = 1,
        .key_right  = 2,
        .key_left   = 3,
        .key_space  = 4,
    };
#endif

#undef count