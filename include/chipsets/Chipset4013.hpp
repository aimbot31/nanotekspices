/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4013
*/

#ifndef CHIPSET4013_HPP_
	#define CHIPSET4013_HPP_

    #include <iostream>
    #include "AComponent.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \class Chipset4013
		* \brief Chipset of type 4013
		*/
		class Chipset4013 : public nts::AComponent {
			public:
				Chipset4013(const std::string &name);
				~Chipset4013() override;

				nts::Tristate compute(std::size_t pin = 1);

			protected:
				nts::Tristate _Gate1;
				nts::Tristate _Gate2;
				nts::Tristate _ClockPrevious1;
				nts::Tristate _ClockPrevious2;
				static constexpr std::size_t _numberOfPin = 14;
				static constexpr std::int16_t _ClockPin1 = 3;
				static constexpr std::int16_t _ClockPin2 = 11;
				static constexpr std::int16_t _SetPin1 = 6;
				static constexpr std::int16_t _SetPin2 = 8;
				static constexpr std::int16_t _ResetPin1 = 4;
				static constexpr std::int16_t _ResetPin2 = 10;
			private:
				nts::Tristate operation1();
				nts::Tristate operation2();
		};
	}

#endif /* !CHIPSET4013_HPP_ */
