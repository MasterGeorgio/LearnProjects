#include "stdafx.h"

#include <iostream>
#include <iomanip>

#include <string>

using namespace std;

// task 1
class Fruit
{
public:
	Fruit(string color,
		  string name) : m_color(color), m_name(name){}

	Fruit(std::string color = "")
	{
		setColor(color);
	}

	void setName(std::string name)
	{
		m_name = name;
	}

	void setColor(std::string color)
	{
		m_color = color;
	}

	const std::string& getName() const
	{
		return m_name;
	}

	const std::string& getColor() const
	{
		return m_color;
	}
private:
	string m_name;
	string m_color;
};

class Apple : public Fruit
{
public:
	Apple(std::string color = "")
	{
		if (color == "")
			color = "green";

		setName("apple");
		setColor(color);
	}
};

class Banana : public Fruit
{
public:
	Banana(std::string color = "")
	{
		if (color == "")
			color = "yellow";

		setName("banana");
		setColor(color);
	}
};

class GrannySmith : public Apple
{
public:
	GrannySmith()
	{
		setName("Granny Smith " + Apple::getName());
	}
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