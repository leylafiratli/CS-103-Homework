/* Author: Samuel Resendez
CSCI 103 - Classy Turtles
October 22nd, 2016
saresend@usc.edu
Cheers! */


// ---------- imports ---
#include <iostream>
#include "turtle.h"
#include "draw.h"

using namespace std;

// ----- Prototypes --------
void drawGoldenProp(Turtle,int,double); /*(RECURSIVE)*/

// ------- consts-----
#define N 100 // N is the # of increments to make one semicircle
#define PI 3.1415
#define initRadius 50 //Radius of first semicircle (approx.)

/*---------global vars----------*/

int counter = 0; //counter used to measure how many times recursiion happens


int main() {
	
	//Initial draw conditions
	//Adjustable penWidth, but not setrange
	draw::setpenwidth(5);
	draw::setrange(-100,100);

	//Set initial locations of turtles and orientations
	//Probably inadvisable to edit, coordinates are weird
	Turtle tim = Turtle(-99,0,270);
	tim.setColor(draw::RED);

	Turtle matt = Turtle(99,0,90);
	matt.setColor(draw::BLUE);

	Turtle zach = Turtle(0,99,180);
	zach.setColor(draw::GREEN);

	Turtle cody = Turtle(0,-99,0);
	cody.setColor(draw::ORANGE);


	/*N is the number of iterations to generate a semi circle
	  and the radius is the inital radius of the spiral(approximately) */
	drawGoldenProp(tim,N,initRadius);
	drawGoldenProp(matt,N,initRadius);
	drawGoldenProp(zach,N,initRadius);
	drawGoldenProp(cody,N,initRadius);
	
	//Checking how many times recursion happened
	cout << counter << endl;
	return 0;
}

void drawGoldenProp(Turtle tim, int fidelity,double radius) {

	if(radius < 1) { //Base case. Not sure what to do here, tbh.
		counter += 1;
		return;
	}
	else {

		//For added dank memes, uncomment the following line:	
		//fidelity=13; drawGoldenProp(tim,fidelity,radius/1.618);draw::setpenwidth(1);
		
		double totalDistance = PI*radius;

		 //Draws the semi circle
		double angleIncrement = (double)180/fidelity;
		for(int i=0;i<fidelity;i++) {
			tim.move(totalDistance/fidelity);
			tim.turn(angleIncrement);
		}

		//Calls itself for the next semicircle!
		drawGoldenProp(tim,fidelity,radius/1.618);
		
	}
}