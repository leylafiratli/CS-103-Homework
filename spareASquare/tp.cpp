/*********************************************************
 * File name : tp.cpp
 * Author    : 
 * Date      : 
 * Purpose   : Simulates the toilet-paper problem
 * Notes     : None
 *********************************************************/

#include <iostream>   // Basic I/O => cin, cout, etc.
#include <cstdlib>    // Other helpful functions => rand(), RANDMAX

using namespace std;

// Prototype/declaration of a function that returns a
// uniform random number between [0,1]
double rand_uniform();

// Prototype/declaration of a function that will perform a single
// simulation of two rolls of paper and users
// Returns the number of squares left on the non-empty roll
int single_sim(int N, double p);

int main(int argc, char *argv[])
{
	srand(time(0)); //set seed

  	int N;                // initial number of squares on each roll

 	double p;             // probability of a big-chooser

  	int sims;             // number of trials for our simulation

  	cout << "Please enter number of squares, probablility, and number of simulations : ";
  	cin >> N >> p >> sims;
  	long totalCounter = 0;
  // Add your code here
  	for(int i = 0; i < sims; i++) {
  		totalCounter += single_sim(N,p);
  	}
  	cout << "Average: " << totalCounter / (double)sims << endl;

  // Be sure you produce an output of the form:
  //    Average: 1.2314
  // where the number is the correct average
  return 0;
}

// return the number of squares on the non-empty roll
//  for this simulation of the problem
int single_sim(int N, double p)
{
	int bigRoll = N;
	int smallRoll = N;
	while(bigRoll > 0 && smallRoll > 0) {
		if(bigRoll == smallRoll) {
			bigRoll--;
			continue;
		}
		double probability = rand_uniform();
		if(probability > p) {
			bigRoll--;
		} 
		else if(probability <= p) {
			smallRoll--;
		} 
	}
	return bigRoll + smallRoll;
}

// returns a uniformly-distributed number in the range [0,1]
//  The caller can use the return result to then determine
//  if it should treat it as a big- or little-chooser by 
//  also using the p parameter. This code only needs to 
//  produce a random number in the range [0,1]
double rand_uniform()
{
	return (double(rand())/(RAND_MAX));

}
