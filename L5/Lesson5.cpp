// TestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

// -------
// Task 1
// -------
template<class T>
class Pair1 {
public:
	Pair1(const T&,
		  const T&);
	~Pair1();

	T& first() {
		return m_a;
	}
	T& second() {
		return m_b;
	}
	void print() {
		cout << "Pair1: " << first() << '\t' << second() << '\n';
	}
private:
	T m_a;
	T m_b;
};
template<class T>
Pair1<T>::Pair1(const T& a,
	          const T& b)
{
	m_a = a;
	m_b = b;
}
template<class T>
Pair1<T>::~Pair1()
{
}
// -------
// End Task 1
// -------

// -------
// Task 2
// -------
template<class T1, class T2>
class Pair
{
public:
	Pair(const T1&,
		 const T2&);
	~Pair();

	T1& first() {
		return m_a;
	}
	T2& second() {
		return m_b;
	}
	void print() {
		cout << "Pair: " << first() << '\t' << second() << '\n';
	}
private:
	T1 m_a;
	T2 m_b;
};
template<class T1, class T2>
Pair<T1, T2>::Pair(const T1& a,
	                 const T2& b)
{
	m_a = a;
	m_b = b;
}

template<class T1, class T2>
Pair<T1, T2>::~Pair()
{
}
// -------
// End Task 2
// -------


// -------
// Task 3
// -------
template<class T2>
class StringValuePair: public Pair<string, T2>
{
public:
	StringValuePair(
		const string &str,
		const T2& value) : Pair<string, T2>(str, value)  {}
};
// -------
// End Task 3
// -------


// -------
// Task 4
// -------
// Test class Hand. That is need for work of valid
class Hand {
public:
	size_t GetTotal();
};

class GenericPlayer: public Hand
{
public:
	GenericPlayer(string name) : m_strName(name) {}
	virtual ~GenericPlayer() {
	}

	virtual bool IsHitting() {
		//return (GetTotal() < 21);
		std::cout << m_strName << ", another card? y/n";
		char cAnswer = ' ';
		std::cin >> cAnswer;
		return cAnswer == 'y' || cAnswer == 'Y';
	}

	bool IsBoosted() {
		return (GetTotal() > 21);
	}

	void Bust() {
		std::cout << m_strName << " is bust!" << endl;
	}

	// Methods
private:
	string m_strName;
};
// -------
// End Task 4
// -------

void main()
{
	// T1
	cout << "--Task 1--" << endl;
	Pair1<int> pairOne1(1, 3);
	pairOne1.print();

	Pair1<float> pairOne2(1.5, -3.2);
	pairOne2.print();

	// T2
	cout << "--Task 2--" << endl;
	Pair<int, double> p1(1, 2.3);
	p1.print();

	Pair<double, int> p2(1.2, 3.3);
	p2.print();

	// T3
	cout << "--Task 3--" << endl;
	Pair<string, int> p3("Amazing", 7);
	p3.print();

	StringValuePair<int> svp("Amazing", 7);
	svp.print();

	system("pause");
}

