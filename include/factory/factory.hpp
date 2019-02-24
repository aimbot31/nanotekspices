/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
	#define FACTORY_HPP_
	
	#include <memory>
	#include <unordered_map>
	#include <functional>
	#include "chipsets/Chipset4001.hpp"
	#include "chipsets/Chipset4008.hpp"
	#include "chipsets/Chipset4011.hpp"
	#include "chipsets/Chipset4030.hpp"
	#include "chipsets/Chipset4069.hpp"
	#include "chipsets/Chipset4071.hpp"
	#include "chipsets/Chipset4081.hpp"
	#include "Clock.hpp"
	#include "Input.hpp"
	#include "Output.hpp"
	#include "IComponent.hpp"

	namespace nts {
		std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);
	};

#endif /* !FACTORY_HPP_ */
