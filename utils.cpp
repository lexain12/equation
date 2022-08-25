#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "equation.h"

void printError(int status)
{
  switch (status)
  {
    case inputError:
      fprintf(stderr, "Error: wrong input");
      break;

    case solveError:
      fprintf(stderr, "Error: error in equation solve");
      break;

    case outputError:
      fprintf(stderr, "Error: output error");
      break;

    default:
      fprintf(stderr, "Error: undefined error");

  }
}

void inputCleaning()
{
    while (getchar() != '\n') {;}
}

bool isZero(double number)
{
  return fabs(number) < EPS;
}

int coefficientInput(Coefficients *coefficients)
{
  assert(coefficients != NULL);

  printf("Enter coefficients of equation ax^2 + bx + c = 0\n");
  int numberOfCorrect = scanf("%lf %lf %lf", &coefficients->a, &coefficients->b, &coefficients->c);

  for (int i = 0; i < 5; i++)
  {
    if (numberOfCorrect < 3)
    {
      printf("Wrong input, enter coefficients again\n");
      inputCleaning();
      scanf("%lf %lf %lf\n", &coefficients->a, &coefficients->b, &coefficients->c);
    }
    else
      return noErrors;
  }

  return inputError;
}

int answerOutput(Solution *solution)
{
  assert(solution != NULL);

  switch (solution->numberOfRoots)
  {
    case noRoots:
      printf("This equation has zero roots\n");
      break;

    case oneRoot:
      printf("This equation has 1 root x = %.3lf\n", solution->x1);
      break;

    case twoRoots:
      printf("This equation has 2 roots x1 = %.3lf  x2 = %.3lf\n", solution->x1, solution->x2);
      break;

    case infRoots:
      printf("This equation has infinite number of roots\n");
      break;

    default:
      return outputError;
  }
  return noErrors;
}

