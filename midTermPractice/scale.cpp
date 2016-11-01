//Author: Samuel Resendez
// Programming midterm Prep
// saresend@usc.edu

/* ---- imports and boilerplate ---- */
#include <iostream>
#include <fstream>

using namespace std;

/* ------ method protoypes ------- */
void read(const char filename[], int* n, double numbers[], string items[]);


int main(int argc, char** argv) {

  ifstream ifile (argv[2]);
  if(argc < 2) {
    cout << "No arguments given!" << endl;
    return 1;
  }
  int count = 0;
  double numbers[100];
  string items[100];
  read(argv[2],&count,numbers,items); 

  return 0;
}
void read(const char filename[],int* n,double numbers[], string items[]) {
  ifstream ifile(filename);
  char buf[80];
  while(!ifile.fail()) {
    ifile >> buf;
      if(ifile.fail()) {
	break;
      }
      if(atoi(buf) == 0) {
	string str = buf;
	items[*n] = str;
      }
      else {
	double num = atof(buf);
	items[*n] = num;
      }
    (*n)++;
    
    cout << *n << endl;
    cout << buf << endl;
    
  }  
}
