##
## EPITECH PROJECT, 2019
## OOP_nanotekspice_2018
## File description:
## Makefile
##

NAME		=	./nanotekspice

PATH_SRCS	=	./src/

FILES		=	AComponent.cpp	\
                Input.cpp		\
                Gates.cpp		\

SRCS		=	$(addprefix $(PATH_SRCS), $(FILES))	\

SRC_MAIN	=	./src/main.cpp	\

OBJS		=	$(SRCS:.cpp=.o)	\
				$(SRC_MAIN:.cpp=.o)	\

#------------------ TESTS -------------

NAME_TEST	=	./unit_test

NAME_QUICK_TEST	=	quicktu

PATH_TEST	=	./tests/

FILES_TEST	=	test_Input.cpp		\
				test_Gates.cpp		\

SRCS_TESTS	=	$(addprefix $(PATH_TEST), $(FILES_TEST))	\

OBJS_TEST	=	$(SRCS:.cpp=.o)	\
				$(SRCS_TESTS:.cpp=.o)	\

#------------------ DEBUG -------------

NAME_DEBUG	=	./debug

NAME_DEBUG_TEST	=	./debug_criterion

#------------------ COMPILATION ------------

HEADER		=	-I ./include/ -I ./include/chipsets

CXXFLAGS	=	-W -Wall -Wextra -std=c++11 $(HEADER)

CXX			=	g++

# ------------------ MANDATORY ------------

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

tests_run:
	$(CXX) -o $(NAME_TEST) $(SRCS_TESTS) $(SRCS) $(CXXFLAGS) -lcriterion --coverage
	$(NAME_TEST) --always-succeed

clean:
	rm --force $(OBJS) $(OBJS_TEST) *.gc* vgcore.*

fclean: clean
	rm --force $(NAME) $(NAME_TEST) $(NAME_DEBUG) $(NAME_QUICK_TEST) $(NAME_DEBUG_TEST) a.out

re: fclean $(NAME)

# ------------------ DEBUG -----------------

$(NAME_DEBUG):
	$(CXX) -g3 -o $(NAME_DEBUG) $(SRC_MAIN) $(HEADER) $(SRCS)

debugCriterion:
	$(CXX) -o $(NAME_DEBUG_TEST) $(SRCS_TESTS) $(SRCS) $(CXXFLAGS) -lcriterion --coverage -g3
	$(NAME_DEBUG_TEST) --always-succeed --verbose --debug=gdb --filter="$T"

# ------------------ QUICK ------------------

$(NAME_QUICK_TEST): $(OBJS_TEST)
	$(CXX) -o $(NAME_QUICK_TEST) $(OBJS_TEST) $(CXXFLAGS)  -lcriterion --coverage

run$(NAME_QUICK_TEST): $(NAME_QUICK_TEST)
	./$(NAME_QUICK_TEST) --always-succeed --verbose -S --full-stats -j4 --filter="*$T" --timeout=180