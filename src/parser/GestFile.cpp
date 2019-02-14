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
	if (!_file.is_open())
		_state = false;
}

void GestFile::GetChipsets()
{
	//std::map<std::string chipset;
	bool isChipset = false;
	std::string line1, line2;

	for (std::string line; std::getline(_file, line); ) {
		if (line.length() <= 1 || !line.find('#', 0))
			continue;
		if (!line.find(".chipsets:", 0)) {
			isChipset = true;
			continue;
		}
		if (!line.find(".links:", 0))
			break;
		if (isChipset) {
			std::size_t len = line.find(' ', 0);
			if (len == std::string::npos)
				len = line.find('	', 0);
			line1 = line.substr(0, len);
			line2 = line.substr(len, line.length());
			std::regex pattern{"\\s"};
			std::string replacement{""};
			std::istringstream result1(std::regex_replace(line1, pattern, replacement));
			std::istringstream result2(std::regex_replace(line2, pattern, replacement));
			std::cout << "This is line 1 : " << result1.str() << std::endl << "This is line 2 : " << result2.str() << std::endl;
		}
	}
}

void GestFile::GetLinks()
{

}

void GestFile::GetObjects()
{
	GetChipsets();
}

GestFile::~GestFile()
{
}
