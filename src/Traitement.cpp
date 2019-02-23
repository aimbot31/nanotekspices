/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Traitement
*/

#include "Traitement.hpp"

nts::Traitement::Traitement(Args &args)
{
	for (auto k : args.component[1]) {
		if ((_Components[k.first] = nts::createComponent(k.second, k.first)) == nullptr)
			throw std::exception();
		_type[k.first] = k.second;
	}
	for (auto k : args.values)
		static_cast<nts::Input *>(_Components[k.first].get())->setInputValue(nts::Tristate(k.second));
	for (auto k : args.component[2]) {
		std::size_t pos1 = k.second.find(':');
		std::size_t pos2 = k.first.find(':');
		if ((_Components.count(k.second.substr(0, pos1)) == 0) || (_Components.count(k.first.substr(0, pos2)) == 0))
			throw std::exception();
		_Components[k.second.substr(0, pos1)]->setLink(std::stoi(k.second.substr(pos1+1, k.second.length()), nullptr, 10), *_Components[k.first.substr(0, pos2)], std::stoi(k.first.substr(pos2+1, k.first.length()), nullptr, 10));
		_Components[k.first.substr(0, pos2)]->setLink(std::stoi(k.first.substr(pos2+1, k.first.length()), nullptr, 10), *_Components[k.second.substr(0, pos1)], std::stoi(k.second.substr(pos1+1, k.second.length()), nullptr, 10));
	}
}

nts::Traitement::~Traitement()
{
}
