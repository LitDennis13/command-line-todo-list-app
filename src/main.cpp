#include <iostream>
#include <fstream>
#include "extra_functions/extra_functions.h"
#include "todo_handler/todo_handler.h"
#include "screen_handler/screen_handler.h"

int main() {
    std::cout << "---Command Line Todo List App---" << std::endl;
    
    std::fstream saveFile("save/CLTLASave.txt");

    if (!saveFile) std::cout << "Could not open the save file!!" << std::endl;

    std::string **todos;
    int numberOfTodos;
    loadTodos(saveFile, &todos, &numberOfTodos);
    

    bool run = true;

    char userInput;
    
    while (run) {
        clearFunction();
        optionScreen(&userInput);

        switch (userInput) {
            case ('l'): {
                clearFunction();
                listTodosScreen(todos, numberOfTodos);
                break;
            }

            case ('a'): {
                /* Create Add tOdO screen */
                break;
            }


            case ('q'): {
                run = 0;
                break;
            }

            default: {
                clearFunction();
                notAnOptionScreen(userInput);
                break;
            } 
        }
    }
    
    return 0;
}