#include <iostream>
#include <task1.h>
using namespace std;

int main()
{
    Complex c1;
    Complex c2(13,45,true);
    Complex c3(1.03,4.08,false);
    double re, img, m=5;
    char k, op=true;
    int o;
//Testing the class
cout<<"Enter either 'r' value or the real portion(Cartesian form):"<<endl;
cin>>re;
cout<<"Enter either theta value or the imaginary portion:"<<endl;
cin>>img;
cout<<"Are you entering in Complex form?(Y/N)"<<endl;
cin>>k;
if (k=='Y'){
    Complex c1(re,img,true);
}
else{
Complex c1(re,img,false);
}

while(op){
    cout<<" M E N U :\n1.Addition operator\n2.Subtraction operator \n3.Multiplication Operator\n4.Division Operator\n5.Equality Operator\n"<<endl;
    cout<<"6.Calculate 'r' value\n7.Calculate phi(angle)\n8.Print\n9.Exit"<<endl;
    cout<<"Enter operation here: "<<endl;
    cin>>o;
    switch(o){
    case 1: {
        if(k=='Y'){
            c1+c2;
        }
        else{
            c1+c3;
        }
        break;
    }
    case 2: {
        if(k=='Y'){
            c1-c2;
        }
        else{
        c1-c3;
        }
        break;
    }
    case 3: {
        c1*m;
        break;
    }
    case 4: {
        c1/m;
        break;
    }
    case 5:{
        if(c1==c2){
            cout<<"Yes they are equal"<<endl;
        }
        else{
        cout<<" No, they are not equal"<<endl;
        }
        break;
    }
    case 6: {
        if(k=='Y'){
            c1.r(c1.get_x(),c1.get_y());
        }
        else{
        cout<<"Already in complex form!"<<endl;
        }
        break;

    }
    case 7:{
        if(k=='Y'){
            c1.phi(c1.get_x(),c1.get_y());
        }
        else{
        cout<<"Already in complex form!"<<endl;
        }
        break;
    }
    case 8:{
        c1.Print_Complex();
        break;
    }
    case 9:{
        cout<<"exiting now..."<<endl;
        op=false;
        break;
    }

    }
}



}
