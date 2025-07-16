#include <iostream>
#include <fstream>
#include "extra_functions/extra_functions.h"
#include "todo_handler/todo_handler.h"
#include "screen_handler/screen_handler.h"

int main() {
    std::cout << "---Command Line Todo List App---" << std::endl;
    
    std::string **todos = nullptr;
    int numberOfTodos = 0;
    loadTodos(&todos, &numberOfTodos);

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
                clearFunction();
                addTodoScreen(&todos, &numberOfTodos);
                break;
            }

            case ('e'): {
                clearFunction();
                editTodoScreen(todos, numberOfTodos);
                break;
            }

            case ('d'): {
                clearFunction();
                deleteTodoScreen(&todos, &numberOfTodos);
                break;
            }

            case ('q'): {
                run = 0;
                break;
            }

            default: {
                clearFunction();
                break;
            } 
        }
    }

    return 0;
}