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
	#include "AComponent.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \class Circuit
		* \brief Component that can hold multiple Component and Form a Circuit
		*/
		class Circuit : public nts::AComponent {
			public:
				Circuit(const std::string &name);
				~Circuit();

				/**
				* \enum ComponentType
				* \brief Different Type of Component that we can see in a Circuit
				*/				
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
	}

#endif /* !CIRCUIT_HPP_ */
