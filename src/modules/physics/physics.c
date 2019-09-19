#if defined _WIN32 && defined module_export
    #define PHYSICS __declspec(dllexport) // We are building logging as a win32 shared library (.dll)
#elif defined _WIN32 && defined module_import
    #define PHYSICS __declspec(dllimport) // we are using logging as a win32 shared library (.dll)
#else
    #define PHYSICS // We are building or using logging as a static library (or a shared one on linux)
#endif

/*
    Collision method: simple AABB
    Check for every static rectangles passed in parameter if a dynamic rectangle,
    from the dynamic rectangles tables, collides with it.
    Change the color idx of the static rectangle if it collides.
*/
void rectangles_collisions_calculate(
    const int in_size_static_rectangles,
    const float in_static_rectangles_x[static in_size_static_rectangles],
    const float in_static_rectangles_y[static in_size_static_rectangles],
    const unsigned short in_static_rectangles_width[static in_size_static_rectangles],
    const unsigned short in_static_rectangles_height[static in_size_static_rectangles],
    const int in_size_dynamic_rectangles,
    const float in_dynamic_rectangles_x[static in_size_dynamic_rectangles],
    const float in_dynamic_rectangles_y[static in_size_dynamic_rectangles],
    const unsigned short in_dynamic_rectangles_width[static in_size_dynamic_rectangles],
    const unsigned short in_dynamic_rectangles_height[static in_size_dynamic_rectangles],
    unsigned short out_static_rectangles_colors_idx[static in_size_static_rectangles],
    const unsigned short in_idx_new_color
){
    // for each static rectangles
    for(int i = 0; i < in_size_static_rectangles; ++i){
        // for each dynamic rectangles
        for(int j = 0; j < in_size_dynamic_rectangles; ++j){
            float dynamic_x = in_dynamic_rectangles_x[j];
            float dynamic_y = in_dynamic_rectangles_y[j];
            float dynamic_width = in_dynamic_rectangles_width[j];
            float dynamic_height = in_dynamic_rectangles_height[j];

            float static_x = in_static_rectangles_x[i];
            float static_y = in_static_rectangles_y[i];
            float static_width = in_static_rectangles_width[i];
            float static_height = in_static_rectangles_height[i];

            if(!
                ((dynamic_y + dynamic_height < static_y || dynamic_y > static_y + static_height)
                || 
                (dynamic_x + dynamic_width < static_x || dynamic_x > static_x + static_width))
            ){
                // collision
                out_static_rectangles_colors_idx[i] = in_idx_new_color;
            }
        }
    }
}


const struct PHYSICS physics {
    void (*const rectangles_collisions_calculate)(
        const int in_size_static_rectangles,
        const float in_static_rectangles_x[static in_size_static_rectangles],
        const float in_static_rectangles_y[static in_size_static_rectangles],
        const unsigned short in_static_rectangles_width[static in_size_static_rectangles],
        const unsigned short in_static_rectangles_height[static in_size_static_rectangles],
        const int in_size_dynamic_rectangles,
        const float in_dynamic_rectangles_x[static in_size_dynamic_rectangles],
        const float in_dynamic_rectangles_y[static in_size_dynamic_rectangles],
        const unsigned short in_dynamic_rectangles_width[static in_size_dynamic_rectangles],
        const unsigned short in_dynamic_rectangles_height[static in_size_dynamic_rectangles],
        unsigned short out_static_rectangles_colors_idx[static in_size_static_rectangles],
        const unsigned short in_idx_new_color
    );
} physics = {
    .rectangles_collisions_calculate = rectangles_collisions_calculate,
};