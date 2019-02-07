/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(const std::string &name) :
nts::AComponent(name),
_Value(nts::Tristate::UNDEFINED)
{}

nts::Tristate Input::compute(size_t pin)
{
    (void)pin;
    return _Value;
}

void Input::setInputValue(nts::Tristate value) noexcept
{
    _Value = value;
}

Input::~Input()
{}
