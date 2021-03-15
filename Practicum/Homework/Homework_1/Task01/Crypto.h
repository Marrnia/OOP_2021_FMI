#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Crypto {
private:
    char *name;
    double lastPrice;
    double currentPrice;

    void erase();
    void copy(const Crypto &);
public:
    Crypto();
    Crypto(const char*, const double &, const double &);
    Crypto(const Crypto &);
    Crypto& operator=(const Crypto &);
    ~Crypto();

    void setName(const char*);
    void setLastPrice(const double &);
    void setCurrentPrice(const double &);

    char *getName() const;
    double getLastPrice() const;
    double getCurrentPrice() const;

    int priceDifference() const;
    void print() const;
};

