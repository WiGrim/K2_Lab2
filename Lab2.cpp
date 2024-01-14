// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <string>
#include <vector>
#include "Human.h"
#include "Customers.h"
#include "Workers.h"
#include "Providers.h"
#include "Product.h"
#include "Chek.h"
#include "Pay.h"
using namespace std;

static int custtype = 0, typ1count = 0, typ2count = 0;
static int c1 = 0, c2 = 0, c3 = 0;

void Scn(int* s) { // Проверка на ввод числа
    int scn = scanf("%d", s);
    rewind(stdin);
    if (scn == 0)
    {
        printf("\nОшибка. Введите число.\n");
    }
}

void chekMake(int ct, Customers cust[2][2], Chek* ck[], Workers work, Product* prodct, int nprod) {  
    if (ct > 2 || ct < 1)
    {
        throw "Выбран не верный пунк списка, операция отменена.";
    }
    int n;
    if (ct == 1)
    {
        printf("Выбирете покупателя:\n");
        for (size_t i = 0; i < typ1count; i++)
        {
            printf("%d ", i + 1);
            cust[ct- 1][i].print(i);
            printf("\n");
        }
        do
        {
            Scn(&n);
            if (n < 1 || n > typ1count)
                printf("\nОшибка. Введите корректный пункт списка.\n");
        } while (n < 1 || n > typ1count);               
    }
    else
    {
        printf("Выбирете покупателя:\n");
        for (size_t i = 0; i < typ2count; i++)
        {
            printf("%d ", i + 1);
            cust[ct - 1][i].print(i);
            printf("\n");
        }        
        do
        {
            Scn(&n);
            if (n < 1 || n > typ2count)
                printf("\nОшибка. Введите корректный пункт списка.\n");
        } while (n < 1 || n > typ2count);
    }
    ck[number] = new Chek(number + 1);
    ck[number]->Chekk(cust[ct- 1][n - 1], work, prodct, nprod);
}

int CheckPay();

int main()
{
    setlocale(LC_ALL, "Russian");
    Customers cust[2][2];
    Workers work;
    Product* prodct = NULL;
    Providers* prov = NULL;
    Chek* ck[100];
    vector<Customers> cv;
    vector<Customers> cv0;
    
	printf("Вводите названия на английском.\n");
    
    extern int number, custtype, typ1count, typ2count;
    int c, npost = 0, nprod = 0;
	do //1 ур. меню
	{
		printf("\n1 Ввод покупателя\n2 Ввод работника\n3 Работа с товарами\n4 Составление чека\n5 Сводка по покупателям\n6 Выход\n");
		do
		{
			Scn(&c);
			if (c < 1 || c > 6)
				printf("\nОшибка. Введите корректный пункт списка.\n");
		} while (c < 1 || c > 6);//Проверка ввода c
        switch (c)
        {
        case 1:
            do
            {
                
                printf("Выберите тип покупателя:\n1 Обычный\n2 VIP\n");
                Scn(&custtype);
                if (custtype < 1 || custtype > 2)
                    printf("\nОшибка. Введите корректный пункт списка.\n");
            } while (custtype < 1 || custtype > 2);
            if (custtype == 1)
            {
                cust[custtype - 1][typ1count].CEnter();
                typ1count++;
            }
            else
            {
                cust[custtype - 1][typ2count].CEnter();
                typ2count++;
            }           
            printf("\nУстановить возраст для покупателя? (0 - нет; 1 - да)\n");
            do
            {
                Scn(&c);
                if (c < 0 || c > 1)
                    printf("\nОшибка. Введите корректный пункт списка.\n");
            } while (c < 0 || c > 1);
            if (c)
            {
                if (custtype == 1)
                {
                    printf("Возраст: ");
                    int n;
                    Scn(&n);
                    cust[custtype - 1][typ1count - 1].setCyear() = n;
                    printf("Возраст покупателя установлен: %d", cust[custtype - 1][typ1count - 1].getCyear());
                }
                else
                {
                    printf("Возраст: ");
                    int n;
                    Scn(&n);
                    cust[custtype - 1][typ2count - 1].setCyear() = n;
                    printf("Возраст покупателя установлен: %d", cust[custtype - 1][typ2count - 1].getCyear());
                }
            }
            c1 = 1;
            break;
        case 2:
            work.WEnter();
            CheckPay();
            printf("\nУстановить новую зарплату для работников? (0 - нет; 1 - да)\n");
            do
            {
                Scn(&c);
                if (c < 0 || c > 1)
                    printf("\nОшибка. Введите корректный пункт списка.\n");
            } while (c < 0 || c > 1);
            if (c)
            {
                printf("Зарплата работников: ");
                int sm;
                Scn(&sm);
                work.setPay(sm);
            }
            c2 = 1;
            break;
        case 3:           
            if (c3)
            {               
                printf("\nИзменить кол-во товаров? (0 - нет; 1 - да)\n");
                do
                {
                    Scn(&c);
                    if (c < 0 || c > 1)
                        printf("\nОшибка. Введите корректный пункт списка.\n");
                } while (c < 0 || c > 1);
                if (c)
                {
                    printf("\nИзменить кол-во товаров у:\n0 Магазина\n1 Поставщика\n");
                    do
                    {
                        Scn(&c);
                        if (c < 0 || c > 1)
                            printf("\nОшибка. Введите корректный пункт списка.\n");
                    } while (c < 0 || c > 1);
                    printf("\nУменьшить кол-во товаров на: \n");
                    int n;
                    Scn(&n);
                    if (c)
                    {
                        for (size_t i = 0; i < nprod; i++)
                        {
                            prov[i].CountLess(n);
                            prodct[i].prdprint();
                            printf("\nНовое кол-во: %d\n", prov[i].getCount());
                        }
                        
                    }
                    else
                    {
                        for (size_t i = 0; i < nprod; i++)
                        {
                            prodct[i].CountLess(n);
                            prodct[i].prdprint();
                            printf("\nНовое кол-во: %d\n", prodct[i].getCount());
                        }
                    }
                    
                }
            }
            else
            {
                printf("\nВведите кол-во товаров: ");
                Scn(&nprod);
                prodct = new Product[nprod];
                prov = new Providers[nprod];
                for (size_t i = 0; i < nprod; i++)
                {
                    prodct[i].ProdEnter();
                    prov[i].ProvEnter();
                    //int* p = prodct[i].
                }
            }            
            c3 = 1;
            break;
        case 4:
            if (c1 & c2 & c3)
            {
                int t = 0;
                printf("Выберите тип покупателя:\n1 Обычный\n2 VIP\n");
                Scn(&t);
                try {
                    chekMake(t, cust, ck, work, prodct, nprod);
                }
                catch (const char* err) {
                    cout << err;
                }
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
                    printf("Товары не заполнены\n");
                }
            }
            break;
        case 5:
            if (c1)
            {
                printf("\nСортировка проводится по годам, их необходимо установить заранее");
                for (size_t i = 0; i < typ1count; i++)
                {
                    cv.push_back(cust[0][i]);
                }
                for (size_t i = 0; i < typ2count; i++)
                {
                    cv.push_back(cust[1][i]);
                }
                int size = cv.size();
                printf("\nСуществуюшие возрасты покупателей:\n");
                for (size_t i = 0; i < size; i++)
                {
                    printf("%d ", cv[i].getCyear());
                }
                cv0.push_back(cust[0][0]);
                for (int i = 0; i < size - 1; i++) { //сортировка пузырьком
                    for (int j = 0; j < size - i - 1; j++) {
                        if (cv[j].getCyear() > cv[j + 1].getCyear()) {
                            cv0[0] = cv[j];
                            cv[j] = cv[j + 1];
                            cv[j + 1] = cv0[0];
                        }
                    }
                }
                printf("\nОтсортированные:\n");
                for (size_t i = 0; i < size; i++)
                {
                    printf("%d ", cv[i].getCyear());
                }
                printf("\nНайти покупателя по ФИ? (0 - нет; 1 - да)\n");
                do
                {
                    Scn(&c);
                    if (c < 0 || c > 1)
                        printf("\nОшибка. Введите корректный пункт списка.\n");
                } while (c < 0 || c > 1);
                if (c)
                {
                    char ffname[10], llname[15];
                    printf("\nВведите имя:\n");
                    fgets(ffname, 10, stdin);
                    rewind(stdin);
                    printf("Фамилия: ");
                    fgets(llname, 15, stdin);
                    rewind(stdin);

                    for (size_t i = 0; i < size; i++)
                    {
                        if (strcmp(ffname, cv[i].getFName()) == 0)
                        {
                            printf("Информация о покупателе:\n");
                            cv[i].print(i);
                            puts(cv[i].getCemail());
                            printf("%d\n", cv[i].getCyear());
                            c = 0;
                            break;
                        }                        
                    }
                    if (c)
                    {
                        printf("Пользователь не найден\n");
                    }
                }
            }
            break;
        case 6:
            break;
        default: printf("\nОшибка. Некорректная переменная ввода. >>> c in main\n");
            break;
        }
	} while (c != 6);
    delete[] ck;
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
