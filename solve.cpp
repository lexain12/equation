#include <math.h>
#include <assert.h>

#include "equation.h"

double findDiscriminant(Coefficents *coefficents)
{
  assert(coefficents != NULL); 

  return coefficents->b * coefficents->b - 4 * coefficents->a * coefficents->c;
}

int linealEquation(Coefficents *coefficents, Solution *solution)
{
  assert(coefficents != NULL);
  assert(solution != NULL);

  if (isZero(coefficents->b))
  {
    if (isZero(coefficents->c))
    {
      solution->numberOfRoots = infRoots;
      return noErrors;
    }
    else
    {
      solution->numberOfRoots = noRoots;
      return noErrors;
    }
  }
  else 
  {
    solution->numberOfRoots = oneRoot;
    solution->x1 = -(coefficents->c) / coefficents->b;
    return noErrors;
  }
  return solveError;
}

int quadraticEquation(Coefficents *coefficents, Solution *solution)
{
  assert(coefficents != NULL);
  assert(solution != NULL);

  if (isZero(coefficents->a))
  {
    linealEquation(coefficents, solution);
    return noErrors;
  }

  double discriminant = findDiscriminant(coefficents);

  if (isZero(discriminant))
  {
    solution->numberOfRoots = oneRoot;
    solution->x1 = -(coefficents->b) / (2 * coefficents->a);
    return noErrors;
  }
  else if (discriminant < 0)
  {
    solution->numberOfRoots = noRoots;
    return noErrors;
  }
  else if (discriminant > 0)
  {
    solution->x1 = (-(coefficents->b) + sqrt(discriminant)) / (2 * coefficents->a);
    solution->x2 = (-(coefficents->b) - sqrt(discriminant)) / (2 * coefficents->a);
    solution->numberOfRoots = twoRoots;
    return noErrors;
  }
  return solveError;
}


