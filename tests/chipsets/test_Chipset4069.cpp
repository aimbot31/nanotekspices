/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de Chipset4069
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Chipset4069.hpp"
#include "Input.hpp"
#include "Output.hpp"

using namespace nts;

TestSuite(Chipset4069,
.init = NULL,
.fini = NULL,
.signal = 0,
.exit_code = 0,
.disabled = 0,
.description = "Test the function: Chipset4069",
.timeout = 0);

Test(Chipset4069, computeWrongPin)
{
    Chipset4069 toto("a0");

    cr_assert_any_throw(toto.compute());
}

Test(Chipset4069, computeFirstGate)
{
    Chipset4069 toto("a0");
    Input a1("a1");

    cr_assert_any_throw(toto.compute(2));
    toto.setLink(1, a1, 1);
    cr_assert_eq(toto.compute(2), nts::Tristate::UNDEFINED);
}

Test(Chipset4069, computeSecondGate)
{
    Chipset4069 toto("a0");
    Input a1("a1");

    toto.setLink(3, a1, 1);
    cr_assert_eq(toto.compute(4), nts::Tristate::UNDEFINED);
}

Test(Chipset4069, computeThirdGate)
{
    Chipset4069 toto("a0");
    Input a1("a1");

    toto.setLink(5, a1, 1);
    cr_assert_eq(toto.compute(6), nts::Tristate::UNDEFINED);
}

Test(Chipset4069, computeFourthGate)
{
    Chipset4069 toto("a0");
    Input a1("a1");

    toto.setLink(9, a1, 1);
    cr_assert_eq(toto.compute(8), nts::Tristate::UNDEFINED);
}

Test(Chipset4069, computeFithGate)
{
    Chipset4069 toto("a0");
    Input a1("a1");

    toto.setLink(11, a1, 1);
    cr_assert_eq(toto.compute(10), nts::Tristate::UNDEFINED);
}

Test(Chipset4069, computeSixGate)
{
    Chipset4069 toto("a0");
    Input a1("a1");

    toto.setLink(13, a1, 1);
    cr_assert_eq(toto.compute(12), nts::Tristate::UNDEFINED);
}
