#include "bigint.h"
#include <iostream>
using namespace std;

// extra test
// expected output:  10000000000000000000000

int main() {

   	BigInt first("DADCAFE", 16); // hexadecimal
	BigInt second("AAABEEF", 16);
	first.add(second);
	cout << first.to_string() << endl;; // prints 185889ED
   return 0;
}
