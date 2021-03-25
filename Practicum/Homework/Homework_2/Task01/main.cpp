#include <iostream>
#include "String.hpp"

using std::cout;
using std::endl;

int main() {
    String z1 = "test";
    z1.print();
    String z2 = "test";
    z2.add('a');
    z2.print();
    if (z1 != z2) {
        cout << "Yes" << endl;
        cout << z1[2] << endl;
    }
    String z3(z2);
    z3.print();
    String z4 = z3 + z2;
    z2.print();
    z3.print();
    z4.print();
    return 0;
}