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

nts::Tristate PinLink::operator()(void)
{
	if (_Execute)
		return _State;
	_Execute = true;
	if (!_Component)
		_State = nts::Tristate::UNDEFINED;
	else
		_State = _Component->compute(_Pin);
	return _State;
}

void PinLink::resetExecution(void)
{
	_Execute = false;
}

PinLink::operator bool(void) const
{
	return (_Component);
}
