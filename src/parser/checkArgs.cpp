/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** CheckArgs
*/

#include "parser/checkArgs.hpp"
#include "parser/GestFile.hpp"
#include "exceptions/Exceptions.hpp"

static void checkValues(std::unordered_map<int, std::map<std::string, std::string>> &component, std::map<std::string, int> &values)
{
	for (auto key : values) {
		if (component[1].count(key.first) == 0 || component[1][key.first] != "input")
			throw std::exception();
	}
}

int checkArgs(int argc, char **argv)
{
	std::unordered_map<int, std::map<std::string, std::string>> component;
	std::map<std::string, int> values;

	if (argc <= 1)
		throw nts::InputError("Please enter enough args", "checkArgs");
	for (int i = 1; i < argc; i++) {
		GestFile tmp(argv[i]);
		if (!tmp.GetStatus()) {
			std::string tmp = {argv[i]};
			std::size_t pos = tmp.find('=');
			if (pos == std::string::npos || pos == tmp.length())
				throw std::exception();
			values[tmp.substr(0, pos)] = std::stoi(tmp.substr(pos+1, tmp.length()), nullptr, 10);
			if (values[tmp.substr(0, pos)] != 0 && values[tmp.substr(0, pos)] != 1)
				throw std::exception();
			continue;
		}
		component = tmp.GetObjects();
	}
	checkValues(component, values);
	return (0);
}