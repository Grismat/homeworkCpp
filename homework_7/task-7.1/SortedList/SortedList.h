#pragma once

typedef int ValueType;

struct Element;

struct SortedList {
    Element* begin = nullptr;
    int size = 0;
};

void addElement(SortedList* list, ValueType value);

bool removeElement(SortedList* list, ValueType value);

void printList(SortedList* list);

