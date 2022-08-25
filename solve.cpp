#include <math.h>
#include <assert.h>

#include "equation.h"

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


