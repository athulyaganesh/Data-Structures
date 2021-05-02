/*Lab 4 - Inheritance, Polymorphism, Abstract Classes*
//Author: Athulya Ganesh
//Partners: Anusha Chitranshi, Abhigyan Acherjee*/
#include <iostream>
#include <string>
using namespace std;

//Task 1: Create a base class to be used for the entire lab

class Game{
 private:
    int x, y;
    string type; //(part of task 2)
public:
    void set_x(int x){ //Sets x
        this->x=x;
    }
    void set_y(int y){ //Sets y
        this->y=y;
    }
    void set_type(string s){//sets type
        this->type=s;
    }
    int get_x(){ //gets (returns) val of x
        return x;
    }
    int get_y(){ //gets (returns) val of y
        return y;
    }
    string get_type(){//returns string type
        return type;
    }
    Game(){ //default constructor, sets all vals to 0 or empt. string
        x=0,y=0;
        type="";
    }
    Game(int fv, int sv,string t){//overloaded constructor
        x=fv,y=sv;
        type=t;
    }
    virtual void Play(){
        cout<<"What game?"<<endl;
    }
    void Winner(){
        cout<<"Not yet"<<endl;
    }
};

//Task 2: Create 2 classes that inherit from class Game


//Class 2
class boardGame: public Game{
public:
    void Play(){
        cout<<"Roll the dice"<<endl;
    }
    void Winner(){
        cout<<"Dancing time"<<endl;
    }
};

//Class 3
class videoGame : public Game{
private:
    int v;
public:
    void set_v(int val){//setting v
        v=val;
    }

    int get_v(){//getter(returns) v
        return v;
    }

    void Play(){
        cout<<"Mash the buttons"<<endl;
    }
    void Winner(){
        cout<<"Winner music"<<endl;
    }
};

template <class T> //Function template, whos argument is any class and outputs Play() and Winner()
void Show (T a) {
  a.Play();
  a.Winner();
}
template <class y>
void ShowP(y *a){
    a->Play();
    a->Winner();
}


//main function(milestone)
int main()
{
    /*
    ***MILESTONE***
    Game obj1;

    videoGame ob2;
    ob2.Play();
    ob2.Winner();

    boardGame o;
    o.Play();
    o.Winner();
    */


    //Task 3 : Test the classes

    char choose = 'Y';
    int inp;

    while(choose=='Y' || choose=='y'){
        cout<<"Press 1 for an instance of game\n"
              "Press 2 for an instance of board game \n"
              "Press 3 for an instance of viseo game\n"
              "Press 4 for an instance of a board game declared as a game\n"
              "Press 5 for an instance of a video game declared as a game\nEnter here:"<<endl;
        cin>>inp;
        if (inp==1){
            Game g;
            g.Play(), g.Winner();
            Show<>(g);
        }
        else if (inp==2){
            boardGame b;
            b.Play(), b.Winner();
            Show<>(b);
        }
        else if (inp==3){
            videoGame v;
            v.Play(),v.Winner();
            Show<>(v);
        }
        else if (inp==4){
        Game *g = new boardGame();
        g->Play(), g->Winner();
        ShowP<>(g);
        }
        else if(inp==5){
            Game *g5= new videoGame();
            g5->Play(),g5->Winner();
            ShowP<>(g5);

        }
        else{
            cout<<"Incorrect option. Try again in the next step";
        }


        cout<<"Do you wish to continue?(Y/N)"<<endl;
        cin>>choose;
    }


    return 0;
}


