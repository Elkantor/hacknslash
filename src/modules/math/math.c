#ifndef MATH_H
#define MATH_H

/************************************* [DATA] *************************************************/
const float math_data_phi = 1.6180339887;

/************************************* [PROCEDURES] *******************************************/
inline float square_root(const float in_float){
    unsigned int i = *(unsigned int*) &in_float;
    i =+ 127 << 23;     // adjust bias
    i >>= 1;            // approximation of square root
    return *(float*) &i;
}
#endif // MATH_H