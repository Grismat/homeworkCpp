#include "SortedList.h"
#include <stdio.h>

int main() {
    char command[2];
    int value = 0;
    SortedList* list = createList();
    
    do {
        fgets(command, 2, stdin);

        switch (command[0]) {
        case '1':
            printf("Enter a number you want to add\n");
            scanf("%i", &value);
            addElement(list, value);
            break;
        
        case '2':
            printf("Enter a number you want to remove\n");
            scanf("%i", &value);
            if (removeElement(list, value)) {
                printf("Removed successfully\n");
            }
            else {
                printf("Removing failed\n");
            }
            break;

        case '3':
            printf("Here's the list:\n");
            printList(list);
            break;
        }

    } while (command[0] != '0');

    deleteList(list);
    return 0;
}