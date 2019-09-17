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

    /************************************* UI PLAY BUTTON *************************************/
        #define ui_play_button_width                    828
        #define ui_play_button_height                   92
        #define ui_play_button_rectangle                (Rectangle){0.0f, 0.0f, 828/3, 92}
        #define ui_play_button_rectangle_hovered        (Rectangle){828/3, 0.0f, 828/3, 92}
        #define ui_play_button_rectangle_pressed        (Rectangle){(828/3)*2, 0.0f, 828/3, 92}
    /******************************************************************************************/

    /************************************* UI PLAY BUTTON *************************************/
        #define ui_bottom_bar_width                    1920
        #define ui_bottom_bar_height                   62
    /******************************************************************************************/

    /************************************* UI SYMBOLS *****************************************/
        #define ui_symbols_width                        816
        #define ui_symbols_height                       56
        #define ui_symbols_rectangle                    (Rectangle){0.0f, 0.0f, 816/2, 56}
        #define ui_symbols_rectangle_mask               (Rectangle){816/2, 0.0f, 816/2, 56}
    /******************************************************************************************/

/************************************* [END UI] *************************************************/