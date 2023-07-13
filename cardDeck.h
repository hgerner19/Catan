//CS1300 Sping 2021
//Author: Holden Gerner
//Recitation: 220 - Micheal Hoefer
//Project - Project 3
#ifndef CARDDECK_H
#define CARDDECK_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Carddeck{ //make a card class for the development cards
    public:
        //Constructor
        Carddeck();
        Carddeck(string knightCard);
        void setKnightCard(string knightCard);
        void setMonopolyCard(string monopolyCard);
        void setYearofPlentyCard(string yearofplentyCard);
        void setVictoryPoint(string victoryPoint);
        //Accessors
        //shuffle the cards after every time its drawn from
        int shuffle();
        //if the user wants to draw a developmental card
        string draw_card();
        //puts the card back only if its a monopoly card or yearofPlenty card
        bool return_card(string card);
        string getKnightCard();
        string getDoubleCard();
        string getMonopolyCard();
        string getYearofPlentyCard();
        string getVictoryPoint();
    private:
        string cards[50];//holds all cards
        string knightCard;
        string monopolyCard;
        string yearofplentyCard;
        string victoryPoint;
};
#endif