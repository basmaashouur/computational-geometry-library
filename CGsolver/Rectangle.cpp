#include "Rectangle.h"


//Rectangle::Rectangle() {}

Rectangle::recpoints::recpoints() {};

Rectangle::recpoints  Rectangle::scanCorners()
{
    cout << "How you wanna enter the rectanagle corners?\n\n";
    cout << "Upper*Left********Upper*right\n";
    cout << "*****************************\n";
    cout << "*****************************\n";
    cout << "*****************************\n";
    cout << "*****************************\n";
    cout << "lower*Left********lower*right\n\n";

    cout << "Upper left & Lower right     --> enter 1\n";
    cout << "Upper right & Lower left     --> enter 2\n";
    cout << "All the rectangle corners    --> enter 3\n";
    cin >> choice;
    recpoints points;
    if (choice == "1")
    {
        cout << "Enter the upper left point\n";
        cin >> points.x1 >> points.y1;
        cout << "Enter the lower right point\n";
        cin >> points.x3 >> points.y3;
        points.x2 = points.x3, points.y2 = points.y1;
        points.x4 = points.x1, points.y4 = points.y3;
    }
    else if (choice == "2")
    {
        cout << "Enter the upper right point\n";
        cin >> points.x2 >> points.y2;
        cout << "Enter the lower left point\n";
        cin >> points.x4 >> points.y4;
        points.x1 = points.x4, points.y1 = points.y2;
        points.x3 = points.x2, points.y3 = points.y4;
    }
    else if (choice == "3")
    {
        cout << "Enter the upper left point\n";
        cin >> points.x1 >> points.y1;
        cout << "Enter the upper right point\n";
        cin >> points.x2 >> points.y2;
        cout << "Enter the lower right point\n";
        cin >> points.x3 >> points.y3;
        cout << "Enter the lower left point\n";
        cin >> points.x4 >> points.y4;
    }
    else
    {
        tool.wrongChoice();
        scanCorners();

    }
    return points;
}

void Rectangle::areaAndPerimeter()
{
    recpoints rec1;
    Points points;
    double hight, width;
    rec1 = scanCorners();

    // take the points from the rectangle and call an object from struct point
    point p1 (rec1.x1, rec1.y1);
    point p2 (rec1.x2, rec1.y2);
    point p3 (rec1.x3, rec1.y3);
    // find the distance between two points to find the hight and width and call the function dist
    width = points.dist(p1, p2);
    hight = points.dist(p2, p3);

    cout << "The Area of the rectangle that has width = " << width << " & hight = "
         << hight << " is " << hight*width << endl;
    cout << "The Perimeter of the rectangle that has width = " << width << " & hight = "
         << hight << " is " << 2 * hight + 2 * width << endl;

}

void Rectangle::overlapRectangles()
{
    recpoints rec1, rec2;
    cout << "Enter the first rectangle\n";
    rec1 = scanCorners();
    cout << "Enter the second rectangle\n";
    rec2 = scanCorners();

}

void Rectangle::segmentsMakeRectangle()
{

}
void Rectangle::pointInsideRectangle()
{

}
