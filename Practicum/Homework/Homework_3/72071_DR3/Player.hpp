#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <algorithm>
#include <ctime>
#include <fstream>
#include "vector.hpp"
#include "string.hpp"
#include "Deck.hpp"

template <typename T, typename U>
class Player
{
	typedef unsigned int uint;

	my::string name;
	uint losses;
	uint wins;
	Deck<T> deck_T;
	Deck<U> deck_U;

public:
	Player();
	Player(const my::string&, const Deck<T>&, const Deck<U>&, const uint&, const uint&);


	void setLosses(const uint&);
	void setWins(const uint&);
	my::string getName() const;
	uint getLosses() const;
	uint getWins() const;

	T drawCard_T();
	U drawCard_U();
	void savePlayer(std::ofstream &) const;
	void loadPlayer(std::ifstream&);
	
};

template <typename T, typename U>
Player<T,U> :: Player() {
	name = "No player";
	losses = 0;
	wins = 0;
}

template <typename T, typename U>
Player<T,U> :: Player(const my::string& name, const Deck<T>& d1, const Deck<U>& d2, const uint& losses, const uint& wins) {
	this->name = name;
	this->deck_T = d1;
	this->deck_U = d2;
	this->losses = losses;
	this->wins = wins;
}

template <typename T, typename U>
void Player<T,U> :: setLosses(const uint& value) {
	losses = value;
}

template <typename T, typename U>
void Player<T,U> :: setWins(const uint& value) {
	wins = value;
}

template <typename T, typename U>
my::string Player<T,U> :: getName() const {
	return name.getString();
}

template <typename T, typename U>
unsigned Player<T,U> :: getLosses() const {
	return losses;
}

template <typename T, typename U>
unsigned Player<T,U> :: getWins() const {
	return wins;
}

template <typename T, typename U>
T Player<T,U> :: drawCard_T() {
	std::cout << "Player " << this->name.getString() << " drawns ";
	return deck_T.drawCard();
}

template <typename T, typename U>
U Player<T,U> :: drawCard_U() {
	std::cout << "Player " << this->name.getString() << " drawns ";
	return deck_U.drawCard();
}

template <typename T, typename U>
void Player<T,U> :: savePlayer(std::ofstream& out) const {
    if (out.is_open()) {
        out << this->name.getString() << "\n";
        out << this->wins << "\n";
        out << this->losses << "\n";
        out.close();
    }
	else {
        std::cerr << "Unable to open the file.\n";
    }

}

template <typename T, typename U>
void Player<T,U> :: loadPlayer(std::ifstream& in) {
    if (in.is_open()) {
		in >> name;
		in >> wins;
		in >> losses;
        in.close();
    }
    else {
        std::cerr << "Unable to open the file.\n";
    }
}

#endif