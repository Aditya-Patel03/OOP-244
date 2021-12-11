/*
Name: Aditya Dharmesh Patel
Student ID : 143595205
email: adpatel31@myseneca.ca
Section:NBB
Date: 29-sep-2021
*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Library.h"

using namespace std;

namespace sdds
{
	void Library::setEmpty()
	{
		m_name[0] = '\0';
		m_sizeOfBooksArray = 0;
		m_books = nullptr;
		m_addedBooks = 0;
	}
	bool Library::isEmpty()const
	{
		return m_name[0] == '\0' && m_sizeOfBooksArray == 0 && m_books == nullptr && m_addedBooks == 0;
	}
	void Library::header(const char* title)const
	{
		cout.width(78);
		cout.fill('-');
		cout << "-" << endl;
		cout << "*****  " << m_name << "  *****" << endl;
		cout << title << endl;
		cout.width(78);
		cout.fill('-');
		cout << "-" << endl;
		cout << "Row Book title                                       SKU     loan days penalty" << endl;
		cout << "--- ------------------------------------------------ ------- --------- -------" << endl;

	}
	void Library::footer()const
	{
		cout.width(78);
		cout.fill('-');
		cout << "-" << endl;
	}
	void Library::initialize(const char* name, int noOfBooks)
	{
		if (name != nullptr && name[0] != '\0' && noOfBooks > 0)
		{
			strcpy(m_name, name);
			m_sizeOfBooksArray = noOfBooks;
			m_books = new Book[noOfBooks];
			m_addedBooks = 0;
		}
		else
			setEmpty();
	}
	bool Library::addBook(const char* book_title, int sku, int loanDays)
	{
		bool res = false;
		if (m_addedBooks < m_sizeOfBooksArray)
		{
			m_books[m_addedBooks].set(book_title, sku, loanDays);
			if (!m_books[m_addedBooks].isEmpty())
			{
				res = true;
				m_addedBooks++;
			}
		}
		return res;
	}
	void Library::clear()
	{
		delete[]m_books;
		m_books = nullptr;
	}
	void Library::display(const char* substr)
	{
		if (!isEmpty())
		{
			bool found = false;
			cout << ">>> Searching for: \"" << substr << "\" <<<" << endl;
			header("Substring search");
			int row = 1;
			for (int i = 0; i < m_addedBooks; i++)
			{
				if (m_books[i].subTitle(substr))
				{
					cout.width(4);
					cout.fill(' ');
					cout.setf(ios::left);
					cout << row++;
					m_books[i].display();
					found = true;
				}


			}
			if (!found)
				cout << "No book title contains \"" << substr << "\"" << endl;
			footer();
		}
		else
			cout << "Invalid Library" << endl;
	}
	void Library::display(bool overdueOnly) const
	{
		if (!isEmpty())
		{
			int row = 1;
			header(overdueOnly ? "Overdue Books" : "Books on Loan");
			for (int i = 0; i < m_addedBooks; i++)
			{
				if (!overdueOnly || m_books[i].hasPenalty())
				{
					cout.setf(ios::left);
					cout.width(4);
					cout.fill(' ');
					cout << row++;
					m_books[i].display();
				}
			}
			footer();
		}
		else
			cout << "Invalid Library" << endl;
	}
}
