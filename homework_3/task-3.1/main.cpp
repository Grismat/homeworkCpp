#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

void insertionSort(int* const begin, int* const end)
{
    size_t size = end - begin;
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && begin[j] < begin[j-1]; j--)
        {
            std::swap(begin[j], begin[j-1]);
        }
    }
}

size_t partition(int* const begin, int* const end)
{
    size_t size = end - begin;
    int pivotElement = begin[size - 1];
    int leftCursor = 0;

    for (int i = 0; i < size; i++)
    {
        if (begin[i] < pivotElement)
        {
            std::swap(begin[i], begin[leftCursor]);
            leftCursor++;
        }
    }
    std::swap(begin[leftCursor], begin[size - 1]);
    return leftCursor;
}

void quickSort(int* const begin, int* const end)
{
    if (end - begin < 10)
    {
        insertionSort(begin, end);
        return;
    }

    size_t partitionIndex = partition(begin, end);
    quickSort(begin, begin + partitionIndex);
    quickSort(begin + partitionIndex + 1, end);
}

int main()
{
    srand(time(0));
    int const size = 100;
    int array1[size];
    int array2[size];

    for (int i = 0; i < size; i++)
    {
        int randomValue = rand()%1000;
        array1[i] = randomValue;
        array2[i] = randomValue;
    }

    quickSort(array1, array1 + size);
    std::sort(array2, array2 + size);

    printf("Here's the array sorted by function from the standard library\n");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array2[i]);
    }

    printf("\n\n");
    printf("Here's the array sorted by my quickSort function\n");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array1[i]);
        if (array1[i] != array2[i])
        {
            printf("\nWrong number at position %i", i);
            break;
        }
    }


    return 0;
}