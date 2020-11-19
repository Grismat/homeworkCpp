#pragma once
#include <cstdlib>

struct Element;

struct Stack;

Stack* createStack();

void deleteStack(Stack* stack);


void pushElement(Stack* stack, float value);

bool popElement(Stack* stack, float* result);

float topElement(Stack* stack);

int size(Stack* Stack);