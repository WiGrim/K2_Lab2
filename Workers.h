#pragma once
#include "Human.h"

//static int c2 = 0;

class Workers : public Human
{

    friend int CheckPay();//Дружественная ф-ия

public:
    Workers();
    ~Workers();
    void setPay(int sm);//Статический метод
    void WEnter();
private:
    static int pay; //Статическая переменная
};



