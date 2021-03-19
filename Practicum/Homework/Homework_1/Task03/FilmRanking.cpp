#include "FilmRanking.hpp"

void FilmRanking :: erase() {
    this->size = 0;
    delete[] films;
}

void FilmRanking :: copy(const FilmRanking &other) {
    setSize(other.size);
    setFilms(other.films);
}

void FilmRanking :: swap(Film *a, Film *b) {
    Film t = *a;
    *a = *b;
    *b = t;
}

void FilmRanking :: sortByAwards() {
    for (size_t i = 0; i < getSize() - 1; i++) {
        for (size_t j = i + 1; j < getSize(); j++) {
            if (films[i].getAwards() < films[j].getAwards()) {
                this->swap(&films[i], &films[j]);
            }
        }
    }
}

FilmRanking :: FilmRanking() {
    size = 1;
    films = new (nothrow) Film[size];
    if (!films) throw "No memory";
}

FilmRanking :: FilmRanking(const Film *films, const size_t &size) {
    setSize(size);
    setFilms(films);
}

FilmRanking :: FilmRanking(const FilmRanking &other) {
    copy(other);
}

FilmRanking &FilmRanking :: operator=(const FilmRanking &other) {
    if (this != &other) {
        erase();
        copy(other);
    }
    return *this;
}

FilmRanking :: ~FilmRanking() {
    erase();
}

void FilmRanking :: setFilms(const Film *films) {
    erase();
    this->films = new (nothrow) Film[getSize()];
    if (!this->films) throw "No memory!";
    for (size_t i = 0; i < getSize(); i++) {
        this->films[i] = films[i];
    }
}

void FilmRanking :: setSize(const size_t &size) {
    if (size > 100) throw "Too big size.";
    this->size = size;
}

const Film *FilmRanking :: getFilms() const {
    return this->films;
}

const size_t FilmRanking :: getSize() const {
    return this->size;
}

void FilmRanking :: print(const unsigned &n) {
    if (n > getSize()) throw "Invalid n";
    sortByAwards();
    for (unsigned i = 0; i < n; i++) {
        films[i].print();
    }
}
