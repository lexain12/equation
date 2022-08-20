#include <stdio.h>
#include <math.h>

enum NumberOfRoots
{
  noRoots   = 0,
  oneRoot   = 1,
  twoRoots  = 2,
  infRoots = -1,
  defaultValue = 3,
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
  NumberOfRoots numberOfRoots = defaultValue;
};

double findDiscriminant(Coefficents *coefficents);

void coefficentReading(Coefficents *coefficents);

void linealEquation(Coefficents *coefficents, Solution *solution);

void quadraticEquation(Coefficents *coefficents, Solution *solution);

void answerOutput(Solution *solution);