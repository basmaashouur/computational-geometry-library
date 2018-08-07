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
	cout << "Back                                            --> enter 0\n";
	cout << "Point Rotation                                  --> enter 1\n";
	cout << "Find Euclidean Distance betwenn two points      --> enter 2\n";
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
	else
	{
		tool.wrongChoice(choice);
		points();
	}

}

void lines()
{
	Lines lines1;
	cout << "Back                          --> enter 0\n";
	cout << "Check Parallel Lines          --> enter 1\n";
	cout << "Check Same Lines              --> enter 2\n";
	cout << "Check Intersect Lines         --> enter 3\n";
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
		tool.wrongChoice(choice);
		lines();
	}
}

void segments()
{
	Segments seg;
	cout << "Back             --> enter 0\n";
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
		tool.wrongChoice(choice);
		segments();
	}
}

void rectangles()
{
	Rectangle rec;
	cout << "Back                                      --> enter 0\n";
	cout << "Area and Perimeter                        --> enter 1\n";
	cout << "Check Rechtangles Overlap                 --> enter 2\n";
	cout << "Check Segments Make Rectangle             --> enter 3\n";
	cout << "Check if a Point is Inside a Rectangle    --> enter 4\n";
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
		tool.wrongChoice(choice);
		rectangles();
	}
}

void triangles()
{
	Triangles tri;
	cout << "Back              --> enter 0\n";
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
		tool.wrongChoice(choice);
		triangles();
	}
}

void circles()
{
	Circles cir;
	cout << "Back            --> enter 0\n";
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
		tool.wrongChoice(choice);
		circles();
	}

}

void quadlitrals()
{
	Quadlitrals quad;
	cout << "Back             --> enter 0\n";
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
		tool.wrongChoice(choice);
		quadlitrals();
	}

}

void polygons()
{
	Polygons pol;
	cout << "Back          --> enter 0\n";
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
		tool.wrongChoice(choice);
		polygons();
	}

}

void scanShape()
{
	cout << "Exit         --> enter 0\n";
	cout << "Points       --> enter 1\n";
	cout << "Lines        --> enter 2\n";
	cout << "Segments     --> enter 3\n";
	cout << "Rectnagles   --> enter 4\n";
	cout << "Triangles    --> enter 5\n";
	cout << "Circles      --> enter 6\n";
	cout << "Quadlitrals  --> enter 7\n";
	cout << "Polygons     --> enter 8\n";
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

