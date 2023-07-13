//CS1300 Sping 2021
//Author: Holden Gerner
//Recitation: 220 - Micheal Hoefer
//Project - Project 3
#include "Banker.h"
#include "Player.h"
#include "Utils.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string BRICKs = "brick";
string WOOLs = "wool";
string WOODs = "wood";
string OREs = "ore";
string WHEATs = "wheat";
//Constructors
Banker::Banker(){
    brick = 19;
    wool = 19;
    wheat = 19;
    wood = 19;
    ore = 19;
}
Banker::Banker(int num){
    //initializing each resource to 19
    brick = 19;
    wool = 19;
    wheat = 19;
    wood = 19;
    ore = 19;
}
void Banker::setWheat(int initial_wheat){
    wheat = initial_wheat;
}
void Banker::setBrick(int initial_brick){
    brick = initial_brick;         
}
void Banker::setWool(int initial_wool){
    wool = initial_wool;
}
void Banker::setOre(int initial_ore){
    ore = initial_ore;      
}
void Banker::setWood(int initial_wood){
    wood = initial_wood;      
}
//Accessors
int Banker::getWheat(){
    return wheat;
}
int Banker::getBrick(){
    return brick;
}
int Banker::getWool(){
    return wool;
}
int Banker::getOre(){
    return ore;
}
int Banker::getWood(){
    return wood;
}
void Banker::displayResources() {
    cout << "Wood: " << getWood() << endl;
    cout << "Ore: " << getOre() << endl;
    cout << "Wool: " << getWool() << endl;
    cout << "Brick: " << getBrick() << endl;
    cout << "Wheat: " << getWheat() << endl;
}
//gives out resources to the players
int Banker::giveOutResources(string resource,int value){
    string formattedResource = Utils::toLower(resource);
    if(formattedResource == BRICKs){
        setBrick(getBrick() - value);
        return getBrick();
    }
    if(formattedResource == WOOLs){
        setWool(getWool() - value);
        return getWool();
    }
    if(formattedResource == WHEATs){
        setWheat(getWheat() - value);
        return getWheat();
    }
    if(formattedResource == WOODs){
        setWood(getWood() - value);
        return getWood();
    }
    if(formattedResource == OREs){
        setOre(getOre() - value);
        return getOre();
    }
    return 0;
}
//receives traded resources or resources collected from the robber
int Banker::receiveResources(string resource,int value){
     string formattedResource = Utils::toLower(resource);
    if(formattedResource == BRICKs ){
        setBrick(getBrick()+value);
    }
    if(formattedResource == WOOLs){
        setWool(getWool() + value);
    }
    if(formattedResource == WHEATs){
        setWheat(getWheat() + value);
    }
    if(formattedResource == WOODs){
        setWood(getWood() + value);
    }
    if(formattedResource == OREs){
        setOre(getOre() + value);
    }
    return 0;
}