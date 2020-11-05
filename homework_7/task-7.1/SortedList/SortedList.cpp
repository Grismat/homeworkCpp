#include "SortedList.h"
#include <stdio.h>

void addElement(SortedList* list, ValueType value) {
    
    Element* newElement = new Element;
    newElement->value = value;
    newElement->next = nullptr;

    if (list->begin == nullptr) {
        list->begin = newElement;
        return;
    }

    Element* currentElement = list->begin;
    while (currentElement->next != nullptr
            && currentElement->next->value < value) {

        currentElement = currentElement->next;
    }
    
    newElement->next = currentElement->next;
    currentElement->next = newElement;

    list->size++;
}

bool removeElement(SortedList* list, ValueType value) {
    Element* currentElement = list->begin;
    Element* previousElement = nullptr;

    if (currentElement == nullptr) {
        return false;
    }
    
    while (currentElement->value != value) {
        if (currentElement->next == nullptr) {
            return false;
        }

        previousElement = currentElement;
        currentElement = currentElement->next;
    }

    previousElement->next = currentElement->next;
    return true;
}

void printList(SortedList* list, ValueType value) {

    Element* currentElement = list->begin;
    if (list->begin == nullptr) {
        printf("\n");
    }

    while (currentElement->next != nullptr) {
        printf("%i ", currentElement->value);
    }
}