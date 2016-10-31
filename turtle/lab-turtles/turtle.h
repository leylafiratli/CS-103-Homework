/*
Author: Samuel Resendez
CS 103 - Goodney
saresend@usc.edu
October 20th, 2016
Cheers!
*/

// ---- import statements ----
#include "draw.h"

//////////////////////////////

class Turtle {
	private:
		bool isDrawing;
		Color color;
		double xPosition;
		double yPosition;
		double orientation;

	public:
		Turtle(double,double,double);
		void move(double);
		void turn(double);
		void setColor(Color);
		void off();
		void on();
};