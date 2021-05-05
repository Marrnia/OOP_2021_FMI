#include <iostream>
#include "Vector.hpp"
#include "SmartFunc.hpp"

int add(int a, int b) {
    return a+b;
}

int add_map(int a) {
    return a + 10;
}

bool bigger_than_5(int a) {
    return a > 5;
}

int main() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(11);
    SmartFunc<int> sm;
    sm.setFilter(bigger_than_5);
    sm.setMap(add_map);
    sm.setReduce(add);
    sm.filter_map(v);
    v.print();
    return 0;
}