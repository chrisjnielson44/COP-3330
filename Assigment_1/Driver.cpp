#include "Line.h"
#include "iostream"
using namespace std; 


int main() {
	//Test Constructors 
	Line line1, line2(9), line3(3, 9.8), line4(4, -3, -1);

	//Getters and Setters
	cout << "Displaying X Coordinate, Y Coordiante, Slope = " << line1.GetXCoord() << ' ' << line1.GetYCoord() << ' ' << line1.GetSlope();
	cout << "Displaying X Coordinate, Y Coordiante, Slope = " << line2.GetXCoord() << ' ' << line2.GetYCoord() << ' ' << line2.GetSlope();

	//Set line to new values 
	line1.SetSlope(7); l1.SetXCoord(10); l1.SetYCoord(15);

	//New Line
	line1.PrintPointSlope();

	//Print Standard 
	line1.PrintStandard();
	line2.PrintStandard();
	line3.PrintStandard();
	line4.PrintStandard();

	//Slope Intercept Form 
	line1.PrintSlopeIntercept();
	line2.PrintSlopeIntercept();
	line3.PrintSlopeIntercept();
	line4.PrintSlopeIntercept();	

	//Point Slope
	line1.PrintPointSlope();
	line2.PrintPointSlope();
	line3.PrintPointSlope();
	line4.PrintPointSlope(); 

	//Perpendicular Line
	line4 = line3.GetPerpendicular();

	//Perpendiclar & Intersection 
	cout << "Line that is Perpendicular to " << line3.PrintSlopeIntercept() << endl; 
	cout << "line 3: " << line4.PrintSlopeIntercept() << endl; 
	line2.PrintSlopeIntercept() 
	cout << "Line 2 intersects " << line3.PrintSlopeIntercept() 
	cout << "Line 3 intersects at the point: " << line2.Intersection(line3);


	return 0; 
}