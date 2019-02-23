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
#include "Parser.hpp"

using namespace nts;

/**
* \brief Constructor of the Circuit Class
* \param[in] std::string name is the name of the compenent
* \return Circuit
*/
Circuit::Circuit(int ac, char **av, const std::string &name) :
Traitement(Parser(ac, av).getArgs()),
nts::AComponent(name)
{
	this->computeAll();
	this->displayAll();
}

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

void Circuit::dumpAll(void)
{
	std::for_each(_Components.cbegin(), _Components.cend(), this->dumpFromMap);
}

void Circuit::setInputValue(std::string &name, nts::Tristate value)
{
	for (auto component : _type) {
		if (component.second == "input")
			if (component.first == name)
				static_cast<Input &>(*_Components[component.first]).setInputValue(value);
	}
}

/**
* \brief Compute All output Pin
*/
void Circuit::computeAll(void)
{
	this->resetExecution();
	for (auto it = _Components.begin(); it != _Components.end(); it++) {
		if (_type.at(it->first) == "output") {
			it->second->compute();
		}
	}
}

/**
* \brief Display All output Pin
*/
void Circuit::displayAll(void)
{
	for (auto it = _Components.begin(); it != _Components.end(); it++) {
		if (_type.at(it->first) == "output") {
			std::cout << it->first << "=" <<  it->second->compute() << std::endl;
		}
	}
}

/**
* \brief static function to call all the reset method of Component
* \param[in] std::map<std::string, std::unique_ptr<nts::IComponent>> &elem 
*/
void Circuit::resetIComponent(std::map<std::string, std::unique_ptr<nts::IComponent>>::value_type &elem)
{
	elem.second->resetExecution();
}


void Circuit::resetExecution(void)
{
	std::for_each(_Components.begin(), _Components.end(), this->resetIComponent);
}

/**
* \brief get the state of the pin in function of the input pin corresponding
* \param[in] pin the pin of the Component that we want the state
* \return nts::Tristate State of the pin
*/
nts::Tristate Circuit::compute(std::size_t pin)
{
	if (pin < 1 || pin > _NbPin)
		throw std::exception(); // Invalid Pin
	pin -= 1;
	return _PinLink[pin]();
}

/**
* \brief Deconstructor for the Circuit class
*/
Circuit::~Circuit()
{}
