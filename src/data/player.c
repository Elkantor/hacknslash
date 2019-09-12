float data_player_x = 150;
float data_player_y = 150;
unsigned short data_player_width = 20;
unsigned short data_player_height = 20;
unsigned short data_player_idx_color = 0;

const struct data_player {
    float *x;
    float *y;
    unsigned short *width;
    unsigned short *height;
    unsigned short *idx_color;
} data_player = {
    .x = &data_player_x,
    .y = &data_player_y,
    .width = &data_player_width,
    .height = &data_player_height,
    .idx_color = &data_player_idx_color,
};