#pragma once
#include "Customers.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
using namespace std;

//extern int c1;

Customers::Customers()
{
    int cyear = 0;
}

Customers::~Customers()
{
}

void Customers::CEnter() {
    printf("Покупатель:\nИмя: ");
    Human::set();
    printf("Емаил: ");
    fgets(email, 25, stdin);
    rewind(stdin);
    cyear = 0;
    //c1 = 1;
}

int& Customers::setCyear() {
    return cyear;
}

int Customers::getCyear() {
    return cyear;
}

char* Customers::getCemail() {
    return email;
}