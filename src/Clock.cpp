/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Clock
*/

#include "Clock.hpp"
#include "Gates.hpp"

using namespace nts;

Clock::Clock(const std::string &name, nts::Tristate state) :
Input(name, state)
{}

void Clock::resetExecution(void)
{
	for (auto it = _PinLink.begin(); it != _PinLink.end(); it++)
		it->second.resetExecution();
	if (this->_Value == nts::Tristate::UNDEFINED)
		return;
	_Value = Gates::Not(_Value);
}

Clock::~Clock()
{}