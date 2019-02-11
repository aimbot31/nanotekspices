/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de Chipset4001
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Chipset4001.hpp"
#include "Input.hpp"
#include "Output.hpp"

using namespace nts;

TestSuite(Chipset4001,
.init = NULL,
.fini = NULL,
.signal = 0,
.exit_code = 0,
.disabled = 0,
.description = "Test the function: Chipset4001",
.timeout = 0);

Test(Chipset4001, computeWrongPin)
{
    Chipset4001 toto("a0");

    cr_assert_any_throw(toto.compute());
}

Test(Chipset4001, computeFirstGate)
{
    Chipset4001 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_assert_any_throw(toto.compute(3));
    toto.setLink(1, a1, 1);
    cr_assert_any_throw(toto.compute(3));
    toto.setLink(2, a2, 1);
    cr_assert_eq(toto.compute(3), nts::Tristate::UNDEFINED);
}

Test(Chipset4001, computeSecondGate)
{
    Chipset4001 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_assert_any_throw(toto.compute(4));
    toto.setLink(5, a1, 1);
    cr_assert_any_throw(toto.compute(4));
    toto.setLink(6, a2, 1);
    cr_assert_eq(toto.compute(4), nts::Tristate::UNDEFINED);
}

Test(Chipset4001, computeThirdGate)
{
    Chipset4001 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_assert_any_throw(toto.compute(10));
    toto.setLink(8, a1, 1);
    cr_assert_any_throw(toto.compute(10));
    toto.setLink(9, a2, 1);
    toto.compute(10);
    cr_assert_eq(toto.compute(10), nts::Tristate::UNDEFINED);
}

Test(Chipset4001, computeFourthGate)
{
    Chipset4001 toto("a0");
    Input a1("a1");
    Input a2("a2");

    cr_assert_any_throw(toto.compute(11));
    toto.setLink(12, a1, 1);
    cr_assert_any_throw(toto.compute(11));
    toto.setLink(13, a2, 1);
    toto.compute(11);
    cr_assert_eq(toto.compute(11), nts::Tristate::UNDEFINED);
}
