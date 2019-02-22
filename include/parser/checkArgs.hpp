/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** checkArgs
*/

#ifndef CHECKARGS_HPP_
	#define CHECKARGS_HPP_

	#include <unordered_map>
	#include <map>

	struct Args {
		std::unordered_map<int, std::map<std::string, std::string>> component;
		std::map<std::string, int> values;
	};

	int checkArgs(int argc, char **argv, Args &args);

#endif /* !CHECKARGS_HPP_ */
