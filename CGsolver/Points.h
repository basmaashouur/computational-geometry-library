#pragma once
#include "Tools.h"


// struct for declaring a point
struct point
{
	double x, y;
	point();
	point(double _x, double _y);
	bool operator < (point other) const; 
};

// Struct for declaring a vector
struct vec
{
	double x, y;
	vec(double _x, double _y);
};
class Points
{
public:

	/*
	Points Functions
	*/

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
	// Function to find the closet Point to a Point that is on a Line
	double distToLine(point p, point a, point b, point &c);
	void distToLine();
	// Function to find the closet Point to a Point that is on a Segment
	double distToLineSegment(point p, point a, point b, point &c);
	void distToLineSegment();
	// Function to find if two Points are Collinear
	bool collinear(point p, point q, point r);
	void collinear();
	// Function to find if Point is on a Line
	void pointOnLine();
	// Function to find if Point is on a Segment
	bool pointOnLineSegment(point p1, point s1, point s2);
	void pointOnLineSegment();
	// Function to find if Point is on a Ray
	bool pointOnRay(point p1, point s1, point s2);
	void pointOnRay();


	/*
	Vector Functions
	*/

	// Convert 2 points to vector a->b
	vec toVec(point a, point b);
	// Scale a vector
	vec scale(vec v, double s);
	// Trnaslate a vector
	point translate(point p, vec v);
	// Dot product
	double dot(vec a, vec b);
	// Cross product
	double cross(vec a, vec b);
	// Normalize a vector
	double norm_sq(vec v);
private:
	Tools tool;
	string choice;

};
