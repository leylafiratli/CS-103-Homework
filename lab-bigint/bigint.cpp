/* 
Author: Samuel Resendez
Class: CSCI 103
Assignment: Lab, V for Vector
Email: saresend@usc.edu
Cheers!
*/

/* -----imports ------- */
#include <iostream>
#include <string>
#include <vector>
#include "bigint.h"
#include <stdexcept>

using namespace std;

/* ---- begin declarations ---- */

BigInt::BigInt(string s, int base) {
	bigBoyBase = base;
	for(int i = s.size()-1; i >=0; i--) {
		char c = s.at(i);
		if((int) c - 48 <= 9) {
			numberVec.push_back((int) c - 48);
		}
		else{
			numberVec.push_back((int) c - 55);
		}
	}
}


BigInt::BigInt(string s) {
	bigBoyBase = 10;
	for(int i = s.size()-1; i >=0; i--) {
		char c = s.at(i);
		if(int(c) - 48 <= 9 ) {
			numberVec.push_back((int) c - 48);
		}
		else{
			numberVec.push_back((int) c - 55);
		}
	}
}
string BigInt::to_string() {
	string valueString = "";
	for(int i = numberVec.size()-1; i >=0 ;i--) {
		if(numberVec[i] + 48 <= 57) {
			valueString += (char)(numberVec[i] + 48);
		}
		else {
			valueString += (char)(numberVec[i] + 55);
		}
		
	}
	for(int i = 0; i < valueString.size(); i++) {
		if(valueString[i] != '0') {
			break;
		}
		else {
			valueString[i] = (char)NULL;
		}
	}
	return valueString;
}
void BigInt::add(BigInt b) {

	if(b.bigBoyBase != bigBoyBase) {
		throw runtime_error("Error - different bases");
	}
	else {
		//numberVec(ones, tens, hundreds, etc...)
		for(int i = 0; i<numberVec.size() || i < b.numberVec.size(); i++) {
			if(i < numberVec.size() && i<b.numberVec.size()) {
				int total = numberVec[i] + b.numberVec[i];
				int valToLeave = total % bigBoyBase;
				int remain = total / bigBoyBase;
				numberVec[i] = valToLeave;

				if( i+1 < numberVec.size()) {
					numberVec[i+1] += remain;
				}
				else if(remain >= 0){
					numberVec.push_back(remain);
				}
			}
			else if(i >= b.numberVec.size()) {
				break;
			}
			else if(i >= numberVec.size()) {
				numberVec.push_back(b.numberVec[i]);
			}
		}
	}

}
