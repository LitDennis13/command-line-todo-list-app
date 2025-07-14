#include "screen_handler.h"
#include <iostream>
#include <limits>
#include "../extra_functions/extra_functions.h"
#include "../todo_handler/todo_handler.h"

void pressEnterToContinue(bool ignore) {
    char temp;
    std::cout << "Press enter to continue";
    if (ignore) std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.get(temp);
}

void optionScreen(char *userInput) {
    std::cout << "Enter the assigned letter for an action and type H for help" << std::endl;
    std::cout << "H - Help" << std::endl;
    std::cout << "L - List Todo's" << std::endl;
    std::cout << "A - Add Todo" << std::endl;
    std::cout << "E - Edit Todo" << std::endl;
    std::cout << "D - Delete Todo" << std::endl;
    std::cout << "Q - Quit program" << std::endl;
    std::cout << "Enter: ";
        
    std::cin.get(*userInput);
    lowerCaseCharacter(userInput);
}

void listTodosScreen(std::string **todos, int numberOfTodos) {
    listTodos(todos, numberOfTodos, false);
    
    pressEnterToContinue(true);
}

void addTodoScreen(std::string ***todos, int *numberOfTodos) {
    std::string name = "";
    std::string desc = "";

    bool attempedToGetName = false;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    do {
        if ((name == "" || checkOnlyContainsWhiteSpace(name)) && attempedToGetName) {
            clearFunction();
            std::cout << "Name cannot be empty" << std::endl;
            pressEnterToContinue(false);
            clearFunction();
        }
        std::cout << "Todo Name: ";
        getline(std::cin, name);

        attempedToGetName = true;
    } while (name == "" || checkOnlyContainsWhiteSpace(name));


    std::cout << "Todo Description: ";
    getline(std::cin, desc);

    std::cout << std::endl;

    upperCaseString(&name);

    addTodo(todos, numberOfTodos, name, desc);

    pressEnterToContinue(false);
}