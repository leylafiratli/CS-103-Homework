#include <iostream>
#include <algorithm>
using namespace std;

// Begin Implementation // 
int main()
{
	int red,green,blue;
	cout << "please enter red Value: ";
	cin >> red;
	cout << "please enter green value: ";
	cin >> green;
	cout << "please enter blue value: ";
	cin >> blue;
	double white = max(red/255.0,green/255.0);
	white = max(white,blue/255.0);

	double cyan = (white - red/255.0)/white;

	double magenta = (white - green/255.0)/white;

	double yellow = (white - blue/255.0)/white;

	double black = 1 - white;
   // Enter your code here
   
   cout << "cyan: " << cyan << endl;
   cout << "magenta: " << magenta << endl;
   cout << "yellow: " << yellow << endl;
   cout << "black: " << black << endl;
   
   
   return 0;
}
