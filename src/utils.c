#include <estia-image.h>
#include <stddef.h>
#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ){

    if(x>width && y>height){
        return NULL;
    }

    else if(data==0){
        return NULL;
    }

    else {
        return (pixelRGB *) &data[(y*height+x)*n];
    }
}

pixelRGB getPixel(unsigned char* data, const unsigned int width, const unsigned int channel_count, const unsigned int x, const unsigned int y){
    pixelRGB pixel;
    int index = (y * width + x) * channel_count; 
    
    pixel.R = data[index];
    pixel.G = data[index + 1];
    pixel.B = data[index + 2];

    return pixel;
}

void setPixel(unsigned char* data, const unsigned int width, const unsigned int channel_count, const unsigned int x, const unsigned int y, pixelRGB pixel) {
    int index = (y * width + x) * channel_count;
    data[index] = pixel.R;
    data[index + 1] = pixel.G;
    data[index + 2] = pixel.B;
}
