unsigned int data_resolution_width;
unsigned int data_resolution_height;

const struct  data_resolution {
    unsigned int* window_width;
    unsigned int* window_height;
} data_resolution = {
    .window_width   = &data_resolution_width,
    .window_height  = &data_resolution_height,
};