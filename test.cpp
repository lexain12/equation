#include <stdio.h>

#include "test.h"

int main()
{
    Test test[] =
    {
        {
            {
             .a = 1,
             .b = -8,
             .c = 7
            },
            {
             .x1 = 7,
             .x2 = 1,
             .numberOfRoots = twoRoots
            }
        },
        {
            {
              .a = 0,
              .b = 0,
              .c = 0
            },
            {
              .x1 = NAN,
              .x2 = NAN,
              .numberOfRoots = infRoots
            }
        },
        {
            {
              .a = -1,
              .b = 0,
              .c = 4
            },
            {
              .x1 = 2,
              .x2 = -2,
              .numberOfRoots = noRoots
            }
        },
        {
            {
              .a = 0,
              .b = 0,
              .c = 1
            },
            {
              .x1 = NAN,
              .x2 = NAN,
              .numberOfRoots = noRoots
            }
        },
        {
            {
              .a = 0,
              .b = 1,
              .c = 1
            },
            {
              .x1 = -1,
              .x2 = NAN,
              .numberOfRoots = oneRoot
            }
        },
        {
            {
              .a = 1,
              .b = 0,
              .c = -4
            },
            {
              .x1 = 2,
              .x2 = -2,
              .numberOfRoots = twoRoots
            }
        },
        {
            {
              .a = 1,
              .b = -1,
              .c = 0
            },
            {
              .x1 = 0,
              .x2 = 1,
              .numberOfRoots = twoRoots
            }
        },
    };
    size_t length = sizeof(test) / sizeof(Test);
    equationTest(test, length) ;
}

bool areEqual(double num1, double num2)
{
    return isnan(num1) && isnan(num2) || isZero(num1 - num2);
}

bool checkSolution(Solution correctSolution, Solution yourSolution)
{
   return  correctSolution.numberOfRoots == yourSolution.numberOfRoots
           && ((   areEqual(correctSolution.x1, yourSolution.x1)
                && areEqual(correctSolution.x2, yourSolution.x2))
           || (    areEqual(correctSolution.x1, yourSolution.x2)
                && areEqual(correctSolution.x2, yourSolution.x1)));
}

void printTestResults(bool passed, size_t testNumber, Solution mySolution, Solution expectedSolution)
{
    if (passed)
    {
        printf("Test №%lu %s passed %s\n", testNumber, COLOR_GREEN, COLOR_RESET);
    }
    else
    {
        printf("Test №%lu %s failed%s\n", testNumber, COLOR_RED, COLOR_RESET);
        printf("Your answers: x1 = %lf x2 = %lf number of roots = %d\n", mySolution.x1, mySolution.x2, mySolution.numberOfRoots);
        printf("Expected:     x1 = %lf x2 = %lf number of roots = %d\n", expectedSolution.x1, expectedSolution.x2, expectedSolution.numberOfRoots);
    }
}

void equationTest(Test test[], size_t numberOfTests)
{
    for (size_t i = 0; i < numberOfTests; i++)
    {
        Solution mySolution = {};
        quadraticEquation(&(test[i].coefficents), &mySolution);

        printTestResults(checkSolution(test[i].solution, mySolution), i + 1, mySolution, test[i].solution);
    }
}

