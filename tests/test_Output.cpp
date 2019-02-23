/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de Output
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Output.hpp"
#include "Input.hpp"

using namespace nts;

TestSuite(Output,
.init = NULL,
.fini = NULL,
.signal = 0,
.exit_code = 0,
.disabled = 0,
.description = "Test the functions of Output",
.timeout = 0);

Test(Output, computeValue)
{
    Output a1("a1");
    Input a2("a2");
    Output a3("a3");

    a1.setLink(1, a2, 1);
    cr_assert_eq(a1.compute(), nts::Tristate::UNDEFINED);
    a2.setInputValue(nts::Tristate::TRUE);
    a1.resetExecution();
    cr_assert_eq(a1.compute(), nts::Tristate::TRUE);
    a3.setLink(1, a1, 1);
    a3.resetExecution();
    cr_assert_eq(a3.compute(), nts::Tristate::TRUE);
}

Test(Output, computeThrow)
{
    Output a1("a1");
    Input a2("a2");
    Output a3("a1");

    cr_assert_any_throw(a1.compute());
    cr_assert_any_throw(a1.compute(0));
    cr_assert_any_throw(a1.compute(2));
}
