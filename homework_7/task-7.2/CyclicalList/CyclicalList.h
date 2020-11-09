#pragma once

typedef int ValueType;

struct Element {
    ValueType value;
    Element* next;
};

struct CyclicalList {
    Element* begin = nullptr;
    Element* last = nullptr;
    int size = 0;
};

void addElementToEnd(CyclicalList* list, ValueType value);

void removeEveryNthElement(CyclicalList* list, int n);

ValueType getFirstValue(CyclicalList* list);