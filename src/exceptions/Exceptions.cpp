/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Exceptions
*/

#include "exceptions/Exceptions.hpp"

nts::NtsError::NtsError(const std::string &msg, const std::string &component) : _component(component), _msg(msg)
{
}

const std::string &nts::NtsError::getComponent() const 
{
	return (_component);
}

const char* nts::NtsError::what() const throw()
{
	return (_msg.c_str());
}

nts::InputError::InputError(const std::string &msg, const std::string &component)
{
	_msg = "Input error : " + msg;
	_component = component;
}