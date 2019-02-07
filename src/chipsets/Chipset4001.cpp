/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4001
*/

#include "Chipset4001.hpp"
#include "Gates.hpp"

Chipset4001::Chipset4001(const std::string &name) :
nts::AComponent(name, Chipset4001::_numberOfPin)
{}

nts::Tristate Chipset4001::operation(std::size_t pin1, std::size_t pin2)
{
	if (!_PinLink[pin1])
		throw std::exception(); // Not Linked Pin1
	if (!_PinLink[pin2])
		throw std::exception(); // Not Linked Pin2
	return nts::Gates::Nor(_PinLink[pin1](), _PinLink[pin2]());
}

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

Chipset4001::~Chipset4001()
{
}
