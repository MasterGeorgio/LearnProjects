#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

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

std::map<eCardSuit, const char*> g_mapSuit = {
	{ Spade,   "♠ Spade"   },
	{ Club,    "♣ Club"    },
	{ Diamond, "♦ Diamond" },
	{ Heart,   "♥ Heart"   }
};
std::map<eCardValue, const char*> g_mapCardValue{
	{ Ace,    "Ace"   },
	{ Two,    "Two"   },
	{ Three,  "Three" },
	{ Four,   "Four"  },
	{ Five,   "Five"  },
	{ Six,    "Six"   },
	{ Seven,  "Seven" },
	{ Eight,  "Eight" },
	{ Nine,   "Nine"  },
	{ Ten,    "Ten"   },
	{ Jack,   "Jack"  },
	{ Queen,  "Queen" },
	{ King,   "King"  },
};


class Card {
	// methods
public:
	friend std::ostream& operator<< (std::ostream &out, const Card &aCard);

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

std::ostream& operator<< (std::ostream &out, const Card &aCard) {

	if (aCard.m_bPos)
	{
		out << " XX ";
	}
	else
	{
		out << g_mapSuit[aCard.m_eSuit] << "\t"
			<< g_mapCardValue[aCard.m_eValue] << "\t"
			<< aCard.m_eValue << "\n";
	}
	return out;
}


class Hand {
	// methods
public:
	void Add(Card* card) {
		m_Cards.push_back(card);
	}

	void Clear() {
		m_Cards.clear();
	}

	size_t GetTotal() const {
		size_t dwCountAce = 0;
		size_t dwSum = 0;
		for (size_t i = 0; i < m_Cards.size(); i++)
			if (m_Cards.at(i)->GetValue() == Ace)
				dwCountAce++;
			else
				dwSum += m_Cards.at(i)->GetValue();

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
protected:
	std::vector<Card*> m_Cards;
};
