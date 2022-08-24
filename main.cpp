#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "equation.h"

int main()
{
  int status = noErrors;

  Coefficients coefficients = {};
  status = coefficientInput(&coefficients);
  if (status)
  {
    printError(status);
    return EXIT_FAILURE;
  }

  Solution solution = {};
  status = solveQuadraticEquation(&coefficients, &solution);
  if (status)
  {
    printError(status);
    return EXIT_FAILURE;
  }

  status = answerOutput(&solution);
  if (status)
  {
    printError(status);
    return EXIT_FAILURE;
  }

  return 0;
}

