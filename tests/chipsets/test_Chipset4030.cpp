/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de Chipset4030
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Chipset4030.hpp"
#include "Input.hpp"
#include "Output.hpp"

using namespace nts;

TestSuite(Chipset4030,
.init = NULL,
.fini = NULL,
.signal = 0,
.exit_code = 0,
.disabled = 0,
.description = "Test the function: Chipset4030",
.timeout = 0);

Test(Chipset4030, computeWrongPin)
{
    Chipset4030 toto("a0");

    cr_expect_any_throw(toto.compute());
}

Test(Chipset4030, computeFirstGate)
{
    Chipset4030 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_expect_eq(toto.compute(3), nts::Tristate::UNDEFINED);
    toto.setLink(1, a1, 1);
    toto.resetExecution();
    cr_expect_eq(toto.compute(3), nts::Tristate::UNDEFINED);
    toto.setLink(2, a2, 1);
    a1.setInputValue(nts::Tristate::TRUE);
    a2.setInputValue(nts::Tristate::TRUE);
    toto.resetExecution();
    cr_expect_eq(toto.compute(3), nts::Tristate::FALSE);
}

Test(Chipset4030, computeSecondGate)
{
    Chipset4030 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_expect_eq(toto.compute(4), nts::Tristate::UNDEFINED);
    toto.setLink(5, a1, 1);
    toto.resetExecution();
    cr_expect_eq(toto.compute(4), nts::Tristate::UNDEFINED);
    toto.setLink(6, a2, 1);
    a1.setInputValue(nts::Tristate::TRUE);
    a2.setInputValue(nts::Tristate::TRUE);
    toto.resetExecution();
    cr_expect_eq(toto.compute(4), nts::Tristate::FALSE);
}

Test(Chipset4030, computeThirdGate)
{
    Chipset4030 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_expect_eq(toto.compute(10), nts::Tristate::UNDEFINED);
    toto.setLink(8, a1, 1);
    toto.resetExecution();
    cr_expect_eq(toto.compute(10), nts::Tristate::UNDEFINED);
    toto.setLink(9, a2, 1);
    a1.setInputValue(nts::Tristate::TRUE);
    a2.setInputValue(nts::Tristate::TRUE);
    toto.resetExecution();
    toto.compute(10);
    cr_expect_eq(toto.compute(10), nts::Tristate::FALSE);
}

Test(Chipset4030, computeFourthGate)
{
    Chipset4030 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_expect_eq(toto.compute(11), nts::Tristate::UNDEFINED);
    toto.setLink(12, a1, 1);
    cr_expect_eq(toto.compute(11), nts::Tristate::UNDEFINED);
    toto.setLink(13, a2, 1);
    a1.setInputValue(nts::Tristate::TRUE);
    a2.setInputValue(nts::Tristate::TRUE);
    toto.resetExecution();
    toto.compute(11);
    cr_expect_eq(toto.compute(11), nts::Tristate::FALSE);
}
