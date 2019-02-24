/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Factory
*/

#include "factory/factory.hpp"

std::unique_ptr<nts::IComponent> nts::createComponent(const std::string &type, const std::string &value)
{
	std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> tab;

	tab["4001"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Chipset4001(value)))); };
	tab["4008"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Chipset4008(value)))); };
	tab["4011"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Chipset4011(value)))); };
	tab["4030"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Chipset4030(value)))); };
	tab["4069"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Chipset4069(value)))); };
	tab["4071"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Chipset4071(value)))); };
	tab["4081"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Chipset4081(value)))); };
	tab["input"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Input(value)))); };
	tab["clock"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Clock(value)))); };
	tab["true"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Input(value, nts::TRUE)))); };
	tab["false"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Input(value, nts::FALSE)))); };
	tab["output"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Output(value)))); };

	return (tab.count(type) == 0 ? nullptr : std::move(tab[type]()));
}