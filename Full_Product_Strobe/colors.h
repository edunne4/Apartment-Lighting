#ifndef __colors_h_
#define __colors_h_


typedef struct rgbColor{
  byte r;
  byte g;
  byte b;
} rgbColor;


const rgbColor off = {0, 0, 0};
const rgbColor red = {255, 0, 0};
const rgbColor green = {0, 255, 0};
const rgbColor blue = {0, 0, 255};
const rgbColor white = {100, 100, 100};//{10, 10, 10};
const rgbColor orange = {255, 30, 0};
const rgbColor yellow = {255, 90, 0};
const rgbColor cyan = {0, 255, 255};
const rgbColor purple = {255, 0, 255};


#define NUM_COLORS 7
rgbColor colors[] = {purple, red, yellow, green, blue, orange, cyan};


#endif
