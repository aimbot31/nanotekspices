/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** main
*/

#include "NanoTekSpice.hpp"

int main(int argc, char **argv)
{
	try {
		nts::NanoTekSpice nanotekspice(argc, argv);
		nanotekspice.run();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (84);
	}
	return (0);
}