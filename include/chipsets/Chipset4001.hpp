/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Chipset4001
*/

#ifndef CHIPSET4001_HPP_
	#define CHIPSET4001_HPP_

    #include <iostream>
    #include <functional>
    #include "AComponent.hpp"

class Chipset4001 : public nts::AComponent {
	public:
		Chipset4001(const std::string &name);
		~Chipset4001() override;

		nts::Tristate compute(std::size_t pin = 1);

	protected:
		nts::Tristate operation(std::size_t pin1, std::size_t pin2);
		static constexpr std::size_t _numberOfPin = 13;
};

#endif /* !CHIPSET4001_HPP_ */
