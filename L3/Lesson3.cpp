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

class PassengerCar : virtual public Car {
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

class Bus : virtual public Car {
public:
	Bus(string company,
		string model) : Car(company, model) {
	}
};

class Minivan : public Bus, public PassengerCar {
public:
	Minivan(string company,
		string model) : Car(company, model), Bus(company, model), PassengerCar(company, model) {
	}
};
/////////
// End Task 2
/////////

/////////
// Task 3
/////////
class Fraction {
public:
	Fraction(){}

	// function
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
	int getNum() {
		return m_num;
	}
	int getDem() {
		return m_dem;
	}

private:
	// variable
	int m_num;
	int m_dem;

	// function
private:
	void reduce() {

	}
};
Fraction operator+(Fraction d1, Fraction d2) {

	return Fraction(d1.getNum(), d2.getDem());
}
/////////
// End Task 3
/////////


/////////
// Task 4
/////////
enum eCardSuit {
	// ♠
	Spade,
	// ♣
	Club,
	// ♦
	Diamond,
	// ♥
	Heart
};

enum eCardValue {
	Ace = 1,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack  = Ten,
	Queen = Ten,
	King  = Ten,
	Ace11
};

class Card {
	// methods
public:
	Card(eCardSuit Suit,
		eCardValue Value,
		bool       Pos = false) : m_eSuit(Suit), m_eValue(Value), m_bPos(Pos) {}

	bool Flip() {
		return m_bPos ^= true;
	}

	eCardValue GetValue() {
		return m_eValue;
	}

	// variable
private:
	eCardSuit  m_eSuit;
	eCardValue m_eValue;
	bool       m_bPos;
};
/////////
// End Task 4
/////////

int main()
{
	// Task 1
	PassengerCar passCar("mazda", "x5");
	Bus          busCar("mazda", "x4");
	Minivan      mnvCar("mazda", "x6");

	// Task 2
	Square Cube(2);
	cout << Cube.area() << '\n';
	Rhombus Romb(2, 2);
	cout << Romb.area() << '\n';

	// Task 3
	Fraction dr1(3, 4);
	Fraction dr2(4, 4);
	Fraction dr3;

	dr3 = dr1 + dr2;

	system("pause");
}

