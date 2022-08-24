#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "equation.h"

void printError(int status)
{
  switch (status)
  {
    case inputError:
      fprintf(stderr, "Ошибка: неправильный ввод");
      break;

    case solveError:
      fprintf(stderr, "Ошибка: произошла ошибка в ходе решения уравнения");
      break;

    case outputError:
      fprintf(stderr, "Ошибка: произошла ошибка во время вывод");
      break;

    default:
      assert(0);

  }
}

bool isZero(double number)
{
  return fabs(number) < eps;
}

int coefficentReading(Coefficents *coefficents)
{
  assert(coefficents != NULL);

  printf("Введите коэффиценты уравнения ax^2 + bx + c = 0\n");
  int numberOfCorrect = scanf("%lf %lf %lf", &coefficents->a, &coefficents->b, &coefficents->c);

  for (int i = 0; i < 5; i++)
  {
    if (numberOfCorrect < 3)
    {
      printf("Неверный ввод, введите коэффиценты еще раз\n");
      fflush(stdin);
      scanf("%lf %lf %lf\n", &coefficents->a, &coefficents->b, &coefficents->c);
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

