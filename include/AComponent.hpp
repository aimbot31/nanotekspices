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
	#include <map>
	#include "IComponent.hpp"

    /**
    * \namespace nts
    * \brief Namespace for Component
    */
	namespace nts {

		/**
		* \class AComponent
		* \brief Abstract Class on top of the Interface Component
		*/
		class AComponent : public nts::IComponent {
			public:
				/**
				* \brief Constructor of the AComponent Class
				* \param[in] std::string name is the name of the compenent
				* \param[in] std::size_t pins is the nb of pin of the Component
				* \return AComponent
				*/
				AComponent(const std::string &name, std::size_t pins = 1);

				/**
				* \brief Deconstructor for the AComponent class
				*/
				virtual ~AComponent();

				/**
				* \brief Connect the Component to an other 
				* \param[in] the pin that will be connected to the other component 
				* \param[in] the other Component 
				* \param[in] the pin of the other Component
				*/
				void setLink(size_t pin, IComponent &other, size_t otherpin) override final;

				/**
				* \brief get the state of the pin in function of the input pin corresponding
				* \param[in] pin the pin of the Component that we want the state
				* \return nts::Tristate State of the pin
				*/
				virtual nts::Tristate compute(std::size_t pin = 1) = 0;

				/**
				* \brief Method To display the Name of the Component
				*/
				void dump(void) const;

				/**
				* \brief return Name of the Component
				* \return Return std::string the name of the Component 
				*/
				inline const std::string &getName(void) const noexcept {    return this->_Name;   };

			protected:
				std::string _Name;
				std::size_t _NbPin;
				std::map<std::size_t, std::function<nts::Tristate(void)>> _PinLink;
		};
	}

#endif /* !ACOMPONENT_HPP_ */
