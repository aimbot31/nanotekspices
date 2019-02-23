/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Parser
*/

#include "Parser.hpp"
#include "GestFile.hpp"
#include "Exceptions.hpp"

Parser::Parser(int argc, char **argv)
{
	checkArgs(argc, argv, _Args);
}

/**
* \brief Check if the link are Correct
* \param[in] file Content
* \param[in] link
*/
void Parser::checkValues(std::unordered_map<int, std::map<std::string, std::string>> &component, std::map<std::string, int> &values)
{
	for (auto key : values) {
		if (component[1].count(key.first) == 0 || component[1][key.first] != "input")
			throw std::exception();
	}
}

/**
* \brief Check That the Args are Correct
* \param[in] nb of args
* \param[in] content of argv
* \param[in] container to fill
*/
void Parser::checkArgs(int argc, char **argv, Args &args)
{
	if (argc <= 1)
		throw nts::InputError("Please enter enough args", "checkArgs");
	for (int i = 1; i < argc; i++) {
		GestFile tmp(argv[i]);
		if (!tmp.GetStatus()) {
			std::string tmp = {argv[i]};
			std::size_t pos = tmp.find('=');
			if (pos == std::string::npos || pos == tmp.length())
				throw std::exception();
			args.values[tmp.substr(0, pos)] = std::stoi(tmp.substr(pos+1, tmp.length()), nullptr, 10);
			if (args.values[tmp.substr(0, pos)] != 0 && args.values[tmp.substr(0, pos)] != 1)
				throw std::exception();
			continue;
		}
		args.component = tmp.GetObjects();
	}
	checkValues(args.component, args.values);
}

Parser::~Parser()
{
}
