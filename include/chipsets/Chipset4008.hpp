/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4008
*/

#ifndef CHIPSET4008_HPP_
	#define CHIPSET4008_HPP_

    #include <iostream>
    #include <functional>
    #include "AComponent.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \class Chipset4008
		* \brief Chipset of type 4008
		*/
		class Chipset4008 : public nts::AComponent {
			public:
				Chipset4008(const std::string &name);
				~Chipset4008() override;

				nts::Tristate compute(std::size_t pin = 1);

			protected:
				/**
				* \brief make the operation
				*/
				void operation(void);
				nts::Tristate sum(nts::Tristate i1, nts::Tristate i2, nts::Tristate carry);
				nts::Tristate getCarry(nts::Tristate before1, nts::Tristate before2, nts::Tristate state);
				nts::Tristate firstOperation(std::size_t pin1, std::size_t pin2, std::size_t pin3);
				nts::Tristate otherOperation(std::size_t pin1, std::size_t pin2);
				static constexpr std::size_t _numberOfPin = 16;
				nts::Tristate _Carry;
				nts::Tristate _Output1;
				nts::Tristate _Output2;
				nts::Tristate _Output3;
				nts::Tristate _Output4;
		};
	}

#endif /* !CHIPSET4008_HPP_ */
