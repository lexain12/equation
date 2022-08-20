#include <stdio.h>
#include <math.h>


struct Coefficents 
{
  double a;
  double b;
  double c;
};

struct Solution
{
  double x1;
  double x2;
  int numberOfRoots;
};

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
    if (coefficents->b == 0)
    {
      if (coefficents->c == 0)
        solution->numberOfRoots = -1;
      else
        solution->numberOfRoots = 0;
    }
    else 
    {
      solution->numberOfRoots = 1;
      solution->x1 = -(coefficents->c) / coefficents->b;
    }
}

void quadraticEquation(Coefficents *coefficents, Solution *solution)
{
  if (coefficents.a == 0)
  {
    linealEquation(&coefficents, &solution);
    return;
  }

  double discriminant = findDiscriminant(coefficents);

  if (discriminant < 0)
  {
    solution->numberOfRoots = 0;
  }
  else if (discriminant == 0)
  {
    solution->numberOfRoots = 1;
    solution->x1 = -(coefficents->b) / (2 * coefficents->a);
  }
  else
  {
  solution->x1 = (-(coefficents->b) + sqrt(discriminant)) / (2 * coefficents->a);
  solution->x2 = (-(coefficents->b) - sqrt(discriminant)) / (2 * coefficents->a);
  solution->numberOfRoots = 2;
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
      fprintf(stderr, "Error: undefined solution");
  }
}

int main()
{
  Coefficents coefficents = {};
  Solution solution = {};

  coefficentReading(&coefficents);

  quadraticEquation();

  answerOutput(&solution);

  return 0;
}

