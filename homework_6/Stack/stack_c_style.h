#pragma once
#include <cstdlib>

struct Element {
    float value;  
    Element* prev;
};

struct Stack {
    Element* top = nullptr;
    size_t size = 0;
};

void pushElement(Stack* stack, float value);
bool popElement(Stack* stack, float* result);