#pragma once
#include "Providers.h"

char aPName[15], aPAdres[15];

void Scn(int* s);

Providers::Providers(char PName[15], char PAderes[15])
{
    strcpy(this->PName, PName);
    strcpy(this->PAderes, PAderes);
}

Providers::Providers()
{
}

Providers::~Providers()
{
}

void Providers::set(char name[], char adr[], int count)
{
    strcpy(this->PName, name);
    strcpy(this->PAderes, adr);
    this->count = count;
}

char* Providers::getPName()
{
    return PName;
}

char* Providers::getPAdres()
{  
    return PAderes;
}

int Providers::getCount() {
    return count;
}

void Providers::CountLess(int count) {
    this->count -= count;
}

void Providers::ProvEnter() {
    int Pcost;
    printf("���������: ");
    fgets(aPName, 15, stdin);
    printf("������: ");
    fgets(aPAdres, 15, stdin);
    printf("���-�� ������ � ����������: ");
    Scn(&Pcost); //do while
    set(aPName, aPAdres, Pcost);
}

/*void Providers::ProvEnter() {
    printf("���������:\n��������: ");
    fgets(aPName, 15, stdin);
    rewind(stdin);
    printf("��� �������: ");
    fgets(atype, 10, stdin);
    rewind(stdin);
    printf("������ ��������: ");
    fgets(aPAdres, 15, stdin);
    rewind(stdin);

    c3 = 1;
}*/
