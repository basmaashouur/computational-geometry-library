#pragma once
#include "Tools.h"
#include "Points.h"

// ax + by + c = 0;
struct line { double a, b, c; };

class Lines
{
public:
	string choice;

	// Constructor
	//Lines() ;
	// Function to convert two points to a standad form line
	void pointsToLine(point p1, point p2, line &l);
	//Function to convert the line intercept form to a standard form
	void line2ToLine(double m, double c, line &l);
	// Function to know which type of a line gonna scan then scan it
	line scanLine();
	// Function to check Parallel Lines
	bool areParallel(line l1, line l2);
	void areParallel();
	// Function to check same lines
	bool areSame(line l1, line l2);
	void areSame();
	// Fucntion to check Intersect Lines
	bool areIntersect(line l1, line l2, point &p);
	void areIntersect();
private:
	Tools tool;
};