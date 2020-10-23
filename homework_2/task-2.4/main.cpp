#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

void transform(int* const begin, int const* end)
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
                if (begin[i] < begin[firstIndex] || i == firstIndex)
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

int main()
{
    srand(time(0));

    int const size = 20;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand()%1000;
    }

    printf("Default array is:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }

    transform(array, array + size);

    printf("\n\nTransformed array is:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }

    return 0;
}