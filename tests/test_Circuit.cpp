/*
** EPITECH PROJECT, 2017
** Test_criterion
** File description:
** Test de Circuit
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Circuit.hpp"
#include "Input.hpp"
#include "Output.hpp"

TestSuite(Circuit,
.init = cr_redirect_stdout,
.fini = NULL,
.signal = 0,
.exit_code = 0,
.disabled = 0,
.description = "Test the function: Circuit",/*
.timeout = 3*/);

Test(Circuit, dump)
{
    Circuit toto("a0");
    std::unique_ptr<nts::IComponent> a1(new Input("a1"));
    std::unique_ptr<nts::IComponent> a2(new Input("a2"));
    std::unique_ptr<nts::IComponent> a3(new Input("a3"));

    toto.addComponent(a1);
    toto.addComponent(a2);
    toto.addComponent(a3);
    toto.dump();
    cr_assert_stdout_eq_str("a1\na2\na3\n");
}

Test(Circuit, addComponent)
{
    Circuit toto("a0");
    std::unique_ptr<nts::IComponent> a1(new Input("a1"));
    std::unique_ptr<nts::IComponent> a2(new Input("a1"));
    std::unique_ptr<nts::IComponent> a3;

    toto.addComponent(a1, Circuit::ComponentType::INPUT);
    cr_assert_any_throw(toto.addComponent(a2, Circuit::ComponentType::INPUT));
    cr_assert_any_throw(toto.addComponent(a3));
}

Test(Circuit, compute)
{
    Circuit Contain("toto");
    std::unique_ptr<nts::IComponent> a1(new Input("a1"));
    std::unique_ptr<nts::IComponent> a2(new Output("o1"));

    a2->setLink(1, *a1, 1);
    cr_assert_any_throw(Contain.compute());
    cr_assert_any_throw(Contain.compute(10));
    cr_assert_any_throw(Contain.compute(0));
    Contain.addComponent(a1, Circuit::ComponentType::INPUT);
    cr_assert_any_throw(Contain.compute());
    Contain.addComponent(a2, Circuit::ComponentType::OUTPUT);
    Contain.compute(2);
}