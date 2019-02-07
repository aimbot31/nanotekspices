/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Circuit
*/

#include <algorithm>
#include "Circuit.hpp"

Circuit::Circuit(const std::string &name) :
nts::AComponent(name)
{}

void Circuit::dump(void) const
{
	std::for_each(_Components.cbegin(), _Components.cend(),
	[](const std::map<std::string, std::unique_ptr<nts::IComponent>>::value_type &elem)->void  {
		elem.second->dump();
	});
}

void Circuit::addComponent(std::unique_ptr<nts::IComponent> &NewComponent, ComponentType type)
{
	if (!NewComponent)
		throw std::exception(); // can't add empty component
	if (_Components[NewComponent->getName()])
		throw std::exception(); // already have this name for component
	this->addPin(NewComponent.get(), type);
	_Components[NewComponent->getName()] = std::move(NewComponent);
}

void Circuit::addPin(nts::IComponent *NewOutput, ComponentType type) noexcept
{
	if (type == Circuit::ComponentType::INTERN)
		return;
	if (type == Circuit::ComponentType::OUTPUT) {
		this->setLink(_NbPin, *NewOutput, 1);
	}
	_NbPin += 1;
}

nts::Tristate Circuit::compute(std::size_t pin)
{
	if (pin < 1 || pin > _NbPin)
		throw std::exception(); // Invalid Pin
	pin -= 1;
	if (!_PinLink[pin])
		throw std::exception(); // Pin not linked
	return _PinLink[pin]();
}

Circuit::~Circuit()
{}
