#include "Points.h"

/*
Structs
*/

point::point() { x = y = 0.0; };
point::point(double _x, double _y) : x(_x), y(_y) {};
bool point::operator < (point other) const
{
	if (fabs(x - other.x) > EPS)
		return x < other.x;
	return y < other.y;
}

vec::vec(double _x, double _y) : x(_x), y(_y) {};

/*
Points Functions
*/

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
	cout << "2- Find Euclidean Distance between two Points\n\n";
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
	cout << "1- Find Point Rotation\n\n";
	point ans, p1 = scanPoint();
	cout << "Enter the rotation theta in Degress\n";
	double theta; cin >> theta;
	ans = rotate(p1, theta);
	cout << "The point (" << p1.x << "," << p1.y << ") after rotation by "
	     << theta << "° is now point (" << ans.x << "," << ans.y << ")\n";

}

double Points::distToLine(point p, point a, point b, point &c)
{
	// formula: c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);

}
void Points::distToLine()
{
	cout << "3- Find the closet Point to a Point that is on a Line\n\n";
	point p, a, b, ans;
	p = scanPoint();
	cout << "Enter the line in a Points form, two points make a line\n";
	a = scanPoint();
	b = scanPoint();

	double ecdis = distToLine(p, a, b, ans);
	cout << "The closet Point to that point is ("
	     << ans.x << "," << ans.y << ") and the distance between them is " << ecdis << "\n";

}

double Points::distToLineSegment(point p, point a, point b, point &c)
{
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0)
	{	// closer to a
		c = point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0)
	{	// closer to b
		c = point(b.x, b.y);
		return dist(p, b);
	}
	return distToLine(p, a, b, c);

}
void Points::distToLineSegment()
{
	cout << "4- Find the closet Point to a Point that is on a Segment\n\n";
	point p, a, b, ans;
	p = scanPoint();
	cout << "Enter the line segments in a Points form, two points make a segment\n";
	a = scanPoint();
	b = scanPoint();

	double ecdis = distToLineSegment(p, a, b, ans);
	cout << "The closet Point to that point is ("
	     << ans.x << "," << ans.y << ") and the distance between them is " << ecdis << "\n";

}

bool Points::collinear(point p, point q, point r)
{
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}
void Points::collinear()
{
	cout << "5- Check if Points are Collinear\n\n";
	bool check = true; point p, q, r;
	cout << "Enter the line in a Points form, two points make a line\n";
	p = scanPoint();
	q = scanPoint();
	cout << " Enter the number of points you want to check if they are Collinear\n";
	int n; cin >> n;
	for (int x = 0; x < n; x++)
	{
		r = scanPoint();
		bool temp = collinear(p, q, r);
		if (!temp)check = false;
	}
	if (check)cout << "The points are Collinear\n";
	else cout << "The points are not Collinear\n";
}


void Points::pointOnLine()
{
	cout << "6- Check if Point is on a Line\n\n";
	bool check; point p, q, r;
	r = scanPoint();
	cout << "Enter the line in a Points form, two points make a line\n";
	p = scanPoint();
	q = scanPoint();
	check = collinear(p, q, r);
	if (check)cout << "The point is on the line\n";
	else cout << "The point is not on the line\n";

}

bool Points::pointOnLineSegment(point p1, point s1, point s2)
{
	// not inside it
	if ((s1 < p1 && s2 < p1) || (p1 < s1 && p1 < s2))
		return false;
	return true;

}
void Points::pointOnLineSegment()
{
	cout << "7- Check if Point is on a Segment\n\n";
	point p, a, b; bool check;
	p = scanPoint();
	cout << "Enter the line segments in a Points form, two points make a Line segment\n";
	a = scanPoint();
	b = scanPoint();
	check = pointOnLineSegment(p, a, b);
	if (check)cout << "The point is on the line segment \n";
	else cout << "The point is not on the line segment\n";
}

bool Points::pointOnRay(point p1, point s1, point s2)
{

}
void Points::pointOnRay()
{
	cout << "8- Find if Point is on a Ray\n\n";

}


/*
Vector Functions
*/

vec Points::toVec(point a, point b) {return vec(b.x - a.x, b.y - a.y);}
vec Points::scale(vec v, double s) {return vec(v.x * s, v.y * s);}
point Points::translate(point p, vec v) {return point(p.x + v.x , p.y + v.y);}
double Points::dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double Points::cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
double Points::norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
