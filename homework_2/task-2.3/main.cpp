#include <algorithm>
#include <stdio.h>

void printArray(int* const begin, int* const end)
{
    size_t size = end - begin;
    for (size_t i = 0; i < size; i++)
    {
        printf("%i ", begin[i]);
    }
    printf("\n");
}

void bubbleSort(int* const begin, int* const end)
{
    size_t size = end - begin;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (begin[j] < begin[j - 1])
            {
                std::swap(begin[j], begin[j - 1]);
            }
        }
    }
}

void countingSort(int* const begin, int* const end)
{
    size_t size = end - begin;
    int* temporaryArray = new int[size];

    for (int i = 0; i < size; i++)
    {
        size_t counter = 0;
        for (int j = 0; j < size; j++)
        {
            if (begin[j] < begin[i] || (begin[i] == begin[j] && j < i))
            {
                counter++;
            }            
        }
        temporaryArray[counter] = begin[i];
    }

    for (int i = 0; i < size; i++)
    {
        begin[i] = temporaryArray[i];
    }

    delete[] temporaryArray;
}

int main()
{
    printf("Here's the simple test for two sort functions\n");

    int const size = 14;

    int array0[size] = {4, 1, 6, 3, 7, 2, 3, 6, 3, 8, 1, 1, 1, 43};
    int array1[size] = {4, 1, 6, 3, 7, 2, 3, 6, 3, 8, 1, 1, 1, 43};
    int array2[size] = {4, 1, 6, 3, 7, 2, 3, 6, 3, 8, 1, 1, 1, 43};

    std::sort(array0, array0 + size);
    bubbleSort(array1, array1 + size);
    countingSort(array2, array2 + size);

    printf("Standart sort function:\n\t");
    printArray(array0, array0 + size);
    
    printf("BubbleSort:\n\t");
    printArray(array2, array2 + size);

    printf("CountingSort:\n\t");
    printArray(array2, array2 + size);

    return 0;
}