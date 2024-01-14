#pragma once
#include "Chek.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include "Pay.h"

extern int number;
extern char aPName[], aPAdres[];

void Scn(int* s);

Chek::Chek(int num) : Customers(), Workers(), Product()
{
    this->num = num;
}

Chek::~Chek()
{
}

void Chek::Chekk(Customers cust, Workers work, Product prd[], int nprod) {
    num = number + 1;
    printf("\n");
    for (size_t i = 0; i < nprod; i++)
    {
        printf("%d ", i + 1);
        prd[i].prdprint();
        printf("\n");
    }
    printf("%d Подтвердить\n\nКакие продукты были куплены?: \n", nprod + 1);
    int i = 0, u, * n;
    n = new int[nprod];
    do
    {
        do
        {
            Scn(&u);
            if (u < 1 || u > nprod + 1)
                printf("\nОшибка. Введите корректный пункт списка.\n");
        } while (u < 1 || u > nprod + 1);
        if (u != nprod + 1)
        {
            n[i] = u - 1;
            i++;
            printf("Добавлено\n");
        }
    } while (u != nprod + 1);

    printf("\n***************************************************************************************************\n");
    printf("Чек\n\nПокупатель:\n");
    cust.print(u);
    printf("Кассир:\n");
    cout << work;
    printf("Товары:\n");
    printf("Цена  *  Название\n\n");
    int sm = 0;
    int *scost = &sm;
    for (size_t j = 0; j < i; j++)
    {
        scost = prd[n[j]].fcout(scost); //указатель
    }
    printf("\nОбщая цена: %d\n", *scost);
    printf("\n***************************************************************************************************\n");
    printf("Введите счет оплаты: ");
    string id;
    cin >> id;
    Pay<string> pay{ id, "1234", *scost};
    pay.print();
    delete[] n;
    number++;
}