#include "Utils.h"
#include "math/LargeInt.h"
#include "math/Quaternion.h"

#include <cmath>
#include <math.h>
#include <sstream>
#include <fstream>
#include <stack>

/// STRING AND GENERAL FUNCTIONS //////////////////////////////////////////////////////
std::string util::toLower(std::string str)
{
	// returns the string if its of length zero.
	if (str.length() == 0)
		return str;

	std::string strL; // temporary string
	strL.assign(str); // copies original string

	for (int i = 0; i < strL.length(); i++)
	{
		strL.at(i) = tolower(strL.at(i)); // converts each 'char' to its lowercase version if applicable
	}

	return strL;
}

// converts a whole string to uppercase
std::string util::toUpper(std::string str)
{
	// returns the string if its of length zero.
	if (str.length() == 0)
		return str;

	std::string strL; // temporary string
	strL.assign(str); // copies original string

	for (int i = 0; i < strL.length(); i++)
	{
		strL.at(i) = toupper(strL.at(i)); // converts each 'char' to its uppercase version if applicable
	}

	return strL;
}

// capitalizes a string.
std::string util::captialize(std::string str)
{
	// returns the string if its of length zero.
	if (str.length() == 0)
		return str;

	std::string strL; // temporary string
	strL.assign(str); // copies original string

	str = toLower(str); // makes the string all lowercase
	str.at(0) = toupper(str.at(0)); // capitalizes the first letter

	return strL;
}

// checks if two strings are equal, ignoring case diffrences.
bool util::equalsIgnoreCase(std::string str1, std::string str2)
{
	// making both strings lowercase
	str1 = toLower(str1);
	str2 = toLower(str2);
	return str1 == str2; // returning whether the two are equal
}

// replaces every instance of a set of characters in a string with another set of characters.
std::string util::replaceSubstring(std::string str, std::string oldSubstr, std::string newSubstr, bool ignoreCase)
{
	unsigned int index; // the index of the most recently found oldSubstr

	// first set is if ignoreCase is false, second set is if ignoreCase is true.
	while ((ignoreCase == false && str.find(oldSubstr) != std::string::npos) || 
		   (ignoreCase == true && util::toLower(str).find(util::toLower(oldSubstr)) != std::string::npos))
	{
		// checks if case sensitivity was requested.
		index = (ignoreCase) ? index = util::toLower(str).find(util::toLower(oldSubstr)) : index = str.find(oldSubstr);

		str.replace(index, oldSubstr.length(), newSubstr); // replaces the old string with the new string.
	}

	return str;
}

// checks if a string is an integer.
bool util::isInt(std::string str)
{
	int strInt; // gets the string as an int.
	std::stringstream ss(str); // creates a string stream for converting the string to an integer.

	ss >> strInt; // puts the string stream into the integer. If non-int values exist, then the int is truncated.

	return std::to_string(strInt) == str; // returns 'true' if all values were carried over from the string.
}

// checks if a string is a decimal number (specifically a double).
bool util::isDecimal(std::string str)
{
	double strDbl; // gets the string as an float
	std::stringstream ss(str); // creates a string stream for converting the string to an integer.

	ss >> strDbl; // puts the string stream into the double. If non-int values exist, then the doubleis truncated.

	return std::to_string(strDbl) == str; // returns 'true' if all values were carried over from the string.
}

// checks to see if a string is a number. IsInt or IsDecimal should be used instead.
bool util::isNum(std::string str)
{
	std::string arr[10] = { "1","2","3","4","5","6","7","8","9","0" };

	// Checks each index of the stirng, checking if it's a whole, numeric value.
	for (int x = 0; x < str.length(); x++) {
		for (int y = 0; y < 10; y++) {
			if (str.substr(x, 1) == arr[y]) {
				break;
			}
			else if (y == 9) {
				return false;
			}
		}
	}
	return true;
}

// fills in zeros for integers converted to strings.
std::string util::zeroFill(int num, const unsigned int LENGTH)
{
	// empty string
	if (LENGTH == 0)
		return std::string("");

	// converts the number to a string.
	std::string numString = std::to_string(num);

	// temporary string to get the zero fill value.
	std::string temp = "";

	// the string's requested length is less than that of the number's itself.
	if (LENGTH < numString.length())
	{
		temp = numString.substr(numString.length() - LENGTH);
	}
	else
	{
		temp = numString;

		// filling with zeroes.
		while (temp.size() < LENGTH)
			temp = "0" + temp;
	}

	return temp;
}

// returns 'true' if the file can be opened and read from.
bool util::fileAccessible(const std::string& filePath)
{
	std::ifstream file(filePath, std::ios::in); // the file
	bool found;

	// if !file is true, then the file couldn't be opened. If it is false, then the file can be accessed.
	found = !file;
	file.close();

	// returns the opposite as 'found' since it's showing if the file does exist.
	return !found;
}
