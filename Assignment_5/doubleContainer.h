
#pragma once 
#include "iostream"
using namespace std;

class DoubleContainer {
private:
    int size;
    double* nums;

public:
    DoubleContainer();

    DoubleContainer(const double*, int);
    DoubleContainer(const DoubleContainer&);

    void add(double);
    double remove();
    void clear();

    DoubleContainer& operator=(const DoubleContainer&);

    DoubleContainer operator+(const DoubleContainer&) const;
    DoubleContainer operator-(const DoubleContainer&) const;
    DoubleContainer& operator+=(const DoubleContainer&);
    DoubleContainer& operator-=(const DoubleContainer&);

    DoubleContainer& operator/=(double);
    DoubleContainer operator -() const;
    DoubleContainer operator*(double) const;
    DoubleContainer operator/(double) const;
    DoubleContainer& operator*=(double);
    friend DoubleContainer operator*(double, const DoubleContainer&);


    double operator*(const DoubleContainer&) const;

    friend ostream& operator<<(ostream&, const DoubleContainer&);
    friend istream& operator>>(istream&, DoubleContainer&);

    ~DoubleContainer();
};