/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4001
*/
/*
* \file
* \brief File with all the method of the Circuit class
*/

#include "Chipset4001.hpp"
#include "Gates.hpp"

using namespace nts;

/**
* \brief Constructor of the Chipset4001 Class
* \param[in] std::string name is the name of the compenent
* \return Chipset4001
*/
Chipset4001::Chipset4001(const std::string &name) :
nts::AComponent(name, Chipset4001::_numberOfPin)
{}

/**
* \brief make the operation of the Chipset (NOR)
* \param[in] input1
* \param[in] input2
* \return Return the State of of the operation
*/
nts::Tristate Chipset4001::operation(std::size_t pin1, std::size_t pin2)
{
	if (!_PinLink[pin1])
		throw std::exception(); // Not Linked Pin1
	if (!_PinLink[pin2])
		throw std::exception(); // Not Linked Pin2
	return nts::Gates::Nor(_PinLink[pin1](), _PinLink[pin2]());
}

/**
* \brief Return the State of the Chipset at a specific pin
* \param[in] pin of the Output
* \return Return the State of the Pin
*/
nts::Tristate Chipset4001::compute(std::size_t pin)
{
	switch (pin) {
		case 3:     return operation(pin - 3, pin - 2);
		case 4:     return operation(pin, pin + 1);
		case 10:    return operation(pin - 3, pin - 2);
		case 11:    return operation(pin, pin + 1);    
		default:	throw std::exception(); // Invalid Pin ask
	}
}

/**
* \brief Deconstructor for the AComponent class
*/
Chipset4001::~Chipset4001()
{}
