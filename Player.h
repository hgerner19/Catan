//CS1300 Sping 2021
//Author: Holden Gerner
//Recitation: 220 - Micheal Hoefer
//Project - Project 3
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Player{
    public:
        //Constructors
        Player();
        Player(string playerName);
        void setPlayerName(string playerName);
        void setWheat(int wheat);
        void setBrick(int brick);
        void setWool(int wool);
        void setOre(int ore);
        void setWood(int wood);
        void setKnightCard(int knightCard);
        void setVictoryPoint(int initial_victoryPoint);
        void displayResources();
        //Accessors
        string getPlayerName();
        int getWheat();
        int getBrick();
        int getWool();
        int getOre();
        int getWood();
        int getCities();
        int getKnightCard();
        int getVictoryPoint();
        //trade with either the bank or other players
        int updateResources(string resource,int value);
        bool enoughResources(string resource,int value);
        int updateVictoryPoint(int value);
        int updateKnightCard(int value);
        int playerRobberCardactivated();

    

    private:
        // vector <int> player_bank; //holds all of players resources
        int wheat;
        int brick;
        int wool;
        int ore;
        int wood;
        int largestArmy;
        int mostCapital;
        int victoryPoints;
        string playerName;
        int knightCard;
        int Cardsize;    
};
#endif