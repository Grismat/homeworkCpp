#include <stdio.h>
#include "List.h"

void readFromFileToList(List* list) {
    printf("Read");
    FILE *file = fopen("book.txt", "r");

    if (!file) {
        printf("file not found!");
    }

    while (!feof(file)) {
        char* firstname = new char[50];
        char* surname = new char[50];

        const int readBytes = fscanf(file, "%s - %s", firstname, surname);
        if (readBytes < 0) {
            break;
        }

        pushElement(list, firstname, surname);
    }

    fclose(file);
}

int main() {
    printf("Read");
    List list;
    readFromFileToList(&list);
    /*List* sortedList = mergeSort(&list, 'f');
    printList(sortedList);*/

    return 0;
}