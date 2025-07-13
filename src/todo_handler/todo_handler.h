#pragma once

#include <iostream>

void loadTodos(std::fstream &inFile, std::string ***saveSpot, int *numberOfTodos);

void listTodos(std::string **todos, int numberOfTodos);