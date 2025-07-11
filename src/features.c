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
 int width, height, channel_count, max=-1, max_x=0, max_y=0;
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
free_image_data(data);
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

void mirror_vertical(char*filename){
   int width,height,channel_count;
    unsigned char *data;
    pixelRGB pixelbas, pixelhaut;
    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height/2; y++) {
        int miroire = height - 1 - y;
        for (int x = 0; x < width; x++) {
            

            pixelhaut = getPixel(data, width, channel_count, x, y);
            pixelbas = getPixel(data, width, channel_count, x, miroire);

            setPixel(data, width, channel_count, x, y, pixelbas);
            setPixel(data, width, channel_count, x, miroire, pixelhaut);
            
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void scale_crop(char *filename, int center_x, int center_y, int width, int height) {
    int src_width,src_height,channel_count;
    unsigned char *data;
    int left   = center_x - width/2;
    int top    = center_y - height/2;
    pixelRGB pixel;
    read_image_data(filename, &data, &src_width, &src_height, &channel_count);

    unsigned char *dst_data = malloc(width * height * channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int x_src = left + x;
            int y_src = top  + y;

            if (x_src >= 0 && x_src < src_width && y_src >= 0 && y_src < src_height){
                pixel = getPixel(data,src_width,channel_count,x_src, y_src);
            } 
            setPixel(dst_data,width, channel_count, x, y, pixel);

        }}

            write_image_data("image_out.bmp",dst_data, width, height);
            free_image_data(data);
            free(dst_data);

}


void rotate_acw(char *filename) {
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(filename, &data, &width, &height, &channel_count);
    unsigned char *rotated_data = malloc(width * height * channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixelRGB pixel = getPixel(data, width, channel_count, x, y);
            setPixel(rotated_data, height, channel_count, y, width - 1 - x, pixel);
        }
    }

    write_image_data("image_out.bmp", rotated_data, height, width);
    free_image_data(data);
    free(rotated_data);
}

void mirror_total(char*filename){
   int width,height,channel_count;
    unsigned char *data;
    pixelRGB pixelbas, pixelhaut;
    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height/2; y++) {
        int miroire = height - 1 - y;
        for (int x = 0; x < width; x++) {
            int miroire2 = width - 1 - x;
            
            pixelhaut = getPixel(data, width, channel_count, x, y);
            pixelbas = getPixel(data, width, channel_count, miroire2, miroire);

            setPixel(data, width, channel_count, x, y, pixelbas);
            setPixel(data, width, channel_count, miroire2, miroire, pixelhaut);
            
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_desaturate(char * filename) {
    int width, height, channel_count;
    unsigned char *data;
    pixelRGB pixel;

    read_image_data(filename, &data, &width, &height, &channel_count);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel = getPixel(data, width, channel_count, x, y);

            unsigned char mn = pixel.R;
            if (pixel.G < mn) mn = pixel.G;
            if (pixel.B < mn) mn = pixel.B;

            unsigned char mx = pixel.R;
            if (pixel.G > mx) mx = pixel.G;
            if (pixel.B > mx) mx = pixel.B;

            unsigned char new_val = (mn + mx) / 2;

            pixel.R = pixel.G = pixel.B = new_val;

            setPixel(data, width, channel_count, x, y, pixel);
        }
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void scale_bilinear(char* filename, float scale) {
    int width, height, channel_count;
    unsigned char* data;

    read_image_data(filename, &data, &width, &height, &channel_count);

    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);

    unsigned char* new_data = malloc(new_width * new_height * channel_count);

    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int src_x = (int)(x / scale);
            int src_y = (int)(y / scale);

            pixelRGB pixel = getPixel(data, width, channel_count, src_x, src_y);
            setPixel(new_data, new_width, channel_count, x, y, pixel);
        }
    }

    write_image_data("image_out.bmp", new_data, new_width, new_height);
    free_image_data(data);
    free_image_data(new_data);
}

void scale_nearest(char *filename, float scale) {
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(filename, &data, &width, &height, &channel_count);

    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);
    unsigned char *resized_data = malloc(new_width * new_height * channel_count);

    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int src_x = (int)(x / scale);
            int src_y = (int)(y / scale);
            pixelRGB pixel = getPixel(data, width, channel_count, src_x, src_y);
            setPixel(resized_data, new_width, channel_count, x, y, pixel);
        }
    }

    write_image_data("image_out.bmp", resized_data, new_width, new_height);
    free_image_data(data);
    free(resized_data);
}
