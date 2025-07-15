#pragma once

#include <iostream>

void loadTodos(std::fstream &inFile, std::string ***saveSpot, int *numberOfTodos);

void listTodos(std::string **todos, int numberOfTodos, bool withIDs);

void listSelectedTodoWithID(std::string **todos, int todoID);

void addTodo(std::string ***saveSpot, int *numberOfTodos, std::string todoName, std::string todoDesc);