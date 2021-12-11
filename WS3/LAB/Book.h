/*
Name: Aditya Dharmesh Patel
Student ID : 143595205
email: adpatel31@myseneca.ca
Section:NBB
Date: 29-sep-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
namespace sdds
{
	class Book
	{
	private://function called to seperate from local data
		char m_title[51];//Title
		int m_SKU;//Barcode
		int m_daysOnLoan;//Loaning days
		void setEmpty();
		double penalty() const;

	public:
		void set(const char* book_title, int SKU, int loanDays);
		bool isEmpty() const;
		bool hasPenalty() const;
		bool subTitle(const char* substr) const;
		void display() const;
	};
}


#endif