/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de Input
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Input.hpp"

TestSuite(Input,
.init = NULL,
.fini = NULL,
.signal = 0,
.exit_code = 0,
.disabled = 0,
.description = "Test the Object: Input",
.timeout = 0);

Test(Input, Constructor,
.description = "Constructor param std::string \"name\"")
{
	Input *input = new Input("name");

	cr_assert_neq(input, nullptr);
	cr_assert_eq(input->getName(), "name");
	cr_assert_eq(input->compute(), nts::Tristate::UNDEFINED);
	delete input;
}

Test(Input, setInputValue_Compute,
.description = "setInputValue and Compute setter and getter")
{
	Input input("a0");

	cr_assert_eq(input.compute(), nts::Tristate::UNDEFINED);
	input.setInputValue(nts::Tristate::FALSE);
	cr_assert_eq(input.compute(), nts::Tristate::FALSE);
	input.setInputValue(nts::Tristate::TRUE);
	cr_assert_eq(input.compute(), nts::Tristate::TRUE);
}

Test(Input, dump,
.description = "Dump: test the ouput on stdout",
.init = cr_redirect_stdout)
{
	Input input("a0");

	input.dump();
	cr_assert_stdout_eq_str("a0\n");
}

Test(Input, setLink,
.description = "setLink: test exception")
{
	Input input("a0");
	Input other("a1");
	Input otherAgain("a2");
	Input newI("a0");

	input.setLink(1, other, 1);
	cr_assert_any_throw(input.setLink(2, otherAgain, 1));
	cr_assert_any_throw(input.setLink(1, otherAgain, 1));
	cr_assert_any_throw(newI.setLink(0, otherAgain, 1));
	cr_assert_any_throw(newI.setLink(1, otherAgain, 0));
}