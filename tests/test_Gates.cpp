/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de Gates
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Gates.hpp"

using namespace nts;

TestSuite(Gates,
.init = NULL,
.fini = NULL,
.signal = 0,
.exit_code = 0,
.disabled = 0,
.description = "Test the functions of Gates",
.timeout = 0);

Test(Gates, Not)
{
    cr_assert_eq(Gates::Not(Tristate::TRUE), Tristate::FALSE);
    cr_assert_eq(Gates::Not(Tristate::FALSE), Tristate::TRUE);
    cr_assert_eq(Gates::Not(Tristate::UNDEFINED), Tristate::UNDEFINED);
}

Test(Gates, Or)
{
    cr_assert_eq(Gates::Or(Tristate::FALSE, Tristate::FALSE), Tristate::FALSE);
    cr_assert_eq(Gates::Or(Tristate::TRUE, Tristate::FALSE), Tristate::TRUE);
    cr_assert_eq(Gates::Or(Tristate::FALSE, Tristate::TRUE), Tristate::TRUE);
    cr_assert_eq(Gates::Or(Tristate::FALSE, Tristate::UNDEFINED), Tristate::UNDEFINED);
    cr_assert_eq(Gates::Or(Tristate::TRUE, Tristate::TRUE), Tristate::TRUE);
}

Test(Gates, And)
{
    cr_assert_eq(Gates::And(Tristate::FALSE, Tristate::FALSE), Tristate::FALSE);
    cr_assert_eq(Gates::And(Tristate::TRUE, Tristate::FALSE), Tristate::FALSE);
    cr_assert_eq(Gates::And(Tristate::TRUE, Tristate::UNDEFINED), Tristate::UNDEFINED);
    cr_assert_eq(Gates::And(Tristate::FALSE, Tristate::TRUE), Tristate::FALSE);
    cr_assert_eq(Gates::And(Tristate::TRUE, Tristate::TRUE), Tristate::TRUE);
}

Test(Gates, Nor)
{
    cr_assert_eq(Gates::Nor(Tristate::FALSE, Tristate::FALSE), Tristate::TRUE);
    cr_assert_eq(Gates::Nor(Tristate::TRUE, Tristate::FALSE), Tristate::FALSE);
    cr_assert_eq(Gates::Nor(Tristate::FALSE, Tristate::TRUE), Tristate::FALSE);
    cr_assert_eq(Gates::Nor(Tristate::TRUE, Tristate::TRUE), Tristate::FALSE);
}


Test(Gates, Nand)
{
    cr_assert_eq(Gates::Nand(Tristate::FALSE, Tristate::FALSE), Tristate::TRUE);
    cr_assert_eq(Gates::Nand(Tristate::TRUE, Tristate::FALSE), Tristate::TRUE);
    cr_assert_eq(Gates::Nand(Tristate::FALSE, Tristate::TRUE), Tristate::TRUE);
    cr_assert_eq(Gates::Nand(Tristate::TRUE, Tristate::TRUE), Tristate::FALSE);
}

Test(Gates, Xor)
{
    cr_assert_eq(Gates::Xor(Tristate::FALSE, Tristate::FALSE), Tristate::FALSE);
    cr_assert_eq(Gates::Xor(Tristate::TRUE, Tristate::FALSE), Tristate::TRUE);
    cr_assert_eq(Gates::Xor(Tristate::FALSE, Tristate::TRUE), Tristate::TRUE);
    cr_assert_eq(Gates::Xor(Tristate::TRUE, Tristate::TRUE), Tristate::FALSE);
}

