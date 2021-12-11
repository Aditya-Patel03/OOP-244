/*
Name: Aditya Dharmesh Patel
Student ID : 143595205
email : adpatel31@myseneca.ca
Section : NBB
Date : 02 - oct - 2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_BACK_H
#define SDDS_BACK_H
#include "Account.h"

namespace sdds
{
	class Bank
	{
		char m_name[31];
		Account* m_accounts;
		int m_sizeOfAccountsArray;
		int m_addedAccounts;
		void setEmpty();
		bool isEmpty()const;
		void header(const char* title)const;
	public:
		void  initialize(const  char* bank_name, int noOfAccounts);
		bool  addAccount(int account_number, double balance, int daysSinceLastPayment);
		void  display(bool intrestOnly = false) const;
		void clear();

	};
}

#endif

