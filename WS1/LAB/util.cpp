
#include <iostream>
#include <cstdio>
#include "util.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds
{
    bool confirm()
    {
        char choice = cin.get();
        clearBuffer();
        return choice == 'Y';
    }

    void clearBuffer()
    {
        while (cin.get() != '\n');
    }
}