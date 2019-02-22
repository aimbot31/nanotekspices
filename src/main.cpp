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

	try {
		checkArgs(argc, argv, args);
		nts::Traitement nanotekspice(args);
		nanotekspice.run();
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return (84);
	}
	return (0);
}