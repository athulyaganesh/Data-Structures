#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Building
{
    friend class Button;
    friend class ElevatorSimulation;
private:
    int min_floor;
    int max_floor;

public:

    void floors()
    {
        int  min, max;

        cout<<"Enter minimum floor in the building: \n";
        cin>>min;
        setMin(min);

        cout<<"Enter maximum floor in the building: \n";
        cin>>max;
        setMax(max);
    }

    void setMin(int min)
    {
        min_floor=min;
    }

    int getMin()
    {
        return min_floor;
    }

    void setMax(int max)
    {
        max_floor=max;
    }

    int getMax()
    {
        return max_floor;
    }

};

class Button
{
private:
    int floor;

public:
    void press()
    {
        Building b;
        int f;
        cout<<"\nWhat floor are you on? \n";
        cin >> f;

        if(f<b.getMax() || f>b.getMin())
            cout<<"Floor does not exist. \n";

        setFloor(f);
    }

    void setFloor(int f)
    {
        floor = f;
    }

    int getFloor()
    {
        return floor;
    }
};


class Passengers
{
    private:
        int destFloor;
        int currFloor;

    public:
        Passengers()
        {
            currFloor = 1;
            destFloor = 2;
        }

        Passengers(int dest, int curr)
        {
            destFloor = dest;
            currFloor = curr;
        }

        int getDestinationFloor()
        {
            return destFloor;
        }

        int getCurrentFloor()
        {
            return currFloor;
        }
};
class ElevatorSimulation
{
    friend class Clock;
    private:
        int currFloor;
        int movement;   // -1 for down and 1 for up
        int numPassengers;
        vector<Passengers> persons;

    public:
        ElevatorSimulation()
        {
            currFloor = 0;
            movement = 1;
            numPassengers = 0;
        }

        void moveFloor()
        {
            currFloor = movement;
        }

        void enterPassenger(Passengers p)
        {
            persons.push_back(p);
            numPassengers++;
        }

        void exitPassenger()
        {
            for(int i = 0; i < numPassengers; i++)
            {
                if(persons.at(i).getDestinationFloor() == currFloor)
                {
                    persons.erase(persons.begin() + i);
                    numPassengers--;
                    i--;
                }
            }
        }

        int passengerCount()
        {
            return numPassengers;
        }

        void setCurrentFloor(int currentF)
        {
            currFloor = currentF;
        }

        void setDestinationFloor(int destinationF)
        {
            movement = destinationF;
        }

        int getCurrentFloor()
        {
            return currFloor;
        }

        int getDestinationFloor()
        {
            return movement;
        }
};


class Clock
{
 private:
     int hours;
     int minutes;
     int seconds;
     const int timeAccelerate = 10;  // Accelerate up or down
     const int timeMoveOneFloor = 10;
     const int timeDoorOpen = 10;
    // const int timeFirstPassenger = 10;
     const int timeOtherPassenger = 10;
     const int timeExitPassenger = 5;

 public:
     Clock()
     {
         hours = 0;
         minutes = 0;
         seconds = 0;
     }

     Clock(int currHour, int currMin, int currSecond)
     {
         hours = currHour;
         minutes = currMin;
         seconds = currSecond;
     }

     void incrementTimeBySeconds(int numIncrease)
     {
         seconds = seconds + numIncrease;
         if(seconds >= 60)
         {
             minutes++;
             seconds = seconds - 60;
         }
         if(minutes >= 60)
         {
             hours++;
             minutes = minutes - 60;
         }
     }

     void accelerateUp()
     {
         incrementTimeBySeconds(timeAccelerate);
     }

     void accelerateDown()
     {
         incrementTimeBySeconds(timeAccelerate);
     }

     void decelerateUp()
     {
         incrementTimeBySeconds(timeAccelerate);
     }

    void decelerateDown()
    {
        incrementTimeBySeconds(timeAccelerate);
    }

    void TMoveOneFloor()
    {
        incrementTimeBySeconds(timeMoveOneFloor);
    }

    void doorOpen()
    {
        incrementTimeBySeconds(timeDoorOpen);
    }

    void doorOpenForOtherPassenger()
    {
        incrementTimeBySeconds(timeOtherPassenger);
    }

    void displayTime()
    {
        cout << hours << ":" << minutes << ":" << seconds << "\n";
    }

    void travelUpByOneFloor(int numPassengers = 1, int floor = 1)
    {
        cout << "Time when a passenger gets on: ";
        displayTime();
        for(int i = 0; i < numPassengers; i++)
        {
            doorOpenForOtherPassenger();
            //cout << "Time when other passenger gets on: ";
            //displayTime();
        }

        accelerateUp();
        cout << "Time after upward journey: ";
        displayTime();

        for(int i = 0; i < floor; i++)
        {
            TMoveOneFloor();
        }


        //cout << "Elevator car moved by  " << dest - curr << " floors: ";
        //displayTime();
        decelerateUp();
        cout << "Time after decelerating and stopping of elevator: ";
        displayTime();
    }

    void passengersGetsOff(int numPassengers = 1)
    {
        for(int i = 0; i < numPassengers; i++)
        {
            incrementTimeBySeconds(timeExitPassenger);
        }
        cout << "Time after passengers get off: ";
        displayTime();
    }

};



#endif // ELEVATOR_H
