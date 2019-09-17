#if defined _WIN32 && defined data_ui_main_menu_build_dll
    #define DATA_UI_MAIN_MENU __declspec(dllexport) // We are building data_ui_main_menu as a win32 shared library (.dll)
#elif defined _WIN32 && defined data_ui_main_menu
    #define DATA_UI_MAIN_MENU __declspec(dllimport) // we are using data_ui_main_menu as a win32 shared library (.dll)
#else
    #define DATA_UI_MAIN_MENU // We are building or using data_ui_main_menu as a static library (or a shared one on linux)
#endif

unsigned int data_ui_main_menu_textures_id[7];
unsigned short data_ui_main_menu_loaded = 0;
unsigned short data_ui_main_menu_current_idx = 0;

unsigned short data_ui_symbols_texture_id = 0;
unsigned int data_ui_symbols_fbo_id = 0;

#if !defined data_ui_main_menu
    const 
#endif
    struct DATA_UI_MAIN_MENU data_ui_main_menu {
        unsigned int* ids;
        unsigned short* current_loaded;
        unsigned short* current_idx;
        unsigned short* symbols_idx_id;
        unsigned int* symbols_fbo_id;
    }
#if defined data_ui_main_menu
    ;
#else
    data_ui_main_menu = {
        .ids = data_ui_main_menu_textures_id,
        .current_loaded = &data_ui_main_menu_loaded,
        .current_idx = &data_ui_main_menu_current_idx,
        .symbols_idx_id = &data_ui_symbols_texture_id,
        .symbols_fbo_id = &data_ui_symbols_fbo_id,
    };
#endif