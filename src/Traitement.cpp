/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Traitement
*/

#include "Traitement.hpp"
#include <iostream>

nts::Traitement::Traitement(Args &args)
{
	std::map<std::string, std::string> type;

	for (auto k : args.component[1]) {
		if ((_component[k.first] = nts::createComponent(k.second, k.first)) == nullptr)
			throw std::exception();
		type[k.first] = k.second;
	}
	for (auto k : args.component[2]) {
		std::size_t pos1 = k.second.find(':'); 
		std::size_t pos2 = k.first.find(':');
		_component[k.second.substr(0, pos1)]->setLink(k.second.substr(pos1, k.second.length()), *_component["a"]["b"].get(), 2);
	}
}

int nts::Traitement::run()
{

}

nts::Traitement::~Traitement()
{
}
