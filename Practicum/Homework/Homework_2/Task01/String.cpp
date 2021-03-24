#include "String.hpp"

/*Private*/

void String :: create() {
    data = nullptr;
    size = capacity = 0;
}

void String :: create(const st &n, const char &value) {
    data = new (nothrow) char[n+1];
    if (!data) throw "No memory!";
    size = capacity = n;
    for (st i = 0; i < size; i++) {
        data[i] = value;
    }
    data[n] = '\0';
}

void String :: copy(const String &other) {
    setString(other.data);
}

void String :: resize() {
    capacity *= 2;
    char *newData = new (nothrow) char[capacity];
    if (!newData) throw "No memory!";
    strcpy_s(newData, getLength() + 1, data);
    erase();
    data = newData; 
}

void String :: erase() {
    delete[] data;
}

void String :: printString () const {
    if (data != nullptr)
        for (st i = 0; i < size; i++) {
            cout << data[i];
        }
    else {
        cout << "nullptr";
    }
}

/*Public*/

String :: String () {
    create();
}

String :: String (const char *str) {
    setString(str);
}

String :: String (const st &n, const char &value) {
    create(n,value);
}

String :: String (const String &other) {
    copy(other);
}

String :: ~String () {
    size = capacity = 0;
    erase();
}

void String :: setString (const char *str) {
    data = new (nothrow) char[strlen(str) + 1];
    if (!data) throw "No memory!";
    strcpy_s(data, strlen(str) + 1, str);
    setSize(strlen(str));
    setCapacity(strlen(str)+1);
}

void String :: setSize (const st &size) {
    if (data == nullptr) {
        cerr << "No value to string." << endl;
        return;
    }
    if (size > strlen(data)) {
        cerr << "Size cannot be larger than string!" << endl;
        return;
    }
    this->size = size;
}

void String :: setCapacity (const st &capacity) {
    if (data == nullptr) {
        cerr << "No value to string." << endl;
        return;
    }
    if (capacity < size) {
        cerr << "Capacity cannot be smaller than string size!" << endl;
        return;
    }
    this->capacity = capacity;
}

const char *String :: getString() const {
    return data;
}
//не знам защо не ми дава да използвам st вместо size_t
size_t String :: getLength () const {
    return strlen(data);
}

size_t String :: getCapacity() const {
    return capacity;
} 

void String :: add (const char &value) {
    if (data == nullptr) {
        setString("");
    }
    if (size >= capacity) {
        resize();
    }
    data[size++] = value;
    data[size] = '\0';
}

void String :: insertAt (const char &value, const st &at) {
    if (at >= size) {
        std::cerr << "Index at must be smaller than size!" << endl;
        return;
    }
    if (size >= capacity) {
        resize();
    }
    for (st i = size; i > at; i--) {
        data[i] = data[i-1];
    }
    size++;
    data[at] = value;
    data[size] = '\0';
}

void String :: removeAt (const st &at) {
    if (at >= size) {
        std::cerr << "Index at must be smaller than size!" << endl;
        return;
    }
    size--;
    for (st i = at; i < size; i++) {
        data[i] = data[i+1];
    }
    data[size] = '\0';
}

void String :: trimStart () {
    removeAt(0);
}

void String :: trimStart (const unsigned &to) {
    if (to > size) {
        cerr << "to must be smaller than size" << endl;
        return;
    }
    for (unsigned i = 0; i < to; i++) {
        trimStart();
    }
}

void String :: trimEnd () {
    removeAt(size-1);
}

void String :: trimEnd (const unsigned &to) {
    if (to > size) {
        cerr << "to must be smaller than size" << endl;
        return;
    }
    for (unsigned i = 0; i < to; i++) {
        trimEnd();
    }
}

String &String :: operator= (const String &other) {
    if (this != &other) {
        erase();
        copy(other);
    }
    return *this;
}

String &String :: operator= (const char *other) {
    setString(other);
    return *this;
}

String &String :: operator+ (const String &other) {
    for (st i = 0; i < other.size; i++) {
        add(other[i]);
    }
    return *this;
}

String &String :: operator+ (const char *other) {
    st sizeStr = strlen(other);
    for (st i = 0; i < sizeStr; i++) {
        add(other[i]);
    }
    return *this;
}

String &String :: operator+= (const String &other) {
    return *this + other;
}

String &String :: operator+= (const char *other) {
    return *this + other;
}

bool String :: operator== (const String &other) {
    if (this->size != other.size) {
        return false;
    }
    else {
        for (st i = 0; i < size; i++) {
            if (this->data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }
}

bool String :: operator== (const char *other) {
    if (this->size != strlen(other)) {
        return false;
    }
    else {
        for (st i = 0; i < size; i++) {
            if (this->data[i] != other[i]) {
                return false;
            }
        }
        return true;
    }
}

bool String :: operator!= (const String &other) {
    return *this == other ? false : true;
}

bool String :: operator!= (const char *other) {
    return *this == other ? false : true;
}

const char &String :: operator[] (const st &index) const {
    return data[index];
}

void String :: print () const {
    cout << "String: ";
    printString();
    cout << endl;
    cout << "Size: " << size << endl;
    cout << "Capacity: " << capacity << endl;
}