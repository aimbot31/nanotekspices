/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Gates
*/
/**
* \file
* \brief File with all the Basic Gates Or Not Nor And Nand
*/

#include "Gates.hpp"

/**
* \brief Or function simulete a OR Gate
* Table de vérité de OU
* a 	b 	a OU b
* ---------------------
* 0 	0 	0
* 0 	1 	1
* 1 	0 	1
* 1 	1 	1 
* \param[in] input1 is the First state
* \param[in] input2 is the second state
* \return nts::Tristate Return the state of the gate in function of his input
*/
nts::Tristate nts::Gates::Or(nts::Tristate input1, nts::Tristate input2)
{
	if (input1 == nts::Tristate::TRUE
	|| input2 == nts::Tristate::TRUE) {
		return nts::Tristate::TRUE;
	}
	if (input1 == nts::Tristate::FALSE
	&& input2 == nts::Tristate::FALSE) {
		return nts::Tristate::FALSE;
	}
	return nts::Tristate::UNDEFINED;
}

/**
* \brief Or function simulete a NOT Gate
* Table de vérité de NOT
* a     a NOT
* ------------
* 0 	1
* 1 	0
* \param[in] input is the state
* \return nts::Tristate Return the state of the gate in function of his input
*/
nts::Tristate nts::Gates::Not(nts::Tristate input)
{
	if (input == nts::Tristate::UNDEFINED)
		return UNDEFINED;
	return ((input != nts::Tristate::TRUE) ? nts::Tristate::TRUE : nts::Tristate::FALSE);
}

/**
* \brief Or function simulete a AND Gate
* Table de vérité de AND
* a     b   a AND b
* -----------------
* 0 	1       0
* 0 	0       0
* 1 	0       0
* 1 	1       1
* \param[in] input1 is the First state
* \param[in] input2 is the Second state
* \return nts::Tristate Return the state of the gate in function of his input
*/
nts::Tristate nts::Gates::And(nts::Tristate input1, nts::Tristate input2)
{
	if (input1 == nts::Tristate::TRUE
	&& input2 == nts::Tristate::TRUE)
		return nts::Tristate::TRUE;
	if ((input1 == nts::Tristate::FALSE
	|| input2 == nts::Tristate::FALSE))
		return nts::Tristate::FALSE;
	return nts::Tristate::UNDEFINED;
}

/**
* \brief Or function simulete a Nor Gate
* Table de vérité de Nor
* a     b   a Nor b
* -----------------
* 0 	0       1
* 0 	1       0
* 1 	0       0
* 1 	1       0
* \param[in] input1 is the First state
* \param[in] input2 is the Second state
* \return nts::Tristate Return the state of the gate in function of his input
*/
nts::Tristate nts::Gates::Nor(nts::Tristate input1, nts::Tristate input2)
{
	return nts::Gates::Not(nts::Gates::Or(input1, input2));
}

/**
* \brief Or function simulete a Xor Gate
* Table de vérité de Xor
* a     b   a Xor b
* -----------------
* 0 	0       0
* 0 	1       1
* 1 	0       1
* 1 	1       0
* \param[in] input1 is the First state
* \param[in] input2 is the Second state
* \return nts::Tristate Return the state of the gate in function of his input
*/
nts::Tristate nts::Gates::Xor(nts::Tristate input1, nts::Tristate input2)
{
	return nts::Gates::And(nts::Gates::Nand(input1, input2),
							nts::Gates::Or(input1, input2));
}

/**
* \brief Or function simulete a Nand Gate
* Table de vérité de Nand
* a     b   a Nand b
* -----------------
* 0 	0       0
* 0 	1       1
* 1 	0       1
* 1 	1       1
* \param[in] input1 is the First state
* \param[in] input2 is the Second state
* \return nts::Tristate Return the state of the gate in function of his input
*/
nts::Tristate nts::Gates::Nand(nts::Tristate input1, nts::Tristate input2)
{
	return nts::Gates::Not(nts::Gates::And(input1, input2));
}