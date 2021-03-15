#include "Film.h"

void Film::erase() {
    delete[] name;
}

void Film::copy(const Film &other) {
    setName(other.name);
    setAwards(other.awards);
}

Film::Film() {
    this->name = new (nothrow) char[6];
    if (!name) throw "No memory!";
    strcpy_s(this->name, 6, "Empty");
}

Film::Film(const char *name, const unsigned &awards) {
    setName(name);
    setAwards(awards);
}

Film::Film(const Film &other) {
    copy(other);
}

Film &Film::operator=(const Film &other) {
    if (this != &other) {
        erase();
        copy(other);
    }
    return *this;
}

Film::~Film() {
    erase();
}

void Film::setName(const char *name) {
    if (name != nullptr) {
        erase();
    }
    if (name[0] < 'A' || name[0] > 'Z') {
        throw "First letter must be capital!";
    }
    this->name = new (nothrow) char[strlen(name) + 1];
    if (!name) throw "No memory!";
    strcpy_s(this->name, strlen(name) + 1, name);
}

void Film::setAwards(const unsigned &awards) {
    if (awards > 10000) {
        throw "Wrong awards!";
    }
    this->awards = awards;
}

char *Film::getName() const {
    return name;
}

unsigned Film::getAwards() const {
    return awards;
}

void Film::print() const {
    cout << "Name: " << getName() << endl;
    cout << "Awards: " << getAwards() << endl;
}