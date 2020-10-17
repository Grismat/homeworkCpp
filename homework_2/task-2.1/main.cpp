#include <stdio.h>

int fibonacciRecursive(int number)
{
    if (number == 1 || number == 2)
    {
        return 1;
    }
    else
    {
        return fibonacciRecursive(number - 1) + fibonacciRecursive(number - 2);
    }
}

int fibonacciIterative(int number)
{
    int prePrevious = 0;
    int previous = 1;
    int currentNumber = 1;

    for (int i = 1; i < number; i++)
    {
        currentNumber = previous + prePrevious;
        prePrevious = previous;
        previous = currentNumber;
    }

    return currentNumber;
}

int main() {

    printf("Here's some test for my functions\n");
    for (int i = 1; i <= 30; i++)
    {
        printf("Number: %i\t iterative: %i\t  recursive: %i\n", i,
               fibonacciRecursive(i), fibonacciIterative(i));
    }

    return 0;
}
