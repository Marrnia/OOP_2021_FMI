#pragma once
#include <iostream>

using std::nothrow;
using std::cout;
using std::endl;
using std::cerr;

class String {
private:
    typedef unsigned long long st;
    char *data;
    st size;
    st capacity;

    void create();
    void create(const st &, const char &);
    void copy(const String &);
    void resize();
    void erase();
    void printString() const;
public:
    String();
    String(const char *);
    String(const st &, const char &);
    String(const String &);
    ~String();

    void setString(const char *);
    void setSize (const st &);
    void setCapacity (const st &);
    const char *getString() const;
    st getLength() const;
    st getCapacity () const;

    void add(const char &);
    void insertAt(const char &, const st &);
    void removeAt(const st &);
    void trimStart(); // премахва първия символ на символния низ
    //Метод trimStart, който приема аргумент, цяло число, което определя 
    //колко елемента от началото на масива да бъдат премахнати.
    void trimStart(const unsigned &);
    void trimEnd(); //премахва последния символ на символния низ
    //Метод trimEnd, който приема аргумент, цяло число, което определя 
    //колко елемента от края на масива да бъдат премахнати.
    void trimEnd(const unsigned &);

    String &operator=(const String &);
    String &operator=(const char *);
    //String &operator=(const char &);
    String operator+(const String &);
    String operator+(const char *);
    //String &operator+(const char &);
    String operator+=(const String &);
    String operator+=(const char *);
    //String &operator+=(const char &);
    
    bool operator==(const String &);
    bool operator==(const char *);
    bool operator!=(const String &);
    bool operator!=(const char *);

    const char &operator[](const st &) const;

    void print() const;
};
