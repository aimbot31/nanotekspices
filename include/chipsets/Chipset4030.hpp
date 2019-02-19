/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4030
*/

#ifndef CHIPSET4030_HPP_
	#define CHIPSET4030_HPP_

    #include <iostream>
    #include <functional>
    #include "AComponent.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \class Chipset4030
		* \brief Chipset of type 4030
		*/
		class Chipset4030 : public nts::AComponent {
			public:
				Chipset4030(const std::string &name);
				~Chipset4030() override;

				nts::Tristate compute(std::size_t pin = 1);

			protected:
				nts::Tristate operation(std::size_t pin1, std::size_t pin2);
				static constexpr std::size_t _numberOfPin = 14;
		};
	}

#endif /* !CHIPSET4030_HPP_ */
