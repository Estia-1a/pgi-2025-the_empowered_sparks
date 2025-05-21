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
    printf("dimension: %d, %d",width, height);
    free_image_data(data);
}

void second_line(char *filename){
    int width,height,channel_count, index;
    unsigned char *data;
    pixelRGB p;


    read_image_data(filename, &data, &width, &height, &channel_count);
    index=(1*height+0)*channel_count;

    p.R = data[index];
    p.G = data[index+1];
    p.B = data[index+2];

    printf("second_line: %d, %d, %d",p.R,p.G,p.B);
    free_image_data(data);
}

