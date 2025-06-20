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

void stat_report (char *filename);

void color_invert (char *filename);

void color_gray(char *filename);

void color_green(char *filename);

void color_gray_luminance(char *filename);

void scale_crop(char *filename, int center_x, int center_y, int width, int heigth);

void mirror_horizontal (char *filename);

void rotate_cw(char *filename);

void mirror_vertical (char *filename);

void mirror_total (char *filename);

void rotate_acw(char * filename);

void color_desaturate(char * filename);

void scale_bilinear(char* filename, float scale);

void scale_nearest(char *filename, float scale);


#endif
