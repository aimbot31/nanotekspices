/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
	#define ICOMPONENT_HPP_

	#include <iostream>

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \enum Tristate
		* \brief Define the three State possible
		*/
		enum Tristate {
			UNDEFINED = (-true),
			TRUE = true,
			FALSE = false
		};

		/**
		* \class IComponent
		* \brief Interface for Component
		*/
		class IComponent {
			public:
				virtual ~IComponent() = default;

				virtual nts::Tristate compute(std::size_t pin = 1) = 0;
				virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
				virtual void dump(void) const = 0;
				virtual const std::string &getName(void) const noexcept = 0;
				virtual void resetExecution(void) = 0;
		};
	}

#endif /* !ICOMPONENT_HPP_ */
