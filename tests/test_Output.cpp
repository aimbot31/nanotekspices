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

TestSuite(Output,
.init = cr_redirect_stdout,
.fini = NULL,
.signal = 0,
.exit_code = 0,
.disabled = 0,
.description = "Test the function: Output",
.timeout = 0);

Test(Output, computeValue)
{
    Output a1("a1");
    Input a2("a2");

    a1.setLink(1, a2, 1);
    cr_assert_eq(a1.compute(), nts::Tristate::UNDEFINED);
    a2.setInputValue(nts::Tristate::TRUE);
    cr_assert_eq(a1.compute(), nts::Tristate::TRUE);
}

Test(Output, computeThrow)
{
    Output a1("a1");
    Input a2("a2");
    Output a3("a1");

    cr_assert_any_throw(a1.compute());
    cr_assert_any_throw(a1.compute(0));
}
