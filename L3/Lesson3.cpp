// TstForm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;


/////////
// Task 1
/////////
class Figure
{
public:
	virtual double area() = 0;
	virtual ~Figure() { };
};

class Parallelogram: public Figure
{
public:
	Parallelogram(double dbLength, double dbWidth) :
		m_dbLength(dbLength),
		m_dbWidth(dbWidth) {};

	Parallelogram(double dbLength) :
		m_dbLength(dbLength),
		m_dbWidth(dbLength) {};

	double area()
	{
		return m_dbLength * m_dbWidth;
	}
private:
	double m_dbLength;
	double m_dbWidth;
};

class Circle : public Figure
{
public:
	Circle(double Radius) :
		m_dbRadius(Radius)
	{
	}

	double area()
	{
		return 3.14 * m_dbRadius * m_dbRadius;
	}
private:
	double m_dbRadius;
};

class Square : public Parallelogram
{
public:
	Square(double dbLength) :
		Parallelogram(dbLength)	{}

	double area()
	{
		return Parallelogram::area();
	}
};

class Rectangle: public Parallelogram
{
public:

	Rectangle(double dbLength, double dbWidth) :
		Parallelogram(dbLength,dbWidth)
	{}

	double area()
	{
		return Parallelogram::area();
	}
private:
	double m_dbLength;
	double m_dbWidth;
};

class Rhombus : public Parallelogram
{
public:

	/// Diagonals d1 and d2
	Rhombus(double dbLength, double dbWidth) :
		Parallelogram(dbLength, dbWidth)
	{}

	double area()
	{
		return Parallelogram::area() * .5;
	}
private:
	double m_dbLength;
	double m_dbWidth;
};
/////////
// End Task 1
/////////

/////////
// Task 2
/////////
class Car {
public:
	Car(string company,
		string model) : m_company(company), m_model(model) {
		PrintInfo();
	}

	void PrintInfo()
	{
		cout << m_company << '\t' << m_model << '\n';
	}
private:
	string m_company;
	string m_model;
};

class PassengerCar : public Car {
public:
	PassengerCar(string company,
		string model) : Car(company, model) {
	}

	void PrintInfo()
	{
		cout << m_company << '\t' << m_model << '\n';
	}
private:
	string m_company;
	string m_model;
};

class Bus : public Car {
public:
	Bus(string company,
		string model) : Car(company, model) {
	}
};

class Minivan : public Bus, public PassengerCar {
public:
	Minivan(string company,
		string model) : Bus(company, model), PassengerCar(company, model) {
	}
};
/////////
// End Task 2
/////////

/////////
// Task 1
/////////
class Fraction {
public:
	Fraction(int num, int dem) {
		if (dem == 0)
			return;

		m_num = num;
		m_dem = dem;
	}

	bool set(int num, int dem) {
		if (dem == 0)
			return false;
		m_num = num;
		m_dem = dem;
	};
	/*/
	Fraction operation + () {
	}
	*/
private:
	int m_num;
	int m_dem;
};
/////////
// End Task 3
/////////

int main()
{
	// Task 1
	// Task 2
	PassengerCar passCar("mazda", "x5");
	Bus          busCar("mazda", "x4");
	Minivan      mnvCar("mazda", "x6");

	Square Cube(2);
	cout << Cube.area() << '\n';
	Rhombus Romb(2, 2);
	cout << Romb.area() << '\n';

	// Task 3

	system("pause");
}

