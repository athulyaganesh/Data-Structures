#include "task3.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//****************************************************************
// Definition of calcSales. Accepts units, prices, and sales     *
// arrays as arguments. The size of these arrays is passed       *
// into the num parameter. This function calculates each         *
// product's sales by multiplying its units sold by each unit's  *
// price. The result is stored in the sales array.               *
//****************************************************************

void Product::calcSales(Product products[], int num)
{
    for (int index = 0; index < num; index++)
        products[index].sales = products[index].units * products[index].prices;
}

//***************************************************************
// Definition of function dualSort. Accepts id and sales arrays *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the id array are exchanged  *
// identically as those of the sales array. size is the number  *
// of elements in each array.                                   *
//***************************************************************

void Product::dualSort(Product products[], int size)
{
    int startScan, maxIndex, tempid;
    double maxValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        maxIndex = startScan;
        maxValue = products[startScan].sales;
        tempid = products[startScan].id;
        for (int index = startScan + 1; index < size; index++)
        {
            if (products[index].sales > maxValue)
            {
                maxValue = products[index].sales;
                tempid = products[index].id;
                maxIndex = index;
            }
        }
        products[maxIndex].sales = products[startScan].sales;
        products[maxIndex].id = products[startScan].id;
        products[startScan].sales = maxValue;
        products[startScan].id = tempid;
    }
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.    *
// The function first displays a heading, then the sorted list   *
// of product numbers and sales.                                 *
//****************************************************************

void Product::showOrder(Product products[], int num)
{
    cout << "Product Number\tSales\n";
    cout << "----------------------------------\n";
    for (int index = 0; index < num; index++)
    {
        cout << products[index].id << "\t\t$";
        cout << setw(8) << products[index].sales << endl;
    }
    cout << endl;
}

//*****************************************************************
// Definition of showTotals function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.     *
// The function first calculates the total units (of all          *
// products) sold and the total sales. It then displays these     *
// amounts.                                                       *
//*****************************************************************

void Product::showTotals(Product products[], int num)
{
    int totalUnits = 0;
    double totalSales = 0.0;

    for (int index = 0; index < num; index++)
    {
        totalUnits += products[index].units;
        totalSales += products[index].sales;
    }
    cout << "Total units Sold:  " << totalUnits << endl;
    cout << "Total sales:      $" << totalSales << endl;
}
