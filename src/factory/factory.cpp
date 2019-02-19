/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Factory
*/

#include "factory/factory.hpp"
#include "chipsets/Chipset4001.hpp"
#include "chipsets/Chipset4008.hpp"
#include "IComponent.hpp"

std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value)
{
	std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string name)>> tab;

	tab["4001"] = [](const std::string &name)->std::unique_ptr<nts::IComponent> { return (std::unique_ptr<nts::IComponent>(nts::Chipset4001(name))); };
	return (nullptr);
	//tab[""] = nts::Chipset4008();
}