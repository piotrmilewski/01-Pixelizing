#include "pixel.h"

int main(){

  int i = 0; //for incrementation
  int color = 0; //assigns color on a scale of 0 to 1535
  int r, g, b; //rgb values

  //create image file
  int imageFile = open( "image.ppm", O_CREAT | O_RDWR, 0644);

  //image file header
  char head[18];
  sprintf( head, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
  write(imageFile, head, strlen(head));

  //image file body
  char pixel[15];
  while (i < (HEIGHT * WIDTH)){
    if (color < 1536){
      //zone 1
      if (color <= 255){
        r = 255;
        g = 0 + color;
        b = 0;
      }
      //zone 2
      else if (color <= 511){
        r = 255 - (color - 256);
        g = 255;
        b = 0;
      }
      //zone 3
      else if (color <= 767){
        r = 0;
        g = 255;
        b = 0 + (color - 512);
      }
      //zone 4
      else if (color <= 1023){
        r = 0;
        g = 255 - (color - 768);
        b = 255;
      }
      //zone 5
      else if (color <= 1279){
        r = 0 + (color - 1024);
        g = 0;
        b = 255;
      }
      //zone 6
      else{
        r = 255;
        g = 0;
        b = 255 - (color - 1280);
      }

      sprintf(pixel, "%d %d %d ", r, g, b);
      write(imageFile, pixel, strlen(pixel));

      //reset color rainbow
      if (color == 1535){
        color = 0;
      }
      else{
        color++;
      }
    }
  i++;
  }

  close(imageFile);

  return 0;
}
