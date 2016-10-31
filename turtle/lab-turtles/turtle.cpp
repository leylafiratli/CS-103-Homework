//Author: Samuel Resendez
//CS 103: Goodney
//Lab: Turtles and lines
//Cheers!!!!

/* ---------- imports -----------*/
#include "turtle.h"
#include "draw.h"
#include <iostream>
#include <cmath>


using namespace std;
/* --------- end --------------*/
//Directives
#define PI 3.1415926

// Method declarations:

void Turtle::move(double dist) {

	//Calculating Cartesian deltas for the line (with the conversion to radians as well)
	double horizValue = dist*cos(orientation*PI/180);
	double vertValue = dist*sin(orientation*PI/180);
	if(isDrawing) {
		draw::setcolor(color);
		draw::line(xPosition,yPosition,xPosition+horizValue,yPosition+vertValue);
	}

	//Updating turtle position
	xPosition = xPosition+horizValue;
	yPosition = yPosition+vertValue;
}
void Turtle::turn(double deg) {
	orientation += deg;
}


void Turtle::setColor(Color c) {
	color = c;
}
void Turtle::off() {
	isDrawing = false;
}
void Turtle::on() {
	isDrawing = true;
}


//Constructor is here!
Turtle::Turtle(double xPos, double yPos, double orient) {

	color = draw::BLACK;
	isDrawing = true;
	xPosition = xPos;
	yPosition = yPos;
	orientation = orient;
}