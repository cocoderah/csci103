//Adelina Hudson
#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;
/*
  0 30 -30 60 60
  0 -30 30 60 600
  0 240 30 60 60
  0 30 240 60 60
  2
 */
/*
 * 
 */
// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {
  //conditionals if negative or input is above 255
  /*if (top < 0) {
    top = 0;
  }
  if (left < 0) {
    left = 0;
  }
  if (height < 0) {
    height = 0;
  }
  if (width < 0) {
    width = 0;
  }
  if (top > 255) {
    top = 255; 
  }
  if (left > 255) {
    left = 255;
  }
  if (height > 255) {
    height = 255;
  }
  if (width > 255) {
    width = 255;
  }
  */
  int th = top + height;
  int wl = width + left;
  //if above 255
  /*if (th > 255) {
    th = 255;
  }
  if (wl > 255) {
    wl = 255;
  }
  */
  for (int i= 0; i < width; i++) {
    int il = (i + left);
    //if (il > 255) {
    //  il = 255;
    //}
    if ((top >= 0) && (top <= 255)) {
      if ((il >= 0) && (il <= 255)) {
      image[top][il] = 0;
      }
    }
    
    if ((th >= 0) && (th <= 255)) {
      if ((il >= 0) && (il <= 255)) {
      image[th][il] = 0;
      }
    } 
    
     //image[top][il] = 0;
     //image[th][il] = 0;
  }
  
  for (int i= 0; i < height; i++) {
    int it = (i + top);
    //if (it > 255) {
    //  it = 255;
    //}
    if ((it >= 0) && (it <= 255)) {
      if ((left >= 0) && (left <= 255)) {
        image[it][left] = 0;
      }
    }
    if ((it >= 0) && (it <= 255)) {
      if ((wl >= 0) && (wl <= 255)) {
        image[it][wl] = 0;
      }
    }
  }
     
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
  for(double theta = 0.0; theta < 2*M_PI; theta += .01) {
    double y = (height/2.0)*sin(theta) + cy;
    double x = (width/2.0)*cos(theta) + cx;
    /*
    //if input is negative
    if(x<0){
      x = 0; 
    }
    if(y<0){
      y=0;
    }
    //if input is above 255
    if(x>255){
      x=255;
    }
    if(y>255){
      y=255;
    }
    */
    
    if ((x>=0) && (x<= 255)){
      if ((y>=0) && (y<=255)) {
        image[(int)y][(int)x]= 0;
      }
    }
    //image[(int)y][(int)x]= 0; //makes it black
  }
  
}

int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   //menu
   int userInput;
   cout << "To draw a rectangle, enter: 0 top left height width" << endl;
   cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
   cout << "To save your drawing as " << "output.bmp" << " and quit, enter: 2" << endl;
   while (cin >> userInput){
     if (userInput == 2){
       break;
     }
     if (userInput == 0)
     {
       int top, left, height, width;
       cin >> top >> left >> height >> width;
       draw_rectangle(top, left, height, width);
     }
      
     if (userInput == 1)
     {
       int cy, cx, height, width;
       cin >> cy >> cx >> height >> width;
       draw_ellipse(cy, cx, height, width);
     }
     
   cout << "To draw a rectangle, enter: 0 top left height width" << endl;
   cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
   cout << "To save your drawing as " << "output.bmp" << " and quit, enter: 2" << endl;
   }

   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}

