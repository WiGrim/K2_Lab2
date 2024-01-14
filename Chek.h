#pragma once
#include "Customers.h"
#include "Workers.h"
#include "Product.h"

extern char aPName[], aPAdres[];
static int number = 0;

class Chek : public Customers, public Workers, public Product
{
public:
    Chek(int num);
    ~Chek();
    void Chekk(Customers cust, Workers work, Product prd[], int nprod);
private:
    int num;
};


