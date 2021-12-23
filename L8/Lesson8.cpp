// TestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

//#include "BJack.h"

using namespace std;

template<typename T>
double div(T a, T b) {
	if (!b)
		throw "DiversionByZero";

	return a / b;
}


class Robot
{
public:
	Robot() {}
	~Robot() {}

private:

};


class Ex
{
public:
	Ex(double x) : m_x(x) {}
	~Ex() {}

private:
	double m_x;
};

class Bar
{
public:
	Bar() : m_y(0) { }
	~Bar() {}

	void set(double a) {
		if (a + m_y > 100)
			throw  Ex::Ex(a * m_y);

		m_y = a;
	}

private:
	double m_y;
};

void main()
{
	// Task 1
	try {
		div(2., 0.);
	}
	catch (const char* exeption) {
		cerr << exeption << endl;
	}

	Bar bar;
	int nParam = 0;
	do {
		cout << "Enter value:" << endl;
		cin >> nParam;
		bar.set(nParam);
		try {

		}
		catch (...){

		}

		cin.clear();

	} while (nParam);

	system("pause");
}

