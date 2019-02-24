/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** AComponent
*/
/**
* \file
* \brief File with all the method of the Circuit class
*/

#include "AComponent.hpp"

/**
* \brief Constructor of the AComponent Class
* \param[in] std::string name is the name of the compenent
* \param[in] std::size_t pins is the nb of pin of the Component
* \return AComponent
*/
nts::AComponent::AComponent(const std::string &name, std::size_t pins) :
_Name(name),
_NbPin(pins)
{}

/**
* \brief Connect the Component to an other 
* \param[in] the pin that will be connected to the other component 
* \param[in] the other Component 
* \param[in] the pin of the other Component
*/
void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	if (pin < 1 || pin > _NbPin)
		throw nts::LinkError("Invalid pin..", "nts::AComponent::setLink"); // Invalid Pin
	if (otherPin < 1)
		throw nts::LinkError("Invalid other pin..", "nts::AComponent::setLink");
	pin -= 1;
	if (_PinLink[pin])
		throw nts::LinkError("Pin already set..", "nts::AComponent::setLink");
	_PinLink[pin] = PinLink(&other, otherPin);
}

/**
* \brief Method To display the Name of the Component
*/
void nts::AComponent::dump(void) const
{
	std::cout << _Name << std::endl;
}

/**
* \brief reset Execution variable of link
*/
void nts::AComponent::resetExecution(void)
{
	for (auto it = _PinLink.begin(); it != _PinLink.end(); it++)
		it->second.resetExecution();
}

/**
* \brief Deconstructor for the AComponent class
*/
nts::AComponent::~AComponent()
{
	_PinLink.clear();
}
