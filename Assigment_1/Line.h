class Line {
private:
    double xCoord; //the x-coordinate of a point on the line
    double yCoord; //the y-coordinate of a point on the line
    double slope; //slope of the line

public:
    Line();
    Line(double, double, double);
    Line(double, double);
    Line(double);
    Line GetPerpendicular(); //returns a perpendicular line that passes through the same point represented by the xCoord and yCoord on the calling object

    void Intersection(Line&); //prints the x and y coordinates of where these lines intersect
    void PrintPointSlope(); //prints the point-slope form of this line to standard out
    void PrintSlopeIntercept(); //prints the x and y coordinates of where these lines intersect
    void PrintStandard();  //prints the standard form of this line to standard out


    double GetXCoord(); //returns the value of xCoord
    void SetXCoord(double); //sets the value of xCoord
    double GetYCoord(); //returns the value of yCoord 
    void SetYCoord(double); //sets the value of yCoord
    double GetSlope();  //returns the value of slope
    void SetSlope(double);  //sets the value of slope

};

