#include <iostream>
#include <cmath>

using namespace std;

// Begin implementation here
int main() {

// defining necessary variables
	int twoCount = 0;
	int threeCount = 0;
	int userInput;
	string yesOrNo = "No";

// Take input 
	cout << "Enter a positive integer: ";
	cin >> userInput;

//Begin algorithm
	while(userInput > 1) {
		if(userInput % 3 == 0) {
			userInput /= 3;
			threeCount += 1;
			if(userInput == 1){
				yesOrNo = "Yes";
				break;
			}
		}if(userInput % 2 == 0) {
			userInput /= 2;
			twoCount += 1;
			if(userInput == 1) {
				yesOrNo = "Yes";
				break;
			}
		} if(userInput % 2 != 0 && userInput % 3 != 0){
			break;
		}
	}



// output
	cout << yesOrNo << endl;
	if(yesOrNo == "Yes") {
		cout << "Two's: " << twoCount << endl;
		cout << "Three's: " << threeCount << endl;
	}

	return 0;
}