#include <algorithm>
#include <stdio.h>

void printArray(int* const begin, int* const end)
{
    size_t size = begin - end;
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
            if (begin[j] < begin[j-1])
            {
                std::swap(begin[j], begin[j-1]);
            }
        }
    }
}

void countingSort(int* const begin, int* const  end)
{
    size_t size = end - begin;

    int maxElement = begin[0];
    for (size_t i = 1; i < size; i++)
    {
        if (begin[i] > maxElement)
        {
            maxElement = begin[i];
        }
    }

    int* valuesCount = new int[maxElement+1]();

    for (size_t i = 0; i < size; i++)
    {
        valuesCount[begin[i]]++;
    }

    for (size_t i = 0; i <= maxElement; i++)
    {
        int mainIdx = 0;
        while (valuesCount[i] > 0) {
            begin[mainIdx] = valuesCount[i]--;
            mainIdx++;
        }
    }

    delete[] valuesCount;
}

int main()
{
    printf("Here's the simple test for two sort functions\n");

    int array0[14] = {4, 1, 6, 3, 7, 2, 3, 6, 3, 8, 1, 1, 1, 43};
    int array1[14] = {4, 1, 6, 3, 7, 2, 3, 6, 3, 8, 1, 1, 1, 43};
    int array2[14] = {4, 1, 6, 3, 7, 2, 3, 6, 3, 8, 1, 1, 1, 43};

    std::sort(array0, array0+14);
    bubbleSort(array1, array1+14);
    countingSort(array2, array2+14);

    printf("Standart sort function:\n\t");
    printArray(array0, array0+14);
    
    printf("BubbleSort:\n\t");
    printArray(array2, array2+14);

    printf("CountingSort:\n\t");
    printArray(array2, array2+14);

    return 0;
}