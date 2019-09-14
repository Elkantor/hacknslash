/*************************************/
/*  Modules available for hot reload */
/*************************************/

// #define module_inputs        KEY_F2
// #define module_maths         KEY_F3
// #define module_physics       KEY_F1

const char* modules_hot_reload[] = {
    #if defined modules_inputs
        "module_inputs",
    #endif
    #if defined module_logging
        "module_logging",
    #endif
    #if defined module_math
        "module_math",
    #endif
    #if defined module_physics
        "module_physics",
    #endif
    #if defined module_resolution
        "module_resolution",
    #endif
};

/**********************************/
/*  Data available for hot reload */
/**********************************/

// #define data_colors          KEY_F5
// #define data_inputs
// #define data_logging
// #define data_player
// #define data_ui

const char* data_hot_reload[] = {
    #if defined data_colors
        "data_colors",
    #endif
    #if defined data_inputs
        "data_inputs",
    #endif
    #if defined data_logging
        "data_logging"
    #endif
    #if defined data_player
        "data_player"
    #endif
};