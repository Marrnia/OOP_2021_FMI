#ifndef FIRECARD_HPP
#define FIRECARD_HPP

#include "string.hpp"
#include "CardType.hpp"
#include <iostream>

using namespace my;

class FireCard {
public:
    FireCard()
    {
        this->card_name = "Empty";
        this->power = 0;
        this->bonus_power = 0;
        this->card_type = FIRE;
    }

    FireCard(const my::string& card_name, const unsigned& power = 0, const unsigned& bonus_power = 0)
    {
        this->card_name = card_name;
        this->power = power;
        this->bonus_power = bonus_power;
        this->card_type = FIRE;
    }

    FireCard(const FireCard& rhs) {
        card_name = rhs.card_name;
        power = rhs.power;
        bonus_power = rhs.bonus_power;
        card_type = rhs.card_type;
    }

    void setName(const my::string &card_name) {
        this->card_name = card_name;
    }

    void setPower(const unsigned& power) {
        this->power = power;
    }

    void setBonusPower(const unsigned& bonus_power) {
        this->bonus_power = bonus_power;
    }

    my::string getName() const {
        return card_name.getString();
    }

    unsigned getPower() const {
        return this->power;
    }

    unsigned getBonusPower() const {
        return this->bonus_power;
    }

    unsigned getScore() const {
        return power + bonus_power + card_type;
    }

    Types getType() const {
        return card_type;
    }

    FireCard& operator=(const FireCard& rhs) {
        card_name = rhs.card_name;
        power = rhs.power;
        bonus_power = rhs.power;
        card_type = rhs.card_type;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const FireCard& object) {
        out << "Name: " << object.card_name
            << "; Power:" << object.power
            << "; Bonus power:" << object.bonus_power
            << "; Type:" << FIRE << ".\n";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, FireCard& object) {
        std::cout << "Name:";
        in >> object.card_name;
        std::cout << "Power:";
        in >> object.power;
        std::cout << "Bonus power:";
        in >> object.bonus_power;
        return in;        
    }
private:
    my::string card_name;
    unsigned power;
    unsigned bonus_power;
    Types card_type;
};

#endif
