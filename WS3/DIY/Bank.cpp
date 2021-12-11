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
#include <cstring>
#include "Bank.h"

using namespace std;

namespace sdds
{
	void Bank::initialize(const char* bank_name, int noOfAccounts) {
		if (bank_name != nullptr && bank_name[0] != '\0' && noOfAccounts > 0)       
		{
			strcpy(m_name, bank_name);
			m_sizeOfAccountsArray = noOfAccounts;
			m_accounts = new Account[noOfAccounts];          //dynamic memory
			m_addedAccounts = 0;
		}
		else
		{
			setEmpty();           
		}
	}

	void Bank::setEmpty() { 
		m_name[0] = 0;
		m_sizeOfAccountsArray = 0;
		m_accounts = nullptr;
		m_addedAccounts = 0;
	}

	bool Bank::addAccount(int account_number, double balance, int daysSinceLastPayment) {
		bool added = false;
		if (m_addedAccounts < m_sizeOfAccountsArray)
		{        
			m_accounts[m_addedAccounts].set(account_number, balance, daysSinceLastPayment);             
			if (!m_accounts[m_addedAccounts].isInvalid())
			{        
				added = true;
				m_addedAccounts++;
			}
		}
		return added;
	}

	void Bank::clear() {            //delete dynamic memory
		delete[] m_accounts;
		m_accounts = nullptr;
	}

	void Bank::display(bool intrestOnly) const {
		int row = 1;
		char title[31];
		if (intrestOnly == true)
		{
			strcpy(title, "INTEREST ONLY LIST!");  //string copy"INTEREST ONLY LIST!"
		}
		else
		{
			title[0] = 0;    
		}
		if (!isEmpty())
		{                    
			double total_interest = 0;
			header(title);                            //displaying header
			for (int i = 0; i < m_addedAccounts; i++)
			{                  //displaying accounts
				if (intrestOnly == false || m_accounts[i].hasIntrest())
				{
					cout.width(5);
					cout.fill(' ');
					cout.setf(ios::left);
					cout.setf(ios::fixed);
					cout << row;
					row++;
					total_interest += m_accounts[i].display();
				}
			}
			cout << "-----------------------------------------" << endl;          
			cout << "              Total interest:  " << total_interest << endl;
			cout.unsetf(ios::fixed);
			cout << endl;
		}
		else
		{
			cout << "Invalid Bank" << endl;
		}
	}

	bool Bank::isEmpty()const {            
		bool yesno = false;
		if ((m_name[0] == '\0') && (m_sizeOfAccountsArray == 0) && (m_addedAccounts == 0) && (m_accounts == nullptr))
		{
			yesno = true;
		}
		return yesno;
	}

	void Bank::header(const char* title)const {
		if (title[0] != 0)
		{				
			cout << title << endl;
		}
		cout << "----------------------------------------" << endl;        // header
		cout << ">>> " << m_name << " <<<" << endl;
		cout << "----------------------------------------" << endl;
		cout << "Row Accnt No       Balance  Days Interest" << endl;
		cout << "--- ---------- ------------ ---- --------" << endl;
	}


}