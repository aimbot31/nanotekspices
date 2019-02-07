/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Input
*/

#ifndef INPUT_HPP_
	#define INPUT_HPP_

    #include "AComponent.hpp"

class Input : public nts::AComponent {
	public:
		Input(const std::string &name);
		~Input();

        // Mandatory
        nts::Tristate compute(std::size_t pin = 1) override;

        // Setters
        void setInputValue(nts::Tristate defaultValue) noexcept;

	protected:
	private:
        nts::Tristate _Value;
};

#endif /* !INPUT_HPP_ */
