/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
	#define CIRCUIT_HPP_

	#include <map>
	#include <memory>
	#include <list>
	#include <unordered_map>
	#include "AComponent.hpp"

class Circuit : public nts::AComponent {
	public:
		Circuit(const std::string &name);
		~Circuit();

		enum ComponentType {
			OUTPUT,
			INPUT,
			INTERN
		};

		void dump(void) const override;
		nts::Tristate compute(std::size_t pin = 1);

		void addComponent(std::unique_ptr<nts::IComponent> &newComponent, ComponentType type = ComponentType::INTERN);

	protected:
		std::map<std::string, std::unique_ptr<nts::IComponent>> _Components;
		void addPin(nts::IComponent *newOutput, ComponentType type) noexcept;
		static void dumpFromMap(const std::map<std::string, std::unique_ptr<nts::IComponent>>::value_type &elem);
};

#endif /* !CIRCUIT_HPP_ */
