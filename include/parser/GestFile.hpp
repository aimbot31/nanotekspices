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
	#include <map>
	#include <unordered_map>

	class GestFile {
		public:
			GestFile(char *filename);
			~GestFile();
			bool GetStatus() const;
			std::unordered_map<int, std::map<std::string, std::string>> GetObjects();
		private:
			std::string _filename;
			bool _state;
			std::ifstream _file;
	};

#endif /* !GESTFILE_HPP_ */
