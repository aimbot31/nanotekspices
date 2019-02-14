/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4008
*/
/*
* \file
* \brief File with all the method of the Circuit class
*/

#include "Chipset4008.hpp"
#include "Gates.hpp"

using namespace nts;

/**
* \brief Constructor of the Chipset4008 Class
* \param[in] std::string name is the name of the compenent
* \return Chipset4008
*/
Chipset4008::Chipset4008(const std::string &name) :
nts::AComponent(name, Chipset4008::_numberOfPin),
_Carry(nts::Tristate::UNDEFINED)
{}

/**
* \brief make the operation of the Chipset (NOR)
* \param[in] input1
* \param[in] input2
* \return Return the State of of the operation
*/
nts::Tristate Chipset4008::sum(nts::Tristate i1, nts::Tristate i2, nts::Tristate carry)
{
	nts::Tristate res = nts::Gates::Xor(i1, i2);
	_Carry = this->getCarry(i1, i2, res);
	return nts::Gates::Xor(res, carry);
}

nts::Tristate Chipset4008::getCarry(nts::Tristate before1, nts::Tristate before2, nts::Tristate state)
{
	nts::Tristate tmp1 = nts::Gates::And(before1, before2);
	nts::Tristate tmp2 = nts::Gates::And(state, _Carry);
	return nts::Gates::Or(tmp1, tmp2);
}

nts::Tristate Chipset4008::otherOperation(std::size_t pin1, std::size_t pin2)
{
	if (!_PinLink[pin1])
		throw std::exception(); // Not Linked Pin1
	if (!_PinLink[pin2])
		throw std::exception(); // Not Linked Pin2
	nts::Tristate input[2] = {_PinLink[pin1](), _PinLink[pin2]()};
	return this->sum(input[0], input[1], _Carry);
}

nts::Tristate Chipset4008::firstOperation(std::size_t pin1, std::size_t pin2, std::size_t pin3)
{
	if (!_PinLink[pin1])
		throw std::exception(); // Not Linked Pin1
	if (!_PinLink[pin2])
		throw std::exception(); // Not Linked Pin2
	if (!_PinLink[pin3])
		throw std::exception(); // Not Linked Pin2
	nts::Tristate input[3] = {_PinLink[pin1](), _PinLink[pin2](), _PinLink[pin3]()};
	return this->sum(input[0], input[1], input[2]);
}

/**
* \brief make the operation
*/
void Chipset4008::operation(void)
{
	_Output1 = this->firstOperation(5, 6, 8); 
	_Output2 = this->otherOperation(3, 4);
	_Output3 = this->otherOperation(1, 2);
	_Output4 = this->otherOperation(0, 14);
}

/**
* \brief Return the State of the Chipset at a specific pin
* \param[in] pin of the Output
* \return Return the State of the Pin
*/
nts::Tristate Chipset4008::compute(std::size_t pin)
{
	this->operation();
	switch (pin) {
		case 10: return _Output1;
		case 11: return _Output2;
		case 12: return _Output3;
		case 13: return _Output4;
		case 14: return _Carry;
		default:
			throw std::exception();
	}
}

/**
* \brief Deconstructor for the AComponent class
*/
Chipset4008::~Chipset4008()
{}
