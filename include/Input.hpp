/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

	#include "AComponent.hpp"

	/**
	* \namespace nts
	* \brief Namespace for Component
	*/
	namespace nts {

		/**
		* \class Input
		* \brief Component that represent a default Input
		*/
		class Input : public nts::AComponent {
			public:
				Input(const std::string &name, nts::Tristate state = nts::Tristate::UNDEFINED);
				~Input();

				// Mandatory
				nts::Tristate compute(std::size_t pin = 1) override;
				// Setters
				void setInputValue(nts::Tristate defaultValue) noexcept;
			protected:
				nts::Tristate _Value; /*!< Default value to return */
		};
	};

#endif /* !INPUT_HPP_ */
