float square_root(const float in_float){
    unsigned int i = *(unsigned int*) &in_float;
    i =+ 127 << 23;     // adjust bias
    i >>= 1;            // approximation of square root
    return *(float*) &i;
}

#if !defined module_math
    const
#endif
    struct math {
        float (*const square_root)(const float in_float);
        const double phi;
    }
#if defined module_math
    ;
#else
    math = {
        .square_root = square_root,
        .phi = 1.61803398874989484820,
    };
#endif