#include <math.h>
#include <assert.h>

#include "equation.h"

functionStrIsEqualStatus checkArg(int numberOfArguments, char* argumentsOfCmd[])
{
  for (int i = 1; i < numberOfArguments; i++)
  {
    if (strIsEqual("-test", argumentsOfCmd[i]))
    {
      return debugStatus;
    }  
    else
    {
      printf("Undefined argument %s\n", argumentsOfCmd[i]);
      return errorStatus;
    }
  }

  return normalStatus;
}

bool strIsEqual(const char rightString[],char yourString[])
{
  int i = 0;

  for (; rightString[i] != '\0' && yourString[i] != '\0'; i++)
  {
    if (!(rightString[i] == yourString[i]))
    {
      return false;
    }
  }

  return (rightString[i] == '\0' && yourString[i] == '\0');
}

int startProgramMode(functionStrIsEqualStatus isDebug)
{
  switch (isDebug)
  {
      case debugStatus:
        {
        system("make debug");
        system("./test");
        return 0;
        }

      case normalStatus:
      {
        fprintf(stderr, "Normal\n");
        int status = noErrors;

        Coefficients coefficients = {};
        status = coefficientInput(&coefficients);
        printf("Ok\n");
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
      case errorStatus:
      {
        return EXIT_FAILURE;
      }
      default:
      {
        printf("default %d, isDebug = %d\n", __LINE__, isDebug);
        return EXIT_FAILURE;
      }
  }
  
}

double evaluateDiscriminant(const Coefficients *coefficients)
{
  assert(coefficients != NULL);

  return coefficients->b * coefficients->b - 4 * coefficients->a * coefficients->c;
}

int solveLinealEquation(Coefficients *coefficients, Solution *solution)
{
  assert(coefficients != NULL);
  assert(solution != NULL);

  if (isZero(coefficients->b))
  {
    if (isZero(coefficients->c))
    {
      solution->x1 = NAN;
      solution->x2 = NAN;
      solution->numberOfRoots = infRoots;
      return noErrors;
    }
    else  // c != 0
    {
      solution->x1 = NAN;
      solution->x2 = NAN;
      solution->numberOfRoots = noRoots;
      return noErrors;
    }
  }
  else    // b != 0
  {
    solution->numberOfRoots = oneRoot;
    solution->x1 = -(coefficients->c) / coefficients->b;
    solution->x2 = NAN;
    return noErrors;
  }

  return solveError;
}

int solveQuadraticEquation(Coefficients *coefficients, Solution *solution)
{
  assert(coefficients != NULL);
  assert(solution     != NULL);

  if (isZero(coefficients->a))
  {
    solveLinealEquation(coefficients, solution);
    return noErrors;
  }

  double discriminant = evaluateDiscriminant(coefficients);

  if (isZero(discriminant))
  {
    solution->numberOfRoots = oneRoot;
    solution->x1 = -(coefficients->b) / (2 * coefficients->a);
    solution->x2 = NAN;
    return noErrors;
  }
  else if (discriminant < 0)
  {
    solution->x1 = NAN;
    solution->x2 = NAN;
    solution->numberOfRoots = noRoots;
    return noErrors;
  }
  else if (discriminant > 0)
  {
    double sqrtDes = sqrt(discriminant);
    solution->x1 = (-(coefficients->b) - sqrtDes) / (2 * coefficients->a);
    solution->x2 = (-(coefficients->b) + sqrtDes) / (2 * coefficients->a);
    solution->numberOfRoots = twoRoots;
    return noErrors;
  }

  return solveError;
}


