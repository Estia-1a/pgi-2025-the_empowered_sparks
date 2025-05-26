#include <estia-image.h>

#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB getPixel(unsigned char* data, const unsigned int width, const unsigned int channel_count, const unsigned int x, const unsigned int y){
    pixelRGB pixel;
    int index = (y * width + x) * channel_count; 
    
    pixel.R = data[index];
    pixel.G = data[index + 1];
    pixel.B = data[index + 2];

    return pixel;
}