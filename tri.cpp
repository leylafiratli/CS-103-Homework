
///////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cmath>
using namespace std;


#define PI 3.1415926535
//Done with boilerplate stuff

//Method delcarations
int getNumberOfCharsInRow(double,int);

int main() {
	//init vars
	int angle;
	double heightX;
	int numberPerLine;
	double radAngle;

	// prompt user
	cout << "Please enter a value between 15 and 75: ";
	cin >> angle;

	//convert input to radians
	radAngle = angle * M_PI/180;

	for(int i = 0;i <= 31; i++) {
		for(int j = 0; j < getNumberOfCharsInRow(radAngle,i); j++) {
			cout << "*";
		}
		cout << endl;

	}


	return 0;
}
//computes the number of Chars in a row.
int getNumberOfCharsInRow(double radAngle, int rowNum) {
	int numberOfChars = floor(tan(radAngle)*rowNum);
	if(numberOfChars >= 20 && numberOfChars <= 30) {
		numberOfChars = 20;
	}
	return numberOfChars;

}