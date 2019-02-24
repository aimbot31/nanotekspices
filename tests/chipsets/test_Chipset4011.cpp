/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de Chipset4011
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Chipset4011.hpp"
#include "Input.hpp"
#include "Output.hpp"

using namespace nts;

TestSuite(Chipset4011,
.init = NULL,
.fini = NULL,
.signal = 0,
.exit_code = 0,
.disabled = 0,
.description = "Test the function: Chipset4011",
.timeout = 0);

Test(Chipset4011, computeWrongPin)
{
    Chipset4011 toto("a0");

    cr_expect_any_throw(toto.compute());
}

Test(Chipset4011, computeFirstGate)
{
    Chipset4011 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_expect_eq(toto.compute(3), nts::Tristate::UNDEFINED);
    toto.setLink(1, a1, 1);
    toto.resetExecution();
    cr_expect_eq(toto.compute(3), nts::Tristate::UNDEFINED);
    toto.setLink(2, a2, 1);
    a1.setInputValue(nts::Tristate::TRUE);
    a2.setInputValue(nts::Tristate::FALSE);
    toto.resetExecution();
    cr_expect_eq(toto.compute(3), nts::Tristate::TRUE);
}

Test(Chipset4011, computeSecondGate)
{
    Chipset4011 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_expect_eq(toto.compute(4), nts::Tristate::UNDEFINED);
    toto.setLink(5, a1, 1);
    toto.resetExecution();
    cr_expect_eq(toto.compute(4), nts::Tristate::UNDEFINED);
    toto.setLink(6, a2, 1);
    a1.setInputValue(nts::Tristate::TRUE);
    a2.setInputValue(nts::Tristate::FALSE);
    toto.resetExecution();
    cr_expect_eq(toto.compute(4), nts::Tristate::TRUE);
}

Test(Chipset4011, computeThirdGate)
{
    Chipset4011 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_expect_eq(toto.compute(10), nts::Tristate::UNDEFINED);
    toto.resetExecution();
    toto.setLink(8, a1, 1);
    cr_expect_eq(toto.compute(10), nts::Tristate::UNDEFINED);
    toto.setLink(9, a2, 1);
    a1.setInputValue(nts::Tristate::TRUE);
    a2.setInputValue(nts::Tristate::FALSE);
    toto.resetExecution();
    toto.compute(10);
    cr_expect_eq(toto.compute(10), nts::Tristate::TRUE);
}

Test(Chipset4011, computeFourthGate)
{
    Chipset4011 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_expect_eq(toto.compute(11), nts::Tristate::UNDEFINED);
    toto.setLink(12, a1, 1);
    toto.resetExecution();
    cr_expect_eq(toto.compute(11), nts::Tristate::UNDEFINED);
    toto.setLink(13, a2, 1);
    a1.setInputValue(nts::Tristate::TRUE);
    a2.setInputValue(nts::Tristate::FALSE);
    toto.resetExecution();
    toto.compute(11);
    cr_expect_eq(toto.compute(11), nts::Tristate::TRUE);
}
