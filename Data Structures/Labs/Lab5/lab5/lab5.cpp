/*Lab 5 *
 *Data Structures Lab - 004 *
 *Author: Athulya Ganesh *
 *Group Members: Anusha Chitranshi, Abigyan Acherjee *
 */
#include <iostream>
using namespace std;

class boardGame
{
    private:
        string name;
    int numPlayers;

    public:

        void setName(string n)
        {
            //setter and getter for the name of the game
            name = n;
        }

    string getName()
    {
        return name;
    }

    void setPlayer(int p)
    {
        //setter and getter for the num of players
        numPlayers = p;
    }

    int getPlayer()
    {
        return numPlayers;
    }
};



const int numBoard = 10;	// Total number of board games initialised using a global variable

class Shelf
{
    private: int onShelf;	//integer value to count the number of items on the shelf
    boardGame arr[numBoard];	//array of type boardGame
    public: class FullShelf {};	//Task 3- Exception Handling with Classes
    class EmptyShelf {};

    Shelf()
    {
        //default constructor to start the shelf off as empty
        onShelf = 0;

    }

    void add(boardGame g)
    {
        // function takes in a boardGame type and adds it to the array, and increments the number of items on shelf

        if (onShelf == numBoard)
        {
            throw FullShelf {};
        }
        else
        {
            arr[onShelf] = g;

            onShelf++;
        }
    }

    boardGame remove()
    {
        // function that displays the last game

        if (onShelf == 0)
        {
            throw EmptyShelf {};

        }
        else
        {
            boardGame g = arr[onShelf - 1];

            onShelf--;	//decrements number on shelf

            return g;
        }
    }

    int num_board()
    {
        // returns number of games on shelf
        return onShelf;

    }
};

int
main()
{
    // Task 2: Use the shelf Class

    bool choose = true;

    int inp;

    Shelf shelf;

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
            try
            {
                boardGame *play = new boardGame[numBoard];
                cout << "Name of game to be added to shelf?:\n";
                string s;
                cin >> s;
                play->setName(s);
                cout << "Number of players to be added?:\n";
                int n;
                cin >> n;
                play->setPlayer(n);

                shelf.add(*play);
                cout << "The game has been added to the shelf " << endl;
            }

            catch (Shelf::FullShelf)
            {
                cout << "Error: Shelf is full" << endl;
            }
        }
        else if (inp == 2)
        {
            try
            {
                 boardGame a = shelf.remove();
                cout<<a.getName()<<" with "<< a.getPlayer() <<" players has been removed."<<endl;
            }

            catch (Shelf::EmptyShelf)
            {
                cout << "Error: Shelf is empty" << endl;
            }
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
