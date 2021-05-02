#include <iostream>
#include <exception>

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

template <typename T>
class Stack;

template <typename T>
void Print(Stack <T> &);


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
 template <typename T> 
  friend void Print <T>(Stack <T> a);			//friend function to print elements
   template<T>
    void Print <T>(Stack<T>&);
};
 template <typename T> 
 void Print ( Stack<T>& a )		
  {
    if (a.length() == 0)
      {
	throw Underflow{};
      }
    else
      {
          
	cout << "Printing stack elements according to LIFO Principle" << endl;
	for (int i = 0; i < a.length(); i++)
	  {
        
	    cout <<i << " " << endl;
	    
	  }
      }
  }
  


int
main ()
{
 cout << "Welcome to the stack program\n" << endl;
  
  Stack < int >s (7);

try{
  int *ptr;
  int a = 1;
  ptr = &a;
  s.push (ptr);

  int *ptr2;
  int b = 2;
  ptr2 = &b;
  s.push (ptr2);

  int *ptr3;
  int c = 3;
  ptr3 = &c;
  s.push (ptr3);

  int *ptr4;
  int d = 4;
  ptr4 = &d;
  s.push (ptr4);

  int *ptr5;
  int e = 5;
  ptr5 = &e;
  s.push (ptr5);

  int *ptr6;
  int f = 6;
  ptr6 = &f;
  s.push (ptr6);

  int *ptr7;
  int g = 7;
  ptr7 = &g;
  s.push (ptr7);
  
    int *ptr8;
  int l = 8;
  ptr8 = &l;
  s.push (ptr8);
  
  
}
    catch(Overflow& e)  
    {  
        cout << e.o();  
    } 
    catch(Underflow&e)
    {
        cout<<e.u();
    }


  cout << "Org. L: " << s.length () << endl;
  cout << "Peek" << endl;
  try{
  cout << *s.Top () << endl;
  }
      catch(Underflow&e)
    {
        cout<<e.u();
    }
  try
  {
      cout << "Remove" << endl;
  s.pop ();
  s.pop ();
  s.pop ();
}
    catch(Underflow&e)
    {
        cout<<e.u();
    }
  cout << "L:" << s.length () << endl;

  cout << "print" << endl;
  try
  {Print (s);}
      catch(Underflow&e)
    {
        cout<<e.u();
    }
  cout << "Length  " << s.length () << endl;

s.empty();


Print(s); 

}

