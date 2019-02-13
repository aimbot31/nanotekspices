/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** CheckArgs
*/

#include "parser/checkArgs.hpp"
#include "exceptions/Exceptions.hpp"

int checkArgs(int argc, char **argv)
{
	if (argc <= 1)
		throw nts::InputError("Please enter enough args", "checkArgs");
	return (0);
}