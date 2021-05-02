#ifndef TASK1_H
#define TASK1_H

#include <iostream>
#include <cmath>
using namespace std;

class Complex{
private:
    double a,b;
    bool op;
public:
    void set_x(double real);
    double get_x();

    void set_y(double im);
    double get_y();

    Complex();
    Complex(double x,double y,bool k);

    void Print_Complex();

    void operator + ( Complex  c);
    void operator - ( Complex c);
    void operator  * (double x);
    void operator / (double x);
    bool operator == (const Complex & c);

    double r(double a, double b);
    double phi(double a, double b);

};


#endif // TASK1_H
