/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_
	#include "Gates.hpp"
	#include "Input.hpp"
	namespace nts {
		class Clock : public nts::Input {
			public:
				Clock(const std::string &name, nts::Tristate state = nts::Tristate::UNDEFINED);
				~Clock();

				void resetExecution(void) override;
			protected:
			private:
		};
	}
#endif /* !CLOCK_HPP_ */
