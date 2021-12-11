/*
Name: Aditya Dharmesh Patel
Student ID : 143595205
email: adpatel31@myseneca.ca
Date: 20-sep-2021
*/
#define _CRT_SECURE_NO_WARNINGS
/*I have done the workshop by myself and only copied the code provided by the professor in the github*/
#include <iostream>
#include <cstdio>
#include "drink.h"
#include "util.h"
using namespace std;
using namespace sdds;


int main()
{
    bool done = false;
    //loadDrinks();
    loadDrinksFromFile("drinks.txt");
     cout << "Welcome to the Seneca Vending Machine" << endl << endl;
    while (!done)
    {
        drinkMenu();
        chooseDrink();
        cout << "\nDo you want to order another drink? (Y)es or (N)o: ";
        done = !confirm();
        cout << endl;
    }
    drinkMenu();
    cout << "\nThank you and come again" << endl;
    return 0;

}