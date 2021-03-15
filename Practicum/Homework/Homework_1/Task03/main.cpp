#include <iostream>
#include "Film.hpp"
#include "FilmRanking.hpp"

int main() {
    const size_t size = 3;
    Film movies[size]; 
    movies[0].setName("Name01");
    movies[0].setAwards(11);
    movies[1].setName("Name02");
    movies[1].setAwards(12);
    movies[2].setName("Name03");
    movies[2].setAwards(2);
    FilmRanking films = FilmRanking(movies, size);
    films.print(3);
    return 0;
}