#pragma once

namespace util
{
	namespace rand
	{
		// Mathematic Utilities
		// http://www.cplusplus.com/reference/random/
		// http://www.cplusplus.com/reference/limits/numeric_limits/
		// Returns a random number starting form 'lbound' upto ubound.
		// If 'includeUbound' is set to 'true', it's upto and including ubound; if false, it's upto but not including ubound. False by default.
		int randInt(int lBound, int uBound, const bool includeUBound = false);

		// Returns a random float from 1.7E-308 to 1.7E+308
		float randFloat();

		// returns a random float. If a 'true' is used, it is up-to and including the upper bound. Not complete.
		// 1.7E-38 to 1.7E+38
		// float randFloat(unsigned int dPlaces, float lBound, float uBound, bool includeUBound = false);
		float randFloat(unsigned int dPlaces);

		// returns a random double
		double randDouble();

		// returns a random double. If 'true' is used for includeUBound, the upper bound is included. Not complete.
		// 1.7E-308 to 1.7E+308
		double randDouble(unsigned int dPlaces);

		// generates a random decimal number
		double randDecimal(unsigned int dPlaces);

		// generates a random decimal number from the lowerbound to the upperbound
		// if true, includeUBound is included.
		double randDecimal(double lBound, double uBound, bool const includeUBound = false);

		// generates a random decimal with a lower bound, upper bound, and an amount of decimal places.
		double randDecimal(double lBound, double uBound, const unsigned int nPlaces, bool const includeUBound = false);

		// returns a random ASCII character. This can return 256 characters, which includes character '0', which is 'NULL'.
		char randAsciiChar();
	}
}