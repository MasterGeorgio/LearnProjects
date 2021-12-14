// TestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cassert>
#include <vector>
#include <set>

void _fastcall swapInt(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

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

	void erase() {
		delete[] m_data;

		m_data = nullptr;
		m_length = 0;
	}

	int getLength() {
		return m_length;
	}
	
	int& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	void resize(int newLength) {
		if (newLength == m_length)
			return;

		if (newLength <= 0)
		{
			erase();
			return;
		}

		int *data = new int[newLength];

		if (m_length > 0)
		{
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;

			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}

		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}

	void insertBefore(int value, int index) {
		// Проверка корректности передаваемого индекса
		assert(index >= 0 && index <= m_length);

		// Создаем новый массив на один элемент больше старого массива
		int *data = new int[m_length + 1];

		// Копируем все элементы до index-а
		for (int before = 0; before < index; ++before)
			data[before] = m_data[before];

		// Вставляем новый элемент в новый массив
		data[index] = value;

		// Копируем все значения после вставляемого элемента
		for (int after = index; after < m_length; ++after)
			data[after + 1] = m_data[after];

		// Удаляем старый массив и используем вместо него новый 
		delete[] m_data;
		m_data = data;
		++m_length;
	}

	void push_back(int value) {
		insertBefore(value, m_length);
	}


	void pop_back() {
		assert(m_length > 0);

		// Создаем новый массив
		int *data = new int[m_length - 1];

		// Копируем все значения
		for (int i = 0; i < m_length - 1; i++)
			data[ i ] = m_data[ i ];
		
		delete[] m_data;
		m_data = data;
		--m_length;
	}

	void pop_begin() {
		assert(m_length > 1);

		// Создаем новый массив
		int *data = new int[m_length - 1];

		// Копируем все значения
		for (int i = 0; i < m_length - 1; i++)
			data[i] = m_data[i + 1];

		delete[] m_data;
		m_data = data;
		--m_length;
	}

	void sort() {
		qs(m_data, 0, m_length - 1);
	}

	void print() {
		std::cout << '\n';
		for (int i = 0; i < m_length; i++)
			std::cout << "   " << m_data[i];
		std::cout << '\n';
	}

private:
	
	// Quick sort
	void qs(int *pnArr, int nFirst, int nLast)
	{
		int nLeft = nFirst;
		int nRigth = nLast;

		int nPivot = pnArr[(nFirst + nLast) / 2];

		// One step
		do
		{
			while (pnArr[nLeft]  < nPivot) nLeft++;
			while (pnArr[nRigth] > nPivot) nRigth--;

			if (nLeft <= nRigth)
			{
				swapInt(&pnArr[nLeft], &pnArr[nRigth]);
				nLeft++;
				nRigth--;
			}

		} while (nLeft <= nRigth);

		// Two step
		if (nLeft < nLast)
			qs(pnArr, nLeft, nLast);
		if (nFirst < nRigth)
			qs(pnArr, nFirst, nRigth);
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

	size_t GetTotal() {
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
	// Task 1
	ArrayInt arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.pop_back();
	arr.print();
	arr.pop_begin();
	arr.print();

	// Task 2
	std::vector<int> Arrow{ 5, 3, 6, 8, 10, 6, 2, 5, 10, 3 };
	Task2(Arrow);

	system("pause");
}

