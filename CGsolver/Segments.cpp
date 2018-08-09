#include "Segments.h"


segment Segments::scanSegment()
{
	point a, b; segment ans;
	cout << "Enter the line segments in Points form, two points make a segment\n";
	a = points1.scanPoint();
	b = points1.scanPoint();
	ans.p1 = a;
	ans.p2 = b;
	return ans;

}
bool Segments::areIntersectSeg(segment s1, segment s2, point &p)
{

}
void Segments::areIntersectSeg()
{
	segment s1, s2; point p; bool check;
	cout << "1- Find if two Segments intersect\n\n";
	cout << "Enter the first Segment\n";
	s1 = scanSegment();
	cout << "Enter the second Segment\n";
	s2 = scanSegment();

	check = areIntersectSeg(s1, s2, p);
	if (check)cout << "The two Segments intersect in point ("
		               << p.x << ", " << p.y << "\n";
	else cout << "The two Segments does not intersect\n";

}