#pragma once
#include "Human.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;
//static int c2 = 0;

class Workers : public Human
{

    friend int CheckPay();//Дружественная ф-ия
    
public:
    Workers();
    ~Workers();
    void setPay(int sm);//Статический метод
    void WEnter();
    friend ostream& operator<<(ostream& out, Workers wrk) {
        return out << "Имя: " << wrk.getFName() << "Фамилия: " << wrk.getLName() << "Отчество: " << wrk.getTName() << endl;
    }
private:
    static int pay; //Статическая переменная
};



