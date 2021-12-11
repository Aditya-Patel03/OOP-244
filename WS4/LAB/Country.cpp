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
#include "Country.h"

using namespace std;
namespace sdds
{
	
	Country::Country() {
		setEmpty();
	}
	
	Country::Country(const char* name, int noOfCity, const City* cities) {
		setEmpty();
		if (name != nullptr && strlen(name) > 0 && noOfCity > 0 && noOfCity <= MAX_CITY) // validating with if loop
		{
			m_name = new char[strlen(name) + 1]; strcpy(m_name, name);
			m_noOfCity = noOfCity;
			m_city = new City[noOfCity];
			for (int i = 0; i < noOfCity; i++)
			{
				m_city[i] = cities[i];
			}
		}
		else
		{
			delete[]m_city;
			setEmpty();
		}
	}
	
	void Country::setName(const char* name) {
		delete m_name;//to delete any existing name

		if (name != nullptr && strlen(name) > 0)//validating with if loop
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else// if its not valid deletes current data and set to its safe empty state
		{
			delete[] m_city;
			setEmpty();
		}
	}
	Country& Country::addCity(const City& c) {
		if (!c.isEmpty())
		{
			City* temp = new City[m_noOfCity + 1];
			for (int i = 0; i < m_noOfCity; i++)
			{
				temp[i] = m_city[i];
			}delete[] m_city;
			temp[m_noOfCity] = c;
			m_city = temp;
			m_noOfCity++;
		}return *this;
	}
	Country& Country::migrate(int people) {
		for (int m = 0; m < m_noOfCity; m++)
		{
			if (m_city[m].getPeople() < POPULATION)
			{
				m_city[m].addPopulation(people);
			}
		}return *this;
	}
	void Country::setEmpty() {
		m_name = nullptr;
		m_city = nullptr;
		m_noOfCity = 0;
	}
	bool Country::isEmpty()const {
		return m_name == nullptr;
	}
	// IMP part-Deallocating the memory allocated by m_name and m_city.
	Country::~Country() {
		delete[] m_name;
		delete[] m_city;
	}

	void Country::display()const {
		if (!isEmpty())
		{
			cout << "Country Name: " << m_name; cout << endl;
			cout << "No of city: " << m_noOfCity; cout << endl;
			cout << left << setw(32) << "City name" << "Population" << endl;
			for (int i = 0; i < m_noOfCity; i++)
			{
				m_city[i].display();
			}

		}
		else
		{
			cout << "Invalid country object" << endl;
		}
	}
}