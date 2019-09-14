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
    struct DATA_COLORS data_colors {
        const int blue;
        const int red;
        const int black;
        const int light_gray_ui;
    } 
#if defined data_colors
    ;
#else
    data_colors = {
        .blue           = 7991807,
        .red            = -433506305,
        .black          = 255,
        .light_gray_ui  = -960779264,
    };
#endif