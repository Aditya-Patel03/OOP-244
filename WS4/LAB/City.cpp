/*
Name: Aditya Dharmesh Patel
Student ID : 143595205
email: adpatel31@myseneca.ca
Section:NBB
Date: 06 - oct -2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "City.h"
using namespace std;
namespace sdds
{
	City::City()
	{
		setEmpty();
	}
	City::City(const char* name, int population)
	{
		setEmpty();
		if (name != nullptr && strlen(name)>0 && population >= 0)//Validating whether name is null or not 
		{
			strncpy(m_cityName, name, 30); m_population = population;
		}
		else
		{
			setEmpty();
		}
	}
	void City::setEmpty()
	{
		m_cityName[0] = '\0';
		m_population = -1;
	}
	void City::setCityName(const char* name) {
		if (name != nullptr)
		{
			strncpy(m_cityName, name, 30);
		}
		else
		{
			m_cityName[0] = '\0';
		}
	}
	void City::setPopulation(int population) {
		if (population < POPULATION&&population>=0)
		{
			m_population = population;
		}
		else
		{
			m_population = -1;
		}
	}
	void City::addPopulation(int population) {
		m_population += population;
		if (m_population > POPULATION)
		{
			m_population = POPULATION;
		}
	}
	bool City::isEmpty()const {
		return ((strlen(m_cityName) == 0) || (m_population < 0));
	}
	int City::getPeople()const {
		return m_population;
	}
	void City::display()const {
		if (!isEmpty())
		{
			cout << "|" << left << setw(30) << m_cityName << " | " << right << setw(10) << m_population << " | " << endl;
		}
		else
		{
			cout << "invalid city" << endl;
		}
	}
}