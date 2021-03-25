#include <iostream>
#include "Rational.hpp"

using std::cout;

int main() {
    Rational z1(1,2);
    Rational z2(2,3);
    Rational z3 = z1 + z2;
    z3.print();
    z3 = z1 - z2;
    z3.print();
    z3 = z1 * z2;
    z3.print();
    z3 = z1 / z2;
    z3.print();
    Rational z4(z3);
    if (z4 == z3) {
        cout << "Neshoooooooooooooo\n";
    }
    if (z1 <= z2) {
        cout << "is true\n";
    }
    return 0;
}