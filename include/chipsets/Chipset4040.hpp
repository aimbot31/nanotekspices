/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4040
*/

#ifndef CHIPSET4040_HPP_
	#define CHIPSET4040_HPP_

    #include <iostream>
    #include <functional>
    #include "AComponent.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \class Chipset4040
		* \brief Chipset of type 4040
		*/
		class Chipset4040 : public nts::AComponent {
			public:
				Chipset4040(const std::string &name);
				~Chipset4040() override;

				nts::Tristate compute(std::size_t pin = 1);

			protected:
				short _Count;
				nts::Tristate _ClockPrevious;
				static constexpr std::size_t _numberOfPin = 14;
				static constexpr std::uint16_t _ResetPin = 11;
				static constexpr std::uint16_t _ClockPin = 11;
		};
	}

#endif /* !CHIPSET4040_HPP_ */
