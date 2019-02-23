/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** NanoTekSpice
*/

#ifndef NANOTEKSPICE_HPP_
	#define NANOTEKSPICE_HPP_

    #include "Circuit.hpp"

    namespace nts {

        class NanoTekSpice : public nts::Circuit {
            public:
                NanoTekSpice(int ac, char **av, const std::string &name = "NanoTekSpice");
                ~NanoTekSpice();

                void run(void);


            protected:
                std::string _CurrentCommand;
                std::string &getNextCommand(void);
                void DoCommandAction(void);
                void simulateInLoop(void);
                void updateInputFromCurrentCommand(void);

                void endRun(void);

                static void stopRunning(int);
                static void doNothing(int);
            public:
                static bool _Running;
            private:
        };
    }

#endif /* !NANOTEKSPICE_HPP_ */
