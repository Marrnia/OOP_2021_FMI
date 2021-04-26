#pragma once
#include <iostream>

namespace my
{

    using std::cerr;
    using std::cout;
    using std::endl;
    using std::nothrow;

    class string
    {
    private:
        typedef unsigned long long st;
        char *data;
        st size;

        void create();
        void create(const st &, const char &);
        void copy(const string &);
        void erase();
        void resize();

    public:
        string();
        string(const char *);
        string(const st &, const char &);
        string(const string &);
        ~string();

        void setString(const char *);
        const char *getString() const;
        st getLength() const;


        string &operator=(const string &);
        string &operator=(const char *);

        bool operator==(const string &);
        bool operator==(const char *);
        bool operator==(const char&);
        bool operator!=(const string &);
        bool operator!=(const char *);

        const char &operator[](const st &) const;
        char &operator[](const st &);

        friend std::ostream &operator<<(std::ostream &out, const string &object)
        {
            out << object.data;
            return out;
        }

        friend std::istream &operator>>(std::istream &in, string &object)
        {
            char *buffer = new char[1000];
            in >> buffer;
            object = string{buffer};
            delete[] buffer;
            return in;
        }

    };
} // namespace my