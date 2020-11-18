#pragma once
#include <cstdlib>

struct Element;

struct Stack {
    Element* top = nullptr;
    size_t size = 0;
};

void pushElement(Stack* stack, float value);

bool popElement(Stack* stack, float* result);

float topElement(Stack* stack);

int size(Stack* Stack);