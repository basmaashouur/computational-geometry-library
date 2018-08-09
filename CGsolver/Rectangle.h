#pragma once
#include "Tools.h"
#include "Points.h"
#include "Segments.h"

// struct for declaring the corners of the rectangles
struct recpoints
{
	double x1, y1, x2, y2, x3, y3, x4, y4;
	recpoints();
};


class Rectangle
{
public:

	// Function for taking the corners of the rectangles
	recpoints scanCorners();

	// Function for finding the area and perimeter, return hight aand width
	void areaAndPerimeter(recpoints rec, double &width, double &hight);
	void areaAndPerimeter();

	// Function to find if two rectangles overlap
	void overlapRectangles(recpoints rec1, recpoints rec2);
	void overlapRectangles();

	// Function to check four segments make a rectangle
	void segmentsMakeRectangle(segment s1, segment s2, segment s3,segment s4);
	void segmentsMakeRectangle();
	// Function tocheck if a point is inside a rectangle
	void pointInsideRectangle(recpoints rec1, point p1);
	void pointInsideRectangle();
private:
	Tools tool;
	string choice;
	Points points1;
	Segments seg;

};

