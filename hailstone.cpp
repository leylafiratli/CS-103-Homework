// Author: Samuel Resendez
//Date: September 6th, 2016


////Boilerplate Box ///
#include <iostream> ///
#include <cmath>    ///
                    ///
using namespace std;///
///////////////////////


// --------------------- Begin Implementation ----------------- //



int main() {
	//-------------------initializing variables -------------- //
	int userInput;
	int loopCounter = 0; // used for counting number of loops needed to reach 1
// -----------------------------------------------------------//

	//Take user input
	cout << "Please, enter a number: ";
	cin >> userInput;

	while(userInput != 1) {
		loopCounter++;
		if(userInput % 2 == 0) { // If the number is EVEN
			userInput /= 2;

		}
		else { // If the number is ODD
			userInput = userInput * 3 + 1;
		}
		cout << userInput << " ";
	}
	cout << endl;
	cout << "Length: " << loopCounter << endl;






	return 0;
}