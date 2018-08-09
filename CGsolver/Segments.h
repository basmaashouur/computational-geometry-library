#pragma once
#include "Tools.h"
#include "Points.h"

struct segment
{
	point p1, p2;
};

class Segments
{
public:
	segment scanSegment();
	bool areIntersectSeg(segment s1, segment s2, point &p);
	void areIntersectSeg();
private:
	Tools tool;
	Points points1;

};