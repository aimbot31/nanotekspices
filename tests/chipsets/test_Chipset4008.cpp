/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de Chipset4008
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Chipset4008.hpp"
#include "Input.hpp"
#include "Output.hpp"

using namespace nts;

TestSuite(Chipset4008,
.init = NULL,
.fini = NULL,
.signal = 0,
.exit_code = 0,
.disabled = 0,
.description = "Test the function: Chipset4008",
.timeout = 0);

Test(Chipset4008, computeWrongPin)
{
    Chipset4008 toto("a0");

    cr_assert_any_throw(toto.compute());
}


Test(Chipset4008, Entry_Correct_1,
.description = "Parameter Correct 1")
{
    Chipset4008 toto("a0");
    Input a1("a1");
    Input a2("a2");
    Input a3("a3");
    Input a4("a4");
    Input a5("a5");
    Input a6("a6");
    Input a7("a7");
    Input a8("a8");
    Input a9("a9");

    toto.setLink(1, a1, 1);
    toto.setLink(15, a2, 1);
    toto.setLink(2, a3, 1);
    toto.setLink(3, a4, 1);
    toto.setLink(4, a5, 1);
    toto.setLink(5, a6, 1);
    toto.setLink(6, a7, 1);
    toto.setLink(7, a8, 1);
    toto.setLink(9, a9, 1);
    a1.setInputValue(nts::Tristate::UNDEFINED);
    a2.setInputValue(nts::Tristate::UNDEFINED);
    a3.setInputValue(nts::Tristate::UNDEFINED);
    a4.setInputValue(nts::Tristate::UNDEFINED);
    a5.setInputValue(nts::Tristate::UNDEFINED);
    a6.setInputValue(nts::Tristate::UNDEFINED);
    a7.setInputValue(nts::Tristate::UNDEFINED);
    a8.setInputValue(nts::Tristate::UNDEFINED);
    a9.setInputValue(nts::Tristate::UNDEFINED);
    cr_assert_eq(toto.compute(10), Tristate::UNDEFINED);
    cr_assert_eq(toto.compute(11), Tristate::UNDEFINED);
    cr_assert_eq(toto.compute(12), Tristate::UNDEFINED);
    cr_assert_eq(toto.compute(13), Tristate::UNDEFINED);
    cr_assert_eq(toto.compute(14), Tristate::UNDEFINED);
}

Test(Chipset4008, Entry_Correct_2,
.description = "Parameter Correct 1")
{
    Chipset4008 toto("a0");
    Input a1("a1");
    Input a2("a2");
    Input a3("a3");
    Input a4("a4");
    Input a5("a5");
    Input a6("a6");
    Input a7("a7");
    Input a8("a8");
    Input a9("a9");

    toto.setLink(1, a1, 1);
    toto.setLink(15, a2, 1);
    toto.setLink(2, a3, 1);
    toto.setLink(3, a4, 1);
    toto.setLink(4, a5, 1);
    toto.setLink(5, a6, 1);
    toto.setLink(6, a7, 1);
    toto.setLink(7, a8, 1);
    toto.setLink(9, a9, 1);
    a1.setInputValue(nts::Tristate::TRUE);
    a2.setInputValue(nts::Tristate::TRUE);
    a3.setInputValue(nts::Tristate::TRUE);
    a4.setInputValue(nts::Tristate::TRUE);
    a5.setInputValue(nts::Tristate::TRUE);
    a6.setInputValue(nts::Tristate::TRUE);
    a7.setInputValue(nts::Tristate::TRUE);
    a8.setInputValue(nts::Tristate::TRUE);
    a9.setInputValue(nts::Tristate::TRUE);
    cr_assert_eq(toto.compute(10), Tristate::TRUE);
    cr_assert_eq(toto.compute(11), Tristate::TRUE);
    cr_assert_eq(toto.compute(12), Tristate::TRUE);
    cr_assert_eq(toto.compute(13), Tristate::TRUE);
    cr_assert_eq(toto.compute(14), Tristate::TRUE);
}

Test(Chipset4008, Entry_Correct_3,
.description = "Parameter Correct 1")
{
    Chipset4008 toto("a0");
    Input a1("a1");
    Input a2("a2");
    Input a3("a3");
    Input a4("a4");
    Input a5("a5");
    Input a6("a6");
    Input a7("a7");
    Input a8("a8");
    Input a9("a9");

    toto.setLink(1, a1, 1);
    toto.setLink(15, a2, 1);
    toto.setLink(2, a3, 1);
    toto.setLink(3, a4, 1);
    toto.setLink(4, a5, 1);
    toto.setLink(5, a6, 1);
    toto.setLink(6, a7, 1);
    toto.setLink(7, a8, 1);
    toto.setLink(9, a9, 1);
    a1.setInputValue(nts::Tristate::FALSE);
    a2.setInputValue(nts::Tristate::FALSE);
    a3.setInputValue(nts::Tristate::TRUE);
    a4.setInputValue(nts::Tristate::FALSE);
    a5.setInputValue(nts::Tristate::TRUE);
    a6.setInputValue(nts::Tristate::TRUE);
    a7.setInputValue(nts::Tristate::TRUE);
    a8.setInputValue(nts::Tristate::TRUE);
    a9.setInputValue(nts::Tristate::FALSE);
    cr_assert_eq(toto.compute(10), Tristate::FALSE);
    cr_assert_eq(toto.compute(11), Tristate::TRUE);
    cr_assert_eq(toto.compute(12), Tristate::FALSE);
    cr_assert_eq(toto.compute(13), Tristate::TRUE);
    cr_assert_eq(toto.compute(14), Tristate::FALSE);
}
