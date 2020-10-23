#include <stdio.h>
#include <cstdlib>
#include <time.h>

size_t binaryPow(int number, int degree)
{
    if (degree % 2 == 0)
    {
        if (degree == 0)
        {
            return 1;
        }
        else
        {
            return binaryPow(number, degree / 2) * binaryPow(number, degree / 2);
        }
    }
    else
    {
        return binaryPow(number, degree/2) * binaryPow(number, degree/2) * number;
    }
}

int linearPow(int number, int degree)
{
    int result = 1;

    for (int i = 0; i < degree; i++)
    {
        result *= number;
    }

    return result;
}

int main()
{
    srand(time(0));
    int const tries = 20;

    printf("Here is the simple test of the pow functions:\n");

    for (int i = 0; i < tries; i++)
    {
        int number = rand() % 10;
        int degree = rand() % 11;
        printf("Number: %i\t Degree: %i\t linearPow: %i\t binaryPow: %i\n",
               number, degree, linearPow(number, degree), binaryPow(number, degree));
    }

    return 0;
}
