#ifndef DATA_H
#define DATA_H

/* This file contains every definition for the textures data and sounds */

/************************************* [UI] *************************************************/

    /************************************* UI ARROW *******************************************/
        #define ui_arrow_width                          59
        #define ui_arrow_height                         342
        #define ui_arrow_rectangle                      (Rectangle){0.0f, 0.0f, 59, 342/3}
        #define ui_arrow_rectangle_hovered              (Rectangle){0.0f, 342/3, 59, 342/3}
        #define ui_arrow_rectangle_pressed              (Rectangle){0.0f, (342/3)*2, 59, 342/3}
    /******************************************************************************************/

    /************************************* UI BACKGROUND **************************************/
        #define ui_background_width                     1920
        #define ui_background_height                    1080
    /******************************************************************************************/

    /************************************* UI LOGO ********************************************/
        #define ui_logo_width                           833
        #define ui_logo_height                          280
    /******************************************************************************************/

    /************************************* UI PLAY BUTTON *************************************/
        #define ui_play_button_width                    828
        #define ui_play_button_height                   92
        #define ui_play_button_rectangle                (Rectangle){0.0f, 0.0f, 828/3, 92}
        #define ui_play_button_rectangle_hovered        (Rectangle){828/3, 0.0f, 828/3, 92}
        #define ui_play_button_rectangle_pressed        (Rectangle){(828/3)*2, 0.0f, 828/3, 92}
    /******************************************************************************************/

    /************************************* UI BOTTOM BAR **************************************/
        #define ui_bottom_bar_width                    1920
        #define ui_bottom_bar_height                   62
    /******************************************************************************************/

    /************************************* UI CHARACTER ***************************************/
        #define ui_character_width                    518
        #define ui_character_height                   897
    /******************************************************************************************/

    /************************************* UI SYMBOLS *****************************************/
        #define ui_symbols_width                        408
        #define ui_symbols_height                       56
        #define ui_symbols_rectangle                    (Rectangle){0.0f, 0.0f, 816/2, 56}
    /******************************************************************************************/

    /************************************* UI GLOW COLOR  *************************************/
        #define ui_glow_color_width                     653
        #define ui_glow_color_height                    462
        #define ui_glow_color_rectangle                 (Rectangle){0.0f, 0.0f, 653, 462}
    /******************************************************************************************/

/************************************* [END UI] *************************************************/

#endif // DATA_H