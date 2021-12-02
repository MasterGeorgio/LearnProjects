#pragma once
//#include "stdafx.h"

#include <iostream>
#include <iomanip>

#include <stdint.h>
#include <string>

using namespace std;

class Person
{
private:
	// Name
	string m_Name;
	// Sex
	string    m_sex;
	// Age
	uint16_t m_wAge;
	// Weigth
	uint16_t m_wWeigth;

	static size_t m_dwCountStudent;

public:
	Person(const string& name, const int& age, const string& sex, const int& wight)
	{
		m_dwCountStudent++;
		m_Name = name;
		m_wAge    = age;
		m_wWeigth = wight;
		m_sex     = sex;
	}

	~Person()
	{
	}
	/**/
	static size_t getCount() {
		return m_dwCountStudent;
	}
	/**/
	// Edit name
	void setName(string name) {
		m_Name = name;
	}
	// Edit Age
	void setAge(uint16_t wAge) {
		m_wAge = wAge;
	}
	// Edit Weigth
	void setWeigth(uint16_t wWeigth) {
		m_wWeigth = wWeigth;
	}

	// name
	string getName() {
		return m_Name;
	}
	// sex
	string getSex() {
		return m_sex;
	}
	// Age
	uint16_t getAge() {
		return m_wAge;
	}
	// Weigth
	uint16_t getWeigth() {
		return m_wWeigth;
	}
	// Print
	virtual void Print()
	{
		cout << getName() << '\t' << getAge() << '\t' << getSex() << '\t' << getWeigth() << '\n';
	}
};

class Student : public Person
{
public:
	Student(
		int year,
		const string& name,
		const int age,
		const string& sex,
		const int wight)
		:Person(name, age, sex, wight), n_year(year)
	{
		n_year = 0;
	}

	int GetYear() {
		return n_year;
	}
	void AddYear(int addValue){
		n_year += addValue;
	}
	void AddYear(){
		n_year++;
	}

	void Print()
	{
		cout << GetYear() << ' ';
		Person::Print();
	}

private:
	int n_year;
};