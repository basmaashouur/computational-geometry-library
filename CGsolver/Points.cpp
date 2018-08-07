#include "Points.h"


point::point() { x = y = 0.0; };
point::point(double _x, double _y) : x(_x), y(_y) {};

//Points::Points() {}

point Points::scanPoint()
{
	cout << "Enter a point\n";
	point p1;
	cin >> p1.x >> p1.y;
	return p1;
}

double Points::dist(point p1, point p2)
{
	return hypot(p1.x - p2.x, p1.y - p2.y);
}
void Points::dist()
{
	point p1 = scanPoint();
	point p2 = scanPoint();
	double ecdist = dist(p1, p2);
	cout << "The Euclidean Distance between those two points is " << ecdist << endl;
}

// Angles convertion from 360 to rad
double Points::DEG_to_RAD(double d) { return d * PI / 180.0; }

double Points::RAD_to_DEG(double r) { return r * 180.0 / PI; }

point Points::rotate(point p, double theta)
{
	double rad = DEG_to_RAD(theta);
	return point(p.x * cos(rad) - p.y * sin(rad),
	             p.x * sin(rad) + p.y * cos(rad));
}
void Points::rotate()
{
	point ans, p1 = scanPoint();
	cout << "Enter the rotation theta \n";
	double theta; cin >> theta;
	ans = rotate(p1, theta);
	cout << "The point (" << p1.x << "," << p1.y << ") after rotation by "
	     << theta << "° is now point (" << ans.x << "," << ans.y << ")\n";

}
