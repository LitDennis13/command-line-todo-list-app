#include "extra_functions.h"

void lowerCaseCharacter(char* inChar) {
    int inCharAscii = (int)(*inChar);
    if (inCharAscii >= 65 && inCharAscii <= 90) {
        *inChar = (char)(inCharAscii+32);
    }
}