//Author: Samuel Resendez
//Date: September 12th, 2016
//CS 103 Homework



// ----- Boilerplate ------
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;
// ---- end Boilerplate -----


// ----- Method Declarations ------ // 
int roll();
void printHistogram(int[21]);





int main() {
  int experiments;
  int recordingTable[21] = {0};
  /* init random seed: */
  srand(time(0));
  // User Input 
  cout << "How many experiments would you like to run?: ";
  cin >> experiments;
  for(int i=0;i<experiments;i++){
    int testValue = roll() + roll() + roll() + roll();
    recordingTable[testValue-4] = recordingTable[testValue-4] + 1;
    }
  printHistogram(recordingTable);

  return 0;
}

int roll() {
  int randomNumber = rand() % 6 + 1;
  return randomNumber;
}
void printHistogram(int counts[21]) {
  for(int i = 0; i <= 20; i++) {
    cout << i + 4 << ":";
    for(int j = 0; j < counts[i]; j++) {
      cout << "X";
    }
    cout << endl;
  }
}
