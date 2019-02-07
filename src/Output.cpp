/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(const std::string &name) :
nts::AComponent(name)
{}

nts::Tristate Output::compute(std::size_t pin)
{
    if (pin < 1 || pin > _NbPin)
        throw std::exception(); // Invalid Pin
    pin--;
    if (!_PinLink[pin])
        throw std::exception();// Link Not Set
    nts::Tristate rValue = _PinLink[pin]();
    std::cout << _Name << "=" << rValue << std::endl;
    return rValue;
}

Output::~Output()
{}
