/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4040
*/
/*
* \file
* \brief File with all the method of the Circuit class
*/

#include "Chipset4040.hpp"
#include "Gates.hpp"

using namespace nts;

/**
* \brief Constructor of the Chipset4040 Class
* \param[in] std::string name is the name of the compenent
* \return Chipset4040
*/
Chipset4040::Chipset4040(const std::string &name) :
nts::AComponent(name, Chipset4040::_numberOfPin),
_Count(0),
_ClockPrevious(nts::Tristate::UNDEFINED)
{}


/**
* \brief Return the State of the Chipset at a specific pin
* \param[in] pin of the Output
* \return Return the State of the Pin
*/
nts::Tristate Chipset4040::compute(std::size_t pin)
{
	if (_PinLink[_ResetPin]() == nts::Tristate::TRUE) {
		_Count = 0; 
		return nts::Tristate::FALSE;
	}
	if (_PinLink[_ClockPin]() != _ClockPrevious) {
		_Count += 1;
		if (_Count == 17)
			_Count = 1;
	}
	switch (pin) {
		case 1:     return ((_Count & 1) == 1) ? nts::Tristate::TRUE : nts::Tristate::FALSE;
		case 2:     return ((_Count & 2) == 2) ? nts::Tristate::TRUE : nts::Tristate::FALSE;
		case 13:    return ((_Count & 4) == 4) ? nts::Tristate::TRUE : nts::Tristate::FALSE;
		case 12:    return ((_Count & 8) == 8) ? nts::Tristate::TRUE : nts::Tristate::FALSE;
		default:	throw nts::PinError("4040"); // Invalid Pin ask
	}

}

/**
* \brief Deconstructor for the AComponent class
*/
Chipset4040::~Chipset4040()
{}
