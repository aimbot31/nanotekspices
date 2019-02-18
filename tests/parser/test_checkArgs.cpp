/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** test_checkArgs
*/

#include <criterion/criterion.h>
#include "parser/checkArgs.hpp"

Test(checkArgs_bad, checkArgs)
{
	char *str[] = {"./test"};
	cr_assert_any_throw(checkArgs(1, str));
}

Test(checkArgs_bad_2, checkArgs)
{
	char *str[4] = {"./test", "./tests/and.nts", "i=0", "i1=0"};
	cr_assert_any_throw(checkArgs(1, str));
}

Test(checkArgs_bad_3, checkArgs)
{
	char *str[4] = {"./test", "./tests/and.nts", "a=0", "s=0"};
	cr_assert_any_throw(checkArgs(1, str));
}

Test(checkArgs_good, checkArgs)
{
	char *str[] = {"./test", "./tests/and.nts", "a=0", "b=0"};
	cr_assert_none_throw(checkArgs(4, str));
}
