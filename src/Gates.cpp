/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** Gates
*/

#include "Gates.hpp"

nts::Tristate nts::Gates::Or(nts::Tristate input1, nts::Tristate input2)
{
    if (input1 == nts::Tristate::TRUE
    || input2 == nts::Tristate::TRUE) {
        return nts::Tristate::TRUE;
    }
    if (input1 == nts::Tristate::FALSE
    && input2 == nts::Tristate::FALSE) {
        return nts::Tristate::FALSE;
    }
    return nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Gates::Not(nts::Tristate input)
{
    if (input == nts::Tristate::UNDEFINED)
        return UNDEFINED;
    return ((input != nts::Tristate::TRUE) ? nts::Tristate::TRUE : nts::Tristate::FALSE);
}

nts::Tristate nts::Gates::And(nts::Tristate input1, nts::Tristate input2)
{
    if (input1 == nts::Tristate::TRUE
    && input2 == nts::Tristate::TRUE)
        return nts::Tristate::TRUE;
    if ((input1 == nts::Tristate::FALSE
    || input2 == nts::Tristate::FALSE))
        return nts::Tristate::FALSE;
    return nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Gates::Nor(nts::Tristate input1, nts::Tristate input2)
{
    return nts::Gates::Not(nts::Gates::Or(input1, input2));
}

nts::Tristate nts::Gates::Nand(nts::Tristate input1, nts::Tristate input2)
{
    return nts::Gates::Not(nts::Gates::And(input1, input2));
}