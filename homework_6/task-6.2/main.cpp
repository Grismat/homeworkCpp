#include "stack_cpp_style.h"
#include <string>
#include <iostream>
#include <stdio.h>

bool checkSymbol(Stack<char>& stack, char const symbol) {

    if (symbol == '(' || symbol == '{' || symbol == '[') {
        stack.pushElement(symbol);
    }
    else { 
        switch (symbol) {
            case ')':
                if (stack.size() == 0 || stack.popElement() != '(') {
                    return false;
                }
                break;
            case '}':
                if (stack.size() == 0 || stack.popElement() != '{') {
                    return false;
                }
                break;
            case ']':
                if (stack.size() == 0 || stack.popElement() != '[') {
                    return false;
                }
                break;
        }            
    }

    return true;
}

bool parseString(std::string const& inputString) {

    Stack<char> stack;

    for (int i = 0; i < inputString.size(); i++) {
        if (!checkSymbol(stack, inputString[i])) {
            return false;
        }
    }

    return stack.size() == 0;
}

int main() {
    
    std::string inputString;
    getline(std::cin, inputString);

    if (parseString(inputString)) {
        printf("OK");
    }
    else {
        printf("Error");
    }

    return 0;
}