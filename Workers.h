#pragma once
#include "Human.h"

//static int c2 = 0;

class Workers : public Human
{

    friend int CheckPay();//������������� �-��

public:
    Workers();
    ~Workers();
    void setPay(int sm);//����������� �����
    void WEnter();
private:
    static int pay; //����������� ����������
};



