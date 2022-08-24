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
      solution->x1 = NAN;
      solution->x2 = NAN;
      solution->numberOfRoots = infRoots;
      return noErrors;
    }
    else
    {
      solution->x1 = NAN;
      solution->x2 = NAN;
      solution->numberOfRoots = noRoots;
      return noErrors;
    }
  }
  else 
  {
    solution->numberOfRoots = oneRoot;
    solution->x1 = -(coefficents->c) / coefficents->b;
    solution->x2 = NAN;
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
    solution->x1 = (-(coefficents->b) - sqrtDes)/ (2 * coefficents->a);
    solution->x2 = (-(coefficents->b) + sqrtDes) / (2 * coefficents->a);
    solution->numberOfRoots = twoRoots;
    return noErrors;
  }
  return solveError;
}


