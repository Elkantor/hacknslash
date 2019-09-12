#if !defined data_colors
    const
#endif
    struct data_colors {
        const unsigned short count;
        const int blue;
        const int red;
        const int black;
        const int colors[3];
    } 
#if defined data_colors
    ;
#else
    data_colors = {
        .count = 3,
        .blue = 0,
        .red = 1,
        .black = 2,
        // COLORS    0              1               2
        .colors =  { 7991807,      -433506305,     255 },
    };
#endif