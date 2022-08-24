#include <stdio.h>

#include "equation.h"

const char* COLOR_RED = "\033[1;31m";
const char* COLOR_RESET = "\033[0m";
const char* COLOR_GREEN = "\033[32m";

///Structure for tests
struct Test
{
    Coefficients coefficients = {};///<Test coefficients
    Solution     solution     = {};///<Correct solution
};


/**Function for checking if two double numbers are equal
 * @param [in] num1 first number that you want to check
 * @param [in] num2 second number that you want to check
 * @return bool value, true if are equal, false if not
 * */
bool areEqual(double num1, double num2);

/**Function for checking if solution that you give is correct
 * @param [in] correctSolution
 * @param [in] yourSolution
 * @return bool value, true if correct, false if not
 * */
bool checkSolution(Solution correctSolution, Solution yourSolution);

/**Function for printing test result
 * @param [in] passed indicates if test passed or not
 * @param [in] testNumber
 * */
void printTestResults(bool passed, size_t testNumber, Solution mySolution, Solution expectedSolution);

/** Main equation test function
 * @param [in] test array with Test structures
 * @param [in] numberOfTest
 * */
void equationTest(Test test[], size_t numberOfTests);

