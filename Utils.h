#ifndef PROJECT_3__UTILS_H
#define PROJECT_3__UTILS_H
#include <string>
#include <iostream>
using namespace std;
class Utils {
public:
    string static toLower(string input);
    int static split(string str, char separator, string arr[], int size);
};
#endif 
