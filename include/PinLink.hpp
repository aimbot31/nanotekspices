/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** PinLink
*/

#ifndef PINLINK_HPP_
	#define PINLINK_HPP_

    #include "IComponent.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
    namespace nts {

		/**
		* \class AComponent
		* \brief Class that manage the PinLink
		*/
        class PinLink {
            public:

				/**
				* \brief Constructor of the AComponent Class
				* \param[in] Component
				* \param[in] pinOfComponent to link
				* \param[in] myPin to link
				* \return PinLink
				*/
                PinLink(nts::IComponent *Component = nullptr, std::size_t pinOfComponent = 0);

				/**
				* \brief Deconstructor for the AComponent class
				*/
                ~PinLink();

                /**
                * \brief return the output of the other Component pin
                * \return State of the component
                */
                nts::Tristate operator()(void) const;

                /**
                * \brief Check if the Pin is Link
                */                
                operator bool(void) const;

            protected:
                nts::IComponent *_Component;/*!< Ref to the component linked */
                std::size_t _Pin;/*!< Ref to the Pin of the linked component */
            private:
        };

    };

#endif /* !PINLINK_HPP_ */
