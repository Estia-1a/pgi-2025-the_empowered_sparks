#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension(char *filename){
    int width,height,channel_count;
    unsigned char *data;
    
    read_image_data(filename, &data, &width, &height, &channel_count);
    printf("dimension: %d, %d", width, height);
    free_image_data(data);
}

void first_pixel(char *filename){
    int width, height, channel_count, index;
    unsigned char *data;
    pixelRGB pixel1;

    read_image_data(filename, &data, &width, &height, &channel_count);

    index = 0;
    pixel1.R = data[index];
    pixel1.G = data[index+1];
    pixel1.B = data[index+2];

    printf("first_pixel: %d, %d, %d",pixel1.R,pixel1.G,pixel1.B);
    free_image_data(data);
}

void tenth_pixel(char *filename) {
    int width, height, channel_count, index;
    unsigned char *data;
    pixelRGB pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);
    index = (0*width + 9) * channel_count;

    pixel.R = data[index];
    pixel.G = data[index+1];
    pixel.B = data[index+2];

    printf("tenth_pixel: %d, %d, %d", pixel.R, pixel.G, pixel.B);
    free_image_data(data);
}

void second_line(char *filename){
    int width,height,channel_count, index;
    unsigned char *data;
    pixelRGB p;


    read_image_data(filename, &data, &width, &height, &channel_count);
    index=(1*width+0)*channel_count;

    p.R = data[index];
    p.G = data[index+1];
    p.B = data[index+2];

    printf("second_line: %d, %d, %d",p.R,p.G,p.B);
    free_image_data(data);
}

void min_pixel(char *filename){
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel, min_pixel;
    int min_sum = 256 * 3 + 1;
    int min_x = 0, min_y = 0; 

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            pixel = getPixel(data, width, channel_count, x, y);
            int sum = pixel.R + pixel.G + pixel.B;

            if (sum < min_sum){
                min_sum = sum;
                min_pixel = pixel;
                min_x = x;
                min_y = y;
            }
        }
    }

    printf("min_pixel (%d, %d): %d, %d, %d",min_x, min_y, min_pixel.R, min_pixel.G, min_pixel.B);
    free_image_data(data);
}

