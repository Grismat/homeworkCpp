#include "CyclicalList.h"
#include <stdio.h>

struct Element {
    ValueType value;
    Element* next;
};

struct CyclicalList;

void addElementToEnd(CyclicalList* list, ValueType value) {
    Element* newElement = new Element;
    newElement->value = value;
    newElement->next = nullptr;

    if (list->begin == nullptr) {
        list->begin = newElement;
        list->last = newElement;
        newElement->next = list->begin;
        list->size++;
        return;
    }

    list->last->next = newElement;
    list->last = newElement;
    newElement->next = list->begin;

    list->size++;
}

void removeEveryNthElement(CyclicalList* list, int const n) {
    Element* currentElement = list->begin;
    Element* previousElement = list->last;
    int position = 1;

    while (list->size != 1) {
        if (position % n == 0) {
            if (currentElement == list->begin) {
                list->begin = currentElement->next;
                list->last->next = list->begin;
            }
            else if (currentElement == list->last) {
                previousElement->next = list->begin;
                list->last = previousElement;
            }
            else {
                previousElement->next = currentElement->next;
            }

            delete currentElement;
            list->size--;
            
            currentElement = previousElement->next;
        }
        else {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }
        position++;
    }
}

ValueType getFirstValue(CyclicalList* list) {
    return list->begin->value;
}