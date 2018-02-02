#include "pixel.h"

char *manSprintF(int R, int G, int B){
  int red, green, blue;
  char str[32] = malloc(32 * sizeof(char));
  sprintf( str, "%d %d %d", red, green, blue);

}

char *imageContents(){


}

int main(){

  //create image file
  int imageFile = open( "image.ppm", O_CREAT | O_RDWR | O_APPEND, 0644);

  


  return 0;
}
