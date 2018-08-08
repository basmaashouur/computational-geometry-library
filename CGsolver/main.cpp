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
	cout << "5- Check if Points are Collinear                            --> enter 5\n";
	cout << "6- Check if Point is on a Line                              --> enter 6\n";
	cout << "7- Cheeck if Point is on a Segment                           --> enter 7\n";
	//cout << "8- Find if Point is on a Ray                                --> enter 8\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")scanShape();
	else if (choice == "1")points1.rotate();
	else if (choice == "2")points1.dist();
	else if (choice == "3")points1.distToLine();
	else if (choice == "4")points1.distToLineSegment();
	else if (choice == "5")points1.collinear();
	else if (choice == "6")points1.pointOnLine();
	else if (choice == "7")points1.pointOnLineSegment();

	/*
	else if (choice == "8")
	{
		points1.pointOnRay();
		tool.makeEndl();
		points();
	}*/
	else
	{
		tool.wrongChoice(choice);
		points();
	}
	if (choice > "0" && choice < "8")
	{
		tool.makeEndl();
		points();
	}
}

void lines()
{
	Lines lines1;
	cout << "0- Back                         --> enter 0\n";
	cout << "1- Check Parallel Lines         --> enter 1\n";
	cout << "2- Check Same Lines             --> enter 2\n";
	cout << "3- Find if two Lines intersect  --> enter 3\n";
	cout << "4- Find Closet Point to a Line  --> enter 4\n";
	cout << "5- Find the angle of two lines  --> enter 5\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")scanShape();
	else if (choice == "1")lines1.areParallel();
	else if (choice == "2")lines1.areSame();
	else if (choice == "3")lines1.areIntersect();
	else if (choice == "4")lines1.closestPoint();
	else if (choice == "5")lines1.angle();
	else
	{
		tool.wrongChoice(choice);
		lines();
	}
	if (choice > "0" && choice < "6")
	{
		tool.makeEndl();
		lines();
	}
}

void segments()
{
	Segments seg;
	cout << "0- Back             --> enter 0\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")scanShape();
	else if (choice == "1") {}
	else
	{
		tool.wrongChoice(choice);
		segments();
	}
	if (choice > "0" && choice < "1")
	{
		tool.makeEndl();
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
	if (choice == "0")scanShape();
	else if (choice == "1")rec.areaAndPerimeter();
	else if (choice == "2")rec.overlapRectangles();
	else if (choice == "3")rec.segmentsMakeRectangle();
	else if (choice == "4")rec.pointInsideRectangle();
	else
	{
		tool.wrongChoice(choice);
		rectangles();
	}
	if (choice > "0" && choice < "5")
	{
		tool.makeEndl();
		rectangles();

	}
}

void triangles()
{
	Triangles tri;
	cout << "0- Back      --> enter 0\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")scanShape();
	else if (choice == "1") {}
	else
	{
		tool.wrongChoice(choice);
		triangles();
	}
	if (choice > "0" && choice < "2")
	{
		tool.makeEndl();
		triangles();
	}
}

void circles()
{
	Circles cir;
	cout << "0- Back    --> enter 0\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")scanShape();
	else if (choice == "1") {}
	else
	{
		tool.wrongChoice(choice);
		circles();
	}
	if (choice > "0" && choice < "1")
	{
		tool.makeEndl();
		circles();
	}
}

void quadlitrals()
{
	Quadlitrals quad;
	cout << "0- Back      --> enter 0\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")scanShape();
	else if (choice == "1") {}
	else
	{
		tool.wrongChoice(choice);
		quadlitrals();
	}
	if (choice > "0" && choice < "1")
	{
		tool.makeEndl();
		quadlitrals();

	}
}

void polygons()
{
	Polygons pol;
	cout << "0- Back          --> enter 0\n";
	cin >> choice;
	tool.clearScreen();
	if (choice == "0")scanShape();
	else if (choice == "1") {}
	else
	{
		tool.wrongChoice(choice);
		polygons();
	}
	if (choice > "0" && choice < "6")
	{
		tool.makeEndl();
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
		tool.wrongChoice(choice);
		scanShape();
	}
}
int main()
{
	scanShape();
	return 0;
}

