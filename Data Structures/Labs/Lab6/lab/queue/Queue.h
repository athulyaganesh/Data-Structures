#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Queue;

template<typename T>
void Print(Queue<T>& q);



template <typename T>
class Queue{
private:
    int top=-1;
    vector<T> steps;
    int size=0;
public:

    void makeEmpty()
    {
        delete[]steps;
        top=-1;
        size=0;
    }
    void push( T rear)
    {
        steps.push_back(rear);
        size++;
    }
    T pop()
    {
        size--;
        T a = steps.back();
        steps.pop_back();
        return a;
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if(size == steps.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int length()
    {
        return size;
    }

    template <typename t>
    friend void Print(Queue<t> & q);
};

template <typename t>
void Print(Queue<t>&q)
{
    for(int i =0; i<q.length();i++)
    {
        cout<<q.steps[i]<<endl;
    }
}
#endif // QUEUE_H
