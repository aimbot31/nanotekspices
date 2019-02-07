/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Gates
*/

#ifndef GATES_H_
	#define GATES_H_

    #include <functional>
    #include "IComponent.hpp"

    namespace nts {
        class Gates {
            public:
                virtual ~Gates() = default;
                static nts::Tristate Or(nts::Tristate input1, nts::Tristate input2);
                static nts::Tristate And(nts::Tristate input1, nts::Tristate input2);
                static nts::Tristate Not(nts::Tristate input);
                static nts::Tristate Nor(nts::Tristate input1, nts::Tristate input2);
                static nts::Tristate Nand(nts::Tristate input1, nts::Tristate input2);
        };
    }

#endif /* !GATES_H_ */
