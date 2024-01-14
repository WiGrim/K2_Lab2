#pragma once
#include "Human.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
using namespace std;

Human::Human()
{
}

Human::~Human()
{
}

void Human::set()
{
    fgets(fname, 10, stdin);
    rewind(stdin);
    printf("Фамилия ");
    fgets(lname, 15, stdin);
    rewind(stdin);
    printf("Отчество: ");
    fgets(tname, 15, stdin);
    rewind(stdin);
    printf("Телефон: ");
    scanf("%d", &tel);
    rewind(stdin);
}

void Human::print()
{
    puts(this->fname);
    puts(this->lname);
    puts(this->tname);
}

char* Human::getFName() {
    return fname;
}

char* Human::getLName() {
    return lname;
}

char* Human::getTName() {
    return tname;
}