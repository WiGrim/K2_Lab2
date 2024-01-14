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
    int* fcout(int* scost); //Указатель
    void operator + (int count); //Перегрузки
    int& operator ++();
    int operator ++(int);
private:
    string ProdName;//Строка
    int cost, count;
};

