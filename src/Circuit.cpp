/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Circuit
*/
/**
* \file
* \brief File with all the method of the Circuit class
*/

#include <algorithm>
#include "Circuit.hpp"

using namespace nts;

/**
* \brief Constructor of the Circuit Class
* \param[in] std::string name is the name of the compenent
* \return Circuit
*/
Circuit::Circuit(const std::string &name) :
nts::AComponent(name)
{}

/**
* \brief static function to call all the dump method of Component
* \param[in] std::map<std::string, std::unique_ptr<nts::IComponent>> &elem 
*/
void Circuit::dumpFromMap(const std::map<std::string, std::unique_ptr<nts::IComponent>>::value_type &elem)
{
	elem.second->dump();
}

/**
* \brief Method To display all the Component in the Circuit
*/
void Circuit::dump(void) const
{
	std::for_each(_Components.cbegin(), _Components.cend(), this->dumpFromMap);
}

/**
* \brief Method To Add a Component to the Circuit, in function of his type
* \param[in] NewComponent
* \param[in] type
*/
void Circuit::addComponent(std::unique_ptr<nts::IComponent> &NewComponent, ComponentType type)
{
	if (!NewComponent)
		throw std::exception(); // can't add empty component
	if (_Components[NewComponent->getName()])
		throw std::exception(); // already have this name for component
	this->addPin(NewComponent.get(), type);
	_Components[NewComponent->getName()] = std::move(NewComponent);
}

/**
* \brief Method To Add a Link to the Circuit, in function of his type
* \param[in] NewOuput
* \param[in] type
*/
void Circuit::addPin(nts::IComponent *NewOutput, ComponentType type) noexcept
{
	if (type == Circuit::ComponentType::INTERN || !NewOutput)
		return;
	if (type == Circuit::ComponentType::OUTPUT) {
		this->setLink(_NbPin, *NewOutput, 1);
	}
	_NbPin += 1;
}

/**
* \brief get the state of the pin in function of the input pin corresponding
* \param[in] std::size_t pin the pin of the Component that we want the state
* \return nts::Tristate State of the pin
*/
nts::Tristate Circuit::compute(std::size_t pin)
{
	if (pin < 1 || pin > _NbPin)
		throw std::exception(); // Invalid Pin
	pin -= 1;
	if (!_PinLink[pin])
		throw std::exception(); // Pin not linked
	return _PinLink[pin]();
}

/**
* \brief Deconstructor for the Circuit class
*/
Circuit::~Circuit()
{}
