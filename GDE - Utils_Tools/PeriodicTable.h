// source for the periodic table
#ifndef PERIODIC_TABLE
#define PERIODIC_TABLE

#include <iostream>
#include <string>

enum matter { unknown, solid, liquid, gas };
enum metalCat {metal, metalloid, nonmetal};
enum metalType {alkali, akalineEarth, lanthanide, actinide, transitionMtl, postTransitionMtl, metalloid, reactiveNonMtl, nobleGas, unknown};

namespace util
{
	class Element
	{
	public:
		Element(unsigned short int atomicNum, std::string symbol, std::string name, float atomicMass, matter mtr, metalCat mtlCat, metalType mtlType);

		// get atomic number
		const short int getAtomicNumber() const;

		// gets the atomic symbol
		const std::string getSymbol() const;

		// gets the element's name
		const std::string getName() const;

		// gets the atomic mass
		const float getAtomicMass() const;

		// gets the state of matter for the element
		const matter getStateOfMatter() const;

		// gets the state of matter for the element as a string
		const std::string getStateOfMatterAsString() const;

		// gets the category of the metal type of the element.
		const metalCat getMetalCategory() const;

		// gets the category of the metal type of the elment as a string.
		const std::string getMetalCategoryAsString() const;

		// gets the type of the metal type of the element.
		const metalType getMetalType() const;

		// gets the type of the metal type of the elment as a string.
		const std::string getMetalTypeAsString() const;

		// gets the element info as a string
		std::string toString() const;

	private:
		const short int atomicNum;
		const std::string symbol;
		const std::string name;
		const float atomicMass;

		const matter mtr;
		const metalCat mtlCat;
		const metalType mtlType;
	protected:

	};

	static class PeriodicTable
	{
		const Element getElementByAtomicNumber(unsigned short int atomicNum) const;

		Element getElementBySymbol();

		Element getElementByName();
	};
};

#endif // !PERIODIC_TABLE