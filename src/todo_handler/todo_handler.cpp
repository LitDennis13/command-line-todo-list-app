#include "todo_handler.h"
#include "../constants/constants.h"
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

void listTodos(std::string **todos, int numberOfTodos) {
    for (int i = 0; i < numberOfTodos; i++) {
        std::cout << todos[i][0] << std::endl;
        if (todos[i][1] != "") {
            std::cout << "    " << todos[i][1] << std::endl;
        }

        std::cout << "    status: ";
        if (todos[i][2] == "1") std::cout << "Completed" << std::endl;
        else std::cout << "Not Completed" << std::endl;

        
        std::cout << std::endl << std::endl;
    }
}