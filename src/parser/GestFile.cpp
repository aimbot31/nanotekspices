/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** GestFile
*/

#include "parser/GestFile.hpp"

GestFile::GestFile(char *filename) : _filename(filename)
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
		if (line.length() <= 1 || !line.compare(0, 1, "#"))
			continue;
		if (!line.compare(0, 10, ".chipsets:")) {
			isChipset = 1;
			continue;
		}
		if (!line.compare(0, 10, ".links:")) {
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
			if (isChipset == 2) {
				std::size_t pos1 = result1.str().find(':');
				std::size_t pos2 = result2.str().find(':');
				if (pos1 == std::string::npos || pos2 == std::string::npos ||
					pos1 == result1.str().length() || pos2 == result2.str().length())
					throw std::exception();
			}
			objects[isChipset][result2.str()] = result1.str();
		}
	}
	return (objects);
}

GestFile::~GestFile()
{
}
