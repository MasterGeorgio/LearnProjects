#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <string>

#include "Task1.h"


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

// Init cout
size_t Person::m_dwCountStudent = 0;

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

	const int N = 3;
	Student* pers[ N ];

	for (int i = 0; i < N; i++)
	{
		int year, wight, age;
		string name, sex;
		cout << "Enter name age sex weight age:" << endl;
		cin >> name >> age >> sex >> wight >> year;
		pers[i] = new Student(year, name, age, sex, wight);
		pers[i]->AddYear(i + 1);
	}

	cout << "Count students:" << Person::getCount() << endl;
	for (int i = 0; i < N; i++)
		pers[i]->Print();

	for (int i = 0; i < N; i++)
		delete pers[i];
	
	system("pause");
}
/*
11 22 33 44 55
33 55 11 44 22
33 44 55 11 22
*/