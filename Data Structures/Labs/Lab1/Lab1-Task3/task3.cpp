// Calculate each product's sales.// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
using namespace std;

struct product{  //Struct with members for ID, unit, Prices and sales to be used instead of arrays
    int id,
            units;
    double prices,
                sales;
};

// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;

//****************************************************************
// Definition of calcSales. Accepts units, prices, and sales     *
// arrays as arguments. The size of these arrays is passed       *
// into the num parameter. This function calculates each         *
// product's sales by multiplying its units sold by each unit's  *
// price. The result is stored in the sales array.               *
//****************************************************************

void calcSales(product p[], int num)
{
for (int index = 0; index < num; index++)
   p[index].sales = p[index].units * p[index].prices;
}

//***************************************************************
// Definition of function dualSort. Accepts id and sales arrays *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the id array are exchanged  *
// identically as those of the sales array. size is the number  *
// of elements in each array.                                   *
//***************************************************************

void dualSort( product p[], int size)
{
int startScan, maxIndex, tempid;
double maxValue;

for (startScan = 0; startScan < (size - 1); startScan++)
{
   maxIndex = startScan;
   maxValue = p[startScan].sales;
   tempid = p[startScan].id;
   for(int index = startScan + 1; index < size; index++)
   {
      if (p[index].sales > maxValue)
      {
         maxValue = p[index].sales;
         tempid = p[index].id;
         maxIndex = index;
      }
   }
  p[maxIndex].sales = p[startScan].sales;
  p[maxIndex].id = p[startScan].id;
  p[startScan].sales = maxValue;
  p[startScan].id = tempid;
}
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.    *
// The function first displays a heading, then the sorted list   *
// of product numbers and sales.                                 *
//****************************************************************

void showOrder(product p[],int num)
{
cout << "Product Number\tSales\n";
cout << "----------------------------------\n";
for (int index = 0; index < num; index++)
{
   cout << p[index].id << "\t\t$";
   cout << setw(8) << p[index].sales << endl;
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

void showTotals(product p[], int num)
{
int totalUnits = 0;
double totalSales = 0.0;

for (int index = 0; index < num; index++)
{
   totalUnits += p[index].units;
   totalSales += p[index].sales;
}
cout << "Total units Sold:  " << totalUnits << endl;
cout << "Total sales:      $" << totalSales << endl;
}





int main()
{
// Array with product ID numbers
int id[NUM_PRODS] = {914, 915, 916, 917, 918, 919, 920,
                     921, 922};

// Array with number of units sold for each product
int units[NUM_PRODS] = {842, 416, 127, 514, 437, 269, 97,
                        492, 212};

// Array with product prices
double prices[NUM_PRODS] = {12.95, 14.95, 18.95, 16.95, 21.95,
                            31.95, 14.95, 14.95, 16.95};

// Array to hold the computed sales amounts
double sales[NUM_PRODS];

product p[NUM_PRODS]; //empty object of array type
for(unsigned int i=0; i<NUM_PRODS;i++){  //populating object with details from the four arrays
    p[i].id = id[i];
    p[i].units=units[i];
    p[i].prices=prices[i];
    p[i].sales=sales[i];
}


calcSales(p, NUM_PRODS);

// Sort the elements in the sales array in descending
// order and shuffle the ID numbers in the id array to
// keep them in parallel.
dualSort(p, NUM_PRODS);

// Set the numeric output formatting.
cout << setprecision(2) << fixed << showpoint;

// Display the products and sales amounts.
showOrder(p, NUM_PRODS);

// Display total units sold and total sales.
showTotals(p, NUM_PRODS);
return 0;
}










