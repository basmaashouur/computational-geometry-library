#include "Lines.h"


void Lines::pointsToLine(point p1, point p2, line &l)
{
	if (fabs(p1.x - p2.x) < EPS)
	{	// vertical line
		l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;
	}
	else
	{
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x); // always -m
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}

}
void Lines::line2ToLine(double m, double c, line &l)
{

}

line Lines::scanLine()
{
   line sline;
	cout << "How you do wanna enter the line?\n";
	cout << "In Standard form ax + by = c                 --> enter 1\n";
	cout << "In Slope-intercept form y = mx + c           --> enter 2\n";
	cout << "In Points form, two points make a line       --> enter 3\n";
	cin >> choice;
	if (choice == "1")
	{
		double a, b, c;
		cout << "Enter the 3 constants A, B and C\n";
		cin >> sline.a >> sline.b >> sline.c;

	}
	else if (choice == "2")
	{
		double m, c;
		cout << "Enter the slope and the y-intercept\n";
		cin >> m >> c;
		line2ToLine(m, c, sline);

	}
	else if (choice == "3")
	{
		point p1, p2;
		cout << "Enter the first point\n";
		cin >> p1.x >> p1.y;
		cout << "Enter the second point\n";
		cin >> p2.x >> p2.y;
		pointsToLine(p1, p2, sline);
	}
	else
	{

	}
	return sline;
}

bool Lines::areParallel(line l1, line l2)
{
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

void Lines::areParallel()
{
	cout << "Enter the first line\n";
	line l1 = scanLine();
	cout << "Enter the second line\n";
	line l2 = scanLine();
	bool check = areParallel(l1, l2);
	if (check)cout << "The two line are Parallel\n";
	else cout << "The two line are not Parallel\n";
}

bool Lines::areSame(line l1, line l2)
{

}
void Lines::areSame()
{
}

bool Lines::areIntersect(line l1, line l2, point &p)
{

}
void Lines::areIntersect()
{
}

