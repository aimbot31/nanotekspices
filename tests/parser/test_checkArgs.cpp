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
	Args args;
	char *str[] = {"./test"};
	cr_assert_any_throw(checkArgs(1, str, args));
}

Test(checkArgs_bad_2, checkArgs)
{
	Args args;
	char *str[4] = {"./test", "./tests/and.nts", "i=0", "i1=0"};
	cr_assert_any_throw(checkArgs(1, str, args));
}

Test(checkArgs_bad_3, checkArgs)
{
	Args args;
	char *str[4] = {"./test", "./tests/and.nts", "a=0", "s=0"};
	cr_assert_any_throw(checkArgs(1, str, args));
}

Test(checkArgs_bad_4, checkArgs)
{
	Args args;
	char *str[4] = {"./test", "./tests/and.nts", "a=1", "b=2"};
	cr_assert_any_throw(checkArgs(1, str, args));
}

Test(checkArgs_bad_5, checkArgs)
{
	Args args;
	char *str[4] = {"./test", "./tests/and.nts", "SALUT A TOUS C JUL", "YAMAH"};
	cr_assert_any_throw(checkArgs(1, str, args));
}

Test(checkArgs_bad_6, checkArgs)
{
	Args args;
	char *str[4] = {"./test", "./tests/and.nts", "a=", "b=3"};
	cr_assert_any_throw(checkArgs(1, str, args));
}

Test(checkArgs_good, checkArgs)
{
	Args args;
	char *str[] = {"./test", "./tests/and.nts", "a=0", "b=0"};
	cr_assert_none_throw(checkArgs(4, str, args));
}

Test(checkArgs_good_2, checkArgs)
{
	Args args;
	char *str[] = {"./test", "./tests/and.nts", "a=1", "b=1"};
	cr_assert_none_throw(checkArgs(4, str, args));
}