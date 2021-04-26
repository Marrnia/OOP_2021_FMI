#include "string.hpp"

namespace my
{
    /*Private*/

    void string ::create()
    {
        data = nullptr;
        size = 0;
    }

    void string ::create(const st &n, const char &value)
    {
        data = new char[n + 1];
        size = n;
        for (st i = 0; i < size; i++)
        {
            data[i] = value;
        }
        data[n] = '\0';
    }

    void string ::copy(const string &other) { 
        strcpy(data, other.data);
        size = other.size;
    }

    void string ::erase()
    {
        delete[] data;
        data = nullptr;
    }


    /*Public*/

    string ::string() { 
        create(); 
    }

    string ::string(const char *str) { 
        data = new char(strlen(str)+1);
        strcpy_s(data, strlen(str)+1, str);
        size = strlen(str);
    }

    string ::string(const st &n, const char &value) { create(n, value); }

    string ::string(const string &other) { copy(other); }

    string ::~string()
    {
        size = 0;
        if (data != nullptr)
            erase();
    }

    void string ::setString(const char *str)
    {
        if (data != nullptr) {
            erase();
        }
        data = new char[strlen(str) + 1];
        strcpy_s(data, strlen(str) + 1, str);
        size = strlen(str);
    }

    const char *string ::getString() const { return data; }
    size_t string ::getLength() const { return strlen(data); }


    string &string ::operator=(const string &other)
    {
        if (this != &other && other.data != nullptr) {
            if (data != nullptr) {
                erase();
            }
            data = new char[strlen(other.data)+1];
            strcpy(data,other.data);
        }
        return *this;
    }

    string &string ::operator=(const char *other)
    {
        char *temp = new char[strlen(other)+1];
        strcpy(temp,other);
        if (data != nullptr) {
            erase();
        }
        data = temp;
        size = strlen(other);
        return *this;
    }

    bool string ::operator==(const string &other)
    {
        if (this->size != other.size)
        {
            return false;
        }
        else
        {
            for (st i = 0; i < size; i++)
            {
                if (this->data[i] != other.data[i])
                {
                    return false;
                }
            }
            return true;
        }
    }

    bool string ::operator==(const char *other)
    {
        if (this->size != strlen(other))
        {
            return false;
        }
        else
        {
            for (st i = 0; i < size; i++)
            {
                if (this->data[i] != other[i])
                {
                    return false;
                }
            }
            return true;
        }
    }

    bool string ::operator==(const char& rhs) {
        if (this->size > 1) {
            return false;
        }
        if (data[0] != rhs) {
            return false;
        }
        return true;
    }

    bool string ::operator!=(const string &other) { return !(*this == other); }

    bool string ::operator!=(const char *other) { return !(*this == other); }

    const char &string ::operator[](const st &index) const {
        if (index < 0 || index >= size) {
                throw std::out_of_range("position is out of range");
            }
        return data[index]; 
    }

    char &string ::operator[](const st &index) {
        if (index < 0 || index >= size) {
                throw std::out_of_range("position is out of range");
            }
        return data[index]; 
    }

} // namespace my