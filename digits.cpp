#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int userInput;
	cout << "Please enter a number between 0 and 999: ";
	cin >> userInput;

	int OnesDigit = userInput % 10;
	int tensDigit = (userInput / 10) % 10;
	int thirdDigit = (userInput /100) % 10;

	cout << "Ones digit is: " << OnesDigit << endl;
	cout << "Tens digit is: " << tensDigit << endl;
	cout << "Hundreds digit is: " << thirdDigit << endl;
}