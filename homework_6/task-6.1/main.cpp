#include "stack_c_style.h"
#include <iostream>
#include <string>

static bool isError = false;

bool applyOperation(Stack* stack, char symbol) {

    float secondOperand = 0;        
    float firstOperand = 0;

    if (!popElement(stack, &secondOperand) || !popElement(stack, &firstOperand)) {
        return false;
    }

    switch (symbol) {
    case '+':
        pushElement(stack, firstOperand + secondOperand);
        break;
    
    case '-':
        pushElement(stack, firstOperand - secondOperand);
        break;

    case '*':
        pushElement(stack, firstOperand * secondOperand);
        break;

    case '/':
        pushElement(stack, firstOperand / secondOperand);
        break;
    }

    return true;
}

bool parseString(Stack* stack, std::string const& inputString) {
    for (int i = 0; i < inputString.size(); i++) {

        if (isdigit(inputString[i])) {
            pushElement(stack, inputString[i] - '0');
        }
        else {
            if (inputString[i] != ' ' && !applyOperation(stack, inputString[i])) {
                return false;
            }
        }           
    }
    return true;
}

int main() {
    
    Stack stack;

    printf("Enter an expression in postfix form\n");
    std::string inputString;
    getline(std::cin, inputString);

    float result = 0;

    if (parseString(&stack, inputString) && stack.size == 1) {
        popElement(&stack, &result);
        printf("%f\n", result);
    }
    else {
        printf("Error\n");
    }

    return 0;
}