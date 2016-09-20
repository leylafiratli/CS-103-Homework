#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) { //WORKS!
   for(int i = top; i<top+height; i++) {
   		if(i <= 255 && left+width <= 255) {
   			image[i][left] = 0;
   			image[i][left+width] = 0;
   		}
   		
   }
   for(int i = left;i < left + width; i++) {
   		if(i <= 255 && top+height <= 255) {
   			image[top][i] = 0;
   			image[top+height][i] = 0;
   		}
   }
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {	

	double xRadius = width / 2;
	double yRadius = height / 2;
	for(double theta=0.0; theta <= 2*M_PI;theta+= .01) {
		double x = xRadius*cos(theta);
    	double y = yRadius*sin(theta);
     	x += cx;
     	y += cy;
     	 image[(int)y][(int)x] = 0;
  }

}


int main() {

	// Instantiate important variables here:
	bool userWantsToStay = true;
	int userInput;
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here
   while(userWantsToStay) {
   	cout << "Please enter a 0 to draw a rectangle, a 1 for an ellipse, and 2 to exit" << endl;
   	cout << ">> ";
   	cin >> userInput;
   	if(userInput == 0) {
   		int top;
   		int left;
   		int width;
   		int height;
   		cout << "Please enter dimensions: ";
   		cin >> top >> left >> height >> width;
   		draw_rectangle(top,left,height,width);
   	} else if(userInput == 1) {
   		int top;
   		int left;
   		int width;
   		int height;
   		cout << "Please enter dimensions: ";
   		cin >> top >> left >> height >> width;
   		draw_ellipse(top,left,height,width);
   	} else if (userInput == 2) {
   		userWantsToStay = false;
   	} else if(userInput == 1337) {

   		//pseudo method = draw_ellipse(x,y,50,50)
   		for(int i = 0; i < 6; i++) {
   			 for(int j = 0; j < 6; j++) {
   			 	draw_ellipse(43 + j*43,43 + 43*i,85,85);
   			 }
   		}
   	}
   }
   
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}
