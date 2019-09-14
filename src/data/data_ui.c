#if defined _WIN32 && defined data_ui_build_dll
    #define DATA_UI __declspec(dllexport) // We are building data_ui as a win32 shared library (.dll)
#elif defined _WIN32 && defined data_ui
    #define DATA_UI __declspec(dllimport) // we are using data_ui as a win32 shared library (.dll)
#else
    #define DATA_UI // We are building or using data_ui as a static library (or a shared one on linux)
#endif

/* Forward declaration of the structures used from raylib */
#if !defined RAYLIB_H
    typedef struct Texture2D {
        unsigned int id;        // OpenGL texture id
        int width;              // Texture base width
        int height;             // Texture base height
        int mipmaps;            // Mipmap levels, 1 by default
        int format;             // Data format (PixelFormat type)
    } Texture2D;

    typedef struct Rectangle {
        float x;
        float y;
        float width;
        float height;
    } Rectangle;

    typedef struct Image {
        void *data;             // Image raw data
        int width;              // Image base width
        int height;             // Image base height
        int mipmaps;            // Mipmap levels, 1 by default
        int format;             // Data format (PixelFormat type)
    } Image;

    typedef struct CharInfo {
        int value;              // Character value (Unicode)
        int offsetX;            // Character offset X when drawing
        int offsetY;            // Character offset Y when drawing
        int advanceX;           // Character advance position X
        Image image;            // Character image data
    } CharInfo;

    typedef struct Font {
        int baseSize;           // Base size (default chars height)
        int charsCount;         // Number of characters
        Texture2D texture;      // Characters texture atlas
        Rectangle *recs;        // Characters rectangles in texture
        CharInfo *chars;        // Characters info data
    } Font;
#endif

Font data_ui_palatino_linotype_regular;

#if !defined data_ui
    const 
#endif
    struct DATA_UI data_ui {
        Font* palatino_linotype_regular;
    }
#if defined data_ui
    ;
#else
    data_ui = {
        .palatino_linotype_regular = &data_ui_palatino_linotype_regular,
    };
#endif