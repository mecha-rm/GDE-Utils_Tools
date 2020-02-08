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
const matter util::Element::getStateOfMatter() const { return mtr; }

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
	case unknown:
	default:
		return "unknown";
		break;
	}
}

// gets the category of the metal type of the element.
const metalCat util::Element::getMetalCategory() const { return mtlCat; }

// gets the category of the metal type of the elment as a string.
const std::string util::Element::getMetalCategoryAsString() const
{
	switch (mtlCat)
	{
	case metal:
		return "metal";
		break;
	case metalloid:
		return "metalloid";
		break;
	case nonmetal:
	default:
		return "nonmetal";
		break;
	}
}

// gets the type of the metal type of the element.
const metalType util::Element::getMetalType() const { return mtlType; }

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

	case metalloid:
		return "Metalloid";
		break;

	case reactiveNonMtl:
		return "Reactive Nonmetal";
		break;

	case nobleGas:
		return "Nobel Gas";
		break;

	case unknown:
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

const util::Element util::PeriodicTable::getElementByAtomicNumber(unsigned short int atomicNum) const
{
	switch (atomicNum)
	{
	case 1:
		return Element(1, "H", "Hydrogen", 1.00794F, matter::gas, metalCat::nonmetal, metalType::reactiveNonMtl);
		break;
	case 2:
		return Element(2, "He", "Helium", 4.002602F, matter::gas, metalCat::nonmetal, metalType::nobleGas);
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
		
	case 0:
	default:
		std::cout << "Failure" << std::endl;
		return Element(0, "~", "None", 0.0F, matter::unknown, metalCat::nonmetal, metalType::unknown);
		break;
	}

	
}
