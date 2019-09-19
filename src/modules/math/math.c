#if defined _WIN32 && defined module_export
    #define MATH __declspec(dllexport) // We are building logging as a win32 shared library (.dll)
#elif defined _WIN32 && defined module_import
    #define MATH __declspec(dllimport) // we are using logging as a win32 shared library (.dll)
#else
    #define MATH // We are building or using logging as a static library (or a shared one on linux)
#endif

float square_root(const float in_float){
    unsigned int i = *(unsigned int*) &in_float;
    i =+ 127 << 23;     // adjust bias
    i >>= 1;            // approximation of square root
    return *(float*) &i;
}

const struct data_math {
    float phi;
} data_math = {
    .phi = 1.6180339887,
};

const struct MATH math {
    const struct data_math* const data;
    float (*const square_root)(const float in_float);
} math = {
    .data           = &data_math,
    .square_root    = square_root,
};