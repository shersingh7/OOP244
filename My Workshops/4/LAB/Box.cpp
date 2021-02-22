//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       4 (Lab)
// Date:           10/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Box.h"

using namespace std;
using namespace sdds;

void Box::setName(const char* Cstr)
{
	if (Cstr != nullptr)
	{
		delete[] m_contentName;
		m_contentName = nullptr;

		int length = strlen(Cstr);

		m_contentName = new char[length + 1];

		strcpy(m_contentName, Cstr);
	}
}

void Box::setUnusable()
{
	delete[] m_contentName;
	m_contentName = nullptr;

	m_width = -1;
	m_height = -1;
	m_length = -1;
	m_contentVolume = -1;
}

bool Box::isUnusable()const
{
	bool ok = false;

	if (m_height == -1 || m_length == -1 || m_width == -1)
	{
		ok = true;
	}
	return ok;
}

bool Box::hasContent()const
{
	bool ok = false;

	if (quantity() > 0)
	{
		ok = true;
	}
	return ok;

}


int Box::capacity()const
{
	return m_height * m_length * m_width;
}

int Box::quantity()const
{
	return m_contentVolume;
}

Box& Box::setContent(const char* contentName)
{
	if ((hasContent()) && (contentName != nullptr))
	{
		setUnusable();
	}
	setName(contentName);

	return *this;
}

std::ostream& Box::display()const
{
	if (isUnusable())
	{
		cout << "Unusable box, discard the content, and recycle.";
	}

	else if (m_contentName == nullptr)
	{
		cout << setw(30);
		cout.fill('.');
		cout << left << "Empty box";

		cout << "  " << right << setw(2);
		cout.fill('0');
		cout << m_width;

		cout << "x" << right << setw(2);
		cout.fill('0');
		cout << m_height;


		cout << "x" << right << setw(2);
		cout.fill('0');
		cout << m_length;

		cout << "  " << setw(6) << right;
		cout.fill(' ');
		cout << quantity() << "/" << capacity() << " C.I.";

	}
	else
	{
		cout << left << setw(30);
		cout.fill('.');
		cout << m_contentName;

		cout << "  " << right << setw(2);
		cout.fill('0');
		cout << m_width;

		cout << "x" << right << setw(2);
		cout.fill('0');
		cout << m_height;


		cout << "x" << right << setw(2);
		cout.fill('0');
		cout << m_length;

		cout << "  " << setw(6) << right;
		cout.fill(' ');
		cout << quantity() << "/" << capacity() << " C.I.";
	}

	return cout;
}

Box& Box::add(int quantity)
{
	
	if ((quantity > 0) && (quantity <= capacity()))
	{
		m_contentVolume += quantity;
	}
	else
	{
		setUnusable();
	}
	return *this;
}

Box& Box::add(Box& B)
{
	if (m_contentName == nullptr || quantity() == 0) {
		setContent(B.m_contentName);
	}
	if (strcmp(m_contentName, B.m_contentName) == 0) {
		if (quantity() + B.quantity() <= capacity()) {
			add(B.quantity());
			B.m_contentVolume = 0;
		}
		else {
			B.m_contentVolume -= (capacity() - quantity());
			m_contentVolume = capacity();
		}
	}
	else {
		if (quantity() + B.quantity() <= capacity()) {
			B.m_contentVolume = 0;
		}
		else {
			B.m_contentVolume -= (capacity() - quantity());
		}
		setUnusable();
	}
	return *this;
	
}

