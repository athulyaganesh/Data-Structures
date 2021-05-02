#include <task1.h>
#include <iostream>
#include <cmath>

using namespace std;

bool op;
void Complex::set_x(double real){
    a=real;
} //setter and getter for x->(a) in a+ib

double Complex:: get_x(){
    return a;
}

void Complex::set_y(double im){
    b=im;
} //setter and getter for y->b in a+ib

double Complex::get_y(){
    return b;
}



Complex::Complex(){
    a=0;
    b=0;
    op=true;
}  //default


Complex::Complex(double x, double y, bool k){
   if(k){
        a=x;
        b=y;
   }
   else{

       a= x*cos(y);
       b= x*sin(y);
   }
}  //if k- input is a and b from a+ib else r and theta


void Complex::Print_Complex(){
    cout<<"The representation is: "<<endl<<get_x()<<" + "<<get_y()<<"i"<<endl;
}//function to print all values in a+ib form


void  Complex::operator  + (Complex c){
    Complex temp;
    temp.a=c.a+a;
    temp.b=c.b+b;
}//operator overloading to add the components of the number

void Complex::operator - ( Complex c){
    Complex temp;
    temp.a=a-c.a;
    temp.b=b-c.b;
}//operator overloading to subtract the components
void Complex::operator  * (double x){
    Complex temp;
    temp.a=x*temp.a;
    temp.b=x*temp.b;

}//operator overloading to perform scalar multiplication
void Complex::operator / (double x){
    Complex temp;
    temp.a= temp.a/x;
    temp.b=temp.b/x;
}//operator overloading to perform scalar division
bool Complex::operator == (const Complex & c){
    Complex temp;
    if((temp.a==c.a)&&(temp.b==c.b)&&(temp.op==c.op)){
        return true;
    }
    return false;
}//operator overloading to check equality of two class instances

double Complex::r(double a, double b){
    return pow((pow(a,2)+pow(b,2)),0.5);
}//function to return r given a and b
double Complex::phi(double a, double b){
    return atan(b/a);
}//function to return the angle given the real and imaginary components
