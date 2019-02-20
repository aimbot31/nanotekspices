/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Factory
*/

#include "factory/factory.hpp"
#include "chipsets/Chipset4001.hpp"
#include "chipsets/Chipset4008.hpp"
#include "chipsets/Chipset4011.hpp"
#include "chipsets/Chipset4030.hpp"
#include "chipsets/Chipset4069.hpp"
#include "chipsets/Chipset4071.hpp"
#include "chipsets/Chipset4081.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "IComponent.hpp"

std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value)
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
	tab["output"] = [value]()->std::unique_ptr<nts::IComponent> { return (std::move(std::unique_ptr<nts::IComponent>(new nts::Output(value)))); };

	return (tab.count(value) == 0 ? nullptr : std::move(tab[value]()));
}