#pragma once

#include <iostream>

void optionScreen(char* userInput);

void listTodosScreen(std::string **todos, int numberOfTodos);

void addTodoScreen(std::string ***todos, int *numberOfTodos);

void editTodoScreen(std::string **todos, int numberOfTodos);