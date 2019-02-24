/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4069
*/
/*
* \file
* \brief File with all the method of the Circuit class
*/

#include "Chipset4069.hpp"
#include "Gates.hpp"

using namespace nts;

/**
* \brief Constructor of the Chipset4069 Class
* \param[in] std::string name is the name of the compenent
* \return Chipset4069
*/
Chipset4069::Chipset4069(const std::string &name) :
nts::AComponent(name, Chipset4069::_numberOfPin)
{}

/**
* \brief make the operation of the Chipset (Not)
* \param[in] input1
* \return Return the State of of the operation
*/
nts::Tristate Chipset4069::operation(std::size_t pin1)
{
	return nts::Gates::Not(_PinLink[pin1]());
}

/**
* \brief Return the State of the Chipset at a specific pin
* \param[in] pin of the Output
* \return Return the State of the Pin
*/
nts::Tristate Chipset4069::compute(std::size_t pin)
{
	switch (pin) {
		case 2:     return operation(pin - 2);
		case 4:     return operation(pin - 2);
		case 6:     return operation(pin - 2);
		case 8:		return operation(pin);
		case 10:    return operation(pin);
		case 12:    return operation(pin);
		default:	throw nts::PinError("4069"); // Invalid Pin ask
	}
}

/**
* \brief Deconstructor for the AComponent class
*/
Chipset4069::~Chipset4069()
{}
