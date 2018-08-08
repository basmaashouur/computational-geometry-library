# Computational Geometry Codes

Table of Contents
================= 
 - [Points](#points)
   + [Points Declaration](#points-declaration)
   + [Euclidean Distance](#euclidean-distance)
   + [Point Rotation](#point-rotation)
   + [Reflection Point](#reflection-point)
   + [Distance To Line](#distance-to-line)
   + [Distance To Line Segment](#distance-to-line-segment)
   + [Collinear](#collinear)
   + [Counter Clockwise](#counter-clockwise)
   + [Point On Line Segment](#point-on-line-segment)
   + [Point On Line](#point-on-line)
   + [Point On Ray](#point-on-ray)
- [Vectors](#vectors)
   + [Vector Declaration](#vector-declaration)
   + [Point To Vector](#point-to-vector)
   + [Scale Vector](#scale-vector)
   + [Translate Point](#translate-point)
   + [Dot Product](#dot-product)
   + [Cross Product](#cross-product)
   + [Normalize](#normalize)
 - [Lines](#lines)
   + [Line Declaration](#line-declaration)
   + [Points To Line](#points-to-line)
   + [Point To Line](#point-to-line)
   + [Parallel Lines](#parallel-lines)
   + [Same Lines](#same-lines)
   + [Intersect Lines](#intersect-lines)
   + [Closet Point To Line](#closet-point-to-line)
   + [Two Lines Angle](#two-lines-angle)
 - [Segments](#segments)
   + [Intersect Lines Segment](#intersect-lines-segment)
 - [Triangles](#triangles)
 - [Rectangles](#rectangles)
 - [Circles](#circles)
 - [Quadlitrals](#quadlitrals)
 - [Polygons](#polygons)
     
   
## Points
### Points Declaration
- If no mush precision needed use this struct
```cpp
struct point_i
{
	int x, y;
	point_i() { x = y = 0; }
	point_i(int _x, int _y) : x(_x), y(_y) {}
};

int main()
{
	point_i p1; // x = 0 y = 0
	point_i p2(1, 2); // x = 1, y = 2

	vector<point_i> P; // vector of points
	P.push_back(point_i(2, 2));
	cout << P[0].x << " " << P[0].y << endl; // print 2 2

	return 0;
}
```

- If more precision is needed then use this struct
```cpp
#define EPS 1e-9

struct point
{
	double x, y;

	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}

	// override less than operator
	bool operator < (point other) const
	{
		if (fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}

	// use EPS (1e-9) when testing equality of two floating points
	bool operator == (point other) const
	{ return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));}

};


int main()
{
	point p1, p2; // x = 0.0 y = 0.0
	point p3(1, 2); // x = 1.0 y = 2.0
	printf("%d %d\n", p1 == p2, p1 == p3); // print 1 0

	vector<point> P;
	P.push_back(point(2, 2));
	cout << P[0].x << " " << P[0].y << endl; // print 2 2
	sort(P.begin(), P.end()); // comparison operator is defined above
	
	return 0;
}

```

### Euclidean Distance
- Don't forget the point struct to insert it above that code
```cpp
double dist(point p1, point p2)
{
	// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main()
{
	point p1(5, 6), p2(1, 10);
	cout << dist(p1, p2) << endl;
	return 0;
}
```
### Point Rotation
- We can rotate a point by angle θ counter clockwise around origin (0, 0) by the following code, 
**Insert point code struct above it**
```cpp
#define PI acos(-1.0) 
// important constant; alternative #define PI (2.0 * acos(0.0))

// Angles convertion from 360 to rad
double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

point rotate(point p, double theta)
{
	double rad = DEG_to_RAD(theta);
	return point(p.x * cos(rad) - p.y * sin(rad),
	             p.x * sin(rad) + p.y * cos(rad));
}

```
### Reflection Point
-
```cpp
```
### Distance To Line
- Two points a and b (a and b must be different) to make a line, find the closet point to line
```cpp
vec toVec(point a, point b){return vec(b.x - a.x, b.y - a.y);}

point translate(point p, vec v){return point(p.x + v.x , p.y + v.y);}

vec scale(vec v, double s){return vec(v.x * s, v.y * s);} 

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double dist(point p1, point p2){return hypot(p1.x - p2.x, p1.y - p2.y);}

double distToLine(point p, point a, point b, point &c)
{
	// formula: c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);
}
```
### Distance To Line Segment
- Put all the functions of Distance to line, find the closet point to line segment
```cpp
double distToLineSegment(point p, point a, point b, point &c)
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

```

### Collinear
- Returns true if point r is on the same line as the line pq
```cpp
#define EPS 1e-9
vec toVec(point a, point b) {return vec(b.x - a.x, b.y - a.y);}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool collinear(point p, point q, point r) 
{
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

```
### Counter Clockwise
- Returns true if point r is on the left side of line pq
```cpp
vec toVec(point a, point b) {return vec(b.x - a.x, b.y - a.y);}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r)
{
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

```
### Point On Line Segment
- Check and see if point p1 is on the line segment s1 and s2
```cpp
bool pointOnLineSegment(point p1, point s1, point s2)
{
	// not inside it
	if ((s1 < p1 && s2 < p1) || (p1 < s1 && p1 < s2))
		return false;
	return true;
}

// or

bool pointOnSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
	        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}
```
### Point On Line
-
```cpp
```
### Point On Ray
-
```cpp
```
## Vectors
### Vector Declaration
- Vector is not the same as stl vector
```cpp
struct vec
{
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};
```
### Point To Vector
- Convert 2 points to vector a->b
```cpp
vec toVec(point a, point b){return vec(b.x - a.x, b.y - a.y);}
```
### Scale Vector
- Nonnegative s = <1 .. 1 .. >1
```cpp
vec scale(vec v, double s){return vec(v.x * s, v.y * s);} 
```
### Translate Point
-  Translate p according to v
```cpp
point translate(point p, vec v) {return point(p.x + v.x , p.y + v.y);}
```
### Dot Product
```cpp
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
```
### Cross Product
```cpp
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
```
### Normalize
```cpp
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
```

## Lines
### Line Declaration
```cpp
// ax + by + c = 0;
struct line { double a, b, c; }; 
// y = mx + c; m is the slop
struct line2 { double m, c; };
```
### Points To Line
- Using the equation ax + by + c = 0
```cpp
#define EPS 1e-9
void pointsToLine(point p1, point p2, line &l)
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
```
- Using the equation y = mx + c
```cpp
#define EPS 1e-9
#define INF 1e9
int pointsToLine2(point p1, point p2, line2 &l)
{
	if (abs(p1.x - p2.x) < EPS)
	{	//  vertical line
		l.m = INF; // means undfined
		l.c = p1.x;
		return 0;   // we need this return variable to differentiate result
	}
	else
	{
		l.m = (double)(p1.y - p2.y) / (p1.x - p2.x);
		l.c = p1.y - l.m * p1.x;
		return 1;
	}
}
```
### Point To Line
- Have a slope and a point
```cpp
void pointSlopeToLine(point p, double m, line &l) 
{
	l.a = -m; // always -m
	l.b = 1;  // always 1
	l.c = -((l.a * p.x) + (l.b * p.y));
} 
```
### Parallel Lines
- Have the same slope and have different intercepts
```cpp
#define EPS 1e-9
bool areParallel(line l1, line l2)
{	// check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
```
### Same Lines
```cpp
#define EPS 1e-9
bool areSame(line l1, line l2)
{	// also check coefficient c
	return areParallel(l1 , l2) && (fabs(l1.c - l2.c) < EPS);
}
```
### Intersect Lines
- Returns true (+ intersection point) if two lines are intersect
```cpp
#define EPS 1e-9
bool areIntersect(line l1, line l2, point &p)
{
	if (areParallel(l1, l2)) return false;
	// solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else  p.y = -(l2.a * p.x + l2.c);
	return true;
}

```

### Intersect Lines Segment
- 
```cpp
bool pointOnSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
	        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;
	return false;
}

int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	if (o1 != o2 && o3 != o4) return true;
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
	return false;
}
```
### Closet Point To Line
- We have 3 cases Vertical, Horizontal or Normal line
```cpp
bool areParallel(line l1, line l2)
{
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areIntersect(line l1, line l2, point &p)
{
	if (areParallel(l1, l2)) return false;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else  p.y = -(l2.a * p.x + l2.c);
	return true;
}
void pointSlopeToLine(point p, double m, line &l)
{
	l.a = -m;
	l.b = 1;
	l.c = -((l.a * p.x) + (l.b * p.y));
}
void closestPoint(line l, point p, point &ans)
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
```
### Two Lines Angle
- The angle between two lines
```cpp
#define PI acos(-1.0)

vec toVec(point a, point b) {return vec(b.x - a.x, b.y - a.y);}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) 
{  // returns angle aob in rad
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

```
- If I have only two corners (upper left and lower right corners) of the rectangle, I can find the other two
```cpp
vector<point> P;
double x1, y1, x3, y3;
cin >> x1 >> y1 >> x3 >> y3;
P.push_back(point(x1,y1)); // upper left corner
P.push_back(point(x3,y1)); // upper right corner
P.push_back(point(x3,y3)); // lower right corner
p.push_back(point(x1,y3)); // lower left corner
```
## Segments
## Triangles
## Rectangles
## Circles
## Quadlitrals
## Polygons
