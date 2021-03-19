#include <iostream>
#include "Crypto.h"

using std::cout;
using std::endl;

int main() {
    Crypto c1("Bitcoin", 30.12, 60.32);
    c1.print();
    return 0;
}
