#pragma once
#include <iostream>
#include "Film.hpp"

using std::nothrow;
using std::cout;
using std::endl;

class FilmRanking {
private:
    Film *films;
    size_t size;
    void erase();
    void copy(const FilmRanking &);
    void swap(Film *, Film *);
    void sortByAwards();
public:
    FilmRanking();
    FilmRanking(const Film *,const size_t &);
    FilmRanking(const FilmRanking &);
    FilmRanking &operator=(const FilmRanking &);
    ~FilmRanking();

    void setFilms(const Film *);
    void setSize(const size_t &);

    const Film* getFilms() const;
    const size_t getSize() const;

    void print(const unsigned &);
};