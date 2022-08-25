#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "equation.h"

int main(int argc, char* argv[])
{
  functionStrIsEqualStatus isDebug = checkArg(argc, argv);

  return startProgramMode(isDebug);
}

