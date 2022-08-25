#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "equation.h"

bool strIsEqual(const char rightString[], char yourString[]);

enum functionStrIsEqualStatus 
{
  normalStatus = 0,
  debugStatus = 1,
  errorStatus = 2
};

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

int main(int argc, char* argv[])
{
  functionStrIsEqualStatus isDebug = checkArg(argc, argv);

  return startProgramMode(isDebug);
}

