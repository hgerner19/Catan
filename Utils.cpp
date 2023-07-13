//CS1300 Sping 2021
//Author: Holden Gerner
//Recitation: 220 - Micheal Hoefer
//Project - Project 3
#include <iostream>
#include "Utils.h"
#include <string>
using namespace std;
string Utils::toLower(string input) {
    for (char &c : input) {
        c = tolower(c);
    }
    return input;
}
int Utils::split(string str ,char separator ,string arr[],int size){
    int x = 0;
    string temp = "";
    string line = "";
    if(line == ""){
        return 0;
    }
    //add separator to the end of the line
    line = line + separator;
    int lineSize = line.length();
    for(int i = 0; i < lineSize; i++){
        if(line[i] != separator){
            // index value of i to temp
            temp += line[i];
        }
            //found the separator
        else{
            arr[x] = temp;
            x++;
            //clear temp
            temp = "";
        }
    }
    return x;
}