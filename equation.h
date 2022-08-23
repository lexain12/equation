#include <stdio.h>
#include <math.h>

/// Conditions of numberOfRoots
enum NumberOfRoots
{
  noRoots   = 0,///< The equation doesn't have roots
  oneRoot   = 1,///< The equation have 1 root
  twoRoots  = 2,///< The equation have two roots
  infRoots = -1,///< The equation have infinite number of roots
};

///Structure with coefficents of equation
struct Coefficents 
{
  double a = NAN;///< cofficent of x^2
  double b = NAN;///< cofficent of x
  double c = NAN;///< free coefficent
};

///Structure dsafasdf 
struct Solution
{
  double x1 = NAN;///< first root of equation
  double x2 = NAN;///< Second root of equation
  NumberOfRoots numberOfRoots = noRoots;///< Number of roots of the equation
};
/// enum with all erorrs
enum Errors 
{
  noErrors    = 0,///< programm has no errors
  inputError  = 1,///< programm has error in coefficentReading function
  solveError  = 2,///< programm has error in quadraticEquation or linealEquation functions 
  outputError = 3,///< programm has error in answerOutput function 
};

const double eps = 1e-10;


/// Function that compares number with zero
/// @param [in] number number that you want to compare
/// @return true if number is zero, false if not
bool isZero(double number);

///Function that prints errors
///\param [in] status status of programm 
void printError(int status);

/**
 * Function that finds descriminant
 * \param [in] coefficent structure with equation coefficents
 * \return value of dicriminant
 * */
double findDiscriminant(Coefficents *coefficents);

/**
 * Function that reads coefficent from flow
 *\param [in] coefficent structure with equation coefficents
 * */
int coefficentReading(Coefficents *coefficents);

/**
 * Function that solves lineal equation 
 * \param [in] coefficent structure with equation coefficents
 * \param [in] solution structure with roots and number of roots
 * */
int linealEquation(Coefficents *coefficents, Solution *solution);

/**
 * Function that solves quadratic equation 
 * \param [in] coefficent structure with equation coefficents
 * \param [in] solution structure with roots and number of roots
 * */
int quadraticEquation(Coefficents *coefficents, Solution *solution);

/**
 * Function that prints solution in flow  
 * \param [in] solution structure with roots and number of roots
 * */
int answerOutput(Solution *solution);
