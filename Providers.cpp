#pragma once
#include "Providers.h"

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

void Providers::set(char name[], char adr[])
{
    strcpy(this->PName, name);
    strcpy(this->PAderes, adr);
}

/*void Providers::ProvEnter() {
    printf("Поставщик:\nНазвание: ");
    fgets(aPName, 15, stdin);
    rewind(stdin);
    printf("Тип товаров: ");
    fgets(atype, 10, stdin);
    rewind(stdin);
    printf("Адреса доставки: ");
    fgets(aPAdres, 15, stdin);
    rewind(stdin);

    c3 = 1;
}*/