/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4013
*/
/*
* \file
* \brief File with all the method of the Circuit class
*/

#include "Chipset4013.hpp"
#include "Gates.hpp"

using namespace nts;

/**
* \brief Constructor of the Chipset4013 Class
* \param[in] std::string name is the name of the compenent
* \return Chipset4013
*/
Chipset4013::Chipset4013(const std::string &name) :
nts::AComponent(name, Chipset4013::_numberOfPin),
_Gate1(nts::Tristate::UNDEFINED),
_Gate2(nts::Tristate::UNDEFINED),
_ClockPrevious1(nts::Tristate::UNDEFINED),
_ClockPrevious2(nts::Tristate::UNDEFINED)
{}

nts::Tristate Chipset4013::operation1(void)
{
	if (_PinLink[_ResetPin1]() == nts::Tristate::TRUE) {
		_Gate1 = nts::Tristate::FALSE;
		return nts::Tristate::FALSE;
	}
	nts::Tristate res = _Gate1;
	if (_PinLink[_ClockPin1]() != _ClockPrevious1) {
		_ClockPrevious1 = _PinLink[_ClockPin1]();
		_Gate2 = (_PinLink[_SetPin2]());
	}
	return res;
}

nts::Tristate Chipset4013::operation2(void)
{
	if (_PinLink[_ResetPin2]() == nts::Tristate::TRUE) {
		_Gate2 = nts::Tristate::FALSE;
		return nts::Tristate::FALSE;
	}
	nts::Tristate res = _Gate2;
	if (_PinLink[_ClockPin2]() != _ClockPrevious2) {
		_ClockPrevious2 = _PinLink[_ClockPin2]();
		_Gate2 = (_PinLink[_SetPin2]());
	}
	return res;
}

/**
* \brief Return the State of the Chipset at a specific pin
* \param[in] pin of the Output
* \return Return the State of the Pin
*/
nts::Tristate Chipset4013::compute(std::size_t pin)
{
	switch (pin) {
		case 1:     return operation1();
		case 2:     return nts::Gates::Not(operation1());
		case 13:    return operation2();
		case 12:    return nts::Gates::Not(operation2());
		default:	throw nts::PinError("4013"); // Invalid Pin ask
	}
}

/**
* \brief Deconstructor for the AComponent class
*/
Chipset4013::~Chipset4013()
{}
