
#pragma once
#ifndef SDDS_DRINKH_H
#define SDDS_DRINKH_H
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

namespace sdds
{

    struct Drink
    {
        char name[10];
        int volume;
        double price;
        int quantity;
    };
    void loadDrinksFromFile(const char* filename);

    //void loadDrinks();
    void drinkMenu();
    void displayDrink(const Drink* drink);
    int chooseDrink();
    bool updateDrink(int sel);
}
#endif