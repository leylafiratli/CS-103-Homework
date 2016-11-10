/* Author: Samuel Resendez
Class: CSCI 103
Lab - Vectors
saresend@usc.edu
Cheers!
*/
//Import statements

#include "bigint.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	BigInt a = BigInt("102030");
	int whoCares = a.numberVec[2];
	cout << whoCares << endl;

	return 0;
}