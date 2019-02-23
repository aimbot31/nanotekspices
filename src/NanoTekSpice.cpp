/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** NanoTekSpice
*/

#include "NanoTekSpice.hpp"

using namespace nts;

bool NanoTekSpice::_Running = false;

NanoTekSpice::NanoTekSpice(int ac, char **av, const std::string &name) :
nts::Circuit(ac, av, name)
{
	_Running = false;
}

std::string &NanoTekSpice::getNextCommand(void)
{
	std::cout << "> ";
	getline(std::cin, _CurrentCommand);
	return _CurrentCommand;
}

void NanoTekSpice::updateInputFromCurrentCommand(void)
{
		std::size_t pos = _CurrentCommand.find('=');
		if (pos == std::string::npos || pos == _CurrentCommand.length()) {
			std::cout << "Invalid Command" << std::endl;
			return;
		}

		std::string name = _CurrentCommand.substr(0, pos);
		int value = std::stoi(_CurrentCommand.substr(pos+1, _CurrentCommand.length()), nullptr, 10);
		if (value != 0 && value != 1) {
			std::cout << "Invalid Value" << std::endl;
			return;
		}

		setInputValue(name, nts::Tristate(value));
}

void NanoTekSpice::run(void)
{
	while (getNextCommand().length() != 0 && _CurrentCommand != "EOF")
		DoCommandAction();
}

void NanoTekSpice::stopRunning(int i)
{
	(void)i;
	_Running = false;
}

void NanoTekSpice::doNothing(int i)
{
	(void)i;
}

void NanoTekSpice::simulateInLoop(void)
{
	_Running = true;
	std::signal(SIGINT, stopRunning);
	while (nts::NanoTekSpice::_Running)
		computeAll();
	std::signal(SIGINT, doNothing);
}


void NanoTekSpice::endRun(void)
{
	exit(0);
}

void NanoTekSpice::DoCommandAction(void)
{
	std::unordered_map<std::string, void (NanoTekSpice::*)(void)> tab;
	tab["exit"] = &NanoTekSpice::endRun;
	tab["display"] = &nts::Circuit::displayAll;
	tab["simulate"] = &nts::Circuit::computeAll;
	tab["loop"] = &nts::NanoTekSpice::simulateInLoop;
	tab["dump"] = &nts::Circuit::dumpAll;

	if (tab.count(_CurrentCommand) == 1) {
		((*this).*tab[_CurrentCommand])();
	} else
		updateInputFromCurrentCommand();
}


NanoTekSpice::~NanoTekSpice()
{
}
