/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** parseCommands
*/

#include "parser/parseCommands.hpp"

static int checkCommand(std::string command)
{
	std::unordered_map<std::string, void> tab;
	tab["exit"] = exit(0);
	tab["display"] = exit(1);
	tab["simulate"] = exit(2);
	tab["loop"] = exit(3);
	tab["dump"] = exit(4);

	if (tab.count(command) == 0)
		return (tab[command]);
	else {
		std::size_t pos = command.find('=');
		if (pos == std::string::npos || pos == command.length())
			return (1);
		// 	throw std::exception();

		//tmp.substr(0, pos)
		//std::stoi(tmp.substr(pos+1, command.length()), nullptr, 10);
		if (values[tmp.substr(0, pos)] != 0 && values[tmp.substr(0, pos)] != 1)
			throw std::exception();
	}
	return (0);
}

int getCommand()
{
	std::cout << ">";
	std::string command;

	getline(std::cin, command);
	checkCommand(command);

	return (0);
}