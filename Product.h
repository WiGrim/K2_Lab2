#pragma once
#include "Providers.h"

extern char aPName[], aPAdres[];
//static int c3 = 0;

class Product :private Providers
{
public:
    Product();
    ~Product();
    void ProdEnter();
    void prdprint();
    int* fcout(int* scost); //���������
    void operator + (int count); //����������
    int& operator ++();
    int operator ++(int);
    Product operator = (Providers prov);
    void CountLess(int count);
    int getCount();
private:
    string ProdName;//������
    int cost, count;
};

