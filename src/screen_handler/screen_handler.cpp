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

void editTodoScreen(std::string **todos, int numberOfTodos) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::string inputString;
    int todoID;
    bool gotTodoID = false;

    while (!gotTodoID) {
        listTodos(todos, numberOfTodos, true);

        std::cout << "Choose a Todo by ID to edit: ";
        getline(std::cin, inputString);

        if (checkIfStringIsANumber(inputString)) todoID = stoi(inputString);
        else todoID = -1;

        

        if (todoID < 0 || todoID >= numberOfTodos) {
            clearFunction();
            std::cout << "Todo ID must be one of the ID's listed above and a number" << std::endl;
            pressEnterToContinue(false);
            clearFunction();
        }
        else {
            gotTodoID = true;
            std::cin.clear();
            break;
        }
    }
    clearFunction();

    std::cout << "Selected ID is " << todoID << std::endl;
    listSelectedTodoWithID(todos, todoID);

    pressEnterToContinue(false);
}