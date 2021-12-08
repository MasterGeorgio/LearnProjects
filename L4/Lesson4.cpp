// TestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cassert>
#include <vector>
#include <set>

/////////
// Task 1
/////////
class ArrayInt {
private:
	int m_length;
	int *m_data;

public:
	ArrayInt() : m_length(0), m_data(nullptr) {}

	ArrayInt(int length) :
		m_length(length)
	{
		assert(length >= 0);

		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}

	~ArrayInt() {
		delete[] m_data;
	}

	void pop_back() {

	}

	void pop_begin() {

	}

	void sort() {

	}

	void print() {
		for (int i = 0; i < m_length; i++)
			std::cout << m_data[i];
	}
};
/////////
// End Task 1
/////////


/////////
// Task 2
/////////
void Task2(std::vector<int>& Arrow) {
	using namespace std;
	cout << "Task 2" << endl;
	vector<int>::iterator it;

	//map <int, int> m1, m2;
	vector <int>::iterator Iter;
	set <int> setValueSpace;
	for (it = Arrow.begin(); it != Arrow.end(); it++)
		setValueSpace.insert(*it);

	set<int>::iterator itSet;
	for (itSet = setValueSpace.begin(); itSet != setValueSpace.end(); itSet++)
		cout << *itSet << endl;

	cout << "Count various value = " << setValueSpace.size() << endl;
}
/////////
// End Task 2
/////////


/////////
// Task 3
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
	Jack = Ten,
	Queen = Ten,
	King = Ten,
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

class Hand {
	// methods
public:
	void Add(Card* card) {
		m_Hand.push_back(card);
	}

	void Clear() {
		m_Hand.clear();
	}

	size_t GetValue() {
		size_t dwCountAce = 0;
		size_t dwSum = 0;
		for (size_t i = 0; i < m_Hand.size(); i++)
			if (m_Hand.at(i)->GetValue() == Ace)
				dwCountAce++;
			else
				dwSum += m_Hand.at(i)->GetValue();

		// The tag for to do back of step
		bool bRevertTag = 0;
		for (size_t i = 0; i < dwCountAce; i++)
		{
			if (dwSum + Ace11 > 21)
			{
				dwSum += Ace;

				// revert to back the pre step of computation
				if (bRevertTag)
					dwSum -= Ace11 + Ace;

				bRevertTag = false;
			}
			else
			{
				dwSum += Ace11;
				bRevertTag = true;
			}
		}

		return dwSum;
	}
	// variable
private:
	std::vector<Card*> m_Hand;
};

/////////
// End Task 3
/////////

void main()
{
	std::vector<int> Arrow{ 5, 3, 6, 8, 10, 6, 2, 5, 10, 3 };
	Task2(Arrow);

	system("pause");
}

