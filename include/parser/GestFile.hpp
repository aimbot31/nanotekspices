/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** GestFile
*/

#ifndef GESTFILE_HPP_
	#define GESTFILE_HPP_

	#include <fstream>
	#include <utility>
	#include <string>
	#include <iostream>
	#include <regex>

	class GestFile {
		public:
			GestFile(char *str);
			~GestFile();
			void GetObjects();
		private:
			void GetLinks();
			void GetChipsets();
			std::string _filename;
			bool _state;
			std::ifstream _file;
	};

#endif /* !GESTFILE_HPP_ */
