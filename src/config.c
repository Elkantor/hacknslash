// modules available for hot reload

#define module_physics      KEY_F1
// #define module_inputs
// #define module_inputs_key

// #define module_maths
// #define module_maths_key

const char* modules_hot_reload[] = {
    #if defined module_physics
        "module_physics",
    #endif
    #if defined modules_inputs
        "module_inputs",
    #endif
};

// data available for hot reload
// #define data_colors