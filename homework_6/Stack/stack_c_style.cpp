#include <cstddef>
#include "stack_c_style.h"

struct Element {
    float value;  
    Element* prev;
};

struct Stack;

void pushElement(Stack* stack, float value) {
    Element* newElement = new Element;
    newElement->value = value;
    newElement->prev = stack->top;

    stack->top = newElement;
    stack->size++;
}

bool popElement(Stack* stack, float* result) {
    if (stack->top  == nullptr) {
        return false;
    }

    float poppedValue = stack->top->value;
    Element* previous = stack->top->prev;
    delete stack->top;

    stack->top = previous;
    stack->size--;

    *result = poppedValue;
    return true;
}

float topElement(Stack* stack) {
    return stack->top->value;
}

int size(Stack* stack) {
    return stack->size;
}