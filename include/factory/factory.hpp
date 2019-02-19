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
	#include "IComponent.hpp"

	namespace nts {
		std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);
	};

#endif /* !FACTORY_HPP_ */
