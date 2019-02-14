/*
** EPITECH PROJECT, 2019
** nanotekspices
** File description:
** test_GestFile
*/

#include <criterion/criterion.h>
#include "parser/GestFile.hpp"

Test(GestFile_goodFile, GestFile)
{
	GestFile tmp("./tests/and.nts");
	cr_assert(tmp.GetStatus() == true);

}

Test(GestFile_badFile, GestFile)
{
	GestFile tmp("./tests/ande.nts");
	cr_assert(tmp.GetStatus() == false);

}