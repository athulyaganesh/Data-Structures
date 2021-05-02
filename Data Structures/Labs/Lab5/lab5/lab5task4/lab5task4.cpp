/*Lab 5 /Task 4*
 *Data Structures Lab - 004 *
 *Author: Athulya Ganesh *
 *Group Members: Anusha Chitranshi, Abigyan Acherjee *
 */


#include <iostream>

using namespace std;

const int numBoard = 10;

//Task 4: Templates

template <typename T>

class EntertainmentCollection{


private: int onShelf;	//integer value to count the number of items on the shelf
T arr[numBoard];	//array of type T

public:


    EntertainmentCollection()
    {
        //default constructor to start the shelf off as empty
        onShelf = 0;

    }

    void add(T g)
    {
        // function takes in a T type and adds it to the array, and increments the number of items on shelf


            arr[onShelf] = g;

            onShelf++;

    }

    T remove()
    {
        // function that displays the last game


            T g = arr[onShelf - 1];

            onShelf--;	//decrements number on shelf

            return g;
        }


    int num_board()
    {
        // returns number of games on shelf
        return onShelf;

    }
};

class videoGame {
private:
    int numPlay;
    string v;
public:
    void set_v(string val){//setting v- name of game
        v=val;
    }

    string get_v(){//getter(returns) v
        return v;
    }

    void set_num(int p ){//setting and getting num of players
        numPlay = p;
    }

    int get_num(){
        return numPlay;
    }

    void Play(){
        cout<<"Mash the buttons"<<endl;
    }
    void Winner(){
        cout<<"Winner music"<<endl;
    }
};

int
main()
{
    // Task 2: Use the shelf Class

    bool choose = true;

    int inp;

    EntertainmentCollection<videoGame> shelf;

    while (choose)
    {
        cout << "\nPress 1 to add a board game to shelf\n"
        "Press 2 to remove board game from shelf \n"
        "Press 3 to see how many board games are currently on the shelf.\n"
        "Press 4 to quit\n";
        cout << endl;

        cin >> inp;

        cout << endl << endl;
        if (inp == 1)
        {

                videoGame *play = new  videoGame[numBoard];
                cout << "Name of game to be added to shelf?:\n";
                string s;
                cin >> s;
                play->set_v(s);
                cout << "Number of players to be added?:\n";
                int n;
                cin >> n;
                play->set_num(n);

                shelf.add(*play);
                cout << "The shelf has been added" << endl;



        }
        else if (inp == 2)
        {

                 videoGame temp = shelf.remove();
                 cout<<temp.get_v()<<" with "<<temp.get_num()<<" players is deleted"<<endl;
                cout << "Removed" << endl;



        }
        else if (inp == 3)
        {
            cout << "We currently have " << shelf.
            num_board() << " games on our shelf" << endl << endl;

        }
        else if (inp == 4)
        {
            cout << "Exiting..." << endl;

            choose = false;

        }
        else
        {
            cout << "Incorrect option. Try again in the next step" << endl;

        }
    }

    return 0;

}




