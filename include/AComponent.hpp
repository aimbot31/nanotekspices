/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** IComponent
*/

#ifndef ACOMPONENT_HPP_
	#define ACOMPONENT_HPP_

	#include <functional>
	#include <vector>
	#include "IComponent.hpp"

	namespace nts {

		class AComponent : public nts::IComponent {
			public:
				AComponent(const std::string &name);
				virtual ~AComponent();

				void setLink(size_t pin, IComponent &other, size_t otherpin) override final;
				virtual nts::Tristate compute(std::size_t pin = 1) = 0;
				void dump(void) const;

				// Getters
				inline const std::string &getName(void) const noexcept {    return this->_Name;   };

			protected:
				std::string _Name;
				std::vector<std::function<nts::Tristate(void)>> _PinLink;
		};

	}


#endif /* !ACOMPONENT_HPP_ */
