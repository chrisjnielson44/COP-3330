#include "Line.h"
#include <iostream> 

using namespace std;


Line::Line(double xPos, double yPos, double slope) {
    xCoord = xPos;
    yCoord = yPos;
    this->slope = slope;
}

Line::Line(double yPos, double slope) {
    xCoord = 0;
    yCoord = yPos;
    this->slope = slope;
}

Line::Line(double slope) {
    xCoord = 0;
    yCoord = 0;
    this->slope = slope;
}

Line::Line() {
    xCoord = 0;
    yCoord = 0;
    slope = 1;
}



void Line::PrintPointSlope() {
    cout << "y - " << yCoord << " = " << slope << "(x - " << xCoord << ")" << endl;
}

void Line::PrintSlopeIntercept() {
    cout << "y = " << slope << "x + " << yCoord - slope*xCoord << endl;
}

int gcd(int a, int b)
{
    a = abs(a); b = abs(b);
    int gcd = min(a, b);
    while (gcd > 0) {
        if (a % gcd == 0 && b % gcd == 0) {
            break;
        }
        gcd--;
    }
    return gcd;
}


void Line::PrintStandard() {
    int commonDenom = gcd(1000, slope*1000);
    std::cout << "Common Denominator = " << commonDenom << " scalar = " << (1000/commonDenom) << std::endl;//debug
    int a = 1 * (1000/commonDenom);
    int b = -(slope)*(1000/commonDenom);
    int c = (-(slope)*xCoord + yCoord) * (1000/commonDenom);

    cout << a << "y + " << b << "x = " << c << endl;
}

void Line::Intersection(Line& line_2) {
    double x_intersect = (line_2.yCoord - yCoord + slope * xCoord - line_2.slope * line_2.xCoord) / (slope - line_2.slope);
    double y_intersect = slope * x_intersect + yCoord - slope * xCoord;
    cout << "(" << x_intersect << ", " << y_intersect << ")";
}



double Line::GetXCoord() {
    return xCoord;
}

double Line::GetYCoord() {
    return yCoord;
}

void Line::SetXCoord(double x) {
    xCoord = x;
}

void Line::SetYCoord(double y) {
    yCoord = y;
}

void Line::SetSlope(double s) {
    slope = s;
}

double Line::GetSlope() {
    return slope;
}

Line Line::GetPerpendicular() {
    Line L2 = Line(xCoord, yCoord, -1 / slope);
    return L2;
}



