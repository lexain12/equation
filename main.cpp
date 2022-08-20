#include <stdio.h>
#include <math.h>

#include "equation.h"

int main()
{
  Coefficents coefficents;
  Solution solution;

  coefficentReading(&coefficents);

  quadraticEquation(&coefficents, &solution);

  answerOutput(&solution);

  return 0;
}

double findDiscriminant(Coefficents *coefficents)
{
  return coefficents->b * coefficents->b - 4 * coefficents->a * coefficents->c;
}

void coefficentReading(Coefficents *coefficents)
{
  printf("Введите коэфиценты уравнения a*x^2 + b*x + c = 0\n");
  scanf("%lf %lf %lf", &coefficents->a, &coefficents->b, &coefficents->c);

  return;
}

void linealEquation(Coefficents *coefficents, Solution *solution)
{
    if (fabs(coefficents->b) < eps)
    {
      if (fabs(coefficents->c) < eps)
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
  if (fabs(coefficents->a) < eps)
  {
    linealEquation(coefficents, solution);
    return;
  }

  double discriminant = findDiscriminant(coefficents);

  if (discriminant < 0)
  {
    solution->numberOfRoots = noRoots;
  }
  else if (fabs(discriminant) < eps)
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

