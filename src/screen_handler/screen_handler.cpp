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
    if (numberOfTodos == 0) {
        std::cout << "There are no todos to list" << std::endl;
        pressEnterToContinue(true);
        return;
    }
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
    saveTodos(*todos, *numberOfTodos);

    pressEnterToContinue(false);
}

void editTodoNameScreen(std::string **todos, int todoID) {
    std::string newName;

    bool attempedToGetName = false;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    do {
        if ((newName == "" || checkOnlyContainsWhiteSpace(newName)) && attempedToGetName) {
            clearFunction();
            std::cout << "Name cannot be empty" << std::endl;
            pressEnterToContinue(false);
            clearFunction();
        }
        listSelectedTodoWithID(todos, todoID);
        std::cout << "Todo Name: ";
        getline(std::cin, newName);

        attempedToGetName = true;
    } while (newName == "" || checkOnlyContainsWhiteSpace(newName));

    upperCaseString(&newName);

    todos[todoID][0] = newName;
}

void editTodoDescScreen(std::string **todos, int todoID) {
    std::string newDesc;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    
    listSelectedTodoWithID(todos, todoID);
    std::cout << "Todo Description: ";
    getline(std::cin, newDesc);
 
    if (checkOnlyContainsWhiteSpace(newDesc)) newDesc = "";

    todos[todoID][1] = newDesc;
}

void editTodoScreen(std::string **todos, int numberOfTodos) {
    if (numberOfTodos == 0) {
        std::cout << "There are no todos to edit" << std::endl;
        pressEnterToContinue(true);
        return;
    }
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

    bool editing = true;
    char editOption;

    while (editing) {
        clearFunction();
        listSelectedTodoWithID(todos, todoID);

        std::cout << "Choose edit option" << std::endl;
        std::cout << "N - Name" << std::endl;
        std::cout << "D - Description" << std::endl;
        std::cout << "C - Toggle Completion Status" << std::endl;
        std::cout << "Q - Quit Todo Editor" << std::endl;

        std::cout << "Enter: ";

        std::cin.get(editOption);
        lowerCaseCharacter(&editOption);

        switch (editOption) {
            case ('n') : {
                clearFunction();
                editTodoNameScreen(todos, todoID);
                saveTodos(todos, numberOfTodos);
                break;
            }
            case ('d') : {
                clearFunction();
                editTodoDescScreen(todos, todoID);
                saveTodos(todos, numberOfTodos);

                break;
            }
            case ('c') : {
                clearFunction();
                if (todos[todoID][2] == "1") todos[todoID][2] = "0";
                else if (todos[todoID][2] == "0") todos[todoID][2] = "1";
                saveTodos(todos, numberOfTodos);
                break;
            }
            case ('q') : {
                clearFunction();
                editing = 0;
            }
            default: {
                break;
            }
        }
    }
}

void deleteTodoScreen(std::string ***todos, int *numberOfTodos) {
    if (*numberOfTodos == 0) {
        std::cout << "There are no todos to delete" << std::endl;
        pressEnterToContinue(true);
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::string inputString;
    int todoID;
    bool gotTodoID = false;

    while (!gotTodoID) {
        listTodos(*todos, *numberOfTodos, true);

        std::cout << "Choose a Todo by ID to delete: ";
        getline(std::cin, inputString);

        if (checkIfStringIsANumber(inputString)) todoID = stoi(inputString);
        else todoID = -1;

        if (todoID < 0 || todoID >= *numberOfTodos) {
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
    listSelectedTodoWithID(*todos, todoID);

    deleteTodo(todos, numberOfTodos, todoID);
    saveTodos(*todos, *numberOfTodos);
    
    std::cout << "THE TODO ABOVE HAS BEEN DELETED" << std::endl;
    std::cout << std::endl;

    pressEnterToContinue(false);
}