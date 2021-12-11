/*
Name: Aditya Dharmesh Patel
Student ID : 143595205
email : adpatel31@myseneca.ca
Section : NBB
Date : 02 - oct - 2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Account.h"

using namespace std;

namespace sdds
{
	const int MAX_DAYS = 30;
	const double Rate = 0.285;
	const int NumberOfDaysInAYear = 365;

	void Account::set(int account_namber, double balance, int daysSinceLastPayment) {
		if (account_namber > 0 && balance > 0 && daysSinceLastPayment > 0)
		{      
			m_account = account_namber;
			m_balance = balance;
			m_days = daysSinceLastPayment;
		}
		else
		{
			setvalid();       
		}
	}

	bool Account::isInvalid() const {    
		bool invalid = false;
		if (m_account <= 0 && m_balance <= 0 && m_days <= 0)
		{
			invalid = true;
		}
		return invalid;
	}

	void Account::setvalid() {        
		m_account = 1;
		m_balance = 1;
		m_days = 1;
	}

	bool Account::hasIntrest() const {         
		bool yesno = false;
		if (m_days > MAX_DAYS)
		{
			yesno = true;
		}
		return yesno;
	}

	double Account::display() const {           
		double in = 0;
		if (!isInvalid())
		{
			cout.width(10);
			cout.fill(' ');
			cout << m_account;
			cout.unsetf(ios::left);
			cout.width(12);
			cout.fill(' ');
			cout.setf(ios::right);
			cout.precision(2);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout << "  ";
			cout.width(4);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_days;
			cout.unsetf(ios::left);
			if (hasIntrest())
			{                     
				in = intrest();
				cout.width(8);
				cout.fill(' ');
				cout.setf(ios::right);
				cout.precision(2);
				cout << in;
			}
			cout.unsetf(ios::right);
			cout << endl;
		}
		return in;
	}

	double Account::intrest() const {
		double intrest = 0;
		if (hasIntrest())
		{                      
			intrest = m_days * (Rate / NumberOfDaysInAYear) * m_balance;
		}
		return intrest;
	}

}