//CS1300 Sping 2021
//Author: Holden Gerner
//Recitation: 220 - Micheal Hoefer
//Project - Project 3
#ifndef BANKER_H
#define BANKER_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Banker{
    public:
        //Constructors
        Banker();
        Banker(int num);
        void setWheat(int wheat);
        void setBrick(int brick);
        void setWool(int wool);
        void setOre(int ore);
        void setWood(int wood);
        //Accessors
        int getWheat();
        int getBrick();
        int getWool();
        int getOre();
        int getWood();
        void displayResources();
        //when a player rolls the dice and gets
        // a resource or when a player wants to trade with bank
        int giveOutResources(string resource,int value);
        // when a player trades with the bank or if the robbery card is drawn.
        // then players have to give half their resources to the bank (only if they have 8 or more cards)
        int receiveResources(string resource,int value);
    private:
        int wheat;
        int brick;
        int wool;
        int ore;
        int wood;
};
#endif