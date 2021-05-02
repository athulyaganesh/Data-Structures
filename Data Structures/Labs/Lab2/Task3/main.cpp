// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
#include <task3.h>
#include <fstream>
#include <string>
using namespace std;


// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;

int main()
{
    ifstream ifs;
    ifs.open("C:\\Users\\Athulya\\Desktop\\e.txt");
    if(!ifs){
        cout<<"Unable to open file. "<<endl;
    }
    else{
    // Array with structures containing product ID numbers, number of units sold for each product,
    // product prices, and computed sales amounts
    Product products[NUM_PRODS] ;
    int id;
    int units;
    double prices;
    double sales;
    string des;
    string T;
    bool TaxExempt;

    int i=0;
    while((ifs>>id) && (i<NUM_PRODS)){

        ifs>>units;
        ifs>>prices;
        ifs>>sales;

        getline(ifs>>ws,des);
        getline(ifs>>ws,T);
        if(T=="True"||T=="true"){
            TaxExempt=false;
        }
        else{
            TaxExempt=true;
        }

        products[i].set_id(id);
        products[i].set_units(units);
        products[i].set_prices(prices);
        products[i].set_sales(sales);
        products[i].set_des(des);
        products[i].set_tax(TaxExempt);

        cout<<products[i].get_id()<<endl;
        cout<<products[i].get_units()<<endl;
        cout<<products[i].get_prices()<<endl;
        cout<<products[i].get_sales()<<endl;
        cout<<products[i].get_des()<<endl;
        if(products[i].get_tax()){cout<<"True"<<endl;}
        else{cout<<"False"<<endl;}


        i++;
    }
    // Calculate each product's sales.
    products->calcSales(products, NUM_PRODS);

    // Sort the elements in the sales array in descending
    // order and shuffle the ID numbers in the id array to
    // keep them in parallel.
    products->dualSort(products, NUM_PRODS);

    // Set the numeric output formatting.
    cout << setprecision(2) << fixed << showpoint;

    // Display the products and sales amounts.
    products->showOrder(products, NUM_PRODS);

    // Display total units sold and total sales.
    products->showTotals(products, NUM_PRODS);
}
    return 0;
}



