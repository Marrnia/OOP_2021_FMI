#include <iostream>
#include "Film.h"

int main() {
    Film f("The Lord of the rings", 11);
    Film f2;
    f.print();
    f2.print();
    f2 = f;
    f2.print();
    f.print();
    return 0;
}