/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** main
*/

#include "Parser.hpp"
#include "Traitement.hpp"

int main(int argc, char **argv)
{

	try {
		Parser nanoParser(argc, argv);
		nts::Traitement nanotekspice(nanoParser.getArgs());
		nanotekspice.run();
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return (84);
	}
	return (0);
}