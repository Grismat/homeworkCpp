#include <stdio.h>
#include "CyclicalList.h"

int main() {
    int warriors = 0;
    int numberToKill = 0;

    printf("Enter count of warriors and position to be killed in format \"warriors numberToKill\"\n");
    scanf("%i %i", &warriors, &numberToKill);

    CyclicalList* list = createList();

    for (int i = 1; i <= warriors; i++) {
        addElementToEnd(list, i);
    }

    removeEveryNthElement(list, numberToKill);

    printf("You should stay on %i position\n", getFirstValue(list));

    deleteList(list);
    return 0;
}