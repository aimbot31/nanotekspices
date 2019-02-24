/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Exceptions
*/

#include "exceptions/Exceptions.hpp"

nts::NtsError::NtsError(const std::string &msg, const std::string &component) : _msg(component), _component(msg)
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

nts::ComponentError::ComponentError(const std::string &msg, const std::string &component)
{
	_msg = "Component error : " + msg;
	_component = component;
}

nts::PinError::PinError(const std::string &msg, const std::string &component)
{
	_msg = "Pin error : " + msg;
	_component = component;
}

nts::LinkError::LinkError(const std::string &msg, const std::string &component)
{
	_msg = "Link error : " + msg;
	_component = component;
}

nts::FileError::FileError(const std::string &msg, const std::string &component)
{
	_msg = "File error : " + msg;
	_component = component;
}