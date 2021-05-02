#include <iostream>
#include "lab7.h"
#include <string>
using namespace std;

int main()
{
//Task 3 part one- Task 1 testing

    cout<<"Welcome to the Linked List Program\n";

    LinkList<int> L;

    int n = 8;
    while(n!=0)
    {
        cout<<"\n\nWhat would you like to do? Here are your options:\n\n";
        cout<<"(1) Exit the program\n";
        cout<<"(2) Add an item to the list\n";
        cout<<"(3)Use the GetItem function to search for an item of your choice\n";
        cout<<"(4) Check whether an item is in the list\n";
        cout<<"(5)Check whether your list is empty\n";
        cout<<"(6)Check the size of your list \n";
        cout<<"(7)Use the SeeNext function\n";
        cout<<"(8) Use the SeeAt function\n";
        cout<<"(9) Use the Reset function\n";
        cout<<"(10) Print your list\n";
        cout<<"Enter here:"<<endl;


        int inp;
        cin>>inp;

        switch(inp)
        {
            case(1):
            {
                cout<<"Quitting the program\n";
                n = 0;
                break;
            }
            case(2):
            {
                cout<<"\nWhat is the value of the item you would like to add? Enter here: \n";
                int a,*ptr;
                cin>>a;
                ptr=&a;
                L.AddItem(*ptr);
                cout<<"Item added!\n";
                break;
            }
            case(3):
            {
                cout<<"What element would you like to search for? Enter the value here:\n";
                int b,*ptr2;
                cin>>b;
                ptr2 = &b;

                int t = L.Getitem(*ptr2);
               if(t==NULL)
               {
                   cout<<"Element isnt in the list\n";
               }
               else
               {
                   cout<<"Element found and deleted ";
                   cout<<"Element: "<<t<<endl;
               }
                break;
            }
            case(4):
            {
                cout<<"Enter the element that you want to check exists in your list or not\n";
                int c, *ptr3;
                cin>>c;
                ptr3 = &c;
                if(L.isInList(*ptr3))
                {
                    cout<<"Element exists\n\n";
                }
                else
                {
                    cout<<"Element does not exist\n\n";
                }
                break;

            }
        case(5):
        {
           if(L.isEmpty())
           {
               cout<<"The list is empty\n";
           }
           else
           {
               cout<<"List is not empty\n";
           }
           break;
        }
        case(6):
        {
            cout<<"Size of the list: "<<L.Size()<<"\n";
            break;
        }
        case(7):
        {
            cout<<"Using the SeeNext() function\n";
            cout<<L.SeeNext();
            break;
        }
        case(8):
        {
            cout<<"Using the SeeAt() function\n";
            cout<<"Enter the location\n";
            int c, *ptr5;
            cin>>c;
            ptr5 = &c;
            cout<<L.SeeAt(*ptr5)<<endl;
            break;
        }
        case(9):
        {
            cout<<"Resetting the location\n";
            L.Reset();
            break;
        }
        case(10):
        {
           cout<<"Printing your linked list as follows: "<<endl;
           L.Print();
        }

        }
    }

    //Task 3 part 2



    LinkList<Part> item;  //creating a Part type linked list
    int z = 0;
    while(z!=1) //while loop for the menu
    {

        cout<<"\nWhat would you like to do? Here is your menu: "<<endl;
        cout<<"(1)Quit the program\n";
        cout<<"(2)AddItem Add a Part object to the Linked List\n";
        cout<<"(3)GetItem Get a Part object\n";
        cout<<"(4)IsInList check if an object is in the list\n";
        cout<<"(5) IsEmpty - checks if the Linked List is empty\n";
        cout<<"(6)Size- check the size of your list\n";
        cout<<"(7)SeeNext function\n";
        cout<<"(8) SeeAt function(Starts at 0)\n";
        cout<<"(9)Reset function\n";
        cout<<"(10)Display list elements\n";
        cout<<"Enter here:\n";
        int i;
        cin>>i;
        switch(i) //switch case
        {
        case(1):
        {
            cout<<"Exiting..."<<endl;
            z=1;
            break;
        }
        case(2):
        {
            cout<<"Enter Part number: "<<endl;
            int p;
            cin>>p;
            cout<<"Enter Description\n";
            string s;
            std::getline(std::cin >> std::ws, s);

            cout<<"Enter price\n";
            double pr;
            cin>>pr;
            cout<<"Enter UOM(as a single character)"<<endl;
            char u;
            cin>>u;
            cout<<"Enter Quantity on hand\n";
            int q;
            cin>>q;
            cout<<"Enter lead time\n";
            int l;
            cin>>l;

            Part * a = new Part;
            a->setPartNum(p);
            a->setD(s);
            a->setPrice(pr);
            a->setU(u);
            a->setQ(q);
            a->setL(l);

            cout<<"Here is your part information: "<<a->GetPartInfo()<<endl;
            if(a->inStock())
            {
                cout<<"Item is in stock\n";
            }
            else
            {
                cout<<"Unfortunately your part is not in stock!\n";
                cout<<"Enter the desired day: "<<endl;
                int d;
                cin>>d;
                cout<<"Enter desired month: "<<endl;
                int m;
                cin>>m;
                cout<<"Enter year: "<<endl;
                int y;
                cin>>y;
                if(a->Available(m,d,y))
                {
                    cout<<"Product will be availabe by "<<d<<"/"<<m<<"/"<<y<<endl;
                }
                else
                {
                    cout<<"Product will not be available by "<<d<<"/"<<m<<"/"<<y<<endl;
                }
            }
            item.AddItem(*a);
            cout<<"Item has been added to the list\n";
            cin.clear();
            break;
        }
        case(3):
        {
            cout<<"Enter Part Number: "<<endl;
            int pn;
            cin>>pn;
            Part * ptr = new Part;
            ptr->setPartNum(pn);
            Part a = item.Getitem(*ptr);
            cout<<"Object of part number"<<a.getPartNum()<<" found and removed!"<<endl;
            break;
        }
        case(4):
        {
            cout<<"Enter a part number: "<<endl;
            int pn;
            cin>>pn;
            Part * ptr = new Part;
            ptr->setPartNum(pn);
            bool a = item.isInList(*ptr);
            if(a)
            {
                cout<<"In list"<<endl;
            }
            else
            {
                cout<<"Not in list\n";
            }
            break;
        }
        case(5):
        {
            bool a = item.isEmpty();
            if(a)
            {
                cout<<"List is empty"<<endl;
            }
            else
            {
                cout<<"Not empty"<<endl;
            }
            break;
        }
        case(6):
        {
            cout<<"Size= "<<item.Size()<<endl;

            break;
        }
        case(7):
        {
            cout<<"Using the Seenext function:"<<endl;
            cout<<"Value of part number : ";
            Part b =item.SeeNext();
            cout<<b.getPartNum()<<endl;
            break;
        }
        case(8):
        {
            cout<<"Enter location: "<<endl;
            int c, * ptr;
            cin>>c;
            ptr = &c;
            Part a =item.SeeAt(*ptr);
            cout<<"Part number: "<<a.getPartNum()<<endl;
            break;
        }
        case(9):
        {
            cout<<"Resetting..."<<endl;
            item.Reset();
            break;
        }

        }

    }

}

