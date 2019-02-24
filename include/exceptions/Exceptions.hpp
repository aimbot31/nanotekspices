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

		class ComponentError : public NtsError
		{
			public:
				ComponentError(const std::string &msg, const std::string &component = "Unknown");
				virtual ~ComponentError() throw() {};
		};

		class PinError : public NtsError
		{
			public:
				PinError(const std::string &component = "Unknown");
				virtual ~PinError() throw() {};
		};

		class LinkError : public NtsError
		{
			public:
				LinkError(const std::string &msg, const std::string &component = "Unknown");
				virtual ~LinkError() throw() {};
		};

		class FileError : public NtsError
		{
			public:
				FileError(const std::string &component = "Unknown");
				virtual ~FileError() throw() {};
		};
	}

#endif /* !EXCEPTIONS_HPP_ */