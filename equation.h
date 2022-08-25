#include <stdio.h>
#include <math.h>

/// Conditions of numberOfRoots
enum NumberOfRoots
{
  noRoots   = 0, ///< The equation doesn't have roots
  oneRoot   = 1, ///< The equation have 1 root
  twoRoots  = 2, ///< The equation have two roots
  infRoots = -1, ///< The equation have infinite number of roots
};

/// Structure with coefficients of equation
struct Coefficients
{
  double a = NAN; ///< cofficent of x^2
  double b = NAN; ///< cofficent of x
  double c = NAN; ///< free term
};

/// Structure with solution data
struct Solution
{
  double x1 = NAN; ///< first root of equation
  double x2 = NAN; ///< Second root of equation
  NumberOfRoots numberOfRoots = noRoots; ///< Number of roots of the equation
};

/// enum with all errors
enum Errors
{
  noErrors    = 0, ///< program has no errors
  inputError  = 1, ///< program has error in coefficentReading function
  solveError  = 2, ///< program has error in quadraticEquation or linealEquation functions
  outputError = 3, ///< program has error in answerOutput function
};

const double EPS = 1e-7;


/// Function that compares number with zero
/// @param [in] number number that you want to compare
/// @return true if number is zero, false if not
bool isZero(double number);

///Function that prints errors
///\param [in] status status of programm
void printError(int status);

/**
 * Function that evaluate descriminant
 * \param [in] coefficent structure with equation coefficients
 * \return value of dicriminant
 * */
double evaluateDiscriminant(const Coefficients *coefficients);

/**Function for cleaning input
 * */
void inputCleaning();

/**
 * Function that reads coefficent from flow
 *\param [in] coefficent structure with equation coefficients
 * */
int coefficientInput(Coefficients *coefficients);

/**
 * Function that solves lineal equation
 * \param [in] coefficent structure with equation coefficients
 * \param [in] solution structure with roots and number of roots
 * */
int solveLinealEquation(Coefficients *coefficients, Solution *solution);

/**
 * Function that solves quadratic equation
 * \param [in] coefficent structure with equation coefficients
 * \param [in] solution structure with roots and number of roots
 * */
int solveQuadraticEquation(Coefficients *coefficients, Solution *solution);

/**
 * Function that prints solution in flow
 * \param [in] solution structure with roots and number of roots
 * */
int answerOutput(Solution *solution);

