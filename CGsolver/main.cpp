#include "Tools.h"
#include "Points.h"
#include "Lines.h"
#include "Segments.h"
#include "Rectangle.h"
#include "Triangles.h"
#include "Circles.h"
#include "Quadlitrals.h"
#include "Polygons.h"

string choice;
Tools tool;

void scanShape();

void points()
{
	Points points1;
	cout << "0- Back                                                     --> enter 0\n";
	cout << "1- Find Point Rotation                                      --> enter 1\n";
	cout << "2- Find Euclidean Distance between two Points               --> enter 2\n";
	cout << "3- Find the closet Point to a Point that is on a Line       --> enter 3\n";
	cout << "4- Find the closet Point to a Point that is on a Segment    --> enter 4\n";
	cout << "5- Find if Points are Collinear                             --> enter 5\n";
	cout << "6- Find if Point is on a Line                               --> enter 6\n";
	cout << "7- Find if Point is on a Segment                            --> enter 7\n";
	//cout << "8- Find if Point is on a Ray                                --> enter 8\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")
	{
		scanShape();
	}
	else if (choice == "1")
	{
		points1.rotate();
		tool.makeEndl();
		points();
	}
	else if (choice == "2")
	{
		points1.dist();
		tool.makeEndl();
		points();
	}
	else if (choice == "3")
	{
		points1.distToLine();
		tool.makeEndl();
		points();
	}
	else if (choice == "4")
	{
		points1.distToLineSegment();
		tool.makeEndl();
		points();
	}
	else if (choice == "5")
	{
		points1.collinear();
		tool.makeEndl();
		points();
	}
	else if (choice == "6")
	{
		points1.pointOnLine();
		tool.makeEndl();
		points();
	}
	else if (choice == "7")
	{
		points1.pointOnLineSegment();
		tool.makeEndl();
		points();
	}
	/*
	else if (choice == "8")
	{
		points1.pointOnRay();
		tool.makeEndl();
		points();
	}*/
	else
	{
		tool.wrongChoice();
		points();
	}

}

void lines()
{
	Lines lines1;
	cout << "0- Back                          --> enter 0\n";
	cout << "1- Check Parallel Lines          --> enter 1\n";
	cout << "2- Check Same Lines              --> enter 2\n";
	cout << "3- Check Intersect Lines         --> enter 3\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")
	{
		scanShape();
	}
	else if (choice == "1")
	{
		lines1.areParallel();
		tool.makeEndl();
		lines();
	}
	else if (choice == "2")
	{
		lines1.areSame();
		tool.makeEndl();
		lines();
	}
	else if (choice == "3")
	{
		lines1.areIntersect();
		tool.makeEndl();
		lines();
	}
	else
	{
		tool.wrongChoice();
		lines();
	}
}

void segments()
{
	Segments seg;
	cout << "0- Back             --> enter 0\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")
	{
		scanShape();
	}
	else if (choice == "1")
	{

	}
	else
	{
		tool.wrongChoice();
		segments();
	}
}

void rectangles()
{
	Rectangle rec;
	cout << "0- Back                                      --> enter 0\n";
	cout << "1- Area and Perimeter                        --> enter 1\n";
	cout << "2- Check Rechtangles Overlap                 --> enter 2\n";
	cout << "3- Check Segments Make Rectangle             --> enter 3\n";
	cout << "4- Check if a Point is Inside a Rectangle    --> enter 4\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")
	{
		scanShape();
	}
	else if (choice == "1")
	{
		rec.areaAndPerimeter();
		tool.makeEndl();
		rectangles();
	}
	else if (choice == "2")
	{
		rec.overlapRectangles();
		tool.makeEndl();
		rectangles();
	}
	else if (choice == "3")
	{
		rec.segmentsMakeRectangle();
		tool.makeEndl();
		rectangles();
	}
	else if (choice == "4")
	{
		rec.pointInsideRectangle();
		tool.makeEndl();
		rectangles();
	}
	else
	{
		tool.wrongChoice();
		rectangles();
	}
}

void triangles()
{
	Triangles tri;
	cout << "0- Back              --> enter 0\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")
	{
		scanShape();
	}
	else if (choice == "1")
	{

	}
	else
	{
		tool.wrongChoice();
		triangles();
	}
}

void circles()
{
	Circles cir;
	cout << "0- Back            --> enter 0\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")
	{
		scanShape();
	}
	else if (choice == "1")
	{

	}
	else
	{
		tool.wrongChoice();
		circles();
	}

}

void quadlitrals()
{
	Quadlitrals quad;
	cout << "0- Back             --> enter 0\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")
	{
		scanShape();
	}
	else if (choice == "1")
	{

	}
	else
	{
		tool.wrongChoice();
		quadlitrals();
	}

}

void polygons()
{
	Polygons pol;
	cout << "0- Back          --> enter 0\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")
	{
		scanShape();
	}
	else if (choice == "1")
	{

	}
	else
	{
		tool.wrongChoice();
		polygons();
	}

}

void scanShape()
{
	cout << "0- Exit         --> enter 0\n";
	cout << "1- Points       --> enter 1\n";
	cout << "2- Lines        --> enter 2\n";
	cout << "3- Segments     --> enter 3\n";
	cout << "4- Rectnagles   --> enter 4\n";
	cout << "5- Triangles    --> enter 5\n";
	cout << "6- Circles      --> enter 6\n";
	cout << "7- Quadlitrals  --> enter 7\n";
	cout << "8- Polygons     --> enter 8\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0") {}
	else if (choice == "1") {points();}
	else if (choice == "2") {lines();}
	else if (choice == "3") {segments();}
	else if (choice == "4") {rectangles();}
	else if (choice == "5") {triangles();}
	else if (choice == "6") {circles();}
	else if (choice == "7") {quadlitrals();}
	else if (choice == "8") {polygons();}
	else
	{
		tool.wrongChoice();
		scanShape();
	}
}
int main()
{
	scanShape();
	return 0;
}

