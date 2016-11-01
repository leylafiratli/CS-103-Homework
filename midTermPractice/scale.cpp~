//Author: Samuel Resendez
// Programming midterm Prep
// saresend@usc.edu

/* ---- imports and boilerplate ---- */
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

  ifstream ifile (argv[2]);
  if(argc < 2) {
    cout << "No arguments given!" << endl;
    return 1;
  }
  float scaleFactor = atof(argv[1]);
  while(!ifile.fail()) {
    char token[80];
    ifile >> token;
    float thing = atof(token);
    if(thing != 0) {
      cout << thing * scaleFactor << " ";
    }
    else {
      cout << token << endl;
    }
  }



  

  return 0;
}
