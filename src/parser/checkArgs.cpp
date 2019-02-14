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
	std::map<std::string, int> values;

	if (argc <= 1)
		throw nts::InputError("Please enter enough args", "checkArgs");
	for (int i = 1; i < argc; i++) {
		GestFile tmp(argv[i]);
		if (!tmp.GetStatus()) {
			std::string tmp = {argv[i]};
			std::size_t pos = tmp.find('=');
			values[tmp.substr(0, pos)] = std::stoi(tmp.substr(pos+1, tmp.length()), nullptr, 10);
			continue;
		}
		tmp.GetObjects();
	}
	// std::cout << "Valeur à initialiser :" << std::endl;
	// for (auto it : values)
	// 	std::cout << "	First : '" << it.first << "'	Second : '" << it.second << "'" << std::endl;
	return (0);
}