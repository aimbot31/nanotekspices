/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** main
*/

#include "parser/checkArgs.hpp"
#include "Traitement.hpp"

int main(int argc, char **argv)
{
	Args args;

	checkArgs(argc, argv, args);
	nts::Traitement nts(args);
	nts.run();
	return (0);
}