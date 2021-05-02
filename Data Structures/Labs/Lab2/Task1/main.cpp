/*
 * Lab 2: Data Structures 004
 * Author: Athulya Ganesh
 * Group Members: Anusha, Abhigyan
 * Task 1
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    ifstream ifs;
    string word;
    cout<<"What is the file name you want to read? Enter here: "<<endl;
    string name;
    cin>>name;

    name= "C:\\Users\\Athulya\\Desktop\\" + name + ".txt";

    ifs.open(name);

    if(ifs){

    int i=0;
    while(ifs>>word && i<10){
        cout<<word<<endl;
        i++;
    }

    }
    else {
        cout<<"Enter appropriate file name"<<endl;
    }
    ifs.close();

}
