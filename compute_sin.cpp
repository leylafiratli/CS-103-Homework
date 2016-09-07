#include <iostream>
#include <cmath>

/* Author: Samuel Resendez
 * Program: compute_sin
 * Description: Reads a number x from input, an angle in radians. 
 *    Computes an approximation to sin(x) using an 4th-order Taylor series.
 */

using namespace std;

int fact(int); // declares a function the skeleton defines for you.

int main(int argc, char *argv[])
{
   // Declare any variables you need here
	double sinApproximation = 0.0;
	double userInput = 0.0;

   
   
   // Prompt the user
   cout << "Enter x in radians:  ";
   cin >> userInput;// get input
   
   
   // Do some operations
   for(int i = 0;i <=3;i += 1)
   {
   		sinApproximation += pow(-1,i)*(pow(userInput,1+2*i)/fact(1+2*i));
   }

   cout << "The sin of " << userInput << " is " << sinApproximation << endl;
   // Print the result to the user
   
   
   // You're done
   return 0;
   
}

// here's the actual definition of fact, declared earlier.
int fact(int n)
{
   int result = 1;
   for (int i = 1; i <= n; i++) {
      result = result * i;
   }
   return result;
}

