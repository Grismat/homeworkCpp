#pragma once

typedef int ValueType;

struct SortedList;

SortedList* createList();
void deleteList(SortedList* list);

void addElement(SortedList* list, ValueType value);

bool removeElement(SortedList* list, ValueType value);

void printList(SortedList* list);

