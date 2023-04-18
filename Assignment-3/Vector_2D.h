#include <iostream>
using namespace std; 

class Pair{
    private: 
    double x, y; 
     
    public: 
    //Constructors 
        Pair(); 
        Pair(double, double); 
        explicit Pair(double); 

    //Addition and Subtraction
        Pair operator+(const Pair&) const; 
        Pair operator-(const Pair&) const; 

    //Multiplication 
        friend Pair operator*(double, const Pair&);
        friend Pair operator*(const Pair&, double);
        
    //Dot Product 
        double operator*(const Pair&) const; 
    
    //Insertion Operator
        friend ostream& operator<<(ostream&, const Pair&);

    //Compare Operator 
        bool operator==(const Pair&) const; 
};