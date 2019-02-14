/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de PinLink
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "PinLink.hpp"
#include "Input.hpp"

using namespace nts; 

TestSuite(PinLink,
.init = NULL,
.fini = NULL,
.signal = 0,
.exit_code = 0,
.disabled = 0,
.description = "Test the function: PinLink",
.timeout = 0);

Test(PinLink, LinkCorrectly)
{
    Input a1("a1");

    PinLink toto(&a1, 1);
    cr_assert_eq(toto(), nts::Tristate::UNDEFINED);
}

Test(PinLink, BoolComparaison)
{
    PinLink toto();
    cr_assert_eq(toto, false);
}
