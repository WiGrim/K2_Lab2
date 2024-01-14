#pragma once
class Human
{
public:
    Human();
    ~Human();
    void set();
    void print();
    char* getFName();
    char* getLName();
    char* getTName();
private:
    char fname[10], lname[15], tname[15];
    int tel;
};



