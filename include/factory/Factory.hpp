/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
	#define FACTORY_HPP_
	
	#include <memory>

	namespace nts {
		class Factory {
			public:
				Factory();
				~Factory();

				std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);
			protected:
			private:
		};
	};

#endif /* !FACTORY_HPP_ */
