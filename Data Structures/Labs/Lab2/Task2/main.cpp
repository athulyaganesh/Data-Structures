// This program demonstrates a two-dimensional array.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    ofstream op;
    cout<<"What name do you want to give your file?"<<endl;
    string name;
    cin>>name;
    name = "C:\\Users\\Athulya\\Desktop\\"+name+".txt";

    op.open(name, std::ios_base::app);
    const int NUM_DIVS = 4;           // Number of divisions
    const int NUM_QTRS = 4;           // Number of quarters
    double sales[NUM_DIVS][NUM_QTRS]; // Array with 3 rows and 4 columns.
    double totalSales = 0;            // To hold the total sales.
    int div, qtr;                     // Loop counters.

    // Nested loops to fill the array with quarterly
    // sales figures for each division.
    cout << "Enter the following sales information:\n\n";
    for (div = 0; div < NUM_DIVS; div++)
    {
        for (qtr = 0; qtr < NUM_QTRS; qtr++)
        {
            cout << "Division " << (div + 1);
            cout<< ", Quarter " << (qtr + 1) << ": $";
            cin >> sales[div][qtr];
        }
        cout << endl; // Print blank line.
    }
    op << "This program will calculate the total sales of\n";
    op << "all the company's divisions.\n";

    op << fixed << showpoint << setprecision(2);
    op << "The sales for the company is: $" << endl;
    op << "Div" << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << endl;


    // Nested loops to display the quarterly sales figures for each division.
    for (div = 0; div < NUM_DIVS; div++)
    {

        op << div + 1 << "\t";
        for (qtr = 0; qtr < NUM_QTRS; qtr++)
        {
            op << "$" << sales[div][qtr] << "\t";
            totalSales+=sales[div][qtr];
        }
        op<< endl; // Print blank line.
    }

    op << endl;
    op << "The total sales for the company are: $";
    op << totalSales << endl;
    op.close();
    return 0;
}
