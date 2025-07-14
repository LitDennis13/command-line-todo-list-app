#include "todo_handler.h"
#include "../constants/constants.h"
#include "../extra_functions/extra_functions.h"
#include <iostream>
#include <fstream>

void loadTodos(std::fstream &inFile, std::string ***saveSpot, int *numberOfTodos) {
    inFile >> *numberOfTodos;

    std::string **returnTodos = new std::string*[*numberOfTodos];

    std::string tempTodoInfo;
    getline(inFile,tempTodoInfo);

    for (int i = 0; i < *numberOfTodos; i++) {
        returnTodos[i] = new std::string[NUMBER_OF_INFO_IN_TODO];

        getline(inFile,tempTodoInfo);
        returnTodos[i][0] = tempTodoInfo;

        getline(inFile,tempTodoInfo);
        returnTodos[i][1] = tempTodoInfo;

        getline(inFile,tempTodoInfo);
        returnTodos[i][2] = tempTodoInfo;

        getline(inFile,tempTodoInfo);
    }

    *saveSpot = returnTodos;
}

void listTodos(std::string **todos, int numberOfTodos, bool withIDs) {
    for (int i = 0; i < numberOfTodos; i++) {
        std::cout << todos[i][0] << std::endl;
        if (todos[i][1] != "" && !checkOnlyContainsWhiteSpace(todos[i][1])) {
            std::cout << "    " << todos[i][1] << std::endl;
        }

        std::cout << "    status: ";
        if (todos[i][2] == "1") std::cout << "Completed" << std::endl;
        else std::cout << "Not Completed" << std::endl;

        if (withIDs) {
            std::cout << "    ID: " << i << std::endl;
        }
        
        std::cout << std::endl << std::endl;
    }
}

void addTodo(std::string ***saveSpot, int *numberOfTodos, std::string todoName, std::string todoDesc) {
    *numberOfTodos += 1;
    
    std::string **newSaveSpot = new std::string*[*numberOfTodos];

    for (int i = 0; i < *numberOfTodos - 1; i++) {
        newSaveSpot[i] = new std::string[3];
        newSaveSpot[i][0] = (*saveSpot)[i][0];
        newSaveSpot[i][1] = (*saveSpot)[i][1];
        newSaveSpot[i][2] = (*saveSpot)[i][2];

        delete [] (*saveSpot)[i];
    }
    
    newSaveSpot[*numberOfTodos - 1] = new std::string[3];
    newSaveSpot[*numberOfTodos - 1][0] = todoName;
    newSaveSpot[*numberOfTodos - 1][1] = todoDesc;
    newSaveSpot[*numberOfTodos - 1][2] = "0";

    delete [] *saveSpot;

    *saveSpot = newSaveSpot;
}