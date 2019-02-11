/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Input
*/
/**
* \file
* \brief File With all the method for the Input class
*/

#include "Input.hpp"

using namespace nts;

/**
* \brief Constructor of the Input Class
* \param[in] std::string name is the name of the compenent
* \return Input
*/
Input::Input(const std::string &name) :
nts::AComponent(name),
_Value(nts::Tristate::UNDEFINED)
{}

/**
* \brief get the state of the pin in function of the input pin corresponding
* \param[in] std::size_t pin the pin of the Component that we want the state
* \return nts::Tristate State of the pin
*/
nts::Tristate Input::compute(size_t pin)
{
    (void)pin;
    return _Value;
}

/**
* \brief Set the default state of the Component
* \param[in] State to Save
*/
void Input::setInputValue(nts::Tristate value) noexcept
{
    _Value = value;
}

Input::~Input()
{}
