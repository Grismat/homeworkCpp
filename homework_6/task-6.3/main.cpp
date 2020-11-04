#include <iostream>
#include <string>
#include <cstring>
#include "stack_cpp_style.h"

bool processSymbol(Stack<char>* stack, char* outputString,
                    size_t* outputStringBack, char symbol) {
    
    char oper;

    if (symbol == '(') {
        stack->pushElement(symbol);
    } else {
        if (symbol == ')') {
            do {
                if (stack->size() == 0) {
                    return false;
                }
                oper = stack->popElement();
                outputString[*outputStringBack] = oper;
                (*outputStringBack)++;
            } while (oper != '(');

            (*outputStringBack)--; //ignore added '(' symbol
    } else {
        if (symbol == '+' || symbol == '-') {
            printf("add\n");
            if (stack->size() != 0 
                    && (stack->topElement() == '*' || stack->topElement() == '/')) {
                outputString[*outputStringBack] = stack->popElement();
                *(outputStringBack)++;
            }
            stack->pushElement(symbol);
    } else {
        if (symbol == '*' || symbol == '/') {
            stack->pushElement(symbol);
    } else {
        if (symbol != ' ' && symbol != '\n') {
            return false;
        }
    }}}}

    return true;
}

bool transformToPostfix(char const* inputString, char* outputString) {
    Stack<char> stack;
    size_t length = strlen(inputString);

    size_t outputStringBack = 0;

    for (int i = 0; i < length; i++) {
        if (isdigit(inputString[i])) {
            outputString[outputStringBack] = inputString[i];
            outputStringBack++;
        }
        else {
            if (!processSymbol(&stack, outputString,
                            &outputStringBack, inputString[i])) {
                return false;
            }
        }  
    }

    while (stack.size() != 0) {
        outputString[outputStringBack] = stack.popElement();
        if (outputString[outputStringBack] == '(') {
            return false;
        }

        outputStringBack++;
    }

    outputString[outputStringBack] = '\0';
    return true;
}

int main() {

    int const maxLength = 10;

    char string[maxLength];
    char outputString[maxLength];

    if (fgets(string, maxLength, stdin) != nullptr
            && transformToPostfix(string, outputString)) {
        printf("%s", outputString);
    }
    else {
        printf("Error");
    }
    

    return 0;
}