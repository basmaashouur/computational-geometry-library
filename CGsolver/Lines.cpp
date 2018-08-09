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
void Lines::pointSlopeToLine(point p, double m, line &l)
{
	l.a = -m; // always -m
	l.b = 1;  // always 1
	l.c = -((l.a * p.x) + (l.b * p.y));
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
	cout << "1- Check Parallel Lines\n\n";
	line l1, l2; bool check;
	cout << "Enter the first line\n";
	l1 = scanLine();
	cout << "Enter the second line\n";
	l2 = scanLine();
	check = areParallel(l1, l2);
	if (check)cout << "The two lines are Parallel\n";
	else cout << "The two lines are not Parallel\n";
}

bool Lines::areSame(line l1, line l2)
{
	// also check coefficient c
	return areParallel(l1 , l2) && (fabs(l1.c - l2.c) < EPS);
}
void Lines::areSame()
{
	cout << "2- Check Same Lines\n\n";
	line l1, l2; bool check;
	cout << "Enter the first line\n";
	l1 = scanLine();
	cout << "Enter the second line\n";
	l2 = scanLine();
	check = areSame(l1, l2);
	if (check)cout << "The two lines are the Same\n";
	else cout << "The two lines are not the Same\n";
}

bool Lines::areIntersect(line l1, line l2, point &p)
{
	if (areParallel(l1, l2)) return false;
	// solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else  p.y = -(l2.a * p.x + l2.c);
	return true;

}
void Lines::areIntersect()
{
	cout << "3- Find if two Lines intersect\n\n";
	point p; line l1, l2; bool check;
	cout << "Enter the first line\n";
	l1 = scanLine();
	cout << "Enter the second line\n";
	l2 = scanLine();
	check = areIntersect(l1, l2, p);
	if (check)cout << "The two lines intersect in point ("
		               << p.x << ", " << p.y << "\n";
	else cout << "The two lines does not intersect\n";
}

void Lines::closestPoint(line l, point p, point &ans)
{
	line perpendicular;  // perpendicular to l and pass through p
	if (fabs(l.b) < EPS)
	{	// special case 1: vertical line
		//y of line and point is the same
		ans.x = -(l.c); ans.y = p.y; return;
	}

	if (fabs(l.a) < EPS)
	{	// special case 2: horizontal line;
		//x of line and point is the same
		ans.x = p.x; ans.y = -(l.c); return;
	}
	// normal line
	pointSlopeToLine(p, 1 / l.a, perpendicular);
	areIntersect(l, perpendicular, ans);

}
void Lines::closestPoint()
{
	cout << "4- Find Closet Point to a Line\n\n";
	line l; point p, ans;
	cout << "Enter the line\n";
	l = scanLine();
	cout << "Enter the point\n";
	cin >> p.x >> p.y;
	closestPoint(l, p, ans);
	cout << "The closet point from a line and a point is ("
	     << ans.x << ", " << ans.y << "\n";
}
double Lines::angle(point a, point o, point b)
{
	vec oa = points1.toVec(o, a), ob = points1.toVec(o, b);
	return acos(points1.dot(oa, ob) / sqrt(points1.norm_sq(oa) * points1.norm_sq(ob)));
}
void Lines::angle()
{
	cout << "5- Find the angle of two lines\n\n";
	cout << "Enter the two rays in points form.\n"
	     << "Three points can make a two rays that have the same beginning point";
	point a, o, b;
	cout << "Enter the First Point\n";
	cin >> a.x >> a.y;
	cout << "Enter the Second Point\n";
	cin >> o.x >> o.y;
	cout << "Enter the Third Point\n";
	cin >> b.x >> b.y;
	cout << "The angle between those two lines is "
	     << points1.RAD_to_DEG(angle(a, o, b)) << "° \n";
}