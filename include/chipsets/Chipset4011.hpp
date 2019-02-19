/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4011
*/

#ifndef CHIPSET4011_HPP_
	#define CHIPSET4011_HPP_

    #include <iostream>
    #include <functional>
    #include "AComponent.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \class Chipset4011
		* \brief Chipset of type 4011
		*/
		class Chipset4011 : public nts::AComponent {
			public:
				Chipset4011(const std::string &name);
				~Chipset4011() override;

				nts::Tristate compute(std::size_t pin = 1);

			protected:
				nts::Tristate operation(std::size_t pin1, std::size_t pin2);
				static constexpr std::size_t _numberOfPin = 13;
		};
	}

#endif /* !CHIPSET4011_HPP_ */
