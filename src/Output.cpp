/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Output
*/
/**
* \file
* \brief File With all the method for the Ouput class
*/

#include "Output.hpp"

using namespace nts;

/**
* \brief Constructor of the Output Class
* \param[in] std::string name is the name of the compenent
* \return Output
*/
Output::Output(const std::string &name) :
nts::AComponent(name)
{}

/**
* \brief get the state of the pin in function of the input pin corresponding
* \param[in] std::size_t pin the pin of the Component that we want the state
* \return nts::Tristate State of the pin
*/
nts::Tristate Output::compute(std::size_t pin)
{
	if (pin < 1 || pin > _NbPin)
		throw std::exception(); // Invalid Pin
	pin--;
	if (!_PinLink[pin])
		throw std::exception();// Link Not Set
	nts::Tristate rValue = _PinLink[pin]();
	return rValue;
}

/**
* \brief Deconstructor for the Output class
*/
Output::~Output()
{}
