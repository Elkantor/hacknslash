#define count 5

int data_inputs_keys[count];
#define data_inputs_key_up      0
#define data_inputs_key_down    1 
#define data_inputs_key_right   2
#define data_inputs_key_left    3
#define data_inputs_key_space   4


const struct data_inputs {
    int *keys;
    unsigned short keys_count;
} data_inputs = {
    .keys = data_inputs_keys,
    .keys_count = count,
};

#undef count