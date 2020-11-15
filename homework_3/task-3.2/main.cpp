#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

bool binarySearch(int value, int* const begin, int* const end) {
    size_t size = end - begin;
    int lowIndex = 0;
    int highIndex = size - 1;

    if (size == 1) {
        return begin[0] == value;
    }

    if (begin[lowIndex] == value || begin[highIndex] == value) {
        return true;
    }

    while (lowIndex + 1 != highIndex) {
        int middleIndex = lowIndex + (highIndex - lowIndex) / 2;

        if (begin[middleIndex] < value) {
            lowIndex = middleIndex;
        }
        else if (begin[middleIndex] > value) {
            highIndex = middleIndex;
        }
        else {
            return true;
        }
    }

    return false;
}

int main() {
    srand (time(0));

    printf("Enter array size \"n\" and count of random numbers \"k\" in format \"n k\"\n");
    
    int arraySize = 0;
    int numbersCount = 0;

    scanf("%i %i", &arraySize, &numbersCount);
    int* array = new int[arraySize];

    printf("Generated array is:\n");
    for (int i = 0; i < arraySize; i++) {
        array[i] = rand() % 1001;
        printf("%i ", array[i]);
    }
    printf("\n");

    std::sort(array, array + arraySize);                            //according to cppreference.com, takes O(n*log(n))

    for (int i = 0; i < numbersCount; i++) {                        //takes O(numbersCount*log(n))
        int randomNumber = rand() % 1001;

        if (binarySearch(randomNumber, array, array + arraySize)) { //takes O(log(n))
            printf("Number %i is in array\n", randomNumber);
        }
        else {
            printf("Number %i is not in array\n", randomNumber);
        }
    }

    delete[] array;
    return 0;
}