/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** AComponent
*/

#include "AComponent.hpp"

nts::AComponent::AComponent(const std::string &name, std::size_t pins) :
_Name(name),
_NbPin(pins)
{}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > _NbPin)
        throw std::exception(); // Invalid Pin
    if (otherPin < 1)
        throw std::exception(); // Invalid other Pin
    pin -= 1;
    if (_PinLink[pin])
        throw std::exception(); // Already ask Pin
    _PinLink[pin] = [&other, otherPin](void)->nts::Tristate {
        return other.compute(otherPin);
    };
}

void nts::AComponent::dump(void) const
{
    std::cout << _Name << std::endl;
}

nts::AComponent::~AComponent()
{
    _PinLink.clear();
}
