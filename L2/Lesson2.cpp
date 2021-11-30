#include "stdafx.h"

#include <iostream>
#include <iomanip>

#include <string>

using namespace std;


#include <math.h>


// task 1
class Fruit
{
public:
	friend class Apple;
public:
	Fruit() {
	}
	Fruit(string color) {
		m_color = color;
	}
	Fruit(
		string color,
		string name) {
		m_color = color;
		m_name  = name;
	}
	string getName() {
		return m_name;
	}

	string getColor() {
		return m_color;
	}
private:
	string m_name;
	string m_color;
};

class Apple: public Fruit
{
public:
	Apple()
	{
		Fruit("green", "apple");
	}
	Apple(string color)
	{
		Fruit(color, "apple");
	}
private:
};

class Banana : public Fruit
{
public:
	Banana()
	{
		Fruit("yellow", "banana ");
	}
	Banana(string color)
	{
		Fruit(color, "banana ");
	}
private:
};

class GrannySmith : public Apple
{
public:
private:
};

int main()
{
	// Task 1
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	// Task 2

	system("pause");
}