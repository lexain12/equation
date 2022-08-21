#include <stdio.h>
#include <math.h>

enum NumberOfRoots
{
  noRoots   = 0,
  oneRoot   = 1,
  twoRoots  = 2,
  infRoots = -1,
};

struct Coefficents 
{
  double a = NAN;
  double b = NAN;
  double c = NAN;
};

struct Solution
{
  double x1 = NAN;
  double x2 = NAN;
  NumberOfRoots numberOfRoots = noRoots;
};

const double eps = 1e-10;

bool isZero(double number);

double findDiscriminant(Coefficents *coefficents);

void coefficentReading(Coefficents *coefficents);

void linealEquation(Coefficents *coefficents, Solution *solution);

void quadraticEquation(Coefficents *coefficents, Solution *solution);

void answerOutput(Solution *solution);
