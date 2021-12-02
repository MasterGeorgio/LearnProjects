#pragma once
#include "stdafx.h"

#include <stdint.h>
#include <string>

enum Sex {
	eFemale,
	eMale
};
class Person
{
private:
	// Name
	string m_name;
	// Sex
	Sex    m_sex;
	// Age
	uint16_t m_wAge;
	// Weigth
	uint16_t m_wWeigth;

	static size_t m_dwCountStudent;

public:
	Person(Sex sex);
	~Person();

	// Edit name
	void setName(string name) {
		m_name = name;
	}

	// Edit Age
	void setAge(uint16_t wAge) {
		m_wAge = wAge;
	}
	// Edit Weigth
	void setWeigth(uint16_t wWeigth) {
		m_wWeigth = wWeigth;
	}
};

Person::Person(Sex sex)
{
	m_sex = sex;
}

Person::~Person()
{
}