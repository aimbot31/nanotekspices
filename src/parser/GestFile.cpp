/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** GestFile
*/

#include "parser/GestFile.hpp"

GestFile::GestFile(char *str) : _filename(str)
{
	_file = std::ifstream(_filename);
	_state = _file.is_open();
}

bool GestFile::GetStatus() const
{
	return (_state);
}

std::unordered_map<int, std::map<std::string, std::string>> GestFile::GetObjects()
{
	std::unordered_map<int, std::map<std::string, std::string>> objects;
	int isChipset = 0;

	for (std::string line; std::getline(_file, line); ) {
		if (line.length() <= 1 || !line.find('#', 0))
			continue;
		if (!line.find(".chipsets:", 0)) {
			isChipset = 1;
			continue;
		}
		if (!line.find(".links:", 0)) {
			isChipset = 2;
			continue;
		}
		if (isChipset) {
			std::size_t len = line.find(' ', 0);
			if (len == std::string::npos)
				len = line.find('	', 0);
			std::string line1 = line.substr(0, len);
			std::string line2 = line.substr(len, line.length());
			std::regex pattern{"\\s|#.+"};
			std::string replacement{""};
			std::istringstream result1(std::regex_replace(line1, pattern, replacement));
			std::istringstream result2(std::regex_replace(line2, pattern, replacement));
			if (result1.str().empty() || result2.str().empty())
				throw std::exception();
			objects[isChipset][result1.str()] = result2.str();
		}
	}
	// for (auto it : objects) {
	// 	if (it.first == 1)
	// 		std::cout << "Chipsets :" << std::endl;
	// 	else
	// 		std::cout << "Links :" << std::endl;		
	// 	for (auto ite : it.second)
	// 		std::cout << "	First : '" << ite.first << "'		Second : '" << ite.second << "'"<< std::endl;
	// }
	return (objects);
}

GestFile::~GestFile()
{
}
