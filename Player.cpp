//CS1300 Sping 2021
//Author: Holden Gerner
//Recitation: 220 - Micheal Hoefer
//Project - Project 3
#include "Player.h"
#include "Utils.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
string BRICK = "brick";
string WOOL = "wool";
string WOOD = "wood";
string ORE = "ore";
string WHEAT = "wheat";
Player::Player() {
    string playerName = "";
    wheat = 0;
    brick = 0;
    wool = 0;
    ore = 0;
    wood = 0;
    largestArmy = 0;
    victoryPoints = 0;
}

Player::Player(string initial_playerName) {
    string playerName = initial_playerName;
    //initializing players resources to 0
    int wheat = 0;
    int brick = 0;
    int wool = 0;
    int ore = 0;
    int wood = 0;
    int victoryPoints = 0;
    int knightCard = 0;
}
void Player::setPlayerName(string initial_playerName) {
    playerName = initial_playerName;
}
void Player::setWheat(int initial_wheat) {
    wheat = initial_wheat;
}
void Player::setBrick(int initial_brick) {
    brick = initial_brick;
}
void Player::setWool(int initial_wool) {
    wool = initial_wool;
}
void Player::setOre(int initial_ore) {
    ore = initial_ore;
}
void Player::setWood(int initial_wood) {
    wood = initial_wood;
}
void Player::setKnightCard(int initial_knightCard) {
    knightCard = initial_knightCard;
}
void Player::setVictoryPoint(int initial_victoryPoint){
    victoryPoints = initial_victoryPoint;
}
//Accessors
string Player::getPlayerName() {
    return playerName;
}
int Player::getWheat() {
    return wheat;
}
int Player::getBrick() {
    return brick;
}
int Player::getWool() {
    return wool;
}
int Player::getOre() {
    return ore;
}
int Player::getWood() {
    return wood;
}
int Player::getKnightCard() {
    return knightCard;
}
int Player::getVictoryPoint() {
    return victoryPoints;
}
int Player::updateResources(string resource, int value) {
    string formattedResource = Utils::toLower(resource);
  
    if (formattedResource == BRICK) {
        setBrick(getBrick() + value);
    } 
    else if (formattedResource == WOOD) {
        setWood(getWood() + value);
    } 
    else if (formattedResource == ORE) {
        setOre(getOre() + value);
    } 
    else if (formattedResource == WHEAT) {
        setWheat(getWheat() + value);
    } 
    else if (formattedResource == WOOL) {
        setWool(getWool() + value);
    }
    return 0;
}
//prints the value of the player_bank for the player
void Player::displayResources() {
    cout << playerName << ":" << endl;
    cout << "Wood: " << getWood() << endl;
    cout << "Ore: " << getOre() << endl;
    cout << "Wool: " << getWool() << endl;
    cout << "Brick: " << getBrick() << endl;
    cout << "Wheat: " << getWheat() << endl;
    cout << "Victory Points: " << getVictoryPoint() << endl;
}
//function that returns true if player has enough
//resources for trading or buying a development card
bool Player::enoughResources(string resource, int value) {
    string formattedResource = Utils::toLower(resource);
    cout << "Checking player has enough resources for player: " << getPlayerName() << endl;
    if (formattedResource == WOOD) { //checks wood
        if (getWood() >= value) {
            return true;
        }
    } 
    else if (formattedResource == ORE) { // checks ore index
        if (getOre() >= value) {
            return true;
        }
    } 
    else if (formattedResource == WOOL) { //checks wool index
        if (getWool() >= value) {
            return true;
        }
    } 
    else if (formattedResource == BRICK) { //checks brick index
        if (getBrick() >= value) {
            return true;
        }
    } 
    else if (formattedResource == WHEAT) { //checks wheat index
        if (getWheat() >= value) {
            return true;
        }
    }
    cout << "Player does not have enough resources" << endl;
    return false;
}
int Player::updateVictoryPoint(int value) {
    setVictoryPoint(getVictoryPoint() + value);
    return getVictoryPoint();
}
int Player::updateKnightCard(int value) {
    knightCard += value;
    return 0;
}


