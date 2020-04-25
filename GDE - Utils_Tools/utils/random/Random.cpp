// randomizer functions
#include "Random.h"

#include <random>
#include <string>
#include "..\math\LargeInt.h"

// generates a random integer
int util::rand::randInt(int lBound, int uBound, bool includeUBound)
{
	int tempInt(0);
	int randInt(0);
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

	// If the upperbound is positive, the values can be used as is.
	// If the upperbound and lowerbound are both negative, then a randomizer is run to get their absoluted range, then another randomizer is run to make it positive or negative.

	randInt = (uBound > 0) ? std::rand() % (uBound - lBound + includeUBound) + lBound : (abs(uBound) - abs(lBound) + includeUBound) + abs(lBound);

	// If the number must be negative, it is multiplied by -1 to make it so.
	if (lBound < 0 && uBound < 0)
		randInt *= -1;
	// randInt = rand() % (uBound - lBound + includeUBound) + lBound;

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

// Returns a random ASCII char
char util::rand::randAsciiChar() { return (char)(std::rand() % 256); }
