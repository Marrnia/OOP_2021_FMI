#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

class Rational {
public: 
    Rational();
    Rational(const int&, const int&);
    Rational(const Rational&);

    void setNumerator(const int&);
    void setDenominator(const int&);

    int getNumerator() const;
    int getDenominator() const;

    void print() const;

    Rational operator+(const Rational &);
    Rational operator-(const Rational &);
    Rational operator*(const Rational &);
    Rational operator/(const Rational &);
    Rational& operator=(const Rational &);
    Rational operator+=(const Rational &);
    Rational operator-=(const Rational &);
    Rational operator*=(const Rational &);
    Rational operator/=(const Rational &);
    bool operator> (const Rational&);
    bool operator< (const Rational&);
    bool operator>=(const Rational& );
    bool operator<=(const Rational& );
    bool operator==(Rational);
    bool operator!=(Rational);
private:
    int numerator;
    int denominator;

    void copy(const Rational&);
    int gcd(const int& , const int& );
    int lcm(const int& , const int& );
    void simplify();
};