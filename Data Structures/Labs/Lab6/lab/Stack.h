#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <exception>
#include <cmath>

using namespace std;


class Overflow:public exception	//overflow class(more elements than stack can contain)
{
public:
  const char *o () const throw ()

  {
    return "~~Overflow error. Cannot add element since stack is full!~~\n ";
  }
};

class Underflow:public exception	//underflow class(no elements in stack)
{
public:
  const char *u () const throw ()
  {
    return "~~Underflow error. Empty stack!~~\n";
  }
};


template<typename T>
class Stack;


template<typename T>
void Print(Stack<T>& stack);

template < typename T > class Stack
{
protected:

  T ** StackTop;
  int top =-1;
  int size ;

public:

  Stack (int s)			//The constructor should includes a parameter to indicate the size of the array
  {
    size = s;
    StackTop = new T *[size];
  }

  int length ()			//The length function will return an int indicating the number of items in the stack.
  {
    return top + 1;
  }

  void push (T * a)		//The push function should accept a pointer and add that pointer to the top of the stack.
    //It doesnt need to create any memory.
  {
    if (top == size - 1)
      {
    throw Overflow{};
      }
    else
      {
    top++;
    StackTop[top] = a;
      }
  }

  T *pop ()			//The pop function should return a pointer.  It doesnt need to delete any memory.
  {
    if (top < 0)
      {
    throw Underflow
    {
    };
      }
    else
      {
    T *a = StackTop[top];
    top--;
    return a;
      }

  }

  T *Top ()
  {
      if(top<0)
      {
          throw Underflow{};
      }
    return StackTop[top];
  }

  void empty ()			//The empty function should empty the stack of all contents.
    //It needs to call delete to avoid memory leaks.  It doesnt need to return any value.
  {
    delete[]StackTop;
    top = -1;
    StackTop = new T *[size];
  }


    bool isFull() //checks if stack is full
    {
        if(top == size - 1)
            return true;
        else
            return false;
    }


    bool isEmpty() //checks if stack is empty
    {
        if(top == -1)
            return true;
        else
            return false;
    }
template <typename t>
    friend void Print( Stack<t>& stack);
};


template <typename t>
void Print( Stack<t>& stack) {
    for(int i = 0; i<stack.length(); i++){
        cout<<*stack.StackTop[stack.length()-1-i]<<endl;
    }
}

#endif // STACK_H
