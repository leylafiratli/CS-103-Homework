#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "bmplib.h"

using namespace std;
//SIZE = 256
//RGB = 3

//============================Add function prototypes here======================
void dummy(unsigned char[][SIZE][RGB],unsigned char[][SIZE][RGB]);
void convolve(unsigned char[][SIZE][RGB],unsigned char[][SIZE][RGB],int,double[][11]);
void sobel(unsigned char[][SIZE][RGB],unsigned char[][SIZE][RGB]);
void unsharp(unsigned char[][SIZE][RGB],unsigned char[][SIZE][RGB],int,double,double);
void gaussian_filter(unsigned char[][SIZE][RGB],unsigned char[][SIZE][RGB],int,double);
void gaussian(double[11][11],int,double);

//============================Do not change code in main()======================

#ifndef AUTOTEST

int main(int argc, char* argv[])
{
   //First check argc
  if(argc < 3)
    {
      //we need at least ./filter <input file> <filter name> to continue
      cout << "usage: ./filter <input file> <filter name> <filter parameters>";
      cout << " <output file name>" << endl;
      return -1;
    }
   //then check to see if we can open the input file
   unsigned char input[SIZE][SIZE][RGB];
   unsigned char output[SIZE][SIZE][RGB];
   char* outfile;
   int N;
   double sigma, alpha;
   //double kernel[11][11]; only edit to main

   // read file contents into input array
   int status = readRGBBMP(argv[1], input); 
   if(status != 0)
   {
      cout << "unable to open " << argv[1] << " for input." << endl;
      return -1;
   }
   //Input file is good, now look at next argument
   if( strcmp("sobel", argv[2]) == 0)
   {
     sobel(output, input);
     outfile = argv[3];
   }
   else if( strcmp("blur", argv[2]) == 0)
   {
     if(argc < 6)
       {
	 cout << "not enough arguments for blur." << endl;
	 return -1;
       }
     N = atoi(argv[3]);
     sigma = atof(argv[4]);
     outfile = argv[5];
     gaussian_filter(output, input, N, sigma);
   }
   else if( strcmp("unsharp", argv[2]) == 0)
   {
     if(argc < 7)
       {
	 cout << "not enough arguments for unsharp." << endl;
	 return -1;
       }
     N = atoi(argv[3]);
     sigma = atof(argv[4]);
     alpha = atof(argv[5]);
     outfile = argv[6];
     unsharp(output, input, N, sigma, alpha);

   }
   else if( strcmp("dummy", argv[2]) == 0)
   {
     //do dummy
     dummy(output, input);
     outfile = argv[3];
   }
   else
   {
      cout << "unknown filter type." << endl;
      return -1;
   }

   if(writeRGBBMP(outfile, output) != 0)
   {
      cout << "error writing file " << argv[3] << endl;
   }

}   

#endif 

//=========================End Do not change code in main()=====================


// Creates an identity kernel (dummy kernel) that will simply
// copy input to output image and applies it via convolve()
//
// ** This function is complete and need not be changed.
// Use this as an example of how to create a kernel array, fill it in
// appropriately and then use it in a call to convolve.
void dummy(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB])
{
   double k[11][11];


//Initialize dummy kernel
   for (int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++) {
         k[i][j] = 0;
      }
   }
   k[1][1] = 1;
   convolve(out, in, 3, k);
}


// Convolves an input image with an NxN kernel to produce the output kernel
// You will need to complete this function by following the 
//  instructions in the comments
void convolve(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
	      int N, double kernel[][11])
{
 
   int padded[SIZE+11][SIZE+11][RGB];  // Use for input image with appropriate 
                                       // padding
   int temp[SIZE][SIZE][RGB];          // Use for the unclamped output pixel 
                                       // values then copy from temp to out, 
                                       // applying clamping 

   //first set all of padded to 0 (black)
   for(int i = 0; i < RGB;i++) {
   		for(int j = 0; j < SIZE+N; j++) {
   			for (int k = 0; k < SIZE + N; k++) {
   				padded[k][j][i] = 0;
   			}
   		}
   }



   //now copy input into padding to appropriate locations
   for(int i = 0; i < RGB; i++) {
   		for(int j=0; j<SIZE;j++) {
   			for(int k = 0; k < SIZE; k++) {
   				padded[k+5][j+5][i] = in[k][j][i];
   			}
   		}
   }



   //initialize temp pixels to 0 (black)
   for(int i = 0; i < RGB; i++) {
   		for(int j = 0; j<SIZE;j++){
   			for(int k = 0 ; k<SIZE;k++) {
   				temp[k][j][i] = 0;

   			}
   		}
   }
   /*
   for(int i = 0; i< RGB; i++) {
   		for(int j = 0; j<SIZE; j++) {
   			for(int k = 0; k<SIZE;k++) {
   				temp[k][j][i] = padded[k+5][j+5][i];
   			}
   		}
   }
	*/

   //now perform convolve (using convolution equation on each pixel of the 
   // actual image) placing the results in temp (i.e. unclamped result)
   for(int i = 0; i< RGB; i++) {
   		for(int j = 0; j < SIZE; j++) {
   			for(int k = 0; k < SIZE; k++) {
   				for(int h = 0; h < N; h++) {
   					for(int w = 0; w < N; w++){
   						temp[k][j][i] += padded[k+h][j+w][i] * kernel[h][w];
   					}
   				}
   			}
   		}
   }




   //now clamp and copy to output
   // You may need to cast to avoid warnings from the compiler:
   // (i.e. out[i][j][k] = (unsigned char) temp[i][j][k];)
   for(int i = 0; i < RGB; i++) {
   		for(int j = 0; j < SIZE; j++) {
   			for(int k = 0; k < SIZE; k++) {
   				if(temp[k][j][i] > 255) {
   					temp[k][j][i] = 255;
   				}
   				else if(temp[k][j][i] < 0) {
   					temp[k][j][i] = 0;
   				}
   				out[k][j][i] = (unsigned char) temp[k][j][i];

   			}
   		}
   }



}

// You will need to complete this function by following the 
//  instructions in the comments
void sobel(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB])
{
   double k[11][11];
   double s_h1[3][3] = { {-1, 0, 1}, 
                         {-2, 0, 2}, 
                         {-1, 0, 1} };
   double s_h2[3][3] = { {1, 0, -1}, 
                         {2, 0, -2}, 
                         {1, 0, -1}};
   
   unsigned char h1_soble[SIZE][SIZE][RGB]; //hold intemediate images
   unsigned char h2_soble[SIZE][SIZE][RGB]; 

   for (int i = 0; i < 11; i++)
   {
      for(int j=0; j < 11; j++)
      {
         k[i][j] = 0;
      }
   }


   // Copy in 1st 3x3 horizontal sobel kernel (i.e. copy s_h1 into k)
   for(int i = 0; i < 3;i++) {
   		for(int j=0;j< 3; j++) {
   			k[i][j] = s_h1[i][j];
   		}
   }



   // Call convolve to apply horizontal sobel kernel with result in h1_soble
   convolve(h1_soble,in,3,k);


   // Copy in 2nd 3x3 horizontal sobel kernel (i.e. copy s_h2 into k)
   for(int i = 0; i < 3; i++) {
   		for(int j=0; j<3; j++) {
   			k[i][j] = s_h2[i][j];
   		}
   }


   // Call convolve to apply horizontal sobel kernel with result in h2_soble
   convolve(h2_soble,in,3,k);


   // Add the two results (applying clamping) to produce the final output 
   
   for(int i =0; i < RGB; i++) {
   		for(int j=0; j<SIZE;j++) {
   			for(int l=0; l<SIZE;l++){
   				int sum = h1_soble[l][j][i] + h2_soble[l][j][i];
   				if(sum > 255) {
   					sum = 255;
   				}
   				else if(sum < 0){
   					sum = 0;
   				}
   				out[l][j][i] = (unsigned char)sum;
   			}
   		}
   }


}


// Add the rest of your functions here (i.e. gaussian, gaussian_filter, unsharp)
void gaussian_filter(unsigned char out[][SIZE][RGB],unsigned char in[][SIZE][RGB],int N,double sigma)
{
	double kernel[11][11];

	gaussian(kernel,N,sigma);

	

	convolve(out,in,N,kernel);

}
void gaussian(double kernel[][11],int N, double sigma) {

	double total= 0;
	for(int i = 0; i<N; i++) {
		for(int j=0; j<N; j++) {
			int gX = j-(N-1)/2, gY = i-(N-1)/2; //Gives the index of the kernel

			//Calculates The gaussian value at (gX, gY)
			double pixelValue = exp(-((gX*gX + gY*gY)/(2*sigma*sigma))); 
			total += pixelValue;
			kernel[i][j] = pixelValue;
			
		}
	}
	//Normalizing each value of the kernel
	for(int i =0; i<N; i++) {
		for(int j=0; j<N; j++) {
			kernel[i][j] = kernel[i][j]/total;
		}
	}
}
void unsharp(unsigned char out[][SIZE][RGB],unsigned char in[][SIZE][RGB],int N,double sigma,double alpha)
{

	unsigned char temp[SIZE][SIZE][RGB];

	gaussian_filter(temp,in,N,sigma);



	for(int i =0;i<RGB;i++){
		for(int j=0;j<SIZE;j++){
			for(int k=0;k<SIZE;k++){
				//Subtract blurred from the original image

				int value = in[k][j][i] - temp[k][j][i];

				//Multiply that value by alpha and add the original again
				int pixelVal = (int)(value * alpha + in[k][j][i]);

				//Applying clamping
				if(pixelVal > 255) {
					pixelVal = 255;
				} else if (pixelVal < 0) {
					pixelVal = 0;
				}
				out[k][j][i] = (unsigned char)pixelVal;
			}
		}
	}
}


