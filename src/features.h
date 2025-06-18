#ifndef FEATURES_H
#define FEATURES_H

void helloWorld();

void dimension(char *filename);

void second_line(char *filename);

void first_pixel (char *filename);

void tenth_pixel (char *source_path);

void print_pixel(char *filename, int x, int y);

void min_pixel (char *filename);

void max_pixel (char *filename);

void max_component(char *filename, char component);

void min_component(char *filename, char component);

void color_red (char *filename);

void color_blue (char *filename);

void color_invert (char *filename);

void color_gray(char *filename);

void color_green(char *filename);

void color_gray_luminance(char *filename);

void mirror_horizontal (char *filename);


#endif
