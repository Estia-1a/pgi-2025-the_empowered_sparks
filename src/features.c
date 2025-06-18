#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
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

void max_pixel(char *filename){
 int width, height, channel_count, max=0, max_x=0, max_y=0;
    unsigned char *data;
    pixelRGB pixel1;
    pixelRGB max_pixel1;

    read_image_data(filename, &data, &width, &height, &channel_count);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channel_count;

            pixel1.R = data[index];
            pixel1.G = data[index + 1];
            pixel1.B = data[index + 2];

            int sum = pixel1.R + pixel1.G + pixel1.B;

            if (sum > max) {
                max = sum;
                max_pixel1 = pixel1;
                max_x = x;
                max_y = y;
            }
        }
    }
    printf("max_pixel (%d, %d): %d, %d, %d",max_x,max_y, max_pixel1.R,max_pixel1.G,max_pixel1.B);
    free_image_data(data);  
}

void max_component(char *filename, char component) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;
    int max_value = -1;
    int max_x = 0, max_y = 0;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = getPixel(data, width, channel_count, x, y);
            int value = 0;

            if (component == 'R') value = pixel.R;
            else if (component == 'G') value = pixel.G;
            else if (component == 'B') value = pixel.B;

            if (value > max_value) {
                max_value = value;
                max_x = x;
                max_y = y;
            }
        }
    }
    printf("max_component %c (%d, %d): %d", component, max_x, max_y, max_value);
    free_image_data(data);
}

void min_component(char *filename, char component) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;
    int min_value = 256;  
    int min_x = 0, min_y = 0;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = getPixel(data, width, channel_count, x, y);
            int value = 0;

            if (component == 'R') value = pixel.R;
            else if (component == 'G') value = pixel.G;
            else if (component == 'B') value = pixel.B;

            if (value < min_value) {
                min_value = value;
                min_x = x;
                min_y = y;
            }
        }
    }

    printf("min_component %c (%d, %d): %d", component, min_x, min_y, min_value);
    free_image_data(data);
}

void color_red(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = getPixel(data, width, channel_count, x, y);
            pixel.G = 0;
            pixel.B = 0;
            setPixel(data, width, channel_count, x, y, pixel);
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_blue(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = getPixel(data, width, channel_count, x, y);
            pixel.G = 0;
            pixel.R = 0;
            setPixel(data, width, channel_count, x, y, pixel);
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}


void print_pixel(char *filename, int x, int y){
    int width,height,channel_count;
    unsigned char *data;
    read_image_data(filename, &data, &width, &height, &channel_count);
    pixelRGB *p = get_pixel(data, width, height, channel_count, x, y);

    printf("print_pixel (%d,%d): %d, %d, %d",x,y,p->R,p->G,p->B);
    free_image_data(data);
}

void stat_report (char *filename){
    int width,height,channel_count, max, max_x=0, max_y=0;
    char components[] = {'R', 'G', 'B'};
    unsigned char *data;
    FILE *f = fopen("stat_reports.txt", "w");
    pixelRGB pixel, min_pixel, pixel1, max_pixel1;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channel_count;

            pixel1.R = data[index];
            pixel1.G = data[index + 1];
            pixel1.B = data[index + 2];

            int sum = pixel1.R + pixel1.G + pixel1.B;

            if (sum > max) {
                max = sum;
                max_pixel1 = pixel1;
                max_x = x;
                max_y = y;
            }
        }
    }
    fprintf(f,"max_pixel (%d, %d): %d, %d, %d\n",max_x,max_y, max_pixel1.R,max_pixel1.G,max_pixel1.B); 

    int min_sum = 256 * 3 + 1;
    int min_x = 0, min_y = 0; 

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

    fprintf(f,"min_pixel (%d, %d): %d, %d, %d\n",min_x, min_y, min_pixel.R, min_pixel.G, min_pixel.B);

    for (int i = 0; i < 3; i++) {
                char component = components[i];
                int max_value = -1;
                int max_x = 0, max_y = 0;

            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    pixel = getPixel(data, width, channel_count, x, y);
                    int value = 0;

                    if (component == 'R') value = pixel.R;
                    else if (component == 'G') value = pixel.G;
                    else if (component == 'B') value = pixel.B;

                    if (value > max_value) {
                        max_value = value;
                        max_x = x;
                        max_y = y;
                    }
                }
            }
            fprintf(f, "max_component %c (%d, %d): %d\n", component, max_x, max_y, max_value);
        }

    for (int i = 0; i < 3; i++) {
            char component = components[i];
            int min_value = 256;
            int min_x = 0, min_y = 0;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                pixel = getPixel(data, width, channel_count, x, y);
                int value = 0;

                if (component == 'R') value = pixel.R;
                else if (component == 'G') value = pixel.G;
                else if (component == 'B') value = pixel.B;

                if (value < min_value) {
                    min_value = value;
                    min_x = x;
                    min_y = y;
                }
            }
        }
        fprintf(f,"min_component %c (%d, %d): %d\n", component, min_x, min_y, min_value);
    }
fclose(f);
}

void color_gray(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = getPixel(data, width, channel_count, x, y);
            unsigned char gray = (pixel.R + pixel.G + pixel.B) / 3;
            pixel.R = gray;
            pixel.G = gray;
            pixel.B = gray;
            setPixel(data, width, channel_count, x, y, pixel);
        }
    }

    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_green(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = getPixel(data, width, channel_count, x, y);
            pixel.R = 0;
            pixel.B = 0;
            setPixel(data, width, channel_count, x, y, pixel);
        }
    }

    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_invert(char *filename) {
    int width,height,channel_count;
    unsigned char *data;
    pixelRGB pixel;
    read_image_data(filename, &data, &width, &height, &channel_count);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            

            pixel = getPixel(data, width, channel_count, x, y);
            pixel.R = 255 - pixel.R ;
            pixel.B = 255 - pixel.B ;
            pixel.G = 255 - pixel.G ;
            setPixel(data, width, channel_count, x, y, pixel);
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_gray_luminance(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = getPixel(data, width, channel_count, x, y);

            unsigned char gray = (unsigned char)(
                0.21 * pixel.R + 0.72 * pixel.G + 0.07 * pixel.B
            );

            pixel.R = gray;
            pixel.G = gray;
            pixel.B = gray;

            setPixel(data, width, channel_count, x, y, pixel);
        }
    }

    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void rotate_cw(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(filename, &data, &width, &height, &channel_count);
    unsigned char *rotated_data = malloc(height * width * channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB pixel = getPixel(data, width, channel_count, x, y);
            setPixel(rotated_data, height, channel_count, height - 1 - y, x, pixel);
        }
    }

    write_image_data("image_out.bmp", rotated_data, height, width);
    free_image_data(data);
    free(rotated_data);
}

void mirror_horizontal(char*filename){
   int width,height,channel_count;
    unsigned char *data;
    pixelRGB pixeldroit, pixelgauche;
    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width/2; x++) {
            int miroire = width - 1 - x;

            pixeldroit = getPixel(data, width, channel_count, x, y);
            pixelgauche = getPixel(data, width, channel_count, miroire, y);

            setPixel(data, width, channel_count, x, y, pixelgauche);
            setPixel(data, width, channel_count, miroire, y, pixeldroit);
            
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}