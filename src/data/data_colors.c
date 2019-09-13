#if defined _WIN32 && defined data_colors_build_dll
    #define DATA_COLORS __declspec(dllexport) // We are building data_colors as a win32 shared library (.dll)
#elif defined _WIN32 && defined data_colors 
    #define DATA_COLORS __declspec(dllimport) // we are using data_colors as a win32 shared library (.dll)
#else
    #define DATA_COLORS // We are building or using data_colors as a static library (or a shared one on linux)
#endif

#if !defined data_colors
    const
#endif
    struct data_colors {
        const int colors[];
        const int blue;
        const int red;
        const int black;
        const unsigned short count;
    } 
#if defined data_colors
    ;
#else
    data_colors = {
        .blue = 0,
        .red = 1,
        .black = 2,
        // COLORS    0              1               2
        .colors =  { 7991807,      -433506305,     255 },
        .count = sizeof(data_colors.colors)/sizeof(data_colors.colors[0]),
    };
#endif