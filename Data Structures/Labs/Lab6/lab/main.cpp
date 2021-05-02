#include <iostream>
#include <cmath>
#include "Stack.h"

using namespace std;


bool isEqual(Stack<int> &stack1, Stack<int> &stack2) {
    if (stack1.isEmpty() && stack2.isEmpty())
      return true;
    else if (stack1.isEmpty() || stack2.isEmpty())
      return false;
    while (!stack1.isEmpty() && !stack2.isEmpty())
    {
      if (stack1.Top() != stack2.Top())
        return false;
      stack1.pop();
      stack2.pop();
    }
    if (stack1.isEmpty() && stack2.isEmpty())
      return true;
    else
      return false;
  }


bool Win(int num,Stack<int>a)
{
    Stack<int> win(num);
    for(int i = 0; i<num; i++)
    {

        int c = num-i;
        int * ptr = &c;
        win.push(ptr);
    }

    if(isEqual(win,a))
    {
        return true;
    }
    return false;

}


bool canAdd(Stack<int>a,Stack<int>b)
{
    try{
    if(b.isEmpty()==true)
    {
        return true;
    }
    else if(a.isEmpty()==true)
    {
        cout<<"Cannot add since stack is empty!"<<endl;
        return false;
    }
    else{
        if(b.Top()>a.Top())
        {
            return true;
        }
        else if(b.Top()==nullptr){
            return true;
        }
        else
        {
            cout<<"Can't add... check sizes and try again! "<<endl;
            return false;

        }

    }
}
    catch(Overflow & e)
    {
        cout<<e.o()<<endl;
    }
    catch(Underflow & e)
    {
        cout<<e.u()<<endl;
    }
return true;
}


int main()
{

    cout<<"Enter number of disks here: "<<endl;
    int num;

    cin>>num;

    cout<<"Number of towers used: 3"<<endl;

    cout<<"Maximum number of steps to reach the solution: "<<pow(num,2)-1<<endl;

    cout<<"Creating three towers..."<<endl<<endl;

    Stack<int>one(num);
    Stack<int>two(num);
    Stack<int>three(num);

    int *tower_A_disks = new int [unsigned(num)];
      int *tower_B_disks = new int [unsigned(num)];
      int *tower_C_disks = new int [unsigned(num)];

      for(int i = 0; i < num; i++)
      {
          tower_A_disks[i] = (num - i);
          int * ptr = &tower_A_disks[i];
          one.push(ptr);

          tower_B_disks[i] = (num - i);
          tower_C_disks[i] = (num - 1);
      }



    cout<<"Original Game Setting"<<endl<<endl;

    cout<<"Tower A\t\t\tTower B\t\t\tTower C"<<endl;

    Print(one);
    cout<<"\t\t\t";
    Print(two);
    cout<<"\t\t\t";
    Print(three);

    cout<<endl<<endl;

    int n = 1;

    while(n!=0)
    {
        cout<<"Press 0 to quit\n\n";

        cout<<"Press 1 to move from Tower A to Tower B\n";
        cout<<"Press 2 to move from Tower B to Tower C\n";
        cout<<"Press 3 to move from Tower A to Tower C\n\n";

        cout<<"Press 4 to move from Tower B to Tower A\n";
        cout<<"Press 5 to move from Tower C to Tower B\n";
        cout<<"Press 6 to move from Tower C to Tower A\n\n";

        cout<<"Enter here: "<<endl;
        int inp;
        cin>>inp;





        switch(inp)
        {



            case(0):
            {
                cout<<"Leaving now! Goodbye\n";
                n=0;
                break;
            }


        case(1):
        {
            try
            {
            if(canAdd(one,two))
            {
                int * ptr = one.pop();
                two.push(ptr);
                cout<<ptr<<" added to rod 2 from from rod 1 "<<endl;

                /*cout<<"Tower A"<<endl;
                Print(one);
                cout<<"Tower B"<<endl;
                Print(two);
                cout<<"Tower C"<<endl;
                Print(three);
                cout<<endl<<endl;
*/
                cout<<"Tower A\t\t\tTower B\t\t\tTower C"<<endl;

                Print(one);
                cout<<"\t\t\t";
                Print(two);
                cout<<"\t\t\t";
                Print(three);

                cout<<endl<<endl;
                if(Win(num,two))
                {
                    cout<<"Game over, you won!"<<endl;
                    n=0;
                }
            }
            }
            catch(Underflow & e)
            {
                cout<<e.u()<<endl;
            }
            catch(Overflow & e)
            {
                cout<<e.o()<<endl;
            }

            break;
        }




        case(2):
            {
            try{
            if(canAdd(two,three))
            {
                int * ptr1 = two.pop();
                three.push(ptr1);
                cout<<ptr1<<" added to rod three from rod two"<<endl;

                cout<<"Tower A"<<endl;
                Print(one);
                cout<<"Tower B"<<endl;
                Print(two);
                cout<<"Tower C"<<endl;
                Print(three);
                cout<<endl<<endl;

                if(Win(num,three))
                {
                    cout<<"Game over, you won!"<<endl;
                    n=0;
                }
            }
            }
            catch(Underflow & e)
            {
                cout<<e.u()<<endl;
            }
            catch(Overflow & e)
            {
                cout<<e.o()<<endl;
            }

            break;
            }



        case(3):
        {
            try{
            if(canAdd(one,three))
            {
                int * ptr2 = one.pop();
                three.push(ptr2);
                cout<<ptr2<<" added to rod three from rod one"<<endl;

                cout<<"Tower A"<<endl;
                Print(one);
                cout<<"Tower B"<<endl;
                Print(two);
                cout<<"Tower C"<<endl;
                Print(three);
                cout<<endl<<endl;

                if(Win(num,three))
                {
                    cout<<"Game over, you won!"<<endl;
                    n=0;
                }
            }
            }
            catch(Underflow & e)
            {
                cout<<e.u()<<endl;
            }
            catch(Overflow & e)
            {
                cout<<e.o()<<endl;
            }

            break;
        }
        case(4):
        {
            try{
            if(canAdd(two,one))
            {
                int * ptr3 = two.pop();
                one.push(ptr3);
                cout<<ptr3<<" added to rod one from rod two"<<endl;

                cout<<"Tower A"<<endl;
                Print(one);
                cout<<"Tower B"<<endl;
                Print(two);
                cout<<"Tower C"<<endl;
                Print(three);
                cout<<endl<<endl;

                if(Win(num,one))
                {
                    cout<<"Game over, you won!"<<endl;
                    n=0;
                }
            }
            }
            catch(Underflow & e)
            {
                cout<<e.u()<<endl;
            }
            catch(Overflow & e)
            {
                cout<<e.o()<<endl;
            }

            break;
        }
        case(5):
        {
            try{
            if(canAdd(three,two))
            {
                int * ptr5 = three.pop();
                two.push(ptr5);
                cout<<ptr5<<" added to rod two from rod three"<<endl;

                cout<<"Tower A"<<endl;
                Print(one);
                cout<<"Tower B"<<endl;
                Print(two);
                cout<<"Tower C"<<endl;
                Print(three);
                cout<<endl<<endl;

                if(Win(num,two))
                {
                    cout<<"Game over, you won!"<<endl;
                    n=0;
                }

            }
            }
            catch(Underflow & e)
            {
                cout<<e.u()<<endl;
            }
            catch(Overflow & e)
            {
                cout<<e.o()<<endl;
            }

            break;
        }
        case(6):
        {
            try{
            if(canAdd(three,one))
            {
                int * ptr6 = three.pop();
                one.push(ptr6);
                cout<<ptr6<<" added to rod one from rod three"<<endl;

                cout<<"Tower A"<<endl;
                Print(one);
                cout<<"Tower B"<<endl;
                Print(two);
                cout<<"Tower C"<<endl;
                Print(three);
                cout<<endl<<endl;

                if(Win(num,one))
                {
                    cout<<"Game over, you won!"<<endl;
                    n=0;
                }
            }
            }
            catch(Underflow & e)
            {
                cout<<e.u()<<endl;
            }
            catch(Overflow & e)
            {
                cout<<e.o()<<endl;
            }

            break;
        }
        }
        }
    return 0;
}
