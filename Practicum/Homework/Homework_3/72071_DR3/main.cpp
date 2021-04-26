#include <iostream>
#include "Deck.hpp"
#include "vector.hpp"
#include "string.hpp"
#include "WaterCard.hpp"
#include "FireCard.hpp"
#include "WindCard.hpp"
#include "EarthCard.hpp"
#include "Player.hpp"
#include "CardType.hpp"

void add_cards_water(Deck<WaterCard>& d) {
    WaterCard w1("Voda1",10,WATER);
    WaterCard w2("Voda2",11,WATER);
    WaterCard w3("Voda3",12,WATER);
    WaterCard w4("Voda4",13,WATER);
    WaterCard w5("Voda5",14,WATER);
    WaterCard w6("Voda6",15,WATER);
    WaterCard w7("Voda7",16,WATER);
    WaterCard w8("Voda8",17,WATER);
    WaterCard w9("Voda9",18,WATER);

    d.addCard(w1); 
    d.addCard(w2);
    d.addCard(w3); 
    d.addCard(w4); 
    d.addCard(w5); 
    d.addCard(w6); 
    d.addCard(w7); 
    d.addCard(w8); 
    d.addCard(w9); 

    d.shuffle();
}

void add_cards_fire(Deck<FireCard>& d) {
    FireCard f1("Fire1",10,FIRE);
    FireCard f2("Fire2",11,FIRE);
    FireCard f3("Fire3",12,FIRE);
    FireCard f4("Fire4",13,FIRE);
    FireCard f5("Fire5",14,FIRE);
    FireCard f6("Fire6",15,FIRE);
    FireCard f7("Fire7",16,FIRE);
    FireCard f8("Fire8",17,FIRE);
    FireCard f9("Fire9",18,FIRE); 

    d.addCard(f1); 
    d.addCard(f2); 
    d.addCard(f3); 
    d.addCard(f4); 
    d.addCard(f5); 
    d.addCard(f6); 
    d.addCard(f7); 
    d.addCard(f8); 
    d.addCard(f9);

    d.shuffle();
}

void add_cards_earth(Deck<EarthCard>& d) {
    EarthCard e1("Earth1",10,EARTH);
    EarthCard e2("Earth2",11,EARTH);
    EarthCard e3("Earth3",12,EARTH);
    EarthCard e4("Earth4",13,EARTH);
    EarthCard e5("Earth5",14,EARTH);
    EarthCard e6("Earth6",15,EARTH);
    EarthCard e7("Earth7",16,EARTH);
    EarthCard e8("Earth8",17,EARTH);
    EarthCard e9("Earth9",18,EARTH);

    d.addCard(e1); 
    d.addCard(e2); 
    d.addCard(e3); 
    d.addCard(e4); 
    d.addCard(e5); 
    d.addCard(e6); 
    d.addCard(e7); 
    d.addCard(e8); 
    d.addCard(e9); 

    d.shuffle();
}

void add_cards_wind(Deck<WindCard>& d) {
    WindCard w1("Wind1",10,WIND);
    WindCard w2("Wind2",11,WIND);
    WindCard w3("Wind3",12,WIND);
    WindCard w4("Wind4",13,WIND);
    WindCard w5("Wind5",14,WIND);
    WindCard w6("Wind6",15,WIND);
    WindCard w7("Wind7",16,WIND);
    WindCard w8("Wind8",17,WIND);
    WindCard w9("Wind9",18,WIND); 

    d.addCard(w1); 
    d.addCard(w2); 
    d.addCard(w3); 
    d.addCard(w4); 
    d.addCard(w5); 
    d.addCard(w6); 
    d.addCard(w7); 
    d.addCard(w8); 
    d.addCard(w9);

    d.shuffle();
}

template <typename T, typename U>
bool counter(T& c1, U& c2) {
    if (c1.getType() == c1.getType()) {
        return false;
    }
    if (c1.getType() == 1) { //Water
        if (c2.getType() == 2) { //Fire
            return true;
        }
        else if (c2.getType() == 3) { //Earth
            return false;
        }
        else if (c2.getType() == 4) { // Wind
            return false;
        }
    } else if (c1.getType() == 2) { //Fire
        if (c2.getType() == 1) { //Water
            return false;
        }
        else if (c2.getType() == 3) { //Earth
            return false;
        }
        else if (c2.getType() == 4) { // Wind
            return true;
        }
    } else if (c1.getType() == 3) { //Earth
        if (c2.getType() == 2) { //Fire
            return false;
        }
        else if (c2.getType() == 1) { //Water
            return true;
        }
        else if (c2.getType() == 4) { // Wind
            return false;
        }} else if (c1.getType() == 4) { //Wind
        if (c2.getType() == 2) { //Fire
            return false;
        }
        else if (c2.getType() == 3) { //Earth
            return true;
        }
        else if (c2.getType() == 1) { // Water
            return false;
        }
    }
    return false;
}

template <typename T, typename U>
bool score(T& card_1, U& card_2, Player<WaterCard,FireCard>& p1, Player<EarthCard,WindCard>& p2, unsigned& score_1, unsigned& score_2) {
    if (card_1.getScore() > card_2.getScore() || counter<T,U>(card_1,card_2)) {
        ++score_1;
        std::cout << "Point for " << p1.getName() << ".\n";
    }
    else if (card_1.getScore() < card_2.getScore() || counter<U,T>(card_2,card_1)) {
        ++score_2;
        std::cout << "Point for " << p2.getName() << ".\n";
    }
    if(score_1 >= 5) {
        p1.setWins(p1.getWins()+1);
        p2.setLosses(p2.getLosses()+1);
        std::cout << "Player 1 won!\n";
        std::ofstream playerIn1("Text_files/p1.txt");
        score_1 = 0;
        return true;
    }
    else if (score_2 >= 5) {
        p2.setWins(p2.getWins()+1);
        p1.setLosses(p1.getLosses()+1);
        std::cout << "Player 2 won!\n";
        std::ofstream playerIn2("Text_files/p2.txt");
        score_2 = 0;
        return true;
    }
    return false;
}

void game(Player<WaterCard,FireCard>& p1, Player<EarthCard,WindCard>& p2) {
    std::cout << "Player 1: " << p1.getName() << "\n";
    std::cout << "Player 2: " << p2.getName() << "\n";
    unsigned score_1 = 0, score_2 = 0;
    while(true) {
        std::srand(time(NULL));
	    unsigned i = rand() % 4 + 1;
        WaterCard water;
        FireCard fire;
        EarthCard earth;
        WindCard wind;
        if (i == 1) {
            water = p1.drawCard_T();
            earth = p2.drawCard_T();
            if (score<WaterCard,EarthCard>(water,earth,p1,p2,score_1,score_2)) {
                break;
            }
        }
        else if(i == 2) {
            water = p1.drawCard_T();
            wind = p2.drawCard_U();
            if (score<WaterCard,WindCard>(water,wind,p1,p2,score_1,score_2)) break;
        }
        else if (i == 3) {
            fire = p1.drawCard_U();
            earth = p2.drawCard_T();
            if (score<FireCard,EarthCard>(fire,earth,p1,p2,score_1,score_2)) break;
        }
        else if (i == 4) {
            fire = p1.drawCard_U();
            wind = p2.drawCard_U();
            if (score<FireCard,WindCard>(fire,wind,p1,p2,score_1,score_2)) break;
        }
    }
}

int main() {
    Deck<WaterCard> d_water;
    add_cards_water(d_water);
    Deck<FireCard> d_fire;
    add_cards_fire(d_fire);
    Deck<WindCard> d_wind;
    add_cards_wind(d_wind);
    Deck<EarthCard> d_earth;
    add_cards_earth(d_earth);
    Player<WaterCard, FireCard> p1("Martin", d_water, d_fire, 0, 0);
    Player<EarthCard, WindCard> p2("Vesselin", d_earth, d_wind, 0, 0);

    std::ifstream playerOut1("Text_files/p1.txt");
    p1.loadPlayer(playerOut1);
    std::ifstream playerOut2("Text_files/p2.txt");
    p2.loadPlayer(playerOut2);

    game(p1,p2);
    return 0;
}

//g++ main.cpp Deck.hpp vector.hpp WaterCard.hpp FireCard.hpp WindCard.hpp EarthCard.hpp Player.hpp CardType.hpp string.cpp