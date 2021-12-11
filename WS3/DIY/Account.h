/*
Name: Aditya Dharmesh Patel
Student ID : 143595205
email : adpatel31@myseneca.ca
Section : NBB
Date : 02 - oct - 2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H

namespace sdds
{
	class Account
	{
	private:
		int m_account;
		double m_balance;
		int m_days;
		void setvalid();
		double intrest() const;
	public:
		void set(int m_account_namber, double m_balance, int m_daysSinceLastPayment);
		bool isInvalid() const;
		bool hasIntrest() const;
		double display() const;
	};
}

#endif