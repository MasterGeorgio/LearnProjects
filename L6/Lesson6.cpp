// TestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

#define VAR_ONE
//#define VAR_TWO

// -----
// Task 1
// -----
void Input() {
	int nValue = 0;

	while (1)
	{
#ifdef VAR_ONE
		string strVal = "";
		cout << "Enter value" << endl;
		cin >> strVal;
		try {
			// Wrap up code in try-catch block if string is not validated
			int res = std::stoi(strVal);
			cout << "Integer: " << res << endl;
			break;
		}
		catch (std::invalid_argument e) {
			//cout << "input fail" << endl;
		}
#endif
#ifdef VAR_TWO
		cout << "Enter value" << endl;
		cin >> nValue;
		if (!cin.fail())
		{
			cout << "Integer: " << nValue << endl;
			break;
	    }
#endif
		cout << "input fail" << endl;
		cin.clear();
		cin.ignore(0x7FFF, '\n');
	}

}
// -----
// End Task 1
// -----



// -----
// Task 2
// -----
ostream &endll(ostream &stream)
{
	stream.clear();
	return stream << endl << endl;
}
// -----
// End Task 2
// -----


// Test class Hand. That is need for work of valid
class Hand {
public:
	size_t GetValue();
};

class GenericPlayer : public Hand
{
public:
	GenericPlayer(string name) : m_strName(name) {}
	virtual ~GenericPlayer() {
	}

	virtual bool IsHitting() {
		//return (GetValue() < 21);
	}

	bool IsBoosted() {
		return (GetValue() > 21);
	}

	void Bust() {
		cout << m_strName << " is bust!" << endl;
	}

	// Methods
protected:
	string m_strName;
};

class Player : public GenericPlayer {
public:
	virtual bool IsHitting() {
		cout << m_strName << ", another card? y/n";
		char cAnswer = ' ';
		cin >> cAnswer;
		return cAnswer == 'y' || cAnswer == 'Y';
	}

	void Win() const {
		cout << m_strName << " is win :)" << endl;
	}
	void Lose() const {
		cout << m_strName << " is win :(" << endl;
	}
	void Push() const {
		cout << m_strName << " is draw :/" << endl;
	}
};

class House : public GenericPlayer {
public:
	House(string name = "House") : GenericPlayer(name) {}

	virtual ~House();

	virtual bool IsHitting() {
		return (GetValue() <= 16);
	}

	void FlipFirstCard()
	{
		/**
		if (m_Card.empty() == 0)
		cout << "Not card" << endl;
		else
		m_Card[0]->Flip();
		/**/
	}
};

void main()
{
	// Task 1
	//Input();

	// Task 2
	cout << "Test" << endll << "test" << endl;

	system("pause");
}

