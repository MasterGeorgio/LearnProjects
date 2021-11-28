#include "stdafx.h"

#include <iostream>
#include <iomanip>

using namespace std;


#include <math.h>
// task 1
class Power
{
public:
	Power()
	{
		m_dbA = 0;
		m_dbB = 0;
	}
	void set(double a, double b)
	{
		m_dbA = a;
		m_dbB = b;
	}

	double calcule()
	{
		return pow(m_dbA, m_dbB);
	}
private:
	double m_dbA;
	double m_dbB;
};

// task 2
class RGBA
{
public:
	RGBA()
	{
		m_ucRed = 0;
		m_ucGreen = 0;
		m_ucBlue = 0;
		m_ucAlpha = 0xFF;
	}

	RGBA(uint8_t ucRed,
		uint8_t ucGreen,
		uint8_t ucBlue,
		uint8_t ucAlpha)
	{
		m_ucRed = ucRed;
		m_ucGreen = ucGreen;
		m_ucBlue = ucBlue;
		m_ucAlpha = ucAlpha;
	}
	void print()
	{
		cout << left << setw(8) << "Red:" << m_ucRed << '\n';
		cout << left << setw(8) << "Green:" << m_ucGreen << '\n';
		cout << left << setw(8) << "Blue:" << m_ucBlue << '\n';
		cout << left << setw(8) << "Alpha:" << m_ucAlpha << '\n';
	}

private:
	uint8_t m_ucRed;
	uint8_t m_ucGreen;
	uint8_t m_ucBlue;
	uint8_t m_ucAlpha;
};

// task 3
#define SZ 10
class Stack
{
public:
	void reset()
	{
		m_Length = 0;

		for (size_t i = 0; i < SZ; i++)
			m_nStack[i] = 0;
	}
	bool push(int nValue)
	{
		if (m_Length + 1 >= SZ)
			return false;

		m_Length++;
		m_nStack[m_Length - 1] = nValue;

		return true;
	}
	bool pop()
	{
		if (m_Length == 0)
			return false;

		m_nStack[m_Length - 1] = 0;
		m_Length--;
		return true;
	}
	void print()
	{

		cout << "(";

		for (size_t i = 0; i < m_Length; i++)
			cout << ' ' << m_nStack[ i ];

		cout << " )";

		cout << '\n';
	}
private:
	int m_nStack[SZ];
	size_t m_Length = 0;
};



int main()
{
	// Task 1
	Power TestPower;
	TestPower.set(3, 5);

	cout << '\n' << "Task 1" << '\n';
	cout << TestPower.calcule() << '\n';

	// Task 1
	cout << '\n' << "Task 2" << '\n';
	RGBA TestRGBA;
	TestRGBA.print();

	cout << '\n' << "Task 3" << '\n';
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}