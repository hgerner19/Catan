//CS1300 Sping 2021
//Author: Holden Gerner
//Recitation: 220 - Micheal Hoefer
//Project - Project 3
#include "cardDeck.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
   //Constructor
Carddeck::Carddeck(){
    string knightCard = "";
    string monopolyCard = "";
    string yearofplentyCard = "";
    string victoryPoint = "";
    string cards[0];
}
Carddeck::Carddeck(string knightCard){
    knightCard = "Knight Card";
    string monopolyCard = "Monopoly Card";
    string yearOfplentyCard= "Year of Plenty Card";
    string victoryPoint = "Victory Point";
}
void Carddeck::setKnightCard(string initial_knightCard){
    knightCard = initial_knightCard;
}
void Carddeck::setMonopolyCard(string initial_monopolyCard){
    monopolyCard = initial_monopolyCard;
}
void Carddeck::setYearofPlentyCard(string initial_yearofplentyCard){
    yearofplentyCard = initial_yearofplentyCard;
}
void Carddeck::setVictoryPoint(string initial_victoryPoint){
    victoryPoint = initial_victoryPoint;
}
//Accessors
//lets the user draw that card if they pay for it
string Carddeck::draw_card(){
    string arr[50];
    string knightCard = "Knight Card";
    string monopolyCard = "Monopoly Card";
    string yearOfplentyCard= "Year of Plenty Card";
    string victoryPoint = "Victory Point";
    // adding each card and the amount of that card to the card vector
    for(int i = 0; i < 14; i++){
        cards[i] = knightCard;
    }
    for(int i = 0; i < 3; i++){
        cards[i] = monopolyCard;
    }
    for(int i = 0; i < 3; i++){
        cards[i] = yearofplentyCard;
    }
    for(int i = 0; i < 20; i++){
        cards[i] = victoryPoint;
    }
    cout << "Test draw card" << endl;
    srand(time(NULL));
    int random = rand() % 40 + 1;
    cout << "You got a " << cards[random] << endl;
    return 0;
}
string Carddeck::getKnightCard(){
    return knightCard;
}
string Carddeck::getMonopolyCard(){
    return monopolyCard;
}
string Carddeck::getYearofPlentyCard(){
    return yearofplentyCard;
}
string Carddeck::getVictoryPoint(){
    return victoryPoint;
}
