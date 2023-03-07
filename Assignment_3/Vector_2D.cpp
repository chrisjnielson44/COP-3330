#include "Vector_2D.h"
using namespace std; 

//Setters & Getters 
Pair::Pair() {
    x = 0; 
    y = 0; 
}

Pair::Pair(double x_vect, double y_vect) {
    x = x_vect;
    y = y_vect; 
}

Pair::Pair(double x_user){
    x = x_user;
    y =  0;
}


//Addition and Subtraction
Pair Pair::operator+(const Pair& Pair_2) const {
    Pair Pair_3 = Pair(x + Pair_2.x, y + Pair_2.y);
    return Pair_3;
}

Pair Pair::operator-(const Pair& Pair_2) const {
    Pair Pair_3 = Pair(x - Pair_2.x, y - Pair_2.y);
    return Pair_3;
}

//Multiplication
Pair operator*(double user_Scalar,const Pair& z) {
    Pair new_vector = Pair(user_Scalar * z.x, user_Scalar * z.y);
    return new_vector; 
}   

//Dot Product
double Pair::operator*(const Pair& dot_pair) const {
    double a = (x * dot_pair.x + y * dot_pair.y);
    return a; 
}


//Insertion Operator 
ostream& operator<<(ostream& output, const Pair& a) {
    output << '(' << a.x << ", " << a.y << ')'; 
    return output; 
}

//Compare Opperator 
bool Pair::operator==(const Pair& a) const {
    bool is_equal = x == a.x && y == a.y;
    return is_equal; 
}

