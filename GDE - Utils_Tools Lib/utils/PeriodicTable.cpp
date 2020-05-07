/*
 * Date: 05/03/2020
 * Description:
 * References:
	* https://pubchem.ncbi.nlm.nih.gov/periodic-table/
	* https://en.wikipedia.org/wiki/Periodic_table
*/

#include "PeriodicTable.h"

// constructor
util::Element::Element(unsigned short int atomicNum, std::string symbol, std::string name, float atomicMass, matter mtr, metalCat mtlCat, metalType mtlType)
	: atomicNum(atomicNum), symbol(symbol), name(name), atomicMass(atomicMass), mtr(mtr), mtlCat(mtlCat), mtlType(mtlType)
{}

// gets the atomic number of the element
const short int util::Element::getAtomicNumber() const { return atomicNum; }

// returns the atomic symbol
const std::string util::Element::getSymbol() const { return symbol; }

// gets the name of the element
const std::string util::Element::getName() const { return name; }

// gets the atomic mass
const float util::Element::getAtomicMass() const { return atomicMass; }

// gets the state of matter
const util::matter util::Element::getStateOfMatter() const { return mtr; }

// gets the state of matter for the element as a string
const std::string util::Element::getStateOfMatterAsString() const
{
	switch (mtr)
	{
	case solid:
		return "solid";
		break;
	case liquid:
		return "liquid";
		break;

	case gas:
		return "gas";
		break;
	case unknownMR:
	default:
		return "unknown";
		break;
	}
}

// gets the category of the metal type of the element.
const util::metalCat util::Element::getMetalCategory() const { return mtlCat; }

// gets the category of the metal type of the elment as a string.
const std::string util::Element::getMetalCategoryAsString() const
{
	switch (mtlCat)
	{
	case metal:
		return "metal";
		break;
	case metalloidMC:
		return "metalloid";
		break;
	case nonmetal:
	default:
		return "nonmetal";
		break;
	}
}

// gets the type of the metal type of the element.
const util::metalType util::Element::getMetalType() const { return mtlType; }

const std::string util::Element::getMetalTypeAsString() const
{
	// returns the metal type
	switch (mtlType)
	{
	case alkali:
		return "Alkali Metal";
		break;

	case akalineEarth:
		return "Alkaline Earth Metal";
		break;

	case lanthanide:
		return "Lanthanide";
		break;

	case actinide:
		return "Actinide";
		break;

	case transitionMtl:
		return "Transition Metal";
		break;

	case postTransitionMtl:
		return "Post-Transition Metal";
		break;

	case metalloidMT:
		return "Metalloid";
		break;

	case reactiveNonMtl:
		return "Reactive Nonmetal";
		break;

	case nobleGas:
		return "Nobel Gas";
		break;

	case unknownMT:
		return "Unknown Chemical Properties";
		break;
	}

	return std::string();
}

// gets the element info as a string
std::string util::Element::toString() const
{
	return "Atomic #: " + std::to_string(atomicNum) + " | Symbol: " + symbol + " | Name: " + name
		+ " | Atomic Mass: " + std::to_string(atomicMass) + " | State of Matter (0 °C): " + getStateOfMatterAsString()
		+ " | Metal Category: " + getMetalCategoryAsString() + " | Metal Type: " + getMetalTypeAsString();
}


// Periodic Table

// constructor
util::PeriodicTable::PeriodicTable()
{
	// creates the null element.
	nullElement = new util::Element(0, "~", "None", 0.0F, util::matter::unknownMR, util::metalCat::nonmetal, util::metalType::unknownMT);

	elements[0] = new Element(1, "H", "Hydrogen", 1.00794F, matter::gas, metalCat::nonmetal, metalType::reactiveNonMtl);
	elements[1] = new Element(2, "He", "Helium", 4.002602F, matter::gas, metalCat::nonmetal, metalType::nobleGas);
	elements[2] = new Element(3, "Li", "Lithium", 6.94F, matter::solid, metalCat::metal, metalType::alkali);
	
	// elements[1] = new Element(2, "He", "Helium", 4.002602F, matter::gas, metalCat::nonmetal, metalType::nobleGas);
	// elements[1] = new Element(2, "He", "Helium", 4.002602F, matter::gas, metalCat::nonmetal, metalType::nobleGas);
	// elements[1] = new Element(2, "He", "Helium", 4.002602F, matter::gas, metalCat::nonmetal, metalType::nobleGas);
	// elements[1] = new Element(2, "He", "Helium", 4.002602F, matter::gas, metalCat::nonmetal, metalType::nobleGas);
	// elements[1] = new Element(2, "He", "Helium", 4.002602F, matter::gas, metalCat::nonmetal, metalType::nobleGas);
	// elements[1] = new Element(2, "He", "Helium", 4.002602F, matter::gas, metalCat::nonmetal, metalType::nobleGas);
	// elements[1] = new Element(2, "He", "Helium", 4.002602F, matter::gas, metalCat::nonmetal, metalType::nobleGas);

}

// gets an instance of the perioic table.
util::PeriodicTable& util::PeriodicTable::GetInstance()
{
	// returns the periodic table.
	static PeriodicTable* singleton = new PeriodicTable();
	return *singleton;
}

// gets an element based on the provided atomic number.
const util::Element& util::PeriodicTable::getElementByAtomicNumber(unsigned short int atomicNum) const
{
	// number is valid
	if (atomicNum <= ELEMENT_COUNT)
	{
		return *elements[atomicNum - 1];
	}
	else // number is not valid
	{
		throw std::runtime_error("Atomic number is not valid");
		return *nullElement;
	}

}

// finds and returns an element based on the provided symbol.
const util::Element& util::PeriodicTable::getElementBySymbol(const std::string symbol)
{
	// cycles through all elements
	for (int i = 0; i < ELEMENT_COUNT; i++)
	{
		if (elements[i]->getSymbol() == symbol)
			return *elements[i];
	}
	
	// symbol not found.
	throw std::runtime_error("Symbol name is not valid");
	return *nullElement;
}

// returns the element by its name.
const util::Element& util::PeriodicTable::getElementByName(const std::string name)
{
	// cycles through all elements
	for (int i = 0; i < ELEMENT_COUNT; i++)
	{
		if (elements[i]->getName() == name)
			return *elements[i];
	}

	// symbol not found.
	throw std::runtime_error("Element name is not valid");
	return *nullElement;
}
