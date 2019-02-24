/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4030
*/
/*
* \file
* \brief File with all the method of the Circuit class
*/

#include "Chipset4030.hpp"
#include "Gates.hpp"

using namespace nts;

/**
* \brief Constructor of the Chipset4030 Class
* \param[in] std::string name is the name of the compenent
* \return Chipset4030
*/
Chipset4030::Chipset4030(const std::string &name) :
nts::AComponent(name, Chipset4030::_numberOfPin)
{}

/**
* \brief make the operation of the Chipset (NOR)
* \param[in] input1
* \param[in] input2
* \return Return the State of of the operation
*/
nts::Tristate Chipset4030::operation(std::size_t pin1, std::size_t pin2)
{
	return nts::Gates::Xor(_PinLink[pin1](), _PinLink[pin2]());
}

/**
* \brief Return the State of the Chipset at a specific pin
* \param[in] pin of the Output
* \return Return the State of the Pin
*/
nts::Tristate Chipset4030::compute(std::size_t pin)
{
	switch (pin) {
		case 3:     return operation(pin - 3, pin - 2);
		case 4:     return operation(pin, pin + 1);
		case 10:    return operation(pin - 3, pin - 2);
		case 11:    return operation(pin, pin + 1);    
		default:	throw nts::PinError("4030"); // Invalid Pin ask
	}
}

/**
* \brief Deconstructor for the AComponent class
*/
Chipset4030::~Chipset4030()
{}
