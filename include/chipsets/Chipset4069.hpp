/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4069
*/

#ifndef CHIPSET4069_HPP_
	#define CHIPSET4069_HPP_

    #include <iostream>
    #include <functional>
    #include "AComponent.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \class Chipset4069
		* \brief Chipset of type 4069
		*/
		class Chipset4069 : public nts::AComponent {
			public:
				Chipset4069(const std::string &name);
				~Chipset4069() override;

				nts::Tristate compute(std::size_t pin = 1);

			protected:
				nts::Tristate operation(std::size_t pin1);
				static constexpr std::size_t _numberOfPin = 14;
		};
	}

#endif /* !CHIPSET4069_HPP_ */
