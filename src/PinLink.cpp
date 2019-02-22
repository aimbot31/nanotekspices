/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** PinLink
*/

#include "PinLink.hpp"

using namespace nts;
/**
* \brief Constructor of the AComponent Class
* \param[in] Component
* \param[in] pinOfComponent to link
* \param[in] myPin to link
* \return PinLink
*/
PinLink::PinLink(nts::IComponent *Component, std::size_t pinOfComponent) :
_Component(Component),
_Pin(pinOfComponent)
{}

PinLink::~PinLink()
{}

nts::Tristate PinLink::operator()(void) const
{
    if (!_Component)
        throw std::exception(); // Unlinked
    return _Component->compute(_Pin);
}

PinLink::operator bool(void) const
{
    return (_Component);
}
