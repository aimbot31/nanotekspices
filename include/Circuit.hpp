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
	#include "Traitement.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \class Circuit
		* \brief Component that can hold multiple Component and Form a Circuit
		*/
		class Circuit : public nts::Traitement, public nts::AComponent {
			public:
				Circuit(int ac, char **av, const std::string &name);
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

				nts::Tristate compute(std::size_t pin = 1);

				/**
				* \brief Compute All output Pin
				*/
				void computeAll(void);
				void displayAll(void);
				void dumpAll(void);


				void setInputValue(std::string &name, nts::Tristate value);



			protected:
				static void dumpFromMap(const std::map<std::string, std::unique_ptr<nts::IComponent>>::value_type &elem);
				void resetExecution(void);
				static void resetIComponent(std::map<std::string, std::unique_ptr<nts::IComponent>>::value_type &elem);
		};
	}

#endif /* !CIRCUIT_HPP_ */
