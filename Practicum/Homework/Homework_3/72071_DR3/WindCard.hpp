#ifndef WINDCARD_HPP
#define WINDCARD_HPP

#include "string.hpp"
#include "CardType.hpp"
#include <iostream>

using namespace my;

class WindCard {
public:
    WindCard()
    {
        this->card_name = "Empty";
        this->power = 0;
        this->bonus_power = 0;
        this->card_type = WIND;
    }

    WindCard(const my::string& card_name, const unsigned& power = 0, const unsigned& bonus_power = 0)
    {
        this->card_name = card_name;
        this->power = power;
        this->bonus_power = bonus_power;
        this->card_type = WIND;
    }

    WindCard(const WindCard& rhs) {
        card_name = rhs.card_name;
        power = rhs.power;
        bonus_power = rhs.bonus_power;
        card_type = rhs.card_type;
    }

    void setName(const string &card_name) {
        this->card_name = card_name;
    }

    void setPower(const unsigned& power) {
        this->power = power;
    }

    void setBonusPower(const unsigned& bonus_power) {
        this->bonus_power = bonus_power;
    }

    string getName() const {
        return this->card_name.getString();
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

    WindCard& operator=(const WindCard& rhs) {
        card_name = rhs.card_name;
        power = rhs.power;
        bonus_power = rhs.power;
        card_type = rhs.card_type;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const WindCard& object) {
        out << "Name: " << object.card_name
            << "; Power:" << object.power
            << "; Bonus power:" << object.bonus_power
            << "; Type:" << WIND << ".\n";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, WindCard& object) {
        std::cout << "Name:";
        in >> object.card_name;
        std::cout << "Power:";
        in >> object.power;
        std::cout << "Bonus power:";
        in >> object.bonus_power;
        return in;        
    }
private:
    string card_name;
    unsigned power;
    unsigned bonus_power;
    Types card_type;
};

#endif
