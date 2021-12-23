// TestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <map>
#include <string>

//#include "BJack.h"

using namespace std;


// ------
// Task 1
template<typename T>
double div(T a, T b) {
	if (!b)
		throw "DiversionByZero";

	return a / b;
}


// ------
// Task 2
class Ex
{
public:
	Ex(double x) try : m_x(x) {
		throw m_x;
	}
	catch (double dbV)
	{
		cerr << "Exeption: " << dbV << endl;
	}
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

// ------
// Task 3
class Robot;

enum eMove {
	Stop,
	Left,
	Rigth,
	Up,
	Down
};

std::map<eMove, const char*> g_mapMove = {
	{ Left,  "Left" },
	{ Rigth, "Rigth" },
	{ Up,    "Up" },
	{ Down,  "Down" }
};

class OffTheField
{
public:
	OffTheField(eMove move, int x, int y) try :
		m_move(move),
		m_x(x),
		m_y(y) {
		throw 1;
	}
	catch (int n)
	{
		cerr << "Exeption OffTheField" << endl;
		cerr << "move: " << g_mapMove[move] << " X: " << x << " Y: " << y << endl;
	}

	~OffTheField() {}
private:
	int   m_x;
	int   m_y;
	eMove m_move;
};

class IllegalCommand
{
public:
	 IllegalCommand(eMove move, int x, int y) try :
		m_move(move),
		m_x(x),
		m_y(y) {
		throw 1;
	}
	catch (int n)
	{
		cerr << "Exeption IllegalCommand" << endl;
		cerr << "move: " << g_mapMove[move] << " X: " << x << " Y: " << y << endl;
	}

	~IllegalCommand() {}
private:
	int   m_x;
	int   m_y;
	eMove m_move;
};

const int g_nSize = 10;

class Robot
{
public:
	Robot() : m_x(0), m_y(0), m_move(Down) {}
	~Robot() {}

	void Move(eMove move, int step) {
		m_move = move;
		if (m_move == Left)
			Shift(m_x, -step);
		else if (m_move == Rigth)
			Shift(m_x, step);
		else if (m_move == Up)
			Shift(m_y, -step);
		else if (m_move == Down)
			Shift(m_y, step);
		else if (m_move == Stop)
			cout << "Stop robot" << endl;
		else
			throw IllegalCommand::IllegalCommand(move, m_x, m_y);

		cout << "move: " << g_mapMove[move] << " X: " << m_x << " Y: " << m_y << endl;
	}

private:
	void Shift(int &nCoord, int step) {
		if ((nCoord + step > g_nSize) ||
			(nCoord + step < 0))
			throw OffTheField::OffTheField(m_move, m_x, m_y);

		nCoord += step;
	}

private:
	int   m_x;
	int   m_y;
	eMove m_move;
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

	// Task 2
	Bar bar;
	int nParam = 0;
	do {
		cout << "Enter value:" << endl;
		cin >> nParam;
		try {
			bar.set(nParam);
		}
		catch (...){

		}

		cin.clear();

	} while (nParam);

	// Task 3
	Robot robot;
	do {
		cout << "Robot:" << endl;
		cout << "0 - exit:" << endl;
		cout << "1 - Left:" << endl;
		cout << "2 - Rigth:" << endl;
		cout << "3 - Up:" << endl;
		cout << "4 - Down:" << endl;
		cout << "Enter step:" << endl;

		cin >> nParam;
		robot.Move(static_cast<eMove>(nParam), 1);
		cin.clear();

	} while (nParam);

	system("pause");
}

