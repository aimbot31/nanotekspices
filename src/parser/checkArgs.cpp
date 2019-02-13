/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** CheckArgs
*/

#include "parser/checkArgs.hpp"
#include "parser/GestFile.hpp"
#include "exceptions/Exceptions.hpp"

int checkArgs(int argc, char **argv)
{
	if (argc <= 1)
		throw nts::InputError("Please enter enough args", "checkArgs");
	for (int i = 1; i < argc; i ++) {
		GestFile tmp(argv[i]);
		tmp.GetObjects();
	}
	return (0);
}