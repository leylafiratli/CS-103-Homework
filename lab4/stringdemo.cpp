//Author: Samuel Resendez
// CS 103: Lab
// Sunday, September 25th, 2016
// Cheers!

// ----- boilerplate -----
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char myString[80] = "ComputerScience";
  char yourString[80];
  char* aString;

  // yourString = myString;
  // strncpy(aString,myString,80);
  
  aString = myString; // make a copy?
  strncpy(yourString, myString, 80); // make a copy?
  cout << aString << endl;
  cout << yourString << endl;
 
  myString[0] = '*'; // which one actually made a copy?
  cout << aString << endl;
  cout << yourString << endl;



  return 0;
}
/*void read(const char filename[], int* n, double numbers[], string items[]) {
   
   ifstream infile(filename);

   *n = 0; // no items so far

   // keep going until input is done
   while (!infile.fail()) {
      // try to read one line
      infile >> numbers[*n] >> items[*n];

      // increase counter, but only if not yet failed
      if (!infile.fail())
         *n = (*n) + 1;
   }

   infile.close();
}

// argv[1] is the double factor
// argv[2] is the name of the input recipe text file
int main(int argc, char* argv[]) {
   
   double factor = atof(argv[1]);
   
   double numbers[100];
   string items[100];
   int item_count;
   
   read(argv[2], &item_count, numbers, items);
   
   // multiply and output
   for (int i=0; i<item_count; i++){
      cout << numbers[i]*factor << " " << items[i] << endl;
   }

   return 0;
}*/
