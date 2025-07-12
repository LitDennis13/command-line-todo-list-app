#include <iostream>
#include <fstream>
#include <cstdlib>
#include "extra_functions/extra_functions.h"
#include "todo_loader/todo_loader.h"

int main() {
    std::cout << "---Command Line Todo List App---" << std::endl;
    
    std::fstream saveFile("save/CLTLASave.txt");

    if (!saveFile) std::cout << "Could not open the save file!!" << std::endl;

    std::string **todos;
    todos = loadTodos(saveFile);
    
    bool run = false;

    char userInput;
    
    while (run) {
        system("clear");
        std::cout << "Enter the assigned letter for an action and type H for help" << std::endl;
        std::cout << "H - Help" << std::endl;
        std::cout << "C - Clear Console" << std::endl;
        std::cout << "L - List Todo's" << std::endl;
        std::cout << "A - Add Todo" << std::endl;
        std::cout << "MC - Mark Todo completed" << std::endl;
        std::cout << "UMC - Un Mark Todo completed" << std::endl;
        std::cout << "D - Delete Todo" << std::endl;
        std::cout << "Q - Quit program" << std::endl;
        std::cout << "Enter: ";
        std::cin >> userInput;
        lowerCaseCharacter(&userInput);

        if (userInput == 'q') {
            run = 0;
        }
    }
    

    
    
    return 0;
}