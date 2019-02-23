/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Traitement
*/

#ifndef TRAITEMENT_HPP_
	#define TRAITEMENT_HPP_

	#include "parser/checkArgs.hpp"
	#include "factory/factory.hpp"
	#include <map>

	namespace nts {
		class Traitement {
			public:
				Traitement(Args &args);
				~Traitement();

			protected:
				std::map<std::string, std::unique_ptr<nts::IComponent>> _Components;/*!< All the Component */
				std::map<std::string, std::string> _type;/*!< type of object from name */
		};
	};

#endif /* !TRAITEMENT_HPP_ */