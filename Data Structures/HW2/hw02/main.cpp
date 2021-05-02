#include <iostream>
#include <iomanip>
#include <elevator.h>

using namespace std;

int main()
{
    cout << "Welcome to the Elevator! \n\n" << endl;

    int destinationFloor = 0;
    int task = 0;
    int currFloor = 0;
    ElevatorSimulation elevator;
    Clock time(0,0,0);
    Building b;
    Button button;

    b.floors();
    button.press();
    int f = button.getFloor();

    cout << "Lift going to Floor " << f << "...\n\n";

    int curr = elevator.getCurrentFloor();
    int d = elevator.getDestinationFloor();

    if (curr < d)
    {
        elevator.setDestinationFloor(d);
        elevator.moveFloor();
        //time.travelUpByOneFloor(1, d - curr);
    }
    else if (d < curr)
    {
        elevator.setDestinationFloor(d);
        elevator.moveFloor();
        //time.travelUpByOneFloor(1, curr - d);
    }

    //cout << "Lift going to Floor " << f << "...\n\n";
    cout << "Start time is 00:00:00 seconds \n\n";
    cout << "\n\nEnter Passenger(0)\n Exit Passenger(1)\n Move Between Floors(2)\n Count Passengers(3) \nStop Simulation(4): \n";
    cin >> task;

    while(task != 4)
    {
        if(task == 0)
        {
            cout << "Choose Destination Floor: ";
            cin >> destinationFloor;
            if(destinationFloor > b.getMax() || destinationFloor < b.getMin())
            {
                cout << "Choose a valid Destination Floor...try again." << endl;
                cout << "\n\nEnter Passenger(0) Exit Passenger(1) Move Between Floors(2) Count Passengers(3) Stop Simulation(4): ";
                cin >> task;
                continue;
            }

            cout << setw(20) << "Passenger Entering...";
            time.doorOpen();
            time.displayTime();
            Passengers person(destinationFloor, currFloor);
            elevator.enterPassenger(person);
            elevator.setDestinationFloor(destinationFloor);
        }

        else if(task == 1)
        {
            int count = elevator.passengerCount();
            elevator.exitPassenger();
            count = abs(count - elevator.passengerCount());
            cout << "Removing " << count << " Passengers at Floor " << elevator.getCurrentFloor() << ".\n\n";
            time.passengersGetsOff(count);

            button.press();
            int f = button.getFloor();
            cout << "Lift going to Floor " << f << "...\n\n";
        }

        else if(task == 2)
        {
            cout << "Going to Floor " << elevator.getDestinationFloor() << "...\n\n";

            int curr = elevator.getCurrentFloor();
            int d = elevator.getDestinationFloor();

            if (curr < d)
            {
                elevator.setDestinationFloor(d);
                elevator.moveFloor();
                time.travelUpByOneFloor(1, d - curr);
            }
            else if (d < curr)
            {
                elevator.setDestinationFloor(d);
                elevator.moveFloor();
                time.travelUpByOneFloor(1, curr - d);
            }
        }

        else if(task == 3)
        {
            cout << "Passenger Count: " << elevator.passengerCount() << "\n\n";
        }

        else
        {
            cout << "Invalid Action...\n\n";
        }
        cout << "\n\nEnter Passenger(0) Exit Passenger(1) Move Between Floors(2) Count Passengers(3) Stop Simulation(4): ";
        cin >> task;
    }
    cout << "Thank you for using the elevator! \n\n";

    return 0;
}
