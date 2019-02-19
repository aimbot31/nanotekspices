/*
** EPITECH PROJECT, 2019
** Documents
** File description:
** Errors
*/

#ifndef EXCEPTIONS_HPP_
	#define EXCEPTIONS_HPP_

	#include <exception>
	#include <string>

	namespace nts {
		class NtsError : public std::exception
		{
			public:
				NtsError(const std::string &msg = "Error", const std::string &component = "Unknown");
				virtual ~NtsError() throw() {};
				const std::string &getComponent() const;
				const char* what() const throw();
			protected:
				std::string _msg;
				std::string _component;
		};

		class InputError : public NtsError
		{
			public:
				InputError(const std::string &msg, const std::string &component = "Unknown");
				virtual ~InputError() throw() {};
		};
	}

#endif /* !EXCEPTIONS_HPP_ */