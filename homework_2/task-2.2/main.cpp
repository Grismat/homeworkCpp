#include <stdio.h>
#include <cstdlib>
#include <time.h>

double binaryPow(int number, int degree)
{
    int integerValue = 0;
    bool isDegreeNegative = false;

    if (degree < 0)
    {
        isDegreeNegative = true;
        degree = -degree;
    }

    if (degree % 2 == 0)
    {
        if (degree == 0)
        {
            integerValue = 1;
        }
        else
        {
            int numberInHalfDegree = binaryPow(number, degree / 2);
            integerValue = numberInHalfDegree * numberInHalfDegree;
        }
    }
    else
    {
        int numberInHalfDegree = binaryPow(number, degree / 2);
        integerValue = numberInHalfDegree * numberInHalfDegree * number;
    }

    return (isDegreeNegative) ? 1.0 / integerValue : integerValue;
}

double linearPow(int number, int degree)
{
    int integerResult = 1;
    bool isDegreeNegative = false;

    if (degree < 0)
    {
        isDegreeNegative = true;
        degree = -degree;
    }

    for (int i = 0; i < degree; i++)
    {
        integerResult *= number;
    }

    return (isDegreeNegative) ? 1.0 / integerResult : integerResult;
}

int main()
{
    srand(time(nullptr));
    int const tries = 20;

    printf("Here is the simple test of the pow functions:\n");

    for (int i = 0; i < tries; i++)
    {
        int number = rand() % 10;
        int degree = rand() % 11;
        if (i % 2 == 0)
        {
            degree = -degree;
        }

        printf("Number: %i\t Degree: %i\t linearPow: %f\t binaryPow: %f\n",
               number, degree, linearPow(number, degree), binaryPow(number, degree));
    }

    return 0;
}
