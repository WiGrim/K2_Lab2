#pragma once
#include "Product.h"
#include <string>

//extern int c3;

void Scn(int* s);

static char aPName[15] = "", aPAdres[15] = "";

Product::Product() :Providers(aPName, aPAdres)
{

}

Product::~Product()
{
}

void Product::ProdEnter() {
    int Pcost;
    printf("Название товара: ");
    cin >> ProdName;
    printf("Цена: ");
    Scn(&cost); //do while
    printf("Количество на складе: ");
    Scn(&count); //do while   
    //c3 = 1;
}

void Product::prdprint()
{
    //string massege {ProdName};
    cout << ProdName;
}

int* Product::fcout(int* scost) //указатель
{
    printf("%5d * ", cost);
    *scost += cost;
    cout << ProdName;
    return scost;
}

/*
int sm = fcout(sm);
int& Product::fcout(int& scost) //ссылка
{
    printf("%5d * ", cost);
    scost += cost;
    cout << ProdName;
    return scost;
}
*/

void Product::operator + (int count)
{
    this->count += count;
}

int& Product::operator ++ ()//Префиксный вариант
{
    this->count++;
    int n = this->count;
    return n;
}

int Product::operator ++ (int count)//Постфиксный вариант
{
    int n = this->count;
    this->count ++;
    return n;
}

Product Product::operator= (Providers prov) { //Перегрузка оператора =
    this->set(prov.getPName(), prov.getPAdres(), prov.getCount());
    return *this;
}

void Product::CountLess(int count) {
    this->count -= count;
}

int Product::getCount() {
    return count;
}
