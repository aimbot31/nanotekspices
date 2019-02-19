/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

    #include "AComponent.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \class Output
		* \brief Component that represent a default ouput in a Circuit
		*/
		class Output : public nts::AComponent {
			public:
				Output(const std::string &name);
				~Output();

				// Mandatory
				nts::Tristate compute(std::size_t pin = 1) override;

			protected:
			private:
		};
	}

#endif /* !OUTPUT_HPP_ */
