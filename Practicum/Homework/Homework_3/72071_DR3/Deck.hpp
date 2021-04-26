#ifndef DECK_HPP
#define DECK_HPP

#include "EarthCard.hpp"
#include "FireCard.hpp"
#include "WaterCard.hpp"
#include "WindCard.hpp"
#include "string.hpp"
#include "vector.hpp"
#include <iostream>

template <typename T>
class Deck
{
	vector<T> deck;

public:
	void shuffle();
	T drawCard();
	void addCard(const T &);
	Deck<T> &operator=(const Deck<T> &);
	Deck<T> operator+(const T &);
	Deck<T> &operator+=(const T &);

	void print();
};

template <typename T>
void Deck<T>::shuffle() { deck.shuffle(); }

template <typename T>
T Deck<T>::drawCard()
{
	T card = deck.back();
	std::cout << card.getName() << ".\n";
	deck.pop_back();
	deck.push_front(card);
	return card;
}

template <typename T>
void Deck<T>::addCard(const T &card)
{
	if (deck.size() >= 30)
	{
		std::cerr << "The deck cannot hold more than 30 cards.\n";
		return;
	}
	for (size_t i = 0; i < deck.size(); ++i)
	{
		if (deck[i].getName() == card.getName())
		{ // ERROR
			std::cerr << "The name " << card.getName()
					  << " already exist in the deck.\n";
			return;
		}
	}
	deck.push_back(card);
}

template <typename T>
Deck<T> &Deck<T>::operator=(const Deck<T> &rhs)
{
	this->deck = rhs.deck;
	return *this;
}

template <typename T>
Deck<T> Deck<T>::operator+(const T &card)
{
	Deck<T> temp;
	temp = *this;
	temp.addCard(card);
	return temp;
}

template <typename T>
Deck<T> &Deck<T>::operator+=(const T &card)
{
	*this = *this + card;
	return *this;
}

template <typename T>
void Deck<T>::print()
{
	std::cout << "Cards in the deck:\n";
	deck.print();
}

#endif