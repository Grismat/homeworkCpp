#include <stdio.h>
#include <stdlib.h>
#include <algorithm>


void transformate(int* const begin, int const* end)
{

    int size = end - begin;
    int firstIndex = 0;
    int firstLessFromEndIndex = size - 1;

    while (firstIndex < firstLessFromEndIndex)
    {
        if (begin[firstIndex] > begin[firstIndex + 1])
        {
            std::swap(begin[firstIndex], begin[firstIndex + 1]);
            firstIndex++;
        }
        else
        {
            for (int i = firstLessFromEndIndex; i >= firstIndex; i--)
            {
                if (begin[i] < begin[firstIndex]  || i == firstIndex)
                {
                    firstLessFromEndIndex = i;
                    break;
                }
            }

            if (firstIndex == firstLessFromEndIndex)
            {
                break;
            }

            std::swap(begin[firstIndex + 1], begin[firstLessFromEndIndex]);
            firstLessFromEndIndex--;
        }
    }
}

#include <iostream>
int main()
{
    int const size = 20;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
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
    }

    return 0;
}