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

    friend int CheckPay();//������������� �-��
    
public:
    Workers();
    ~Workers();
    void setPay(int sm);//����������� �����
    void WEnter();
    friend ostream& operator<<(ostream& out, Workers wrk) {
        return out << "���: " << wrk.getFName() << "�������: " << wrk.getLName() << "��������: " << wrk.getTName() << endl;
    }
private:
    static int pay; //����������� ����������
};



