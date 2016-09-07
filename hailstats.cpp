//Author: Samuel Resendez
//Date: Tuesday, September 6th, 2016

//////Boilerplate ///////
#include <iostream>
#include <cmath>

using namespace std;
/////////////////////////


// ---------------- Begin Implementation --------------- //

//---------- Method Declarations ------------ //
int getLengthOfValue(int); //Given a number, returns the number of loops needed to reach 1


//------------------------------------------- //
int main() {

	// Var declaration //
	int minimum; // Range lower bound
	int maximum; // Range upper bound
 	int currentMinimumLength = 2147483647; //Set to very large,to make sure it gets reset
 	int currentMaximumLength = -1;
 	int minLengthNumber;
 	int maxLengthNumber; 
 	bool isValidRange = true;

 	//Read user Input //
 	cout << "Please enter a min for your range: ";
 	cin >> minimum;
 	cout << "Please enter a max for you range: ";
 	cin >> maximum;

 	//Check to make sure that min is less than max 
 	if(minimum > maximum) {
 		cout << "Invalid input" << endl;
 		isValidRange = false;
 	}
	 if(isValidRange) {
	 	for(int i = minimum;i < maximum; i++) {
	 		int distanceOfValue = getLengthOfValue(i);
	 		if(distanceOfValue < currentMinimumLength) {
	 			currentMinimumLength = distanceOfValue;
	 			minLengthNumber = i;
	 		}
	 		if(distanceOfValue > currentMaximumLength) {
	 			currentMaximumLength = distanceOfValue;
	 			maxLengthNumber = i;
	 		}
	 	}
	 }	

 	//Displaying outputs:
 	if(isValidRange) {
	 	cout << "Minimum Length: " << currentMinimumLength << endl;
	 	cout << "Achieved by: " << minLengthNumber << endl;
	 	cout << "Maximum Length: " << currentMaximumLength << endl; 
	 	cout << "Achieved by: " << maxLengthNumber << endl;
	 }



	return 0;
}

int getLengthOfValue(int number) {
	int counter = 0;
	while(number != 1) {
		counter++;
		if(number % 2 == 0) { //The number is EVEN
			number /= 2;
		}else { //Number is ODD
			number = number * 3 + 1;
		}
	} return counter;
}