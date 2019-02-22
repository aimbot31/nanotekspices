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

				int run();
			protected:
				std::map<std::string, std::unique_ptr<nts::IComponent>> _component;
		};
	};

#endif /* !TRAITEMENT_HPP_ */