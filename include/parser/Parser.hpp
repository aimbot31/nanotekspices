/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Parser
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

    #include "checkArgs.hpp"

class Parser {
	public:
		Parser(int argc, char **argv);
		~Parser();

        /**
        * \brief get option of the program
        * \return options of the programes
        */
        inline Args &getArgs(void)  {    return _Args;   };

        /**
        * \brief Check That the Args are Correct
        * \param[in] nb of args
        * \param[in] content of argv
        * \param[in] container to fill
        */
        static void checkArgs(int argc, char **argv, Args &args);
	protected:
        Args _Args;/*!< Contain info about the option of program */
	private:

        /**
        * \brief Check if the link are Correct
        * \param[in] file Content
        * \param[in] link
        */
        static void checkValues(std::unordered_map<int, std::map<std::string, std::string>> &component, std::map<std::string, int> &values);
        void checkCommand(std::string command);
};

#endif /* !PARSER_HPP_ */
