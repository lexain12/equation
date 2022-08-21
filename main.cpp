#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "equation.h"

int main()
{
  Coefficents coefficents = {};
 coefficentReading(&coefficents);

  Solution solution = {};
  quadraticEquation(&coefficents, &solution);

  answerOutput(&solution);

  return 0;
}

double findDiscriminant(Coefficents *coefficents)
{
  assert(coefficents != NULL); 

  return coefficents->b * coefficents->b - 4 * coefficents->a * coefficents->c;
}

bool isZero(double number)
{
  return fabs(number) < eps;
}

void coefficentReading(Coefficents *coefficents)
{
  assert(coefficents != NULL);

  printf("Введите коэфиценты уравнения a*x^2 + b*x + c = 0\n");
  scanf("%lf %lf %lf", &coefficents->a, &coefficents->b, &coefficents->c);

  for (int i = 0; i < 5; i++)
  {
    if (isnan(coefficents->a) || isnan(coefficents->b) || isnan(coefficents->c))
    {
      printf("Неверный ввод, введите коэфиценты еще раз\n"); 
      fflush(stdin);
      scanf("%lf %lf %lf\n", &coefficents->a, &coefficents->b, &coefficents->c);
    }
    else
      return;
  }
  printf("You're annoying\n");
  exit(EXIT_FAILURE);

  return;
}

void linealEquation(Coefficents *coefficents, Solution *solution)
{
  assert(coefficents != NULL);
  assert(solution != NULL);

    if (isZero(coefficents->b))
    {
      if (isZero(coefficents->c))
        solution->numberOfRoots = infRoots;
      else
        solution->numberOfRoots = noRoots;
    }
    else 
    {
      solution->numberOfRoots = oneRoot;
      solution->x1 = -(coefficents->c) / coefficents->b;
    }
}

void quadraticEquation(Coefficents *coefficents, Solution *solution)
{
  assert(coefficents != NULL);
  assert(solution != NULL);

  if (isZero(coefficents->a))
  {
    linealEquation(coefficents, solution);
    return;
  }

  double discriminant = findDiscriminant(coefficents);

  if (isZero(discriminant))
  {
    solution->numberOfRoots = noRoots;
  }
  else if (discriminant < 0)
  {
    solution->numberOfRoots = oneRoot;
    solution->x1 = -(coefficents->b) / (2 * coefficents->a);
  }
  else if (discriminant > 0)
  {
  solution->x1 = (-(coefficents->b) + sqrt(discriminant)) / (2 * coefficents->a);
  solution->x2 = (-(coefficents->b) - sqrt(discriminant)) / (2 * coefficents->a);
  solution->numberOfRoots = twoRoots;
  }
}

void answerOutput(Solution *solution)
{
  assert(solution != NULL);

  switch (solution->numberOfRoots)
  {
    case 0:
      printf("This equation has zero roots\n");
      break;
    case 1:
      printf("This equation has 1 root x = %.3lf\n", solution->x1);
      break;
    case 2:
      printf("This equation has 2 roots x1 = %.3lf  x2 = %.3lf\n", solution->x1, solution->x2); 
      break;
    case -1:
      printf("This equation has infinite number of roots\n");
      break;
    default:
      fprintf(stderr, "Error: wrong input\n");
  }
}

