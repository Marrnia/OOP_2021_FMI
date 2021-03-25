#include "Rational.hpp"

/*Private*/

void Rational :: copy(const Rational &other) {
    setNumerator(other.numerator);
    setDenominator(other.denominator);
}

int Rational :: gcd(const int &a, const int &b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void Rational :: simplify() {
    numerator /= gcd(numerator, denominator);
    denominator /= gcd(numerator, denominator);

    if (numerator < 0 && denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

int Rational :: lcm(const int &a, const int &b) {
    return (a * b) / gcd(a, b);
}

/*Public*/

Rational :: Rational() {
    setNumerator(1);
    setDenominator(1);
}

Rational :: Rational(const int &numerator, const int &denominator) {
    setNumerator(numerator);
    setDenominator(denominator);
}

Rational :: Rational(const Rational& other) {
    this->copy(other);
}

void Rational :: setNumerator(const int& numerator) {
    this->numerator = numerator;
}

void Rational :: setDenominator(const int& denominator) {
    if (denominator == 0) {
        cerr << "Undefined fraction" << endl;
    }
    this->denominator = denominator;
}

int Rational :: getNumerator() const {
    return this->numerator;
}

int Rational :: getDenominator() const {
    return this-> denominator;
}

void Rational :: print() const {
    cout << numerator << "/" << denominator;
    cout << endl;
}

Rational Rational :: operator+(const Rational &other) {
    Rational result;
    result.denominator = lcm(this->denominator, other.denominator);
    result.numerator = (this->numerator * (result.denominator / this->denominator)) + (other.numerator * (result.denominator / other.denominator));
    result.simplify();
    return result;
}

Rational Rational :: operator-(const Rational& other) {
    Rational result;
    result.denominator = lcm(this->denominator, other.denominator);
    result.numerator = (this->numerator * (result.denominator / this->denominator)) - (other.numerator * (result.denominator / other.denominator));
    result.simplify();
    return result;
}

Rational Rational :: operator*(const Rational& other) {
    Rational result;
    result.numerator = this->numerator * other.numerator;
    result.denominator = this->denominator * other.denominator;
    simplify();
    return result;
}

Rational Rational :: operator/(const Rational& other) {
    Rational result;
    result.numerator = this->numerator * other.denominator;
    result.denominator = this->denominator * other.numerator;
    simplify();
    return result;
}

bool Rational :: operator>=(const Rational& other) {
    return (((double)this->numerator/this->denominator) >= ((double)other.numerator/other.denominator));
}

bool Rational :: operator<=(const Rational& other) {
    return (((double)this->numerator / this->denominator) <= ((double)other.numerator / other.denominator));
}

bool Rational :: operator==(Rational other) {
    this->simplify();
    other.simplify();
    return this->numerator == other.numerator && this->denominator == other.denominator ? true : false;
}

bool Rational :: operator!=(Rational other) {
    return *this == other ? false : true;
}

Rational &Rational :: operator=(const Rational &other) {
    this->copy(other);
    return *this;
}

Rational Rational :: operator+=(const Rational &other)
{
    return *this + other;
}

Rational Rational :: operator-=(const Rational &other)
{
    return *this - other;
}

Rational Rational :: operator*=(const Rational &other)
{
    return *this * other;
}

Rational Rational :: operator/=(const Rational &other)
{
    return *this / other;
}