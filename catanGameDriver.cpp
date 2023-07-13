//CS1300 Sping 2021
//Author: Holden Gerner
//Recitation: 220 - Micheal Hoefer
//Project - Project 3
#include <vector>
#include "Banker.h"
#include "Player.h"
#include "cardDeck.h"
#include "Utils.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
// function to collect all of the players name
void startGame(Player &p1, Player &p2, Player &p3) {
    string player1;
    string player2;
    string player3;
    cout << "Hello and welcome to Catan!" << endl;
    cout << "The rules of the game are simple, first player to 10 points or player with most points after 10 rounds, wins." << endl;
    cout << endl;
    cout << "First player, enter your name:" << endl;
    cin >> player1;
    cout << "Second player, enter your name:" << endl;
    cin >> player2;
    cout << "Third player, enter your name:" << endl;
    cin >> player3;
    p1.setPlayerName(player1);
    p2.setPlayerName(player2);
    p3.setPlayerName(player3);
    cout << endl;
    cout << "Welcome " << player1 << ", " << player2 << ", " << player3 << ", " << endl;
    cout << "Lets get started!" << endl;
}
//rolls the dice
int rollTwoDice() {
    //first dice roll
    int roll = rand() % 6 + 1;
    //second dice roll
    int roll2 = rand() % 6 + 1;
    int answer = roll + roll2;
    return answer;
}
//checks what resource(s) you get from the roll
int diceRoll(Player &player,Banker b1) {
    srand(time(0));
    int answer = rollTwoDice();
    string resource1;
    string resource2;
    cout << answer << endl;
    if (answer == 2) {
        cout << "You rolled " << answer << endl;
        resource1 = "Wool";
        player.updateResources(resource1, 1);
        b1.giveOutResources(resource1,1);
        cout << "You got a wool" << answer << endl;
        cout << "Congrats! You got a victory Point" << endl;
        player.updateVictoryPoint(1);
    } 
    else if (answer == 3) {
        cout << "You rolled " << answer << endl;
        resource1 = "Ore";
        resource2 = "Wood";
        player.updateResources(resource1, 1);
        player.updateResources(resource2, 1);
        b1.giveOutResources(resource1,1);
        b1.giveOutResources(resource2,1);
        cout << "You got an ore and a wood" << endl;
    } 
    else if (answer == 4) {
        cout << "You rolled " << answer << endl;
        resource1 = "Wool";
        resource2 = "Wheat";
        player.updateResources(resource1, 1);
        b1.giveOutResources(resource1,1);
        player.updateResources(resource2, 1);
        b1.giveOutResources(resource2,1);
        cout << "You got a wool and a wheat" << endl;
    } 
    else if (answer == 5) {
        cout << "You rolled " << answer << endl;
        resource1 = "Brick";
        resource2 = "Wool";
        player.updateResources(resource1, 1);
        b1.giveOutResources(resource1,1);
        player.updateResources(resource2, 1);
        b1.giveOutResources(resource2,1);
        cout << "You got a brick and a wool" << endl;
    } 
    else if (answer == 6) {
        cout << "You rolled " << answer << endl;
        resource1 = "Brick";
        resource2 = "Wheat";
        player.updateResources(resource1, 1);
        b1.giveOutResources(resource1,1);
        player.updateResources(resource2, 1);
        b1.giveOutResources(resource2,1);
        cout << "You got a brick and wheat" << endl;
    } 
    else if (answer == 7) {
        cout << "Desert spot, sorry" << endl;
        cout << "Don't worry tho enjoy these 2 Victory Points!" << endl;
        player.updateVictoryPoint(2);
    } 
    else if (answer == 8) {
        cout << "You rolled " << answer << endl;
        cout << "You got an ore and a wood" << endl;
        resource1 = "Ore";
        resource2 = "Wood";
        player.updateResources(resource1, 1);
        b1.giveOutResources(resource1,1);
        player.updateResources(resource2, 1);
        b1.giveOutResources(resource2,1);
    } 
    else if (answer == 9) {
        cout << "You rolled " << answer << endl;
        cout << "You got a wood and a wheat" << endl;
        resource1 = "Wood";
        resource2 = "Wheat";
        player.updateResources(resource1, 1);
        b1.giveOutResources(resource1,1);
        player.updateResources(resource2, 1);
        b1.giveOutResources(resource2,1);
    } 
    else if (answer == 10) {
        cout << "You rolled " << answer << endl;
        cout << "You got an ore and a brick" << endl;
        resource1 = "Ore";
        resource2 = "Brick";
        player.updateResources(resource1, 1);
        b1.giveOutResources(resource1,1);
        player.updateResources(resource2, 1);
        b1.giveOutResources(resource2,1);
    } 
    else if (answer == 11) {
        cout << "You rolled " << answer << endl;
        cout << "You got a wood and a wool" << endl;
        resource1 = "Wood";
        resource2 = "Wool";
        player.updateResources(resource1, 1);
        b1.giveOutResources(resource1,1);
        player.updateResources(resource2, 1);
        b1.giveOutResources(resource2,1);
    } 
    else if (answer == 12) {
        cout << "You rolled " << answer << endl;
        cout << "You got a wheat" << endl;
        resource1 = "Wheat";
        player.updateResources(resource1, 1);
        b1.giveOutResources(resource1,1);
        cout << "Congrats! You got a victory Point" << endl;
        player.updateVictoryPoint(1);
    }
    return 0;
}
// function to keep track and print the amount of points for each player
int leaderBoard(Player arr[]) {
    string fileName = "leaderboard.txt";
    string line;
    ofstream myFile;
    myFile.open(fileName);
    if (myFile.is_open()) {
        myFile << arr[0].getPlayerName() << ", " << arr[1].getVictoryPoint() << endl;
        myFile << arr[1].getPlayerName() << ", " << arr[1].getVictoryPoint() << endl;
        myFile << arr[2].getPlayerName() << ", " << arr[2].getVictoryPoint() << endl;
    } 
    else {
        cout << "Unable to open file.";
    }
    return 0;
}
void updateLeaderBoard(Player p1,Player p2,Player p3){
    string line;
    ifstream myFile;
    myFile.open("learderboard.txt");
    ofstream temp;
    temp.open("temp.txt");
    //updating temp file with the data from the leaderboard file
    if (myFile.is_open() && temp.is_open()) {
        while (getline(myFile, line)) {
            cout << line << endl;
        }
    } 
    else {
        cout << "Unable to open file the second time.";
    }
    myFile.close();
    temp.close();
    //deleting the leaderboard file
    remove("leaderboard.txt");
    //making the temp file the leaderboard file
    rename("temp.txt","leaderboard.txt");
    ofstream myFile2;
    myFile2.open("leaderboard.txt");
    //updating stats of players
    myFile2 << p1.getPlayerName() << ", " << p1.getVictoryPoint() << endl;
    myFile2 << p2.getPlayerName() << ", " << p2.getVictoryPoint() << endl;
    myFile2 << p3.getPlayerName() << ", " << p3.getVictoryPoint() << endl;
    myFile2.close();
    ifstream myFile3;
    myFile3.open("leaderboard.txt");
    //reading file 
    if(myFile3.is_open()){
        while(getline(myFile3,line)){
            cout << line << endl;
        }
    }
    myFile3.close();
}
// trade resources with bank
int bankTrade(Player player, Banker b1) {
    string resourcewanting;
    string resourcegiving;
    int amountwanting;
    string answer;
    do {
        //letting the player know what the conditions are for trading with the bank
        cout << "Trading with the bank is 4:1" << endl;
        cout << "What would you like to trade for?" << endl;
        cin >> resourcewanting;
        cout << "How many " << resourcewanting << " would you like?" << endl;
        cin >> amountwanting;
        cout << "What would you like to trade away?" << endl;
        cin >> resourcegiving;
        int amountgiveup = amountwanting * 4;
        //checks if the player has enough resources to trade
        bool checker = player.enoughResources(resourcegiving, amountgiveup);
        if (checker) { // if checker is true
            cout << "You had enough! Transaction complete" << endl;
            //updates players resources
            player.updateResources(resourcewanting, amountwanting);
            player.updateResources(resourcegiving, -amountgiveup);
            //takes the resource out of the bank
            b1.giveOutResources(resourcewanting, amountwanting);
            //receives the resource that the player traded
            b1.receiveResources(resourcegiving, amountgiveup);
        } 
        else if (checker == false) { //if checker is false
            cout << "Not enough resources" << endl;
        }
        cout << "Would you like to trade again?" << endl;
        cin >> answer;
    } 
    while (answer == "Yes" || answer == "yes");
    cout << "Thank You for your business" << endl;
    player.displayResources();
    return 0;
}

//trade resources with players
int playerTrade(Player &player, Player player2) {
    string answer;
    string resourcewant;
    int amount1;
    int amount2;
    string resourcegiving;
    string tradeofferAnswer;
    cout << player.getPlayerName() << ", what resource do you want?" << endl;
    cin >> resourcewant;
    cout << "How many do you need?" << endl;
    cin >> amount1;
    cout << "What are you offering?" << endl;
    cin >> resourcegiving;
    cout << "How many are you offering?" << endl;
    cin >> amount2;
    cout << player2.getPlayerName() << ", do you accept? (Yes/No)" << endl;
    cin >> tradeofferAnswer;
    if (tradeofferAnswer == "Yes") {
        //checks if first player has enough resources to give
        bool checker1 = player.enoughResources(resourcegiving, amount2);
        //checks if second player has enough resources to give
        bool checker2 = player2.enoughResources(resourcewant, amount1);
        if (checker1 == true && checker2 == true) { // if both checkers are true
            cout << "Transaction complete" << endl;
            player.updateResources(resourcewant, amount1);
            player.updateResources(resourcegiving, -amount2);
            player2.updateResources(resourcewant, -amount1);
            player2.updateResources(resourcegiving, amount2);
        }
        if (checker1 == false) { // if first player doesn't have enough resources
            cout << player.getPlayerName() << " does not have enough resources. Transaction denied" << endl;
        }
        if (checker2 == false) { // if second player doesn't have enough resources
            cout << player2.getPlayerName() << " does not have enough resources. Transaction denied" << endl;
        }
    } 
    else if (tradeofferAnswer == "No") {
        cout << "Sorry " << player.getPlayerName() << ", " << player2.getPlayerName() << " doesnt accept your offer."
             << endl;
        return 0;
    }
    return 0;
}
//function for the monopoly card
int MonopolyCard(Player &player, Player& player2, Player& player3) {
    string resource;
    //empty string for the update resource function in the player class
    //allows nothing to pass to it
    cout << "You get to take a resource from each player." << endl;
    cout << player.getPlayerName() << ", what resource do you want to take from each player?" << endl;
    cin >> resource;
    if(player2.enoughResources(resource,1)== true){
        player.updateResources(resource,1);
        player2.updateResources(resource,-1);
    }
    else{
        cout << player2.getPlayerName() << " does not any " << resource << endl;
    }
    if(player3.enoughResources(resource,1)== true){
        player.updateResources(resource,1);
        player3.updateResources(resource,-1);
    }
    else{
         cout << player3.getPlayerName() << " does not any " << resource << endl;
    }
    cout << "Transaction complete" << endl;
    return 0;
}
//function for the year of plenty card
int yearOfPlentyCard(Player &player, Banker b1) {
    string resource1;
    string resource2;
    cout << "You can take any 2 resources from the bank" << endl;
    cout << "Resource 1?" << endl;
    cin >> resource1;
    cout << "Resource 2?" << endl;
    cin >> resource1;
    player.updateResources(resource1, 1);
    player.updateResources(resource2, 1);
    b1.giveOutResources(resource1, 1);
    b1.giveOutResources(resource2, 1);
    cout << "Transaction complete" << endl;
    return 0;
}
//function for the knight card
int knightCard(Player &player, int robbernum) {
    int newrobbernum;
    //player changing the robber spot
    cout << "What number would you like to change the robber spot to? (2-12)" << endl;
    cin >> newrobbernum;
    return newrobbernum;
}
//function to buy a development card
int buyDevelopmentCard(Player& player, Player& player2, Player& player3) {
    cout << "The cost of a Development Card is: 1 Ore, 1 Wood, 1 Wheat" << endl;
    //checkers to see if player has the corresponding resources
    bool checker = player.enoughResources("ore", 1);
    bool checker2 = player.enoughResources("wood", 1);
    bool checker3 = player.enoughResources("wheat", 1);
    Carddeck c1;
    //if they do have enough resources
    if (checker == true && checker2 == true && checker3 == true) {
        //removing resources from players bank
        player.updateResources("ore",-1);
        player.updateResources("wood",-1);
        player.updateResources("wheat",-1);
        //drawing the card
        string card = c1.draw_card();
        cout << "You got a " << card << endl;
        if (card == "Monopoly Card") { // if monopoly card is drawn
            MonopolyCard(player,player2,player3);
        } 
        else if (card == "Year of Plenty Card") { //if year of plenty card is drawn
            player.updateResources("ore", 1);
            player.updateResources("wheat", 1);
            player.updateResources("brick", 1);
        }
        else if (card == "Victory Point") { // if victory point is drawn
            player.updateVictoryPoint(1);
        } 
        else if (card == "Knight Card") {
            player.updateKnightCard(1);
        }
    } 
    else { //if they do not have enough resources
        cout << "You do not have enough resources." << endl;
        return 0;
    }
    return 0;
}
//function to find if any players have 3 knight cards
//if so they will get the largest army card which is worth 1 point
bool findLargestArmy(Player &player) {
    if (player.getKnightCard() >= 3) {
        player.updateVictoryPoint(1);
        return true;
    } 
    else {
        return false;
    }
    return 0;
}
//prompts player if they want to trade with the banker
void handleBankTradeQuestion(Player &player, Banker banker) {
    string answer;
    cout << "Would you like to trade with the bank? (Yes/No)" << endl;
    cin >> answer;
    if (answer == "Yes") {
        bankTrade(player, banker);
    } 
    else if (answer == "No") {
        cout << "Ok, moving on" << endl;
    } 
    else {
        cout << "Please respond with (Yes/No)\n";
        handleBankTradeQuestion(player, banker);
    }
}
//prompt if player wants to trade with another player
void handleTradeQuestion(Player &player, Player& player2,Player& player3) {
    string playerAnswer;
    string playerTradeAnswer;
    string playerNameAnswer;
    cout << "Would you like to trade with another player? (Yes/No)" << endl;
    cin >> playerAnswer;
    if (playerAnswer == "Yes") {
        cout << "Would anyone like to trade with " << player.getPlayerName() << "? (Yes/No)" << endl;
        cin >> playerTradeAnswer;
        if (playerTradeAnswer == "Yes") {
            cout << "Who?" << endl;
            cin >> playerNameAnswer;
            if(playerNameAnswer == player2.getPlayerName()){
                playerTrade(player,player2);
            }
            else if(playerNameAnswer == player3.getPlayerName()){
                playerTrade(player,player3);
            }
            else{
                cout << "Player does not exist" << endl;
            }
        } 
        else {
            cout << "Sorry, no one wants to trade with you" << endl;
        }
    } 
    else if (playerAnswer == "No") {
        cout << "Ok, moving on" << endl;
    } 
    else {
        cout << "Please respond with (Yes/No)\n";
        handleTradeQuestion(player, player2,player3);
    }
}
//prompts the player if they want to buy a development card
void handleDevelopmentCardQuestion(Player &player, Player& player2,Player& player3) {
    string buyCardAnswer;
    cout << "Would you like to buy a development card? (Yes/No)" << endl;
    cin >> buyCardAnswer;
    if (buyCardAnswer == "Yes") {
        buyDevelopmentCard(player, player2,player3);
    } 
    else if (buyCardAnswer == "No") {
        cout << "Ok, moving on" << endl;
    } 
    else {
        cout << "Please respond with (Yes/No)" << endl;
        handleDevelopmentCardQuestion(player,player2,player3);
    }
}
//checks if player has 10 points
bool findWinner(Player player){
    if(player.getVictoryPoint() >= 10){
        cout << "Congrats " << player.getPlayerName() << "! You win!" << endl;
        return true;
    }
    return false;
}
// recursive menu that will run 
// the game questions and run until the first player has 10 points
void PlayerTurnMenu(Player &player, Player& player2,Player& player3, Banker b1) {
    cout << "It is " << player.getPlayerName() << "'s turn" << endl;
    diceRoll(player,b1);
    cout << endl;
    //Ask player if they want to trade with the bank
    handleBankTradeQuestion(player, b1);
    cout << endl;
    //Ask player if they want to trade with another player
    handleTradeQuestion(player, player2,player3);
    cout << endl;
    //Ask player if they want to buy a development card
    handleDevelopmentCardQuestion(player,player2,player3);
    cout << endl;
    //Displays players resource
    cout << "Here are your resources:" << endl;
    player.displayResources();
}
// //real driver function to play the game
int main() {
    Player p1;
    Player p2;
    Player p3;
    Player arr[3];
    startGame(p1, p2, p3);
    arr[0] = p1;
    arr[1] = p2; //putting each player object into a player array
    arr[2] = p3;
    int rounds = 10;
    Banker b1 = Banker(2);
    cout << leaderBoard(arr) << endl;
    // do while loop to run the game until a player reaches 10 victory points
    for(int i = 0; i < rounds; i++){
        PlayerTurnMenu(p1,p2,p3, b1);
        bool checker = findWinner(p1);
        PlayerTurnMenu(p2,p1,p3, b1);
        bool checker2=findWinner(p2);
        PlayerTurnMenu(p3,p1,p2, b1);
        bool checker3=findWinner(p3);
        //if a player has 10 points break the loop
        if(checker == true || checker2 == true || checker3 == true){
            break;
        }
        cout << "Here is the score" << endl;
        //display stats
        cout << endl;
        updateLeaderBoard(p1,p2,p3);
        cout << endl;
    }
    cout << "Game Over. Thanks for Playing!!" << endl;
}