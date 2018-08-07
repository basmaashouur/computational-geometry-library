#pragma once
#include "Tools.h"


// struct for declaring a point
struct point
{
	double x, y;
	point();
	point(double _x, double _y);
};

class Points
{
public:

	// Constructor
	//Points() ;
	// Function for taking the point
	point scanPoint();
	// Function for finding the Euclidean Distance
	double dist(point p1, point p2);
	void dist();
	// Function to rotate a point by some degree
	double DEG_to_RAD(double d);
	double RAD_to_DEG(double r);
	point rotate(point p, double theta);
	void rotate();
private:
	Tools tool;
	string choice;

};
