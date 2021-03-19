#include <iostream>

using std::cout;
using std::endl;
using std::nothrow;

class Film {
private:
    char *name;
    unsigned awards;
    void erase();
    void copy(const Film &);
public:
    Film(); // Default constructor
    Film(const char *, const unsigned &); // constructor
    Film(const Film &); // Copy constructor
    Film& operator=(const Film &); // =
    ~Film(); //Destructor

    void setName(const char *);
    void setAwards(const unsigned &);

    const char *getName() const;
    unsigned getAwards() const;

    void print() const;
};