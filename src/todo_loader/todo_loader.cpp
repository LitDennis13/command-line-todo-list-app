#include "todo_loader.h"
#include "../constants/constants.h"

#include <iostream>
#include <fstream>

std::string **loadTodos(std::fstream &inFile) {
    int numberOfTodos;
    inFile >> numberOfTodos;

    std::string **returnTodos = new std::string*[numberOfTodos];

    std::string tempTodoInfo;
    getline(inFile,tempTodoInfo);

    for (int i = 0; i < numberOfTodos; i++) {
        returnTodos[i] = new std::string[NUMBER_OF_INFO_IN_TODO];

        getline(inFile,tempTodoInfo);
        returnTodos[i][0] = tempTodoInfo;

        getline(inFile,tempTodoInfo);
        returnTodos[i][1] = tempTodoInfo;

        getline(inFile,tempTodoInfo);
        returnTodos[i][2] = tempTodoInfo;

        getline(inFile,tempTodoInfo);
    }
    
    return returnTodos;
}