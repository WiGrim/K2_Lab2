#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
using namespace std;

class Providers
{
public:
    Providers(char PName[15], char PAderes[15]);
    Providers();
    ~Providers();
    void set(char name[], char adr[], int count);
    char* getPName();
    char* getPAdres();
    virtual void CountLess(int count);
    void ProvEnter();
    int getCount();
    //void ProvEnter();
private:
    char PName[15], PAderes[15];
    int count;
};



