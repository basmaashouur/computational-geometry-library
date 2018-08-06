#pragma once
#include "Tools.h"
#include "Points.h"

class Rectangle
{
public:
	string choice;

	// Defualt constructor
	//Rectangle() ;

	// struct for declaring the corners of the rectangles
	struct recpoints
	{
		double x1, y1, x2, y2, x3, y3, x4, y4;
		recpoints();
	};

	// Function for taking the corners of the rectangles
	recpoints scanCorners();

	// Function for finding the area and perimeter
	void areaAndPerimeter();

	// Function to find if two rectangles overlap
	void overlapRectangles();
	void segmentsMakeRectangle();
	void pointInsideRectangle();
private:
	Tools tool;
};

