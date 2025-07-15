#include "extra_functions.h"
#include <iostream>
#include <cstdlib>

void lowerCaseCharacter(char* inChar) {
    int inCharAscii = (int)(*inChar);
    if (inCharAscii >= 65 && inCharAscii <= 90) {
        *inChar = (char)(inCharAscii+32);
    }
}

void upperCaseString(std::string *str) {
    for (int i = 0; i < str->length(); i++) {
        int c = (int)((char)(*str)[i]);
        if (c >= 97 && c <= 122) {
            c -= 32;
        }
        (*str)[i] = (char)c;
    }
}

bool checkOnlyContainsWhiteSpace(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ' && str[i] != '\n') {
            return false;
        }
    }
    return true;
}

bool checkIfStringIsANumber(std::string str) { // only works with positive numbers which is fine
    if (str.length() == 0) return false;
    
    for (int i = 0; i < str.length(); i++) {
        int c = (int)str[i];
        if (c < 48 || c > 57) {
            return false;
        }
    }

    return true;
}

void clearFunction() {
    // using system is not good for security however for this project will be fine
    // FYI to use on windows must change the command to cls
    system("clear");
    system("clear");

    // more secur way of clearing, but doesnt remove text from before the command is called like the above
    // std::cout << "\033[2J\033[H";
    // std::cout << "\033[2J\033[H";
}


