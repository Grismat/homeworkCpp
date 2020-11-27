#pragma once

typedef int ValueType;

struct CyclicalList;

CyclicalList* createList();
void deleteList(CyclicalList* list);

void addElementToEnd(CyclicalList* list, ValueType value);

void removeEveryNthElement(CyclicalList* list, int n);

ValueType getFirstValue(CyclicalList* list);