#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "equation.h"

int main()
{
  int status = noErrors;

  Coefficents coefficents = {};
  status = coefficentReading(&coefficents);
  if (status)
  {
    printError(status); 
    return EXIT_FAILURE;
  } 

  Solution solution = {};
  status = quadraticEquation(&coefficents, &solution);
  if (status)
  {
    printError(status); 
    return EXIT_FAILURE;
  } 

  status = answerOutput(&solution);
  if (status)
  {
    printError(status); 
    return EXIT_FAILURE;
  } 

  return 0;
}

