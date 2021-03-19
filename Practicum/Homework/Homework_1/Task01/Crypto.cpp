#include "Crypto.h"

void Crypto::erase() {
    delete[] name;
}

void Crypto::copy(const Crypto &other) {
    this->setName(other.name);
    this->setLastPrice(other.lastPrice);
    this->setCurrentPrice(other.currentPrice);
}

Crypto::Crypto() {
    this->name = new char[1];
    this->name[0] = '\0';
    this->lastPrice = 0.0;
    this->currentPrice = 0.0;
}

Crypto::Crypto(const char* name, const double &lastPrice, const double &currentPrice) {
    this->setName(name);
    this->setLastPrice(lastPrice);
    this->setCurrentPrice(currentPrice);
}

Crypto::Crypto(const Crypto &other) {
    this->copy(other);
}

Crypto& Crypto::operator=(const Crypto &other) {
    if (this != &other) {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Crypto::~Crypto() {
    this->erase();
}


void Crypto::setName(const char *name) {
    if (strlen(name) > 30) {
        throw "Too long name.";
    }
    if (name[0] < 'A' || name[0] > 'Z') {
        throw "First letter must be capital!";
    }
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
}

void Crypto::setLastPrice(const double &lastPrice) {
    if (lastPrice < 0) {
        throw "The lastprice must be a positive number!";
    }
    this->lastPrice = lastPrice;
}

void Crypto::setCurrentPrice(const double &currentPrice) {
    if (currentPrice < 0) {
        throw "The currentprice must be a positive number!";
    }
    this->currentPrice = currentPrice;
}

const char* Crypto::getName() const{
    return this->name;
}

double Crypto::getLastPrice() const {
    return this->lastPrice;
}

double Crypto::getCurrentPrice() const {
    return this->currentPrice;
}

int Crypto::priceDifference() const{
    return (int)(getCurrentPrice() - getLastPrice()) * 100 / getLastPrice();
}

void Crypto::print() const {
    cout << "Name: " << getName() << endl;
    cout << "Last price: " << getLastPrice() << endl;
    cout << "Current price: " << getCurrentPrice() << endl;
    cout << "Difference: " << priceDifference() << "%" << endl;
}
