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

  //  yourString = myString;
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
