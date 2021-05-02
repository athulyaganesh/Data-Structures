#ifndef TASK3_H
#define TASK3_H
#include <iostream>
#include <string>

using namespace std;

class Product{
    private:
      int id;
      int units;
      double prices;
      double sales;
      string des;
      bool TaxExempt;
    public:
      void calcSales(Product[], int);
      void showOrder(Product[], int);
      void dualSort(Product[], int);
      void showTotals(Product[], int);

      void set_id(int i){id=i;}
      int get_id(){return id;}

      void set_units(int u){units=u;}
      int get_units(){return units;};

      void set_prices(double p){prices=p;}
      double get_prices(){return prices;}

      void set_sales(double s){sales=s;}
      double get_sales(){return sales;};

      void set_des(string d){des=d;}
      string get_des(){return des;}

      void set_tax(bool t){TaxExempt=t;}
      bool get_tax(){return TaxExempt;}

    };

#endif // TASK3_H
