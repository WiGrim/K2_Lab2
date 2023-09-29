// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
using namespace std;

struct Human
{
    char fname[10], lname[15], tname[15];
    int tel;
};

struct Customers
{
    Human hum;
    char email[25];
};

struct Workers
{
    Human hum;
    int pay;
};

struct Providers
{
    char type[10], PName[15], PAderes[15];
};

struct Products
{
    Providers prov;
    char ProdName[10];
    int cost, count;
};

struct Chek
{
    Customers cust;
    Workers work;
    Products product[20];
};

static int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

void Scn(int* s) { // Проверка на ввод числа
    int scn = scanf("%d", s);
    rewind(stdin);
    if (scn == 0)
    {
        printf("\nОшибка. Введите число.\n");
    }
}

void CEnter(Customers customer[]) {
    printf("Покупатель:\nИмя: ");
    fgets(customer[0].hum.fname, 10, stdin);
    rewind(stdin);
    printf("Фамилия ");
    fgets(customer[0].hum.lname, 15, stdin);
    rewind(stdin);
    printf("Отчество: ");
    fgets(customer[0].hum.tname, 15, stdin);
    rewind(stdin);
    printf("Телефон: ");
    scanf("%d", &customer[0].hum.tel);
    rewind(stdin);
    printf("Емаил: ");
    fgets(customer[0].email, 25, stdin);
    rewind(stdin);
    c1 = 1;
}

void WEnter(Workers worker[], int nwork) {
    for (size_t i = 0; i < nwork; i++)
    {
        printf("Работник:\nИмя: ");
        fgets(worker[i].hum.fname, 10, stdin);
        rewind(stdin);
        printf("Фамилия ");
        fgets(worker[i].hum.lname, 15, stdin);
        rewind(stdin);
        printf("Отчество: ");
        fgets(worker[i].hum.tname, 15, stdin);
        rewind(stdin);
        printf("Телефон: ");
        scanf("%d", &worker[i].hum.tel);
        rewind(stdin);
        printf("Зарплата: ");
        Scn(&worker[i].pay);
    }
    c2 = 1;
}

void ProvEnter(Providers providers[], int npost) {
    for (size_t i = 0; i < npost; i++)
    {
        printf("Поставщик:\nНазвание: ");
        fgets(providers[i].PName, 15, stdin);
        rewind(stdin);
        printf("Тип товаров: ");
        fgets(providers[i].type, 10, stdin);
        rewind(stdin);
        printf("Адреса доставки: ");
        fgets(providers[i].PAderes, 15, stdin);
        rewind(stdin);
    }
    c3 = 1;
}

void ProdEnter(Products products[], Providers providers[], int npost, int nproduct) {
    for (size_t i = 0; i < npost; i++)
    {
        printf("\nПоставщик #%d:\nНазвание: ", i+1);
        puts(providers[i].PName);
        printf("Тип товаров: ");
        puts(providers[i].type);
        printf("Адреса доставки: ");
        puts(providers[i].PAderes);
    }
    for (size_t i = 0; i < nproduct; i++)
    {
        int u;
        printf("Товар:\nВыберите поставщика: ");
        Scn(&u);
        products[i].prov = providers[u - 1];
        printf("Название: ");
        fgets(products[i].ProdName, 10, stdin);
        rewind(stdin);
        printf("Цена: ");
        Scn(&products[i].cost);
        printf("Количество: ");
        Scn(&products[i].count);
    }
    c4 = 1;
}

void CChek(Customers customer[], Workers worker[], Products products[], int nwork, int nprod, Chek chek[], int nchek) {
    chek[nchek].cust = customer[0];
    printf("\nВыберите продавца:\n");
    for (size_t i = 0; i < nwork; i++)
    {
        puts(worker[i].hum.lname);
    }
    printf("\n");
    int u;
    Scn(&u);
    chek[nchek].work = worker[u];
    printf("\n");
    for (size_t i = 0; i < nprod; i++)
    {
        printf("%d ", i + 1);
        puts(products[i].ProdName);
    }
    printf("\n%d Выход\nВыберите продукт для добавления: ", nprod + 1);
    int i = 0;
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
            chek[nchek].product[i] = products[u];
            i++;
            printf("Добавлено\n");
        }
    } while (u != nprod + 1);

    printf("\n***************************************************************************************************\n");
    printf("Чек\n\nПокупатель:\n");
    puts(chek[nchek].cust.hum.fname);
    puts(chek[nchek].cust.hum.lname);
    puts(chek[nchek].cust.hum.tname);
    printf("Кассир:\n");
    puts(chek[nchek].work.hum.fname);
    puts(chek[nchek].work.hum.lname);
    puts(chek[nchek].work.hum.tname);
    printf("Товары:\n");
    printf("Цена  *  Название\n\n");
    int scost = 0;
    for (size_t j = 0; j < i; j++)
    {
        printf("%5d * ", chek[nchek].product[j].cost);
        scost += chek[nchek].product[j].cost;
        puts(chek[nchek].product[j].ProdName);
    }
    printf("\nОбщая цена: %d\n", scost);
    printf("\n***************************************************************************************************\n");
    nchek++;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Customers customer[1];
    Workers worker[5];
    Products products[20];
    Providers providers[5];
    Chek chek[10];

	printf("Вводите названия на английском.\n");
	int c, npost, nprod, nwork, nchek = 0;
    extern int c1, c2, c3, c4;
	do //1 ур. меню
	{
		printf("\n1 Ввод покупателя\n2 Ввод работника\n3 Ввод поставщиков\n4 Ввод товаров\n5 Составление чека\n6 Выход\n");
		do
		{
			Scn(&c);
			if (c < 1 || c > 6)
				printf("\nОшибка. Введите корректный пункт списка.\n");
		} while (c < 1 || c > 6);//Проверка ввода c
        switch (c)
        {
        case 1:
            CEnter(customer);
            break;
        case 2:
            do
            {
                printf("\nВведите кол-во работников (МАКС - 5): ");
                Scn(&nwork);
                if (nwork < 1 || nwork > 5)
                {
                    printf("\nОшибка. Введите корректное кол-во.\n");
                }
            } while (nwork < 1 || nwork > 5);
            WEnter(worker, nwork);
            break;
        case 3:
            do
            {
                printf("\nВведите кол-во поставщиков (МАКС - 5): ");
                Scn(&npost);
                if (npost < 1 || npost > 5)
                {
                    printf("\nОшибка. Введите корректное кол-во.\n");
                }
            } while (npost < 1 || npost > 5);
            ProvEnter(providers, npost);
            break;
        case 4:
            if (c3)
            {
                do
                {
                    printf("\nВведите кол-во товаров (МАКС - 20): ");
                    Scn(&nprod);
                    if (nprod < 1 || nprod > 20)
                    {
                        printf("\nОшибка. Выберите корректный id строки.\n");
                    }
                } while (nprod < 1 || nprod > 20);
                ProdEnter(products, providers, npost, nprod);
            }
            else
            {
                printf("\nОшибка. Список поставщиков пуст.\n");
            }
            break;
        case 5:
            if (c1 & c2 & c3 & c4)
            {
                CChek(customer, worker, products, nwork, nprod, chek, nchek);
            }
            else
            {
                printf("\nОшибка. Не все поля заполнены.\n");
                if (!c1)
                {
                    printf("Покупатель не заполнен\n");
                }
                if (!c2)
                {
                    printf("Продавец не заполнен\n");
                }
                if (!c3)
                {
                    printf("Поставщики не заполнены\n");
                }
                if (!c4)
                {
                    printf("Товары не заполнены\n");
                }
            }
            break;
        case 6:
            break;
        default: printf("\nОшибка. Некорректная переменная ввода. >>> c in main\n");
            break;
        }
	} while (c != 6);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
