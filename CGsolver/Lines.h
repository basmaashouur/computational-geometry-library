#pragma once
#include "Tools.h"
#include "Points.h"

// ax + by + c = 0;
struct line { double a, b, c; };

class Lines
{
public:

	// Constructor
	//Lines() ;
	// Function to convert two points to a standad form line
	void pointsToLine(point p1, point p2, line &l);
	//Function to convert the line intercept form to a standard form
	void line2ToLine(double m, double c, line &l);
	// Function to convert a point and a slope to a line
	void pointSlopeToLine(point p, double m, line &l);
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
	// Function to find the closet point from a line and point
	void closestPoint(line l, point p, point &ans);
	void closestPoint();
	// Function to find the angle between two lines and returns angle aob in rad
	double angle(point a, point o, point b);
	void angle();
private:
	Tools tool;
	Points points1;
	string choice;
};