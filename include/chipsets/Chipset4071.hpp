/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4071
*/

#ifndef CHIPSET4071_HPP_
	#define CHIPSET4071_HPP_

    #include <iostream>
    #include <functional>
    #include "AComponent.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \class Chipset4071
		* \brief Chipset of type 4071
		*/
		class Chipset4071 : public nts::AComponent {
			public:
				Chipset4071(const std::string &name);
				~Chipset4071() override;

				nts::Tristate compute(std::size_t pin = 1);

			protected:
				nts::Tristate operation(std::size_t pin1, std::size_t pin2);
				static constexpr std::size_t _numberOfPin = 13;
		};
	}

#endif /* !CHIPSET4071_HPP_ */
