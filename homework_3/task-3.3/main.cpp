#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

int findMostFrequentElement(int* const begin, int* const end) {
    int size = end - begin;
    int mostFrequentElement = begin[0];
    int maxCount = 1;
    int count = 1;

    for (int i = 1; i < size; i++) {
        if (begin[i] == begin[i - 1]) {
            count++;
        }
        else {
            if (count > maxCount) {
                mostFrequentElement = begin[i - 1];
                maxCount = count;
            }
            count = 1;
        }
    }

    /*if (count > maxCount) {
        mostFrequentElement = begin[size - 1];
    }*/

    return (count > maxCount) ? begin[size - 1] : mostFrequentElement; //стоит ли так делать, или лучше лишнее ветвление?
}

int main() {
    srand(time(0));

    int const size = 20;
    int array[size];

    printf("Array is:\n");
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 101;
        printf("%i ", array[i]);
    }

    std::sort(array, array + size); //O(size*log(size))

    printf("\nSorted array is:\n");
    for (int i = 0; i < size; i++) {

        printf("%i ", array[i]);
    }

    int mostFrequentElement = findMostFrequentElement(array, array + size); //O(size)

    printf("\nThe most frequent element is: %i", mostFrequentElement);
    return 0;
}