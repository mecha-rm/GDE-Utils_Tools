/*
 * Date: 05/03/2020
 * Description:
 * References:
	* https://pubchem.ncbi.nlm.nih.gov/periodic-table/
	* https://en.wikipedia.org/wiki/Periodic_table
*/

// source for the periodic table
#ifndef PERIODIC_TABLE
#define PERIODIC_TABLE

#include <iostream>
#include <string>

namespace util
{
	enum matter { unknownMR, solid, liquid, gas };
	enum metalCat { metal, metalloidMC, nonmetal };
	enum metalType { alkali, akalineEarth, lanthanide, actinide, transitionMtl, postTransitionMtl, metalloidMT, reactiveNonMtl, nobleGas, unknownMT };

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

	// the periodic table class.
	// TODO: make a singleton?
	class PeriodicTable
	{
	public:
		// gets an instance for the periodic table.
		static PeriodicTable& GetInstance();

		// returns an element based on its atomic number.
		const Element& getElementByAtomicNumber(unsigned short int atomicNum) const;

		// gets an element based on its symbol.
		const Element& getElementBySymbol(const std::string symbol);

		// gets an element based on its name.
		const Element& getElementByName(const std::string name);

	private:
		// constuctor
		PeriodicTable();

		// element count
		const int ELEMENT_COUNT = 118;

		// element array
		Element * elements[118];

		// element used when there is no element selected.
		util::Element* nullElement;

	protected:

	};
};

#endif // !PERIODIC_TABLE