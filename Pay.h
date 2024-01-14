#pragma once
#include <iostream> 
using namespace std;

template <typename T>
class Pay
{
public:
    Pay(T from, T to, int sum) : from{ from }, to{ to }, sum{ sum } { }

    void print() const
    {
        cout << "\n�� �����: " << from << "\n�� ����: " << to
            << "\n����� : " << sum << endl;
    }
private:
    T from;  
    T to; 
    int sum; 
};