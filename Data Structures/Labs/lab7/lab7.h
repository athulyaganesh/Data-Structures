/* Data Structures Lab 7- Linked Lists
 * Author: Athulya Ganesh
 * Group Members: Abhigyan Acherjee, Anusha Chitranshi
 */

#ifndef LAB7_H
#define LAB7_H

#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Task 1
template<class T>
class LinkList
{
private:
    struct ListNode
    {
        T value;
        ListNode *next;
    };//struct for linked list

ListNode *head; //head of linked list
ListNode *location; //location of the list(used specifically for SeeAt, SeeNext and Reset.

public:
    LinkList() //constructor
    {
        head = nullptr;
    }


    ~LinkList() //destructor
    {
        if ( !isEmpty() )
        {
            ListNode *currentPtr = head;
            ListNode *tempPtr = currentPtr;

            while ( currentPtr != 0 )
            {
                tempPtr = currentPtr;
                currentPtr = currentPtr->next;
                delete tempPtr;
            }
        }
    }

    void AddItem(T);//appends item to end of linked list
    T Getitem(T); //gets item and deletes from list
    bool isInList(T); //Checks if element is in the list
    bool isEmpty(); // bool to check list is empty
    int Size(); //returns size of list
    T SeeAt(int); //finds an item at a location and returns item without removing it
    T SeeNext(); //returns the item without removing it from given list at a given location in the list
    void Reset(); //Resets location that the SeeNext function uses to point at first item in the list

    void Print(); //Prints out data elements of linked list
};

template<class T>
void LinkList<T>::AddItem(T data)
{
    ListNode *newNode;
    ListNode *nodePtr;

    newNode = new ListNode;
    newNode -> value = data;
    newNode -> next = nullptr;

    if(!head)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head;
        while(nodePtr ->next)
        {
        nodePtr = nodePtr -> next;
        }
        nodePtr ->next = newNode;
    }
}

template<class T>
T LinkList<T>::Getitem(T data)
{
    ListNode *nodePtr = new ListNode;
    ListNode *previousNode = new ListNode;
    T t;
    if (head ->value == data)
    {
        t = head -> value;
        nodePtr = head ->next;
        delete head;
        head = nodePtr;

    }
    else
    {
        nodePtr = head;
        while(nodePtr->next != nullptr && nodePtr ->value != data)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr -> next;
        }
        if(nodePtr)
        {
            t = nodePtr -> value;
            previousNode -> next = nodePtr -> next;
            delete nodePtr;

        }


    }
    return t;
}

template<class T>
bool LinkList<T>::isInList(T data)
{
    ListNode *nodePtr;


    if (head ->value == data)
    {
        return true;
    }
    else
    {
        nodePtr = head;
        while(nodePtr != NULL)
        {
            if(nodePtr -> value == data)
            {
            return true;
            }
            nodePtr = nodePtr -> next;
        }
        return false;
    }
}

template<class T>
int LinkList<T>::Size()
{
    int count = 0;
    ListNode *current = head;
    while(current != NULL)
    {
        count++;
        current = current -> next;

    }
    return count;
}

template<class T>
bool LinkList<T>::isEmpty()
{
    if(head == nullptr)
    return true;

    else
    return false;
}

template<class T>
T LinkList<T>::SeeAt(int loc)
{
    ListNode *nodePtr;
    int count;
    nodePtr = head;
    while(count < loc)
    {
        if(nodePtr ->next == nullptr)
        {
            throw "empty list!";
        }
        nodePtr = nodePtr -> next;
        count++;
    }

    location = nodePtr -> next;
    return nodePtr -> value;
}

template<class T>
T LinkList<T>::SeeNext()
{
    ListNode *nodePtr = location;
    if(nodePtr ->next == nullptr)
    {
        throw exception();
    }
    nodePtr = location;
    location = nodePtr -> next;
    return nodePtr -> value;
}

template<class T>
void LinkList<T>::Reset()
{
    location = head;
}

template <class T>
void LinkList<T>::Print()
{
    ListNode * tempPtr = head;
    int n=0;
    while(tempPtr!=nullptr)
    {
        cout<<"Value number "<<n+1<<": ";
        cout<<tempPtr->value<<endl;
        tempPtr= tempPtr->next;
        n++;
    }

}

//Task 2: create a class to represesnt a part that will be used as the
// item stores in the list

struct Date
{
    int day, month, year;
};


class Part
{
private:

    int PartNumber;
    string Description;
    double Price;
    char UOM; //unit of measure
    int QuantityOnHand;
    int LeadTime;//num of days to order and arrive if out of stock

public:
    Part()
    {
        PartNumber=0;
        Description ="";
        Price = 0;
        UOM='-';
        QuantityOnHand = 0;
        LeadTime = 0;

    }
    Part(int num, string des, double price, char u, int l, int q = 0)
    { //Constructor
        PartNumber = num;
        Description = des;
        Price = price;
        UOM = u;
        LeadTime = l;
        QuantityOnHand = q;
    }
    void setD(string s)
    {
        Description = s;
    }
    string getD()
    {
        return Description;
    }
    void setPrice(double p)
    {
        Price = p;
    }
    double getPrice()
    {
        return Price;
    }
    void setU(char s)
    {
        UOM = s;
    }
    char getU()
    {
        return UOM;
    }
    void setL(int s)
    {
        LeadTime = s;
    }
    int getL()
    {
        return LeadTime;
    }
    void setQ(int s)
    {
        QuantityOnHand =s ;
    }
    int getQ()
    {
        return QuantityOnHand;
    }

    void setPartNum(int d)
    {
        PartNumber = d;
    }
    int getPartNum() //returns part number of obj
    {
        return PartNumber;
    }
    string GetPartInfo() //returns string concatenation of PartNumber and Description
    {
        return "Part name is " +to_string(PartNumber) + ", and description is "+ Description;
    }

    double GetPrice() // returns Price
    {
        return Price;
    }

    bool inStock() //indicates if quantity is available in stock
    {
        if(QuantityOnHand > 0 )
            return true;
        return false;
    }

    bool Available(int d, int m, int y) //checks availability
    {
        Date desired;
        desired.day=d, desired.month=m, desired.year=y;
        Date current;
        cout<<"Enter today's date please!"<<endl;
        cout<<"Enter day: "<<endl;
        cin>>current.day;
        cout<<"Enter month: "<<endl;
        cin>>current.month;
        cout<<"Enter year:"<<endl;
        cin>>current.month;

        if(QuantityOnHand>0)
            return true;
        else
        {
             current.day =+LeadTime;
             if(current.day>30)
             {
                 current.day=current.day-30;
                 current.month++;
             }
             if(current.month>12)
             {
                 current.month=current.month-12;
                 current.year++;
             }
        }

        if(desired.day>=current.day &&desired.month>=current.month && desired.year >=current.year)
          {
               return true;

          }


        return false;
    }

   bool operator ==(Part a) //overloaded operator to check equality of PartNumbers of two objects
   {
        if (this->PartNumber == a.PartNumber)
            return true;
        return false;
   }

   bool operator <(Part a)
   {
       if(this->PartNumber < a.PartNumber)
           return true;
       return false;
   }

   bool operator >(Part a)
   {
       if(a.PartNumber < this->PartNumber)
           return true;
       return false;
   }
   bool operator !=(Part a)
   {
       if(this->PartNumber !=a.PartNumber)
       {
           return true;
       }
       else
       {
           return false;
       }
   }

   void display()
   {
       cout<<"Displaying information about your product: "<<endl;
       cout<<"Part number: "<<PartNumber<<endl;
       cout<<"Description: "<<Description<<endl;
       cout<<"Price: "<<Price<<endl;
   }


};



#endif // LAB7_H
