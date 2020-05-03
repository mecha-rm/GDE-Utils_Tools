/*
 * Date: 05/02/2020
 * Description: generates random numbers.
 * References:
	* http://www.cplusplus.com/reference/cstdlib/rand/
	* http://www.cplusplus.com/reference/cmath/trunc/
	* http://www.cplusplus.com/reference/string/string/substr/
	* https://en.cppreference.com/w/cpp/language/types
	* http://www.cplusplus.com/reference/iomanip/setprecision/
	* https://stackoverflow.com/questions/16605967/set-precision-of-stdto-string-when-converting-floating-point-values
 */

// randomizer functions
#include "Random.h"

#include <random>
#include <string>
#include "math/LargeInt.h"

// generates a random integer
int util::rand::randInt(int lBound, int uBound, const bool includeUBound)
{
	int randInt(0); // random intger
	int tempInt(0); // temporary value.

	// If the upper and lower bounds on the same, it returns the lBound
	if (lBound == uBound)
	{
		return lBound;
	}
	// If the lower bound is greater than the upper bound, they are swapped
	else if (lBound > uBound)
	{
		tempInt = lBound;
		lBound = uBound;
		uBound = tempInt;
	}

	// gets the difference between the lower bound and upper bound.
	// it then adds the result to the lower bound so that the offset is relative to it.
	tempInt = (includeUBound) ? (abs(uBound - lBound) + 1) : abs(uBound - lBound);
	
	randInt = std::rand() % tempInt;
	
	// offset based on lower bound.
	randInt += lBound;

	// return random integer.
	return randInt;
}

// returns a random float from float max to float min; not complete
float util::rand::randFloat() { return (float)randDecimal(std::to_string(std::numeric_limits<float>::max()).length()); }

// returns a random float. If a 'true' is used, it is up-to and including the upper bound.
// 1.7E-38 to 1.7E+38
float util::rand::randFloat(unsigned int dPlaces) { return (float)randDecimal(dPlaces); }

// returns a random double
double util::rand::randDouble() { return randDecimal(std::to_string(std::numeric_limits<double>::max()).length()); }

// returns a random double. If 'true' is used for includeUBound, the upper bound is included.
// 1.7E-308 to 1.7E+308
double util::rand::randDouble(unsigned int dPlaces) { return randDecimal(dPlaces); }

// returns a random decimal
double util::rand::randDecimal(unsigned int dPlaces)
{
	// TODO: get a random number between (0,n), then multiply it by 1 over the column number.
	// do it until you get all the values you want

	// minimum six floating points.
	// maximum value (Float): 340282346638528859811704183484516925440.000000
	std::string str = ""; // gets the largeInt as a string
	math::LargeInt lg; // used to help generat the random float

	double dbl(0.0F); // saves and returns the double.

	if (dPlaces == 0) // if there are no decimal places requested, then a 0 is returned.
		return 0;

	// if (dPlaces > digits_max + abs(digits_min)) // if the digits requested go beyond the limit, it's truncated
		// dPlaces = digits_max + abs(digits_min);

	for (int i = 0; i < dPlaces; i++) // generates a number from 0 to 9, and inserts it into the large int.
		lg.lnum.push_back(std::rand() % 10);

	str = lg.toString(); // gets the large int as a string.

	if (str.length() == 0) // if the string is of length 0, then a 0 is returned.
		return 0.0F;

	str.at(std::rand() % (str.length() - 1) + 1) = '.'; // inserts a decimal point
	dbl = std::stof(str); // gets the string as a float

	return dbl;
}

// generates a random double.
double util::rand::randDecimal(double lBound, double uBound, const bool includeUBound)
{
	// saves the amount of decimal places, which is based on how many decimal places the provided numbers have.
	int nPlaces = 0;

	// converts the numbers to strings
	std::string lBoundStr = std::to_string(lBound), uBoundStr = std::to_string(uBound);
	
	// this defaults to 6 digits of double percision, regardless of how many there are for lb and ub.
	// maybe figure out how to change it to be more accurate?

	// finds the decimal place, and counts the amount of digits after it.
	// it is saved for the lower bound and upper bound.
  	int lnPlaces = lBoundStr.substr(lBoundStr.find(".")).length() - 1;
	int unPlaces = uBoundStr.substr(uBoundStr.find(".")).length() - 1;
	
	// gets the highest of the two values
	nPlaces = std::max(lnPlaces, unPlaces);

	return randDecimal(lBound, uBound, nPlaces, includeUBound);

	//// due to the way this is designed, it's weighted towards the lower end of the randomization bounds.

	//// if the values are the same.
	//if (lBound == uBound)
	//	return uBound;

	//// the result of the randomization.
	//double result = 0.0;

	//// L for 'lower', and U for 'upper' (in terms of lower bound and upper bound
	//// the pre decimal seperator values (whole numbers)
	//double prePntL = trunc(lBound), prePntU = trunc(uBound);

	//// the post decimal sperator values (fraction numbers)
	//double postPntL = lBound - prePntL, postPntU = uBound - prePntU;

	//// the maximum number of decimal places.
	//int nPlaces = 0;

	//{
	//	// converts the numbers to strings
	//	std::string lBoundStr = std::to_string(lBound), uBoundStr = std::to_string(uBound);

	//	// finds the decimal place, and counts the amount of digits after it.
	//	// it is saved for the lower bound and upper bound.
	//	int lnPlaces = lBoundStr.substr(lBoundStr.find(".")).length() - 1;
	//	int unPlaces = uBoundStr.substr(uBoundStr.find(".")).length() - 1;

	//	// gets the highest of the two values
	//	nPlaces = std::max(lnPlaces, unPlaces);
	//}

	//// basically it multiplies both numbers by some multiple of 10 in order to move all decimal values to the left.
	//// a regular rand() operation is done to generate a random value from this result.
	//// after that, it divides the result by the number of number places shifted over so that it's back within the bounds.
	//// as such, the amount of decimal places is limited to the amount for the provided numbers.

	//// randomization
	//{
	//	// the multiple of 10 being applied.
	//	int tenMult = pow(10, nPlaces);

	//	// the lower bound and upper bound multiplied by the ten multiple.
	//	int lbX = lBound * tenMult;
	//	int ubX = uBound * tenMult;

	//	// makes them whole numbers and generates a random value.
	//	result = randInt(lbX, ubX, includeUBound);

	//	// puts back within the bounds of the decimal numbers.
	//	result /= tenMult;
	//}

	//// returns the result.
	//return result;
}

// rand decimal with varying decimal places
double util::rand::randDecimal(double lBound, double uBound, const unsigned int nPlaces, bool const includeUBound)
{
	// due to the way this is designed, it's weighted towards the lower end of the randomization bounds.

		// if the values are the same.
	if (lBound == uBound)
		return uBound;

	// the result of the randomization.
	double result = 0.0;

	// L for 'lower', and U for 'upper' (in terms of lower bound and upper bound
	// the pre decimal seperator values (whole numbers)
	double prePntL = trunc(lBound), prePntU = trunc(uBound);

	// the post decimal sperator values (fraction numbers)
	double postPntL = lBound - prePntL, postPntU = uBound - prePntU;

	// basically it multiplies both numbers by some multiple of 10 in order to move all decimal values to the left.
	// a regular rand() operation is done to generate a random value from this result.
	// after that, it divides the result by the number of number places shifted over so that it's back within the bounds.
	// as such, the amount of decimal places is limited to the amount for the provided numbers.

	// randomization
	{
		// the multiple of 10 being applied.
		int tenMult = pow(10, nPlaces);

		// the lower bound and upper bound multiplied by the ten multiple.
		int lbX = lBound * tenMult;
		int ubX = uBound * tenMult;

		// makes them whole numbers and generates a random value.
		result = randInt(lbX, ubX, includeUBound);

		// puts back within the bounds of the decimal numbers.
		result /= tenMult;
	}

	// returns the result.
	return result;
}


// Returns a random ASCII char
char util::rand::randAsciiChar() { return (char)(std::rand() % 256); }
