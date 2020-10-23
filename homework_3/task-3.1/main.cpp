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

bool hasPivotElement(int* const begin, int* const end)
{
    int* elementPtr = begin + 1;

    while (elementPtr != end)
    {
        if (*elementPtr != *begin)
        {
            return true;
        }
        elementPtr++;
    }
    return false;
}

void badQuickSort(int* const begin, int* const end)
{
    size_t size = end - begin;

    if (size < 10)
    {
        insertionSort(begin, end);
        return;
    }

    if (!hasPivotElement(begin, end))
    {
        return;
    }

    size_t leftCursor = 0;
    size_t rightCursor = size - 1;

    int pivotElement = *(end - 1);

    bool isLeftCursorMoving = true;
    bool isRightCursorMoving = true;

    while (leftCursor < rightCursor)
    {
        if (isLeftCursorMoving)
        {
            if (begin[leftCursor] < pivotElement)
            {
                leftCursor++;
            }
            else
            {
                isLeftCursorMoving = false;
            }
        }

        if (isRightCursorMoving)
        {
            if (begin[rightCursor] >= pivotElement)
            {
                rightCursor--;
            }
            else
            {
                isRightCursorMoving = false;
            }
        }

        if (!isRightCursorMoving && !isLeftCursorMoving && leftCursor < rightCursor)
        {
            std::swap(begin[rightCursor], begin[leftCursor]);
            isRightCursorMoving = true;
            isLeftCursorMoving = true;
        }
    }

    badQuickSort(begin, begin + rightCursor);
    badQuickSort(begin + rightCursor, end);
}

int main()
{
    /*srand(time(NULL));
    int const size = 3;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand()%100;
    }

    printf("Default array is:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }

    transformate(array, array + size);

    printf("\n\nTransformed array is:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }*/
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

    badQuickSort(array1, array1 + size);
    std::sort(array2, array2 + size);

    for (int i = 0; i < size; i++)
    {
        printf("%i ", array2[i]);
    }

    printf("\n");
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