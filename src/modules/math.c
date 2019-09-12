float square_root(const float in_float){
    unsigned int i = *(unsigned int*) &in_float;
    i =+ 127 << 23;     // adjust bias
    i >>= 1;            // approximation of square root
    return *(float*) &i;
}

#if !defined module_math
    const
#endif
    struct maths {
        float (*const square_root)(const float in_float);
    }
#if defined module_math
    ;
#else
    maths = {
        square_root = square_root,
    };
#endif