#pragma once
#include "Workers.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
using namespace std;

//extern int c2;

int Workers::pay = 0;

Workers::Workers()
{
}

Workers::~Workers()
{
}

void Workers::WEnter()
{
    printf("Работник:\nИмя: ");
    Human::set();
    //c2 = 1;
}

void Workers::setPay(int sm)
{
    this->pay = sm;
}

int CheckPay() 
{
    if (Workers::pay)
    {
        printf("Установленная оплата для работников: %d", Workers::pay);
    }
    else
    {
        printf("Оплата для работников не установленна");
    }
    return Workers::pay;
}