#pragma once
#include "Human.h"

//static int c1 = 0;

class Customers : public Human
{
public:
    Customers();
    ~Customers();
    void CEnter();
    int& setCyear();
    int getCyear();
    char* getCemail();
private:
    char email[25];
protected:
    int cyear;
};

