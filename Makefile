##
## EPITECH PROJECT, 2019
## OOP_nanotekspice_2018
## File description:
## Makefile
##

NAME		=	./nanotekspice

PATH_SRCS	=	./src/

FILES		=	parser/checkArgs.cpp		\
				parser/GestFile.cpp			\
				exceptions/Exceptions.cpp

SRCS		=	$(addprefix $(PATH_SRCS), $(FILES))	\

SRC_MAIN	=	./src/main.cpp	\

OBJS		=	$(SRCS:.cpp=.o)	\
				$(SRC_MAIN:.cpp=.o)	\

#------------------ TESTS -------------

NAME_TEST	=	./unit_test

NAME_QUICK_TEST	=	quicktu

PATH_TEST	=	./tests/

FILES_TEST	=	parser/test_checkArgs.cpp		\
				parser/test_GestFile.cpp		\

SRCS_TESTS	=	$(addprefix $(PATH_TEST), $(FILES_TEST))	\

OBJS_TEST	=	$(SRCS:.cpp=.o)	\
				$(SRCS_TESTS:.cpp=.o)	\

#------------------ DEBUG -------------

NAME_DEBUG	=	./debug

#------------------ COMPILATION ------------

HEADER		=	-I ./include/

CXXFLAGS	=	-W -Wall -Wextra -pedantic $(HEADER)

CXX			=	g++

# ------------------ MANDATORY ------------

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

tests_run:
	$(CXX) -o $(NAME_TEST) $(SRCS_TESTS) $(SRCS) $(CXXFLAGS) -lcriterion --coverage
	$(NAME_TEST) --always-succeed

travis_run:
	$(CXX) -o $(NAME_TEST) $(SRCS_TESTS) $(SRCS) $(CXXFLAGS) -lcriterion --coverage
	$(NAME_TEST)

clean:
	rm --force $(OBJS) *.gc*

fclean: clean
	rm --force $(NAME) $(NAME_TEST) $(NAME_DEBUG)

re: fclean $(NAME)

# ------------------ DEBUG -----------------

$(NAME_DEBUG):
	$(CXX) -g3 -o $(NAME_DEBUG) $(HEADER)

# ------------------ QUICK ------------------

quicktu: $(OBJS) $(SRCS_TESTS:.cpp=.o)
	$(CXX) -o $(NAME_TEST) $(OBJS) $(SRCS_TESTS:.cpp=.o) -lcriterion --coverage